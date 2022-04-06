#include <vector>
#include <iostream>
#include "Truck.h"
#include "Package.h"
#include "FileReader.h"
using namespace std;

#define TRUCKS_FILE "../data/carrinhas.txt"
#define PACKAGES_FILE "../data/encomendas.txt"

int main()
{
  vector<Truck> trucks = FileReader::getTrucks(TRUCKS_FILE);
  for (auto t : trucks)
    cout << t;

  vector<Package> packages = FileReader::getPackages(PACKAGES_FILE);
  for (auto p : packages)
    cout << p;

  return 0;
}