#ifndef MAIL_SYSTEM
#define MAIL_SYSTEM

#include "FileReader.h"
#include "Truck.h"

#define TRUCKS_FILE "../data/carrinhas.txt"
#define PACKAGES_FILE "../data/encomendas.txt"

class MailSystem
{
private:
    list<Truck> trucks;
    list<Package> packages;

public:
    MailSystem();
    void scene1();
    void printResults();
};

#endif /* MAIL_SYSTEM */