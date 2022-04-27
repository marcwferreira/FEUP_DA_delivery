/*! \mainpage DA Delivery System - Calculating and organizing the best way of delivering packages using the least amount of resources possible
 *
 * This project uses Alrogithm conception studies in order to calculate the best way of organinzing deliveries for a ficticional company with the goal of 
 * delivering the maximum amount of packages in a day using the least amount of resources, specified by the different functions provided.
 *
 * This work was done within the scope of the Algorithms Development curricular course,
 * and aimed at deepening the knowledge about conception of algorithms and dynamic programming.
 *
 * With this simple program you can select load a list of packages to be delivered and a list of trucks, in which
 * after you select from 3 possible cases:
 *  - Least amount of trucks 
 *  - Maximize profit (even in detriment of customer satisfaction by an small amount)
 *  - Maximize number of express deliveries
 *
 * This project was made by:
 * @author Fábio Araújo de Sá, Francisco João Gonçalves Calado Araújo, Marcos William Ferreira Pinto
 *
 * @date 04/02/2022
 */

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
  cout << "\t\t[TIME]\n\t\t   Number of seconds of work time. Must be always be positive (Optional)\n"
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
    error();
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
    {
        outputFile = "../output/";
        outputFile.append(argv[4]);
    }
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
      string temporary = argv[3];
      if(isdigit(temporary[0])){
        numberOfSeconds = stoi(argv[3]);

        if (argv[4] == NULL)
        {
          outputFile = DEFAULT_OUTPUT;
        }
        else
        {
        outputFile = "../output/";
        outputFile.append(argv[4]);
        }
      }
      else{
        numberOfSeconds = WORK_TIME;
        outputFile = "../output/";
        outputFile.append(argv[3]);
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
