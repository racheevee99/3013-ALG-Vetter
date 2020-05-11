//////////////////////////////////////////////////////////////////////////////////
//
// Author:           Rachel Vetter
// Email:            racheevee99@gmail.com
// Label:            10901
// Title:            Ferry Loading III
// Course:           CMPS 3013
// Semester:         Spring 2020
//
// Description:
//       
//
/////////////////////////////////////////////////////////////////////////////////
#include <iostream>
#include <queue>

using namespace std;

int main() {

    //Variable declarations
    int c, n, t, m, arrival, time;
    string port, currentPort = "left";
    queue<pair<int, string>> ferry;

    //read in number of cases
    cin >> c;
    for(int i = 0; i < c; i++)
    {
        //Declare ferry queue
        time = 0;
        //Read in number of cars allowed on ferry, time to travel river, and number of cars waiting
        cin >> n >> t >> m;
        for (int j = 0; j < m; j++)
        {
          //Fill queue
            cin >> arrival >> port;
            ferry.push(make_pair(arrival, port));
        }

        while(!ferry.empty())
        {
            for(int car = 0; car < n; car++)
            {
                if(ferry.front().first <= time 
                && ferry.front().second == currentPort)
                {
                    cout << time + t << endl;
                    ferry.pop();
                }
            }
            time += t; 
            if (currentPort == "left")
            {
                currentPort = "right";
            }
            else
            {
                currentPort = "left";
            }
        }
        cout << endl;
    }
  return 0;
}