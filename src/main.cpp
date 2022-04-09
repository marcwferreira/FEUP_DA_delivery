#include <iostream>
#include <string>
#include "MailSystem.h"
using namespace std;

#define INPUT_FOLDER "../input/"
#define DEFAULT_OUTPUT "../output.txt"

void error() 
{
    cerr << "\tInvalid arguments" << endl
         << "\tIf you need help use '--help'" << endl;
    exit(-1);
}

void helper() 
{
    cout << "\n\t./main <TRUCKS> <PACKAGES> <MODE> [OUTPUT]\n" << endl;
    cout << "\t\t<TRUCKS>\n\t\t   Name of Trucks dataset in input folder\n" << endl;
    cout << "\t\t<PACKAGES>\n\t\t   Name of Packages dataset in input folder\n" << endl;
    cout << "\t\t<MODE>\n";
    cout << "\t\t   1: Otimização do número de estafetas" << endl;
    cout << "\t\t   2: Otimização do lucro da empresa" << endl;
    cout << "\t\t   3: Otimização das entregas expresso\n" << endl;
    cout << "\t\t[OUTPUT]\n\t\t   Name of output file\n" << endl;
    exit(-1);
}

bool exists(const string &fileName)
{
    fstream file;
    file.open(fileName, ios::in);
    if (!file)
    {
        cerr << "Error: file " << fileName << " not found" << endl;
        return false;
    }
    file.close();
    return true;
}

int main(int argc, char *argv[])
{
    if (argv[1] == NULL) error();
    string fileTrucks = argv[1];
    if (fileTrucks == "--help" && argc == 2) helper();
    if (argc < 4 || argc > 5) error();

    string filePackages = argv[2];
    string c = argv[3]; int mode = c[0] - '0';

    if (mode > 3 || mode < 1) 
    {
      cerr << "Invalid mode" << endl;
      return -1;
    }
  
    if (!(exists(INPUT_FOLDER + fileTrucks) && exists(INPUT_FOLDER + filePackages))) return -1;

    int day = 1;
    MailSystem mailSystem = MailSystem(INPUT_FOLDER + fileTrucks, INPUT_FOLDER + filePackages);

    switch (mode)
    {
      case 1:
          cout << "Modo 1 brevemente" << endl;
          break;

      case 2:
          cout << "Modo 2 brevemente" << endl;
          break;

      case 3:
          cout << "Modo 3 brevemente" << endl;
          break;
    }

    return 0; // para não seguir para já

    // TODO: passar esta mecânica de baixo para dentro do case 1 do switch
    do
    {
      if (!mailSystem.case1(argv[1], day))
      {
        break;
      }
      cin >> filePackages;

      if (filePackages.empty())
      {
        break;
      }

      mailSystem = MailSystem(fileTrucks, filePackages);
      day++;
    } while (true);

    return 0;
}
