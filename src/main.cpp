#include <iostream>
#include "MailSystem.h"
using namespace std;

int main()
{
  MailSystem mailSystem = MailSystem();

  mailSystem.statistics();
  mailSystem.reset();
  mailSystem.case1_ByWeight();
  mailSystem.reset();
  mailSystem.case1_ByVolume();
  cout << endl;

  return 0;
}
