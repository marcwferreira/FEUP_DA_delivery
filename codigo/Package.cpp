#include "Package.h"

Package::Package(int id, unsigned int priority, unsigned int volume, unsigned int weight, unsigned int reward, unsigned int duration)
    : id(id), priority(priority), volume(volume), weight(weight), reward(reward), duration(duration) {}

int Package::getId() const
{
    return this->id;
}

void Package::setId(int id)
{
    this->id = id;
}

unsigned int Package::getPriority() const
{
    return this->priority;
}

unsigned int Package::getVolume() const
{
    return this->volume;
}

unsigned int Package::getWeight() const
{
    return this->weight;
}

unsigned int Package::getReward() const
{
    return this->reward;
}

unsigned int Package::getDuration() const
{
    return this->duration;
}

void Package::addPriority()
{
    priority += 1;
}

bool Package::operator==(const Package &package) const
{
    return this->priority == package.priority && this->volume == package.volume && this->weight == package.weight &&
           this->reward == package.reward && this->duration == package.duration && this->id == package.id;
}

bool Package::operator<(const Package &package) const
{
    return this->weight < package.weight;
}

ostream &operator<<(ostream &os, const Package &package)
{
    os << package.id << " " << package.priority << " " << package.volume << " " << package.weight
       << " " << package.reward << " " << package.duration << endl;
    return os;
}