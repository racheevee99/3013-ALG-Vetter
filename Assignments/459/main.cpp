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

typedef vector<char> vi;    // vector of integers
typedef pair<char, int> ii; // pair of integer and char
typedef vector<ii> vii;    // vector of pairs

const int VISITED = 1;
const int UNVISITED = -1;

vi been_visited;     // container to keep track of who get visited
vector<vii> AdjList; // AdjList stores our edge lists

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
  cout << u << " ";          // write u to stdout

  // Loop overadjacency list looking for connections
  for (int j = 0; j < (int)AdjList[u].size(); j++)
  {

    // v is a pair representing a neighbor and the
    // weight of the edge from u->v
    ii v = AdjList[u][j];

    //cout << u << "->" << v.first << " with weight " << v.second << endl;

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

  char n, u, v;

  // vi been_visited;
  // vector<vii> AdjList;

  cin >> n;
  

  AdjList.resize(n + 1);
  been_visited.resize(n + 1, UNVISITED);

  for (int i = 0; i < m; i++)
  {
    cin >> u >> v;

    // Here u is the start of the edge
    // So u connects to v (or u->v)
    // The 10 is a "weight" assigned to the edge
    // 10 is just an arbitrary number
    AdjList[u].push_back(make_pair(v, 10));
  }

  int n, mcs, size = 0;
  char big;
  string node;
  bool visited = false;
  cin >> n;
  for (int i = 0; i < n; i++)
  {
    cin >> big;

    cout << mcs << endl;
  }

  infile.close();
  return 0;
}