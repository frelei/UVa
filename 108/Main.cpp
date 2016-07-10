///  https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=3&page=show_problem&problem=44

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>

using namespace std;

int matrix[101][101] = {0};

int main()
{
	int N;
	cin >> N;

	for(int i = 0; i < N; i++)
	{
		for(int j = 0; j < N; j++)
		{
				int elem;
				cin >> elem;
				//cout << elem << " ";
				matrix[i][j] = elem + matrix[i-1][j] + matrix[i][j-1] - matrix[i-1][j-1];
		}
		//cout << endl;
	}

 int result = 0;
	for (int i = 0; i < N; i++)
	{
	  for (int j = 0; j < N; j++)
		{
	     for (int k = i; k < N; k++)
			 {
	        for (int l = j; l < N; l++)
					{
	          result = max(result, matrix[k][l] - matrix[i-1][l] - matrix[k][j-1] + matrix[i-1][j-1]);
	        }
	      }
	   }
	}
	cout << result << endl;

	return 0;
}
