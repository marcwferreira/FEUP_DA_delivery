/**
 * @file Truck
 * @brief This contains the implementation and organization of a truck, it stores the necessary
 * information about it and the functions to access the information
 *
 * @author Fábio Araújo de Sá, Francisco João Gonçalves Calado Araújo, Marcos William Ferreira Pinto
 *
 * @date 04/02/2022
 */

#ifndef TRUCK_H
#define TRUCK_H

#include <iostream>
#include <string>
#include <list>
#include "Package.h"
using namespace std;

/**
 * This class represents a truck (of delivery vehicle)
 * @param maxVolume The maximum amount possible to load in the vehicle
 * @param maxWeight The maximum amount of wight supported by the vehicle
 * @param actualVolume Actual volume filled in the vehicle
 * @param actualWeight Actual weight loaded into the vehicle
 * @param cost The price of a delivery (idependent of the actual load)
 * @param listOfPackages List of packages currently loaded into the
 */
class Truck
{

private:
    string licencePlate;
    unsigned int maxVolume;
    unsigned int maxWeight;
    unsigned int actualVolume = 0;
    unsigned int actualWeight = 0;
    unsigned int cost;
    list<Package> listOfPackages = {};

public:
    Truck(string licencePlate, unsigned int maxVolume, unsigned int maxWeight, unsigned int cost);
    string getLicencePlate() const;
    unsigned int getMaxVolume() const;
    unsigned int getMaxWeight() const;
    unsigned int getActualVolume() const;
    unsigned int getActualWeight() const;
    unsigned int getCost() const;
    list<Package> getPackages() const;
    bool getEmpty() const;
    void clearPackages();
    bool addPackage(Package p);
    bool operator==(const Truck &truck) const;
    bool operator<(const Truck &truck) const;
    friend ostream &operator<<(ostream &os, const Truck &truck);
};

#endif /* TRUCK_H */
