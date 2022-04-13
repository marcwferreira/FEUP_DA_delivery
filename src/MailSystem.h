#ifndef MAIL_SYSTEM
#define MAIL_SYSTEM

#include <algorithm>
#include <vector>

#include "FileReader.h"
#include "Utils.h"

#define INPUT_FOLDER "../input/"

class MailSystem
{
private:
    list<Truck> trucks;
    list<Package> packages;

public:
    MailSystem(const string &trucks_filename, const string &packages_filename);
    void setPackages(const string &packages_filename);
    void case1(const string &filename, const unsigned int day);
    bool statistics();
    void reset();
    
    //Second case
    void case2();
    bool knapsackWeight(Truck &currentTruck, list<Package> &packages);
    bool knapsackVolume(Truck &currentTruck, list<Package> &packages);

};

#endif /* MAIL_SYSTEM */
