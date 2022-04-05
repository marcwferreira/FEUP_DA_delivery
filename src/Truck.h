#ifndef TRUCK_H
#define TRUCK_H

#include <iostream>
using namespace std;

//! @brief Truck :D
class Truck
{

private:
    unsigned int maxVolume;
    unsigned int maxWeight;
    unsigned int cost;

public:
    Truck(unsigned int maxVolume, unsigned int maxWeight, unsigned int cost);
    unsigned int getMaxVolume();
    unsigned int getMaxWeight();
    unsigned int getCost();
    bool operator==(const Truck &truck) const;
    bool operator<(const Truck &truck) const;
    friend ostream &operator<<(ostream &os, const Truck &truck);
};

#endif /* TRUCK_H */