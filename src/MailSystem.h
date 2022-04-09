#ifndef MAIL_SYSTEM
#define MAIL_SYSTEM

#include "FileReader.h"
#include "Utils.h"

#define TRUCKS_FILE "../data/carrinhas50.txt"
#define PACKAGES_FILE "../data/encomendas450.txt"

class MailSystem
{
private:
    list<Truck> trucks;
    list<Package> packages;

public:
    MailSystem();
    void case1();
    bool statistics();
    void reset();
};

#endif /* MAIL_SYSTEM */