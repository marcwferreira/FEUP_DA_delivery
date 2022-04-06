#ifndef TRUCK_H
#define TRUCK_H

#include <iostream>
#include <string>
#include <list>
#include "Package.h"
using namespace std;

//! @brief Truck :D
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
    bool addPackage(Package p);
    bool operator==(const Truck &truck) const;
    bool operator<(const Truck &truck) const;
    friend ostream &operator<<(ostream &os, const Truck &truck);
};

#endif /* TRUCK_H */