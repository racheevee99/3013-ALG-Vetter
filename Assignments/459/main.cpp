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
//       Using maps to find the maximum number of subgraphs in given graphs.
//
/////////////////////////////////////////////////////////////////////////////////
#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

typedef multimap<char, int> vis;    // vector of chars and ints for visits
typedef multimap<char, char> graph; // pair of chars for connected nodes

const int VISITED = 1;
const int UNVISITED = -1;

vis visited;  // container to keep track of who get visited
graph AdjList;  // container to keep track of connections


void dfs(char u)
{
  //Iterators
  vis::iterator itrv;
  graph::iterator itrg;

  // In DFS we use a stack structure to keep track of who to visit next.
  // Recursive acts just like a stack so we dont need to declare any
  // structure to keep track for us, we let the recursive calls do it for us
  for(itrv = visited.begin(); itrv != visited.end(); itrv++)
    {
      if(itrv->first == u)
      {
        itrv->second = VISITED;// mark u as visited
      }
    } 

  // Loop overadjacency list looking for connections
  for(itrg = AdjList.begin(); itrg != AdjList.end(); itrg++)
  {
    //Check all edges connected to u
    if(itrg->first == u)
    {
      //Check if each edge is visited 
      for(itrv = visited.begin(); itrv != visited.end(); itrv++)
      {
        if(itrv->first == itrg->second && itrv->second == UNVISITED)
        {
          //Check connecting edges if unvisited
          dfs(itrv->first);
        }
      }
    }
  } 
}

int main()
{
  int n, mcs;
  char big = 'a', u, v;
  string uv;

  cin >> n;
  for (int i = 0; i < n; i++)
  {
    mcs = 0;

    //Read in first and largest edge 
    if(big == 'a')
    {
      cin >> big;
    }
    for(char c = 'A'; c <= big; c++)
    {
      AdjList.insert(make_pair(c, c));
      visited.insert(make_pair(c , UNVISITED));
    }

    while (cin >> uv && uv.length() > 1)
    {
      u = uv[0];
      v = uv[1];
      //make new pairs
      AdjList.insert(make_pair(u, v));
      AdjList.insert(make_pair(v, u));
      //set all edges to unvisited
      visited.insert(make_pair(u, UNVISITED));
      visited.insert(make_pair(v, UNVISITED));
    }
    big = uv[0];
    //Find maximal connected subgraphs
    for(vis::iterator itrv = visited.begin(); itrv != visited.end(); itrv++)
    {
      if(itrv->second == UNVISITED)
       {
         mcs++;
         dfs(itrv->first);
       }
    }

    //Display maximum connected subgraphs
    cout << mcs << "\n\n";
    AdjList.clear();
    visited.clear();
  }
  return 0;
}