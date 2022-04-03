#include "Package.h"

Package::Package(bool express, unsigned int volume, unsigned int weight, unsigned int reward, unsigned int duration)
    : express(express), volume(volume), weight(weight), reward(reward), duration(duration) {}

bool Package::isExpress() const
{
    return this->express;
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

bool Package::operator==(const Package &package) const
{
    return this->express == package.express && this->volume == package.volume && this->weight == package.weight &&
           this->reward == package.reward && this->duration == package.duration;
}

bool Package::operator<(const Package &package) const
{
    return this->weight < package.weight;
}

ostream &operator<<(ostream &os, const Package &package)
{
    os << package.express << " " << package.volume << " " << package.weight << " " << package.reward << " " << package.duration << endl;
    return os;
}