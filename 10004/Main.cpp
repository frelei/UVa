/// https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=12&page=show_problem&problem=945

#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int graph[201][201];

bool check(int source)
{
    int color[201];
    for (int i = 0; i < 201; i++)
        color[i] = -1;

    color[source] = 1;
    queue<int> q;
    q.push(source);

    while (!q.empty())
    {
        int u = q.front();
        q.pop();

        for (int v = 0; v < 201; v++)
        {
            if (graph[u][v] && color[v] == -1)
            {
                color[v] = 1 - color[u];
                q.push(v);
            }
            else if (graph[u][v] && color[v] == color[u])
                return false;
        }
    }
    return true;
}


int main()
{
	int nodes, edges;
	int u,v,s;

	while(cin >> nodes >> edges)
  {

		for (int i = 0; i < 201; i++)
			for (int j = 0; j < 201; j++)
				graph[i][j] = 0;

		for (int i = 0; i < edges; i++)
    {
			cin >> u >> v;
			graph[u][v] = 1;
			graph[v][u] = 1;
			s = u;
		}

		if (check(s))
    {
			cout << "BICOLORABLE." << endl;
		}
    else
    {
			cout << "NOT BICOLORABLE." << endl;
		}
	}
	return 0;

}
