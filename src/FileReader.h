/**
 * @file FileReader
 * @brief This contains the implementation of the reader for the user files (the file containing the trucks and the packages).
 *
 * @author Fábio Araújo de Sá, Francisco João Gonçalves Calado Araújo, Marcos William Ferreira Pinto
 *
 * @date 04/02/2022
 */

#ifndef FILES_READER
#define FILES_READER

#include <iostream>
#include <fstream>
#include <list>
#include <string>
#include <limits>
#include "Truck.h"
#include "Package.h"

class FileReader
{
public:
    static std::list<Truck> getTrucks(const string &filename);
    static std::list<Package> getPackages(const string &filename, list<Package> &expressoPackage);
};

#endif /* FILES_READER */