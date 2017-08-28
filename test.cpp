/*
 *
 * hello.cpp
 *
*/

#include <iostream>
#include <cstring>
#include <string>

using std::cout;

// using std::basic_string;
using namespace std;

int main (int argc, char* argv[]) {

  int *p, n;
  n = 666;
  p = &n;

  typedef basic_string<char> string;

  string fred="Fred";

  std::cout << "Hello p and n are " << p << " and " << n << "\n";

  cout << "fred=" << fred << "\n";

  char Stocks[1000][10] = {{ 0 }};
  cout << "Stocks[500][3] = " << Stocks[500][3]+0 << "\n";
  
  int Intervals[1000]; // = { 0 };
  cout << "Intervals[66] = " << Intervals[66] << "\n";

  return 0;
}

