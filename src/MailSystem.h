#ifndef MAIL_SYSTEM
#define MAIL_SYSTEM

#include <algorithm>
#include <vector>
#include <ctime>
#include <sstream>

#include "FileReader.h"
#include "Utils.h"

#define INPUT_FOLDER "../input/"
#define OUTPUT_FOLDER "../output/"
#define DEFAULT_OUTPUT "../output/output.txt"

class MailSystem
{
private:
    list<Truck> trucks;
    list<Package> packages;
    list<Package> expressoPackages = {};

public:
    MailSystem(const string &trucks_filename, const string &packages_filename);
    //First case
    void case1(const string &filename);
    bool statistics();
    void reset();
    void writeNotDelivered(const string &filename, const list<Package> &notDelivered);
    string fileNameGenerator(int mode);
    //Second case
    void case2(const string &filename);
    bool knapsackWeight(Truck &currentTruck, list<Package> &packages);
    bool knapsackVolume(Truck &currentTruck, list<Package> &packages);
    //Third case
    void case3(const string &filename);
};

#endif /* MAIL_SYSTEM */
