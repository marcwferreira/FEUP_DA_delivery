#include "FileReader.h"

list<Truck> FileReader::getTrucks(const string &filename)
{
    list<Truck> trucks = {};
    string licencePlate, maxVolume, maxWeight, cost;

    fstream file;
    file.open(filename, ios::in);
    if (!file)
    {
        cerr << "Error: file " << filename << " not found" << endl;
        return trucks;
    }
    if (file.is_open())
    {
        file.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        while (!file.eof())
        {
            getline(file, licencePlate, ' ');
            if (licencePlate.empty())
                break;
            getline(file, maxVolume, ' ');
            getline(file, maxWeight, ' ');
            getline(file, cost);

            trucks.push_back(Truck(licencePlate, stoi(maxVolume), stoi(maxWeight), stoi(cost)));
        }
        file.close();
    }
    return trucks;
}

list<Package> FileReader::getPackages(const string &filename, list<Package> &expressoPackage)
{
    list<Package> packages = {};
    string id, expresso, priority, volume, peso, recompensa, duracao;

    fstream file;
    file.open(filename, std::ios::in);
    if (!file)
    {
        cerr << "Error: file " << filename << " not found" << endl;
        return packages;
    }
    if (file.is_open())
    {
        file.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        while (!file.eof())
        {
            getline(file, id, ' ');
            if (id.empty())
                break;
            getline(file, expresso, ' ');
            getline(file, priority, ' ');
            getline(file, volume, ' ');
            getline(file, peso, ' ');
            getline(file, recompensa, ' ');
            getline(file, duracao);
            if (expresso[0] == '1')
            {
                expressoPackage.push_back(Package(stoi(id), stoi(priority), stoi(volume), stoi(peso), stoi(recompensa), stoi(duracao)));
            }
            else
            {
                packages.push_back(Package(stoi(id), stoi(priority), stoi(volume), stoi(peso), stoi(recompensa), stoi(duracao)));
            }
        }
        file.close();
    }
    return packages;
}