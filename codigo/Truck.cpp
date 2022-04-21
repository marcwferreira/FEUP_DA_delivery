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

unsigned int Truck::getActualVolume() const
{
    return this->actualVolume;
}

unsigned int Truck::getActualWeight() const
{
    return this->actualWeight;
}

unsigned int Truck::getCost() const
{
    return this->cost;
}

list<Package> Truck::getPackages() const
{
    return this->listOfPackages;
}

void Truck::clearPackages()
{
    this->listOfPackages.clear();
    this->actualVolume = 0;
    this->actualWeight = 0;
}

bool Truck::addPackage(Package p)
{
    if (p.getVolume() + this->actualVolume <= this->maxVolume && p.getWeight() + this->actualWeight <= this->maxWeight)
    {
        this->actualWeight += p.getWeight();
        this->actualVolume += p.getVolume();
        this->listOfPackages.push_back(p);
        return true;
    }
    return false;
}

bool Truck::getEmpty() const {
    return !(listOfPackages.size() > 0);
};

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
