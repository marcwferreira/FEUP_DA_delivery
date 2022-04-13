#include <iostream>
#include <string>
#include "MailSystem.h"
using namespace std;

#define DEFAULT_OUTPUT "../output.txt"

void error()
{
  cerr << "\tInvalid arguments" << endl
       << "\tIf you need help use '--help'" << endl;
  exit(-1);
}

void helper()
{
  cout << "\n\t./main <MODE> <PACKAGES> [TRUCKS] [OUTPUT]\n"
       << endl;
  cout << "\t\t<TRUCKS>\n\t\t   Name of Trucks dataset in input folder\n"
       << endl;
  cout << "\t\t<PACKAGES>\n\t\t   Name of Packages dataset in input folder\n"
       << endl;
  cout << "\t\t<MODE>\n";
  cout << "\t\t   1: Otimização do número de estafetas" << endl;
  cout << "\t\t   2: Otimização do lucro da empresa" << endl;
  cout << "\t\t   3: Otimização das entregas expresso\n"
       << endl;
  cout << "\t\t[OUTPUT]\n\t\t   Name of output file\n"
       << endl;
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
  if (argv[1] == NULL)
    error();
  string modeString = argv[1];
  if (modeString == "--help" && argc == 2)
    helper();
  int mode = stoi(modeString);
  if (mode > 3 || mode < 1)
  {
    cerr << "Invalid mode" << endl;
    return -1;
  }
  if ( (mode == 1 || mode == 2) && argc != 3 && argc !=4 )
    error();
  if ( mode == 3 && argc != 2 && argc != 3 )
    error();
  
  string filePackages = argv[2];
  string fileTrucks;
  string outputFile;
  if (mode != 3){
    fileTrucks = argv[3];
    if (argv[4] == NULL)
      outputFile = DEFAULT_OUTPUT;
    else
      outputFile = argv[4];
  }
  else {
    if (argv[3] == NULL)
      outputFile = DEFAULT_OUTPUT;
    else
      outputFile = argv[3];
  }

  if (!(exists(INPUT_FOLDER + fileTrucks) && exists(INPUT_FOLDER + filePackages)))
  {
    return -1;
  }

  MailSystem mailSystem = MailSystem(INPUT_FOLDER + fileTrucks, INPUT_FOLDER + filePackages);


  switch (mode)
  {
  case 1:
    mailSystem.case1(outputFile, 1);
    break;

  case 2:
    cout << "Modo 2 brevemente" << endl;
    break;

  case 3:
    cout << "Modo 3 brevemente" << endl;
    break;

  default:
    cout << "Error: Mode invalid" << endl;
    break;
  }

  return 0;
}
