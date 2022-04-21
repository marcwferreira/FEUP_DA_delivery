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

/**
 * This class represents a package
 * @param id The id of the package
 * @param priority The priority of the package
 * @param volume The volume of the package
 * @param weight The weight of the package
 * @param reward The reward of the package
 * @param duration The duration of the package delivery
 */
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
    /**
    * @brief Constructor of the class
    *
    * @param id Identifier of the package
    * @param priority Int representing the priority to be delivered
    * @param volume Volume of the package
    * @param weight Weight of the package
    * @param reward Profit obtained from the package
    * @param duration Time to deliver the package
    */
    Package(int id, unsigned int priority, unsigned int volume, unsigned int weight, unsigned int reward, unsigned int duration);
    /** 
    * @brief This function gets the id (identifier number) of a package
    *
    * @return It returns an int with the id for the package
    */
    int getId() const;
    /** 
    * @brief This function can be used to change the id of a package
    *
    * @param id A int wiht the new id number for the package
    */
    void setId(int id);
    /**
     * @brief This function gets the Priority of the package as an int (the highter the value
     * the more important is the package)
     * 
     * @return unsigned int representing the prioroty
     */
    unsigned int getPriority() const;
    /**
     * @brief This function gets the Volume of the package
     * 
     * @return unsigned int representing the volume of the package
     */
    unsigned int getVolume() const;
    /**
     * @brief This function gets the Weight of the package
     * 
     * @return unsigned int representing the weight of the object
     */
    unsigned int getWeight() const;
    /**
     * @brief This function gets the Reward (profit) of the package
     * 
     * @return unsigned int representing the profit from it
     */
    unsigned int getReward() const;
    /**
     * @brief This function gets the time needed to deliver the package (time to deliver + time
     * to return to warehouse)
     * 
     * @return unsigned int representing the amount of time to deliver the package
     */
    unsigned int getDuration() const;
    /**
     * @brief This functions makes the packages' priority level higher by one
     * 
     */
    void addPriority();
    /** 
    * @brief This function compares two objects of the class Package
    *
    * @param package another object that will be compared
    * @return if the current object is equal than object passed by reference
    */
    bool operator==(const Package &package) const;
    /** 
    * @brief This function compares two objects of the class Package
    *
    * @param package another object that will be compared
    * @return if the current object is less than object passed by reference
    */
    bool operator<(const Package &package) const;
    /** 
    * @brief This function returns all characteristics of the Package being manipulated
    *
    * @param os ostream object, passed by reference
    * @param package package object, passed by reference
    * @return ostream object
    */
    friend ostream &operator<<(ostream &os, const Package &package);
};

#endif /* PACKAGE_H */