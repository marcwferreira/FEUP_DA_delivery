#include <iostream>
#include <fstream>
#include <string>

#define PACKAGES_FILE "../data/encomendas.txt"
#define TRUCKS_FILE "../data/carrinhas.txt"

using namespace std;

int main()
{
  fstream my_file;
  my_file.open(PACKAGES_FILE, ios::in);
  if (!my_file)
  {
    cout << "No such file";
  }
  else
  {
    string aux;

    while (!my_file.eof())
    {
      getline(my_file, aux, ' ');
      cout << " " << aux;
    }
  }
  my_file.close();
  return 0;
}