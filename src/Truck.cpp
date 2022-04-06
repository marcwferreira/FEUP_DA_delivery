#include "Truck.h"

Truck::Truck(string licencePlate, unsigned int maxVolume, unsigned int maxWeight, unsigned int cost)
    : licencePlate(licencePlate), maxVolume(maxVolume), maxWeight(maxWeight), cost(cost) {}

string Truck::getLicencePlate() const
{
    return this->licencePlate;
}

unsigned int Truck::getMaxVolume() const
{
    return this->maxVolume;
}

unsigned int Truck::getMaxWeight() const
{
    return this->maxWeight;
}

unsigned int Truck::getCost() const
{
    return this->cost;
}

bool Truck::operator==(const Truck &truck) const
{
    return this->licencePlate == truck.licencePlate && this->maxWeight == truck.maxWeight &&
           this->maxVolume == truck.maxVolume && this->cost == truck.cost;
}

bool Truck::operator<(const Truck &truck) const
{
    return this->cost < truck.cost;
}

ostream &operator<<(ostream &os, const Truck &truck)
{
    os << truck.licencePlate << " " << truck.maxVolume << " " << truck.maxWeight << " " << truck.cost << endl;
    return os;
}