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

/**
 * This class represents a Mail System
 * @param trucks A list containing all trucks of the system
 * @param packages  A list containing all non express packages of the system
 * @param expressoPackages A list containing all express packages of the system
 */
class MailSystem
{
private:
    list<Truck> trucks;
    list<Package> packages;
    list<Package> expressoPackages;

public:

    /**
    * @brief Constructor of the class
    *
    * @param trucks_filename file containing Trucks attributes
    * @param packages_filename file containing Packages attributes
    */
    MailSystem(const string &trucks_filename, const string &packages_filename);
    /**
    * @brief This function writes the data of undelivered packages in a file
    *
    * @param filename file to be written
    * @param notDelivered a list containing Packages objects that will be written to the file
    * @param express indicates if a list contains express packages
    */
    void writeNotDelivered(const string &filename, const list<Package> &notDelivered, bool express);
    /**
    * @brief This function calculates the best way of organizing the packages into the trucks taking into account the number of packages per truck
    * if all packages fit in the trucks, or the number of trucks if all packages can be delivered
    *
    * @param filename file to be written
    */
    void case1(const string &filename);
    /**
    * @brief This function calculates the maximum absolute deviation (volume, weight) of all packages
    *
    * @return if the maximum absolute deviation of weight is less than or equal the maximum absolute deviation of volume
    */
    bool statistics();
    /**
    * @brief This function clears all packages in trucks
    */
    void reset();
    /**
    * @brief This function calculates the maximum absolute deviation (volume, weight) of packages
    *
    * @param mode The mode of the problem (1, 2 or 3)
    * @return the new file name
    */
    string fileNameGenerator(int mode);
    /**
     * @brief This function calculates the best way of organizing the packages into the trucks taking into account the profit
     * for the deliveries. Even though the function has no return it generates a file with the information of the trucks, which packages goes into
     * which trucks, the total profit. the profit per truck, and etc.
     * 
     * @param filename Name of the file to save the output
     */
    void case2(const string &filename);
    /**
     * @brief This function uses the Knapsack algorithm to determine the best way of allocating packages in to a truck, using the weight as measure to
     * what is put into the truck and the profit of the package as reward for the algorithm
     * 
     * @param currentTruck The current truck tried to be filled with packages
     * @param packages The list of packages still not allocated to any truck
     * @return true if the truck generated profit
     * @return false if truck genereated no profit or ended with negative balance
     */
    bool knapsackWeight(Truck &currentTruck, list<Package> &packages);
    /**
     * @brief This function used the Knapsack algorithm to determine the best way of allocating packages in to a truck, using the volume as measure to
     * what is put into the truck and the profit of the package as reward for the algorithm
     * 
     * @param currentTruck The current truck tried to be filled with packages
     * @param packages The list of packages still not allocated to any truck
     * @return true if the truck generated profit
     * @return false if truck genereated no profit or ended with negative balance
     */
    bool knapsackVolume(Truck &currentTruck, list<Package> &packages);
    /**
     * @brief This function tried to allocate the maximum amount of packages flagged for express delivery into the company truck
     * 
     * @param filename Name of the file to save the output
     * @param numberOfSeconds Time available to make all deliveries in a day (for a function call)
     */
    void case3(const string &filename, int numberOfSeconds);
};

#endif /* MAIL_SYSTEM */
