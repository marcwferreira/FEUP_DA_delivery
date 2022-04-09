#include <iostream>
#include "MailSystem.h"
using namespace std;

int main(int argc, char *argv[])
{
  MailSystem mailSystem;
  unsigned int day = 1;
  string fileTrucks, filePackages;

  if (argc < 2)
  {
    cout << "\tPlease specify at least the path to the output file" << endl
         << "\tIf you need help use --help" << endl;
    return 0;
  }
  else if (argc == 4)
  {
    mailSystem = MailSystem(argv[2], argv[3]);
    fileTrucks = argv[2];
  }
  else
  {
    mailSystem = MailSystem();
    fileTrucks = TRUCKS_FILE;
  }

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
