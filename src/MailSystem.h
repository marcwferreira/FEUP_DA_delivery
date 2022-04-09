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
    MailSystem(const string &trucks_filename = TRUCKS_FILE, const string &packages_filename = PACKAGES_FILE);
    bool case1(const string &filename, const unsigned int day);
    bool statistics();
    void reset();
};

#endif /* MAIL_SYSTEM */