///https://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=2026

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>

using namespace std;

vector<int> queens(8,0);
vector<int> result(8,0);

int checkPosition(int row, int pos)
{
	for (int i = 0; i < row; i++) // CHECK OTHERS QUEENS POSITIONS
	{
		if (pos == result[i])
			return false;
		if (abs(row - i) == abs(pos - result[i]))
			return false;
	}
	return true;
}

int backtracking(int n)
{
	if (n == 8) 
	{
		return 0;
	}
	int cost = 100000;

	for(int i = 0; i <= 7; i++)
	{
		if (checkPosition(n,i))
		{
			result[n] = i;
			// if (i == queens[i])
			// {
			// 	cost = min(cost, backtracking(n+1));
			// }
			// else
			// {
			// 	cost = min(cost, 1 + backtracking(n+1));
			// }
			cost  =  min(cost, i == queens[i] ? backtracking(n+1) : 1 + backtracking(n+1) );
		}
	}
	return cost;
}


int main()
{
	int count = 1, rows = 0, val = 0;
	
	while(cin >> val)
	{
		val--;
		//cout << val << endl;
		queens[rows] = val;
		result[rows] = queens[rows];
		rows++;
		if (rows == 8)
		{
			 rows = 0;
			 cout << "Case " << count << ": " << backtracking(0) << endl;
			 //queens.clear();
			 //result.clear();
			 count++;
		}
	}
	return 0;
}

// #include<algorithm>
// #include<cstdio>
 
// using namespace std;
 
// int queens[8], path[8];
 
// bool valid(int r, int c) {
//     for(int j = 0; j < r; j++) {
//         if(c == path[j]) return false;
//         if(abs(r - j) == abs(c - path[j])) return false;
//     }
//     return true;
// }
 
// int search(int n) {
//     if(n == 8) return 0;
 
//     int tot = 100000;
 
//     for(int i = 0; i < 8; i++)
//         if(valid(n, i)) {
//             path[n] = i;
//             tot = min(tot, i == queens[n]? search(n + 1) : 1 + search(n + 1));
//         }
 
//     return tot;
// }
 
// int main() {
//     for(int T = 1;; T++) {
//         for(int i = 0; i < 8; i++) {
//             if(scanf("%d", &queens[i]) == -1) return 0;
//             queens[i]--; path[i] = queens[i];
//         }
 
//         printf("Case %d: %d\n", T, search(0));
//     }
// }

