#ifndef FILES_READER
#define FILES_READER

#include <iostream>
#include <fstream>
#include <list>
#include <string>
#include "Truck.h"
#include "Package.h"

class FileReader
{
public:
    static std::list<Truck> getTrucks(const string &filename);
    static std::list<Package> getPackages(const string &filename);
};

#endif