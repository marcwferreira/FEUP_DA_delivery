#include "Truck.h"

Truck::Truck(unsigned int maxVolume, unsigned int maxWeight, unsigned int cost)
    : maxVolume(maxVolume), maxWeight(maxWeight), cost(cost) {}

unsigned int Truck::getMaxVolume()
{
    return this->maxVolume;
}

unsigned int Truck::getMaxWeight()
{
    return this->maxWeight;
}

unsigned int Truck::getCost()
{
    return this->cost;
}

bool Truck::operator==(const Truck &truck) const
{
    return this->maxWeight == truck.maxWeight && this->maxVolume == truck.maxVolume && this->cost == truck.cost;
}

bool Truck::operator<(const Truck &truck) const
{
    return this->cost < truck.cost;
}

ostream &operator<<(ostream &os, const Truck &truck)
{
    os << truck.maxVolume << " " << truck.maxWeight << " " << truck.cost << endl;
    return os;
}