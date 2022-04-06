#ifndef MAIL_SYSTEM
#define MAIL_SYSTEM

#include "FileReader.h"
#include "Truck.h"
#include "Package.h"

#define TRUCKS_FILE "../data/carrinhas.txt"
#define PACKAGES_FILE "../data/encomendas.txt"

class MailSystem
{
private:
    vector<Truck> trucks;
    vector<Package> packages;
    void sortTrucks();
    void sortPackages();

public:
    MailSystem();
    void scene1();
};

#endif /* MAIL_SYSTEM */