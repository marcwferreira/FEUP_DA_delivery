#include "FileReader.h"

list<Truck> FileReader::getTrucks(string filename)
{
    list<Truck> trucks = {};
    string licencePlate, maxVolume, maxWeight, cost;

    fstream file;
    file.open(filename, ios::in);
    if (!file)
    {
        cout << "O ficheiro " << filename << " nao existe!" << endl;
        return trucks;
    }
    if (file.is_open())
    {
        file.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        while (!file.eof())
        {
            getline(file, licencePlate, ' ');
            getline(file, maxVolume, ' ');
            getline(file, maxWeight, ' ');
            getline(file, cost);

            trucks.push_back(Truck(licencePlate, stoi(maxVolume), stoi(maxWeight), stoi(cost)));
        }
        file.close();
    }
    return trucks;
}

list<Package> FileReader::getPackages(string filename)
{
    list<Package> packages = {};
    string expresso, volume, peso, recompensa, duracao;

    fstream file;
    file.open(filename, std::ios::in);
    if (!file)
    {
        cout << "O ficheiro " << filename << " nao existe!" << endl;
        return packages;
    }
    if (file.is_open())
    {
        file.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        while (!file.eof())
        {
            getline(file, expresso, ' ');
            if (expresso.empty())
                break;
            getline(file, volume, ' ');
            getline(file, peso, ' ');
            getline(file, recompensa, ' ');
            getline(file, duracao);

            packages.push_back(Package(expresso == "1", stoi(volume), stoi(peso), stoi(recompensa), stoi(duracao)));
        }
        file.close();
    }
    return packages;
}