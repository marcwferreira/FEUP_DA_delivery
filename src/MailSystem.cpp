#include "MailSystem.h"

MailSystem::MailSystem()
{
    this->trucks = FileReader::getTrucks(TRUCKS_FILE);
    this->packages = FileReader::getPackages(PACKAGES_FILE);
}

void MailSystem::scene1()
{
    trucks.sort([](const Truck &a, const Truck &b)
                { return a.getMaxVolume() < b.getMaxVolume(); });
    packages.sort([](const Package &a, const Package &b)
                  { return a.getVolume() < b.getVolume(); });

    for (auto t : trucks)
    {
        for (auto it = packages.begin(); it != packages.end(); ++it)
        {
            if ((*it).getVolume() + t.getActualVolume() <= t.getMaxVolume() && (*it).getWeight() + t.getActualWeight() <= t.getMaxWeight())
            {
                t.addPackage(*it);
                packages.erase(it);
            }
        }
    }
}

void MailSystem::printResults()
{
    for (auto t : trucks)
    {
        cout << "Truck: " << t.getLicencePlate();
        for (auto p : t.getPackages())
        {
            cout << "\tPackage: " << p;
        }
    }
}