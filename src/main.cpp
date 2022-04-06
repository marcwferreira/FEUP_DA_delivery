#include <iostream>
#include "MailSystem.h"
using namespace std;

int main()
{
  MailSystem mailSystem = MailSystem();

  // mailSystem.statistics();
  char answer;
  cout << "Weight (w) or Volume (v)? "; // para ser mais simples de visualizar soluções
  cin >> answer;
  if (tolower(answer) == 'w') mailSystem.case1_ByWeight(); else mailSystem.case1_ByVolume();

  return 0;
}
