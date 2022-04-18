#include <iostream>
#include <string>
#include "MailSystem.h"
using namespace std;

void error()
{
  cerr << "\tInvalid arguments" << endl
       << "\tIf you need help use '--help'" << endl;
  exit(-1);
}

void helper()
{
  cout << "\n\t\t<MODE>\n";
  cout << "\t\t   1: Optimization of the number of trucks" << endl;
  cout << "\t\t\t  ./project <MODE> <PACKAGES> <TRUCKS> [OUTPUT]" << endl;
  cout << "\t\t   2: Optimization of the profit" << endl;
  cout << "\t\t\t  ./project <MODE> <PACKAGES> <TRUCKS> [OUTPUT]" << endl;
  cout << "\t\t   3: Optimization of the express deliveries" << endl;
  cout << "\t\t\t  ./project <MODE> <PACKAGES> [TIME] [OUTPUT]" << endl
       << endl;
  cout << "\t\t<PACKAGES>\n\t\t   Name of Packages dataset in input folder\n"
       << endl;
  cout << "\t\t<TRUCKS>\n\t\t   Name of Trucks dataset in input folder\n"
       << endl;
  cout << "\t\t[TIME]\n\t\t   Number of seconds of work time. Must be always be positive\n"
       << endl;
  cout << "\t\t[OUTPUT]\n\t\t   Name of output file. Always optional\n"
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
  {
    helper();
  }
  int mode = modeString[0] - '0';
  if (mode > 3 || mode < 1)
  {
    cerr << "Invalid mode" << endl
         << "\tIf you need help use '--help'" << endl;
    exit(-1);
  }

  if ((mode == 1 || mode == 2) && (argc == 3 || argc > 5))
  {
    error();
  }

  if (mode == 3 && argc > 5)
  {
    error();
  }

  string filePackages = argv[2];
  string fileTrucks;
  string outputFile;
  int numberOfSeconds = 0;
  if (mode != 3)
  {
    fileTrucks = argv[3];
    if (argv[4] == NULL)
      outputFile = DEFAULT_OUTPUT;
    else
      outputFile = argv[4];
  }
  else
  {
    if (argv[3] == NULL)
    {
      numberOfSeconds = WORK_TIME;
      outputFile = DEFAULT_OUTPUT;
    }
    else
    {
      numberOfSeconds = stoi(argv[3]);
      if (argv[4] == NULL)
      {
        outputFile = DEFAULT_OUTPUT;
      }
      else
      {
        outputFile = argv[4];
      }
    }

    if (numberOfSeconds <= 0)
    {
      error();
    }
  }

  if (!(exists(INPUT_FOLDER + fileTrucks) && exists(INPUT_FOLDER + filePackages)))
  {
    return -1;
  }

  MailSystem mailSystem = MailSystem(INPUT_FOLDER + fileTrucks, INPUT_FOLDER + filePackages);

  switch (mode)
  {
  case 1:
    mailSystem.case1(outputFile);
    break;

  case 2:
    mailSystem.case2(outputFile);
    break;

  case 3:
    mailSystem.case3(outputFile, numberOfSeconds);
    break;

  default:
    cout << "Error: Mode invalid" << endl;
    break;
  }

  return 0;
}
