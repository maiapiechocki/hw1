#include <string>
#include <vector>
#include <iostream>
#include <sstream>

#include "ulliststr.h"

using namespace std;


//Use this file to test your ulliststr implementation before running the test suite

int main(int argc, char* argv[])
{
  ULListStr list;

	list.push_back("a");

  cout << list.get(0) << endl;
  cout << list.empty() << endl; 

}
