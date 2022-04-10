#ifndef FILES_READER
#define FILES_READER

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <limits>
#include "Truck.h"
#include "Package.h"

class FileReader
{
public:
    static std::vector<Truck> getTrucks(string filename);
    static std::vector<Package> getPackages(string filename);
};

#endif