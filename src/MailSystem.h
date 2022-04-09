#ifndef MAIL_SYSTEM
#define MAIL_SYSTEM

#include "FileReader.h"
#include "Utils.h"

#define TRUCKS_FILE "../data/carrinhas50.txt"
#define PACKAGES_FILE "../data/encomendas3000.txt"

class MailSystem
{
private:
    list<Truck> trucks;
    list<Package> packages;

public:
    MailSystem();
    void statistics();
    void case1_ByVolume(); // volume
    void reset();
    void case1_ByWeight(); // peso
};

#endif /* MAIL_SYSTEM */