/**
 * @file Truck
 * @brief This contains the implementation and organization of a truck, it stores the necessary
 * information about it and the functions to access the information
 *
 * @author Fábio Araújo de Sá, Francisco João Gonçalves Calado Araújo, Marcos William Ferreira Pinto
 *
 * @date 04/02/2022
 */

#ifndef TRUCK_H
#define TRUCK_H

#include <iostream>
#include <string>
#include <list>
#include "Package.h"
using namespace std;

/**
 * This class represents a truck (of delivery vehicle)
 * @param maxVolume The maximum amount possible to load in the vehicle
 * @param maxWeight The maximum amount of wight supported by the vehicle
 * @param actualVolume Actual volume filled in the vehicle
 * @param actualWeight Actual weight loaded into the vehicle
 * @param cost The price of a delivery (idependent of the actual load)
 * @param listOfPackages List of packages currently loaded into the
 */
class Truck
{

private:
    string licencePlate;
    unsigned int maxVolume;
    unsigned int maxWeight;
    unsigned int actualVolume = 0;
    unsigned int actualWeight = 0;
    unsigned int cost;
    list<Package> listOfPackages = {};

public:
    /**
    * @brief Constructor of the class
    *
    * @param licensePlate Identifier for the truck - license plate of it used for this purpose
    * @param maxVolume The maximum size able to be loaded into the truck
    * @param maxWeight the maximum weight the truck supports as a load
    * @param cost Cost of using the truck for a delivery
    */
    Truck(string licencePlate, unsigned int maxVolume, unsigned int maxWeight, unsigned int cost);
    /** 
    * @brief This function gets the license plate from the truck
    *
    * @return It returns a string of the license plate
    */
    string getLicencePlate() const;
    /** 
    * @brief This function gets maximum volume the truck is able to carry
    *
    * @return It returns an unsigned int with the volume
    */
    unsigned int getMaxVolume() const;
    /** 
    * @brief This function gets the maximum weight the truck is able to carry
    * 
    * @return It returns an unsigned int with the maximum weight
    */
    unsigned int getMaxWeight() const;
    /** 
    * @brief This function gets the volume that is loaded into the truck at the moment of its call
    * 
    * @return It returns an unsigned int with the actual volume
    */
    unsigned int getActualVolume() const;
    /** 
    * @brief This function gets the weight that is loaded into the truck at the moment of its call
    * 
    * @return It returns an unsigned int with the loaded weight into the truck
    */
    unsigned int getActualWeight() const;
    /** 
    * @brief This function gets the cost of the truck
    * 
    * @return It returns an unsigned int with the cost of current truck
    */
    unsigned int getCost() const;
    /** 
    * @brief This function gets the list os packages that are loaded into the truck at the moment os its call
    * 
    * @return It returns a list of packages with all the packages loaded into the truck
    */
    list<Package> getPackages() const;
    /** 
    * @brief This function indicates whether the truck is empty
    * 
    * @return It returns a boolean which indicates if the truck is empty
    */
    bool getEmpty() const;
    /** 
    * @brief This function clears the packages loaded into the truck, making it empty. Also updates the current volume and weight 
    * left to the maximum amount of both
    */
    void clearPackages();
    /** 
     * @brief This function loads a prackage into the truck and update the current load of the truck
     * 
     * @param p package to be added into the truck
     * @return true if adding the package to the truck was successful
     * @return false if otherwise
    */
    bool addPackage(Package p);
    /** 
    * @brief This function compares two objects of the class Truck
    * 
    * @param truck another object that will be compared
    * @return if the current object is equal than object passed by reference
    */
    bool operator==(const Truck &truck) const;
    /** 
    * @brief This function compares two objects of the class Truck
    * 
    * @param truck another object that will be compared
    * @return if the current object is less than object passed by reference
    */
    bool operator<(const Truck &truck) const;
    /** 
    * @brief This function returns all characteristics of the Truck being manipulated
    * 
    * @param os ostream object, passed by reference
    * @param truck truck object, passed by reference
    * @return ostream object
    */
    friend ostream &operator<<(ostream &os, const Truck &truck);
};

#endif /* TRUCK_H */
