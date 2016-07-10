/// https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=678&page=show_problem&problem=1927

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <stack>
#include <queue>
#include <vector>
#include <sstream>

using namespace std;

vector< vector< pair<int,int> > > graph;

int dijkstra(int a, int b, int n)
{
  priority_queue< pair<int,int>, vector< pair<int,int> >, greater< pair<int,int> > > queue;
  vector<int> distance(n, -1);
  pair<int,int> p;
  int v,w;

  queue.push( make_pair(0,a) );
  while (!queue.empty())
  {
      p = queue.top();
      queue.pop();
      v = p.second;
      w = p.first;
      if ( distance[v] != -1 )
        continue;
      if (v == b)
        return w;
      distance[v] = w;

      for (int i = 0; i < graph[v].size(); ++i)
      {
	     if ( distance[ graph[v][i].first ] == -1 )
	      {
	         queue.push( make_pair( w + graph[v][i].second, graph[v][i].first ) );
	      }
      }
  }
  return -1;
}


int main ()
{
    int N, n, m, S, T, u, v, w;
    int count = 1;
    cin >> N;
    for(int i = 0; i < N; i++)
    {
        cin >> n >> m >> S >> T;
        vector<vector<pair<int,int> > >temp(n+1);
        swap(temp, graph);
        for (int i = 0; i < m; ++i)
        {
           cin >> u >> v >> w;
           graph[u].push_back(make_pair(v,w));
           graph[v].push_back(make_pair(u,w));
         }

         int result = dijkstra(S,T,n);

          if (result == -1) {
            cout << "Case #"<< count <<": unreachable" << endl;
          } else {
            cout << "Case #"<< count <<": " << result << endl;
          }
          count++;
    }
    return 0;
}
