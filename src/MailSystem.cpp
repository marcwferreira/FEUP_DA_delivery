#include "MailSystem.h"

MailSystem::MailSystem()
{
    this->trucks = FileReader::getTrucks(TRUCKS_FILE);
    this->packages = FileReader::getPackages(PACKAGES_FILE);
}

void MailSystem::scene1()
{
    sortTrucks();
    sortPackages();

    for (auto t : trucks)
    {
        cout << t;
    }
}

/** Auxiliar fuctions **/
void MailSystem::sortTrucks()
{
    sort(trucks.begin(), trucks.end());
}

void MailSystem::sortPackages()
{
    sort(packages.begin(), packages.end());
}
