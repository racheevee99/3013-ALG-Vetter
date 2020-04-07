//////////////////////////////////////////////////////////////////////////////////
//
// Author:           Rachel Vetter
// Email:            racheevee99@gmail.com
// Label:            459
// Title:            Graph Connectivity
// Course:           CMPS 3013
// Semester:         Spring 2020
//
// Description:
//       Using a singly linked list to store words and their definitions
//      then searching through them as each character is entered.
//
/////////////////////////////////////////////////////////////////////////////////
#include <iostream>
#include <fstream>

using namespace std;

int main() {
  ifstream infile;
  infile.open("input");

  int t, a, b;
  cin >> t;
  for(int i = 0; i < t; i++)
  {
    cin>>a >>b;
    if (a > b)
      cout << ">\n";
    else if(a < b)
      cout << "<\n";
    else 
      cout << "=\n";
  }

infile.close();
return 0;
}