//////////////////////////////////////////////////////////////////////////////////
//
// Author:           Rachel Vetter
// Email:            racheevee99@gmail.com
// Label:            11597
// Title:            Spanning Subtree
// Course:           CMPS 3013
// Semester:         Spring 2020
//
// Description:
//       Using simple arithmetic to calculate the maximum number of spanning 
//       subtrees from a connected graph where no 2 edges are shared.
//
/////////////////////////////////////////////////////////////////////////////////
#include <iostream>

using namespace std;


int main() {
    int vertices, trees, cases = 0;
    while(cin >> vertices && vertices != 0)
    {
        cases++;
        trees = vertices/2;
        cout << "Case " << cases << ": " << trees << endl;
    }


return 0;
}