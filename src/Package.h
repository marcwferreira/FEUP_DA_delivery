/**
 * @file Package
 * @brief This contains the implementation and organization of a package, it stores the necessary
 * information about it and the functions to access the information
 *
 * @author Fábio Araújo de Sá, Francisco João Gonçalves Calado Araújo, Marcos William Ferreira Pinto
 *
 * @date 04/02/2022
 */

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
    void setId(int id);
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