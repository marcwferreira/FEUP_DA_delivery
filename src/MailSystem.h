#ifndef MAIL_SYSTEM
#define MAIL_SYSTEM

#include "FileReader.h"
#include "Utils.h"

class MailSystem
{
private:
    list<Truck> trucks;
    list<Package> packages;
    string packages_filename;

public:
    MailSystem(const string &trucks_filename, const string &packages_filename);
    void setPackages(const string &packages_filename);
    bool case1(const string &filename, const unsigned int day);
    bool statistics();
    void reset();
};

#endif /* MAIL_SYSTEM */