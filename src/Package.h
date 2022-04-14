#ifndef PACKAGE_H
#define PACKAGE_H

#include <iostream>
using namespace std;

class Package
{

private:
    int id;
    unsigned int priority;
    unsigned int volume;
    unsigned int weight;
    unsigned int reward;
    unsigned int duration;

public:
    Package(int id, unsigned int priority, unsigned int volume, unsigned int weight, unsigned int reward, unsigned int duration);
    int getId() const;
    unsigned int getPriority() const;
    unsigned int getVolume() const;
    unsigned int getWeight() const;
    unsigned int getReward() const;
    unsigned int getDuration() const;
    void addPriority();
    bool operator==(const Package &package) const;
    bool operator<(const Package &package) const;
    friend ostream &operator<<(ostream &os, const Package &package);
};

#endif /* PACKAGE_H */