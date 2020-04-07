//////////////////////////////////////////////////////////////////////////////////
//
// Author:           Rachel Vetter
// Email:            racheevee99@gmail.com
// Label:            484
// Title:            The Department of Redundancy Department
// Course:           CMPS 3013
// Semester:         Spring 2020
//
// Description:
//       Using a map to store values and how many times they are read in.
//
/////////////////////////////////////////////////////////////////////////////////
#include <iostream>
#include <map>

using namespace std;


int main() {
    int n, a[10000], c = 0;
    bool b;
    map<int,int> m;
    map<int,int>::iterator itr;

  cin >> n;
  m.insert(make_pair(n, 1));
  a[c] = n;
  c++;

    while(cin >> n)
    {
      b = false;
      for (itr = m.begin(); itr != m.end(); itr++)
        {
         if(n == itr->first)
         {
           itr->second++;
           b = true;
         }
        }
        if (b == false)
         {
           m.insert(make_pair(n, 1));
           a[c] = n;
           c++;
         }
    }

    //Display map values
    for (int i = 0; i < c; i++)
    {
        cout << a[i] << " ";
        for (itr = m.begin(); itr != m.end(); ++itr)
        {
          if(a[i] == itr->first)
          {
            cout << itr->second << endl;
          }
        }
    }

  return 0;
}
