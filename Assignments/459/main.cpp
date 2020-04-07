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
#include <queue>
#include <string>
#include <vector>

using namespace std;

typedef vector<char> vi;    // vector of chars
typedef pair<char, int> ii; // pair of integer and char
typedef vector<ii> vii;     // vector of pairs

const int VISITED = 1;
const int UNVISITED = -1;

vi been_visited;     // container to keep track of who get visited
vector<vii> AdjList; // AdjList stores our edge lists
vector<vii>::iterator itr1;
vector<ii>::iterator itr2;

/**
 * Depth First Search
 * 
 * Params:
 *  char u - starting node id
 * 
 */
void dfs(char u)
{
  // In DFS we use a stack structure to keep track of who to visit next.
  // Recursive acts just like a stack so we dont need to declare any
  // structure to keep track for us, we let the recursive calls do it for us

  been_visited[u] = VISITED; // mark u as visited

  // Loop overadjacency list looking for connections
  for (int j = 0; j < (int)AdjList[u].size(); j++)
  {

    // v is a pair representing a neighbor and the
    // weight of the edge from u->v
    ii v = AdjList[u][j];

    // check to see if our neighbor was visited
    if (been_visited[v.first] == UNVISITED)
    {
      dfs(v.first);
    }
  }
}

int main()
{
  ifstream infile;
  infile.open("input");

  int mcs = 0, n;
  cin >> n;
  for (int i = 0; i < n; i++)
  {
    char big, u, v;
    bool b = false;
    int n = 0;

    // vi been_visited;
    // vector<vii> AdjList;
    AdjList.resize(n + 1);
    been_visited.resize(n + 1, UNVISITED);

    cin >> big;
    while (b == false && cin >> u >> v)
    {
      n++;
      AdjList.resize(n);
      been_visited.resize(n, UNVISITED);
      //make new pair
      AdjList[u].push_back(make_pair(v, 10));
      if (u == big)
      {
        b = true;
      }
    }

    for (int j = 0; j < (int)AdjList[u].size(); j++)
    {
      ii v = AdjList[u][j];
      if (been_visited[v.first] == UNVISITED)
      {
        mcs++;
        dfs(v.first);
      }
    }
  }

  cout << mcs;

  infile.close();
  return 0;
}