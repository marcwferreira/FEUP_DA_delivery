#include "MailSystem.h"

MailSystem::MailSystem(const string &trucks_filename, const string &packages_filename)
{
    this->trucks = FileReader::getTrucks(trucks_filename);
    this->packages = FileReader::getPackages(packages_filename);
}

bool MailSystem::case1(const string &filename, const unsigned int day)
{
    fstream file;
    file.open(filename, ios::ate);
    if (!file.is_open())
    {
        cout << "ERROR: Unable to open file";
        return false;
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
                    packages.erase(i--);
                    break;
                }
            }
            if (flagNotSent)
            {
                (*i).addPriority();
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
    return true;
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