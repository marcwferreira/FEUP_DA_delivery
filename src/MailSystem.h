#ifndef MAIL_SYSTEM
#define MAIL_SYSTEM

#include <algorithm>
#include <vector>
#include <ctime>

#include "FileReader.h"
#include "Utils.h"

#define INPUT_FOLDER "../input/"
#define NOT_DELIVERED_FILE "../input/NotDelivered.txt"

class MailSystem
{
private:
    list<Truck> trucks;
    list<Package> packages;

public:
    MailSystem(const string &trucks_filename, const string &packages_filename);
    void case1(const string &filename);
    bool statistics();
    void reset();
    
    //Second case
    void case2(const string &filename);
    bool knapsackWeight(Truck &currentTruck, list<Package> &packages);
    bool knapsackVolume(Truck &currentTruck, list<Package> &packages);

};

#endif /* MAIL_SYSTEM */
