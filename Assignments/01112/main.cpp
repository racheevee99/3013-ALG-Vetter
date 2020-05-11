//////////////////////////////////////////////////////////////////////////////////
//
// Author:           Rachel Vetter
// Email:            racheevee99@gmail.com
// Label:            1112
// Title:            Mice and Maze
// Course:           CMPS 3013
// Semester:         Spring 2020
//
// Description:
//       Using a map to store values and how many times they are read in.
//
/////////////////////////////////////////////////////////////////////////////////
#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

//Map of pairs of edges and their weights
typedef multimap<pair<int, int>, int> graph; 
graph AdjList;  // container to keep track of connections
graph visited;

const int VISITED = 1;
const int UNVISITED = -1;

int dfs(int u, int v, int time)
{
  //Iterators
  graph::iterator itrv;
  graph::iterator itrg;

  // In DFS we use a stack structure to keep track of who to visit next.
  // Recursive acts just like a stack so we dont need to declare any
  // structure to keep track for us, we let the recursive calls do it for us
  for(itrv = visited.begin(); itrv != visited.end(); itrv++)
    {
      if(itrv->first.first == u && itrv->first.second == v)
      {
        itrv->second = VISITED;// mark u->v as visited
      }
    } 

  // Loop overadjacency list looking for connections
  for(itrg = AdjList.begin(); itrg != AdjList.end(); itrg++)
  {
    //Check all edges connected to u
    if(itrg->first.first == u)
    {
      //Check if each edge is visited 
      for(itrv = visited.begin(); itrv != visited.end(); itrv++)
      {
        if(itrv->first.first == itrg->first.second && itrv->second == UNVISITED)
        {
          time = time + itrg->second;
          //Check connecting edges if unvisited
          dfs(itrv->first.first, itrv->first.second, time);
        }
      }
    }
  } 
  return time;
}

int main() {
int cases, N, M, E, T, a, b, c, time, mice;
  cin >> cases;
  for(int i = 0; i < cases; i++)
  {
    mice = 0;
    cin >> N >> E >> T; //# of cells, exit cell, time
    cin >> M; //# of connections in maze
    for(int j = 0; j < M; j++)
    {
      cin >> a >> b >> c;
      AdjList.insert(make_pair(make_pair(a, b), c));
      AdjList.insert(make_pair(make_pair(j, j), T));
    }
    for(graph::iterator itr = AdjList.begin(); itr != AdjList.end(); itr++)
    {
      time = 0;
      time = dfs(itr->first.first, itr->first.second, time);
      if (time <= T)
      {
        mice++;
      }
    }
    cout << mice << "\n\n";
    AdjList.clear();
  }

return 0;
}