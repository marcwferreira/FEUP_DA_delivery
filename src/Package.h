#ifndef PACKAGE_H
#define PACKAGE_H

#include <iostream>
using namespace std;

class Package
{

private:
    bool express;
    unsigned int volume;
    unsigned int weight;
    unsigned int reward;
    unsigned int duration;

public:
    Package(bool express, unsigned int volume, unsigned int weight, unsigned int reward, unsigned int duration);
    bool isExpress();
    unsigned int getVolume();
    unsigned int getWeight();
    unsigned int getReward();
    unsigned int getDuration();
    bool operator==(const Package &package) const;
    bool operator<(const Package &package) const;
    friend ostream &operator<<(ostream &os, const Package &package);
};

#endif /* PACKAGE_H */