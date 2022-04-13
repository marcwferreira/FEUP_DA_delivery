#include "MailSystem.h"

MailSystem::MailSystem(const string &trucks_filename, const string &packages_filename)
{
    this->trucks = FileReader::getTrucks(trucks_filename);
    this->packages = FileReader::getPackages(packages_filename);
}

void MailSystem::setPackages(const string &packages_filename)
{
    this->packages = FileReader::getPackages(INPUT_FOLDER + packages_filename);
}

void MailSystem::case1(const string &filename, const unsigned int day)
{
    fstream file, notDeliveredFile;
    file.open(filename, ios::app);
    notDeliveredFile.open("../input/NotDelivered.txt", ios::out);

    if (!file.is_open())
    {
        cout << "ERROR: Unable to open the file " << filename << "." << endl;
        return;
    }

    if (!notDeliveredFile.is_open())
    {
        cout << "ERROR: Unable to open the file "
             << "../input/NotDelivered.txt"
             << "." << endl;
        return;
    }

    bool flagNotSent = true;
    if (statistics())
    {
        this->trucks.sort(byMaxVolumeDesc); // descending
        this->packages.sort(byVolumeAsc);   // ascending -> na carrinha maior cabem mais packages menores
    }
    else
    {
        this->trucks.sort(byMaxWeightDesc); // descending
        this->packages.sort(byWeightAsc);   // ascending -> na carrinha que pode levar mais peso cabem mais packages menos pesados
    }

    file << "Information: " << endl
         << "\tTruck: matricula volMax pesoMax custo" << endl
         << "\tPackage: priority volume weight reward duration" << endl
         << endl;

    notDeliveredFile << "Information: " << endl
                     << "\tPackage: priority volume weight reward duration" << endl
                     << endl;

    file << "Day " << day << ": " << endl;
    for (list<Package>::iterator i = packages.begin(); i != packages.end(); i++)
    {
        if (!(*i).isExpress())
        {
            for (list<Truck>::iterator j = trucks.begin(); j != trucks.end(); j++)
            {
                if ((*j).addPackage(*i))
                {
                    flagNotSent = false;
                    break;
                }
            }
            if (flagNotSent)
            {
                (*i).addPriority();
                notDeliveredFile << "\t" << (*i);
            }
            else
            {
                flagNotSent = true;
            }
        }
    }

    // results
    int howManyTrucks = 0, howManyPackages = 0, totalPackages = 0;
    for (list<Truck>::iterator j = trucks.begin(); j != trucks.end(); j++)
    {
        list<Package> p = (*j).getPackages();
        if (!p.empty())
        {
            file << "\tTruck: " << *j;
            for (auto i = p.begin(); i != p.end(); i++)
            {
                howManyPackages++;
                file << "\t\tPackage " << howManyPackages << ": " << (*i);
                totalPackages++;
            }
            file << "\tNumber of Packages: " << howManyPackages << endl
                 << endl;
            howManyTrucks++;
            howManyPackages = 0;
        }
    }
    // cout << howManyTrucks << ",";
    file << "\tNumber of trucks: " << howManyTrucks << endl;
    file << "\tNumber of packages (total, !express): " << totalPackages << endl;

    file.close();
    notDeliveredFile.close();
}

bool MailSystem::statistics()
{
    reset();

    long long int pesoTotal = 0, volumeTotal = 0;
    int numberPackages = this->packages.size();

    for (const Package &p : packages)
    {
        pesoTotal += p.getWeight();
        volumeTotal += p.getVolume();
    }

    double mediaPeso = pesoTotal / (double)numberPackages, mediaVolume = volumeTotal / (double)numberPackages;
    double desvioPeso = 0, desvioVolume = 0;

    for (const Package &p : packages)
    {
        desvioPeso = abs(mediaPeso - p.getWeight()) > desvioPeso ? abs(mediaPeso - p.getWeight()) : desvioPeso;
        desvioVolume = abs(mediaVolume - p.getVolume()) > desvioVolume ? abs(mediaVolume - p.getVolume()) : desvioVolume;
    }

    return desvioPeso >= desvioVolume;
}

void MailSystem::reset()
{

    for (list<Truck>::iterator it = trucks.begin(); it != trucks.end(); it++)
    {
        (*it).clearPackages();
    }
    this->trucks.sort();
    this->packages.sort();
}

void MailSystem::case2() {

    this->trucks.sort(byCostAsc); // ascending
    this->packages.sort(byRewardDesc); 

    list<Package> normalPackages;
    for(auto elem: packages) {
        if(!elem.isExpress())
            normalPackages.push_back(elem);
    }

    bool statisticVolume = statistics();
    for (list<Truck>::iterator j = trucks.begin() ; j != trucks.end() ; j++) {
        bool TruckPositive;
        if (!normalPackages.empty()) {
            j->clearPackages();
            if(statisticVolume)
                TruckPositive = knapsackVolume( (*j) , normalPackages);
            else
                TruckPositive = knapsackWeight((*j) , normalPackages);
            if (!TruckPositive)
                break;
        }
        else break;
    }

    int money = 0;
    for (list<Truck>::iterator j = trucks.begin() ; j != trucks.end() ; j++) {
        if(j->getEmpty()) continue;
        int moneyTemp = 0;

        cout << endl << "Carrinha: " << j->getLicencePlate() << endl;
        cout << "capacidade total (peso): " << j->getMaxWeight() <<" capacidade atigida (peso): " << j->getActualWeight() << endl;
        cout << "capacidade total (volume): " << j->getMaxVolume() <<" capacidade atigida (volume): " << j->getActualVolume() << endl;
        if( j->getPackages().empty()) continue;
        moneyTemp -= j->getCost();
        cout << "custo dela: " << j->getCost() << endl;
        for(auto elem: j->getPackages()){
            moneyTemp += elem.getReward();
            cout << "Custo do pacote: " << elem.getReward() << " peso do elemento: " << elem.getWeight() << " volume do elemento: " << elem.getVolume() << endl;
        }
        cout << "O ganho total foi: " << moneyTemp << endl;
        money += moneyTemp;
    }

    cout << endl << "O ganho total foi final: " << money << endl;
}

bool MailSystem::knapsackWeight(Truck &currentTruck, list<Package> &currentPackages) {

    //table to calculate the reward values
    std::vector<std::vector<int>> knapsack;
    knapsack.resize(currentPackages.size()+1);
    for (unsigned int i = 0; i < currentPackages.size() + 1; i++) {
        knapsack[i].resize(currentTruck.getMaxWeight() + 1);
        knapsack[i][0] = 0;
    }
    for (unsigned int i = 1; i < currentTruck.getMaxWeight() + 1; i++)
        knapsack[0][i] = 0;

    list<Package>::iterator pIt = currentPackages.begin();
    // Computes the maximum value that can be reached varying the number of elements and the capacity
    for (unsigned int n = 1; n <= currentPackages.size(); n++) {
        for (unsigned int capacity = 1; capacity <= currentTruck.getMaxWeight(); capacity++) {
            if ( pIt->getWeight() <= capacity) {
                if ( ( (int)(( *pIt).getWeight()) + knapsack[n-1][capacity - (int)(( *pIt).getWeight())] ) > knapsack[n-1][capacity])
                    knapsack[n][capacity] = pIt->getReward()+knapsack[n-1][capacity - pIt->getWeight()];
                else
                    knapsack[n][capacity] = knapsack[n - 1][capacity];
            } 
        }
        advance(pIt,1);
    }


    list<list<Package>::iterator> selectedIt; //TEMPORARY - list of iterators just to erase from list
    int weight = currentTruck.getMaxWeight();
    int res = knapsack[currentPackages.size()][currentTruck.getMaxWeight()];
    pIt = currentPackages.end();
    int packagesGain = 0;

    for( int i = currentPackages.size(); i > 0 && res > 0; i--){
        --pIt;
        if ( res == knapsack[i-1][weight])
            continue;
        else {
           if ( (*pIt).getVolume() + currentTruck.getActualVolume() <= currentTruck.getMaxVolume() && (*pIt).getWeight() + currentTruck.getActualWeight() <= currentTruck.getMaxWeight()) {
                currentTruck.addPackage(*pIt);
                selectedIt.push_back(pIt);
                packagesGain += (int)((*pIt).getReward());

                res -= pIt->getReward();
                weight -= pIt->getWeight();
            }
            else 
                break;
        }
    }

    if( (packagesGain- (int)currentTruck.getCost()) >= 0) {
        for(auto it: selectedIt) currentPackages.erase(it); //TEMPORARY - deleteing items from list
        return true;
    }
    else {
        currentTruck.clearPackages();
        return false;
    }

}

bool MailSystem::knapsackVolume(Truck &currentTruck, list<Package> &currentPackages) {

    //table to calculate the reward values
    std::vector<std::vector<int>> knapsack;
    knapsack.resize(currentPackages.size()+1);
    for (unsigned int i = 0; i < currentPackages.size() + 1; i++) {
        knapsack[i].resize(currentTruck.getMaxVolume() + 1);
        knapsack[i][0] = 0;
    }
    for (unsigned int i = 1; i < currentTruck.getMaxVolume() + 1; i++)
        knapsack[0][i] = 0;

    list<Package>::iterator pIt = currentPackages.begin();
    // Computes the maximum value that can be reached varying the number of elements and the capacity
    for (unsigned int n = 1; n <= currentPackages.size(); n++) {
        for (unsigned int capacity = 1; capacity <= currentTruck.getMaxVolume(); capacity++) {
            if ( pIt->getVolume() <= capacity) {
                if ( ( (int)(( *pIt).getVolume()) + knapsack[n-1][capacity - (int)(( *pIt).getVolume())] ) > knapsack[n-1][capacity])
                    knapsack[n][capacity] = pIt->getReward()+knapsack[n-1][capacity - pIt->getVolume()];
                else
                    knapsack[n][capacity] = knapsack[n - 1][capacity];
            } 
        }
        advance(pIt,1);
    }

    list<list<Package>::iterator> selectedIt; //TEMPORARY - list of iterators just to erase from list
    int volume = currentTruck.getMaxVolume();
    int res = knapsack[currentPackages.size()][currentTruck.getMaxVolume()];
    pIt = currentPackages.end();
    int packagesGain = 0;

    for( int i = currentPackages.size(); i > 0 && res > 0; i--){
        --pIt;
        if ( res == knapsack[i-1][volume])
            continue;
        else {
           if ( (*pIt).getVolume() + currentTruck.getActualVolume() <= currentTruck.getMaxVolume() && (*pIt).getWeight() + currentTruck.getActualWeight() <= currentTruck.getMaxWeight()) {
                currentTruck.addPackage(*pIt);
                selectedIt.push_back(pIt);
                packagesGain += (int)((*pIt).getReward());

                res -= pIt->getReward();
                volume -= pIt->getVolume();
            }
            else 
                break;
        }
    }

    if( (packagesGain- (int)currentTruck.getCost()) >= 0) {
        for(auto it: selectedIt) currentPackages.erase(it); //TEMPORARY - deleteing items from list
        return true;
    }
    else {
        currentTruck.clearPackages();
        return false;
    }

}
