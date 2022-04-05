#ifndef TRUCK_H
#define TRUCK_H

#include <iostream>
#include <string>
using namespace std;

//! @brief Truck :D
class Truck
{

private:
    string licencePlate;
    unsigned int maxVolume;
    unsigned int maxWeight;
    unsigned int cost;

public:
    Truck(string licencePlate, unsigned int maxVolume, unsigned int maxWeight, unsigned int cost);
    string getLicencePlate() const;
    unsigned int getMaxVolume() const;
    unsigned int getMaxWeight() const;
    unsigned int getCost() const;
    bool operator==(const Truck &truck) const;
    bool operator<(const Truck &truck) const;
    friend ostream &operator<<(ostream &os, const Truck &truck);
};

#endif /* TRUCK_H */