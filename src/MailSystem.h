/**
 * @file MailSystem
 * @brief This contains the storage of the trucks and packages, also the implementation for case 1 (put the packages in the least amount of trucks possible),
 * case2 (maximize the profit during delivery), and case 3 (deliver the maximum amount of express delivery)
 *
 * @author Fábio Araújo de Sá, Francisco João Gonçalves Calado Araújo, Marcos William Ferreira Pinto
 *
 * @date 04/02/2022
 */

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
#define WORK_TIME 28800

class MailSystem
{
private:
    list<Truck> trucks;
    list<Package> packages;
    list<Package> expressoPackages;

public:
    MailSystem(const string &trucks_filename, const string &packages_filename);
    void writeNotDelivered(const string &filename, const list<Package> &notDelivered, bool express);
    // First case
    void case1(const string &filename);
    bool statistics();
    void reset();
    string fileNameGenerator(int mode);
    // Second case
    void case2(const string &filename);
    bool knapsackWeight(Truck &currentTruck, list<Package> &packages);
    bool knapsackVolume(Truck &currentTruck, list<Package> &packages);
    // Third case
    void case3(const string &filename, int numberOfSeconds);
};

#endif /* MAIL_SYSTEM */
