#include "MailSystem.h"

MailSystem::MailSystem(const string &trucks_filename, const string &packages_filename)
{

    this->trucks = FileReader::getTrucks(trucks_filename);
    this->packages = FileReader::getPackages(packages_filename, this->expressoPackages);
}

void MailSystem::writeNotDelivered(const string &filename, const list<Package> &notDelivered, bool express)
{

    fstream notDeliveredFile;
    notDeliveredFile.open(INPUT_FOLDER + filename, ios::out);

    if (!notDeliveredFile.is_open())
    {
        cout << "ERROR: Unable to open the file " << filename << endl;
        return;
    }

    notDeliveredFile << "id express priority volume weight reward duration" << endl;
    int newId = 0;
    for (auto i = notDelivered.begin(); i != notDelivered.end(); i++)
    {
        notDeliveredFile << newId << ' '
                         << express << ' '
                         << (*i).getPriority() + 1 << ' '
                         << (*i).getVolume() << ' '
                         << (*i).getWeight() << ' '
                         << (*i).getReward() << ' '
                         << (*i).getDuration() << endl;
        newId++;
    }
    notDeliveredFile.close();
    notDeliveredFile.close();
}

string MailSystem::fileNameGenerator(int mode)
{
    time_t now = time(0);
    tm *ltm = localtime(&now);
    string outputFileName = "../output/case" + to_string(mode) + "_" + to_string(1900 + ltm->tm_year) + "-" + to_string(1 + ltm->tm_mon);
    outputFileName += "-" + to_string(ltm->tm_mday) + "_" + to_string(ltm->tm_hour) + "-" + to_string(ltm->tm_min) + ".txt";
    return outputFileName;
}

void MailSystem::case1(const string &filename)
{
    string outputFileName = filename == DEFAULT_OUTPUT ? fileNameGenerator(1) : filename;

    fstream file;
    file.open(outputFileName, ios::out);

    if (!file.is_open())
    {
        cout << "ERROR: Unable to open the file " << outputFileName << "." << endl;
        return;
    }

    if (statistics())
    {
        this->trucks.sort(byMaxVolumeDesc);
        this->packages.sort(byVolumeAsc);
    }
    else
    {
        this->trucks.sort(byMaxWeightDesc);
        this->packages.sort(byWeightAsc);
    }

    file << "Information: " << endl
         << "\tTruck: licencePlate volMax weightMax cost" << endl
         << "\tPackage: id priority volume weight reward duration" << endl
         << endl;

    time_t tt;
    struct tm *ti;
    time(&tt);
    ti = localtime(&tt);
    file << asctime(ti) << endl;

    list<Package> notDelivered = {};
    list<Truck>::iterator j = trucks.begin();
    for (list<Package>::iterator i = packages.begin(); i != packages.end(); i++)
    {   
        if ((*j).addPackage(*i));
        else if (j == trucks.end()) {
            (*i).addPriority();
            notDelivered.push_back(*i);
        } else {
            j++;
            i--;
        }
    }

    writeNotDelivered("Case1NotDelivered.txt", notDelivered, false);

    int howManyTrucks = 0, howManyPackages = 0, totalPackages = 0, deliveredPackages = 0;
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
            deliveredPackages += howManyPackages;
            howManyPackages = 0;
        }
    }

    file << "\tNumber of trucks: " << howManyTrucks << endl;
    file << "\tNumber of packages (total, !express): " << totalPackages << endl;
    file << "\tPercentage of delivered packages: " << (deliveredPackages / (float) packages.size()) * 100 << "%";

    file.close();
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

void MailSystem::case2(const string &filename)
{

    string outputFileName = filename == DEFAULT_OUTPUT ? fileNameGenerator(2) : filename;

    this->trucks.sort(byCostAsc); // ascending
    this->packages.sort(byRewardDesc);

    list<Package> normalPackages;
    for (auto elem : packages)
    {
        normalPackages.push_back(elem);
    }
    const int NormalPackageSize = normalPackages.size();

    bool statisticVolume = statistics();
    for (list<Truck>::iterator j = trucks.begin(); j != trucks.end(); j++)
    {
        bool TruckPositive;
        if (!normalPackages.empty())
        {
            j->clearPackages();
            if (statisticVolume)
                TruckPositive = knapsackVolume((*j), normalPackages);
            else
                TruckPositive = knapsackWeight((*j), normalPackages);
            if (!TruckPositive)
                break;
        }
        else
            break;
    }

    fstream outputFile;
    outputFile.open(outputFileName, ios::out);

    if (!outputFile.is_open())
    {
        cout << "ERROR: Unable to open the file " << outputFileName << "." << endl;
        return;
    }

    int money = 0, usedTrucks = 0;
    for (list<Truck>::iterator j = trucks.begin(); j != trucks.end(); j++)
    {
        if (j->getEmpty())
            continue;
        int moneyTemp = 0;

        outputFile << "Truck lincense plate: " << j->getLicencePlate() << endl;
        outputFile << "Total weight capacity: " << j->getMaxWeight() << " Filled weight capacity: " << j->getActualWeight() << endl;
        outputFile << "Total volume capacity: " << j->getMaxVolume() << " Filled volume capacity: " << j->getActualVolume() << endl;
        if (j->getPackages().empty())
            continue;
        moneyTemp -= j->getCost();
        outputFile << "Cost of truck delivery: " << j->getCost() << endl;
        for (auto elem : j->getPackages())
        {
            moneyTemp += elem.getReward();
            outputFile << "Id: " << elem.getId()
                       << " Profit before shipping: " << elem.getReward()
                       << " Weight: " << elem.getWeight()
                       << " Volume: " << elem.getVolume() << endl;
        }
        outputFile << "Profit from truck: " << moneyTemp << endl
                   << endl;
        money += moneyTemp;
        usedTrucks++;
    }

    float efficiency = (((float)NormalPackageSize - (float)normalPackages.size()) / ((float)NormalPackageSize)) * 100;

    outputFile << endl
               << "Total profit for the day: " << money << endl;
    outputFile << "Number of used Trucks: " << usedTrucks << endl;
    outputFile << "Number of delivered packages: " << packages.size() - normalPackages.size() << endl
               << "Number of packages in total: " << NormalPackageSize << endl;
    outputFile << "Percentage of delivered packages: " << efficiency << "%";

    outputFile.close();

    writeNotDelivered("Case2NotDelivered.txt", normalPackages, false);

}

bool MailSystem::knapsackWeight(Truck &currentTruck, list<Package> &currentPackages)
{

    // table to calculate the reward values
    std::vector<std::vector<int>> knapsack;
    knapsack.resize(currentPackages.size() + 1);
    for (unsigned int i = 0; i < currentPackages.size() + 1; i++)
    {
        knapsack[i].resize(currentTruck.getMaxWeight() + 1);
        knapsack[i][0] = 0;
    }
    for (unsigned int i = 1; i < currentTruck.getMaxWeight() + 1; i++)
        knapsack[0][i] = 0;

    list<Package>::iterator pIt = currentPackages.begin();
    // Computes the maximum value that can be reached varying the number of elements and the capacity
    for (unsigned int n = 1; n <= currentPackages.size(); n++)
    {
        for (unsigned int capacity = 1; capacity <= currentTruck.getMaxWeight(); capacity++)
        {
            if (pIt->getWeight() <= capacity)
            {
                if (((int)((*pIt).getWeight()) + knapsack[n - 1][capacity - (int)((*pIt).getWeight())]) > knapsack[n - 1][capacity])
                    knapsack[n][capacity] = pIt->getReward() + knapsack[n - 1][capacity - pIt->getWeight()];
                else
                    knapsack[n][capacity] = knapsack[n - 1][capacity];
            }
        }
        advance(pIt, 1);
    }

    list<list<Package>::iterator> selectedIt; // TEMPORARY - list of iterators just to erase from list
    int weight = currentTruck.getMaxWeight();
    int res = knapsack[currentPackages.size()][currentTruck.getMaxWeight()];
    pIt = currentPackages.end();
    int packagesGain = 0;

    for (int i = currentPackages.size(); i > 0 && res > 0; i--)
    {
        --pIt;
        if (res == knapsack[i - 1][weight])
            continue;
        else
        {
            if ((*pIt).getVolume() + currentTruck.getActualVolume() <= currentTruck.getMaxVolume() && (*pIt).getWeight() + currentTruck.getActualWeight() <= currentTruck.getMaxWeight())
            {
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

    if ((packagesGain - (int)currentTruck.getCost()) >= 0)
    {
        for (auto it : selectedIt)
            currentPackages.erase(it); // TEMPORARY - deleteing items from list
        return true;
    }
    else
    {
        currentTruck.clearPackages();
        return false;
    }
}

bool MailSystem::knapsackVolume(Truck &currentTruck, list<Package> &currentPackages)
{

    // table to calculate the reward values
    std::vector<std::vector<int>> knapsack;
    knapsack.resize(currentPackages.size() + 1);
    for (unsigned int i = 0; i < currentPackages.size() + 1; i++)
    {
        knapsack[i].resize(currentTruck.getMaxVolume() + 1);
        knapsack[i][0] = 0;
    }
    for (unsigned int i = 1; i < currentTruck.getMaxVolume() + 1; i++)
        knapsack[0][i] = 0;

    list<Package>::iterator pIt = currentPackages.begin();
    // Computes the maximum value that can be reached varying the number of elements and the capacity
    for (unsigned int n = 1; n <= currentPackages.size(); n++)
    {
        for (unsigned int capacity = 1; capacity <= currentTruck.getMaxVolume(); capacity++)
        {
            if (pIt->getVolume() <= capacity)
            {
                if (((int)((*pIt).getVolume()) + knapsack[n - 1][capacity - (int)((*pIt).getVolume())]) > knapsack[n - 1][capacity])
                    knapsack[n][capacity] = pIt->getReward() + knapsack[n - 1][capacity - pIt->getVolume()];
                else
                    knapsack[n][capacity] = knapsack[n - 1][capacity];
            }
        }
        advance(pIt, 1);
    }

    list<list<Package>::iterator> selectedIt; // TEMPORARY - list of iterators just to erase from list
    int volume = currentTruck.getMaxVolume();
    int res = knapsack[currentPackages.size()][currentTruck.getMaxVolume()];
    pIt = currentPackages.end();
    int packagesGain = 0;

    for (int i = currentPackages.size(); i > 0 && res > 0; i--)
    {
        --pIt;
        if (res == knapsack[i - 1][volume])
            continue;
        else
        {
            if ((*pIt).getVolume() + currentTruck.getActualVolume() <= currentTruck.getMaxVolume() && (*pIt).getWeight() + currentTruck.getActualWeight() <= currentTruck.getMaxWeight())
            {
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

    if ((packagesGain - (int)currentTruck.getCost()) >= 0)
    {
        for (auto it : selectedIt)
            currentPackages.erase(it); // TEMPORARY - deleteing items from list
        return true;
    }
    else
    {
        currentTruck.clearPackages();
        return false;
    }
}

void MailSystem::case3(const string &filename, int numberOfSeconds)
{

    string outputFileName = filename == DEFAULT_OUTPUT ? fileNameGenerator(3) : filename;

    fstream file;
    file.open(outputFileName, ios::out);
    if (!file.is_open())
    {
        cout << "ERROR: Unable to open the file " << outputFileName << "." << endl;
        return;
    }

    if (expressoPackages.empty())
    {
        file.close();
        return;
    }

    file << "Information: " << endl
         << "\tPackage: id priority volume weight reward duration" << endl
         << endl;

    this->expressoPackages.sort(byDurationAsc);

    int timeLeft = numberOfSeconds;
    unsigned int averageTime = 0;
    unsigned int numberOfPackagesDelivered = 0;
    list<Package> notDelivered = {};
    for (auto p : expressoPackages)
    {
        if (timeLeft - static_cast<int>(p.getDuration()) >= 0)
        {
            file << "\tPackage " << p;
            timeLeft -= p.getDuration();
            averageTime += p.getDuration();
            numberOfPackagesDelivered++;
        }
        else
        {
            notDelivered.push_back(p);
        }
    }

    writeNotDelivered("Case3NotDelivered.txt", notDelivered, true);

    file << endl;
    if (numberOfPackagesDelivered > 0)
    {
        file << "Average time to make a delivery: " << (averageTime / numberOfPackagesDelivered) << " seconds." << endl;
    }
    else
    {
        file << "Average time to make a delivery: 0 seconds." << endl;
    }

    file << "Number of packages to be delivered: " << expressoPackages.size() << endl;
    file << "Number of packages delivered: " << numberOfPackagesDelivered << endl;
    file << "Percentage of delivered packages: " << (static_cast<double>(numberOfPackagesDelivered) / static_cast<double>(expressoPackages.size())) * 100 << "%" << endl;
    file.close();
}