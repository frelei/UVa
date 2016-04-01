//https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=628&page=show_problem&problem=3503

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <stack>
#include <stdlib.h>

using namespace std;


int main()
{
	int K, N, M;
	while(cin >> K)
	{
		if (K == 0) break;
		cin >> N;
		cin >> M;

		for(int i= 0; i < K; i++)
		{
			int latitude, longitude;
			cin >> latitude;
			cin >> longitude;

			if (latitude == N || longitude == M)
			{
				cout << "divisa" << endl;
			}
			else if (latitude > N && longitude > M)
			{
				cout << "NE" << endl;
			}
			else if (latitude < N && longitude > M)
			{
				cout << "NO" << endl;
			}
			else if (latitude > N && longitude < M)
			{
				cout << "SE" << endl;
			}
			else
			{
				cout << "SO" << endl;
			}

		}
	}
	return 0;
}