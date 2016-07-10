/// http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=226&page=show_problem&problem=2927

#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <sstream>
#include <string>

using namespace std;

int gcd(int a, int b)
{
	if( b == 0)
	 	return a;
  else
		return gcd(b, a % b);
}

int main()
{
	int T, numbers[101];
	string line;

	cin >> T;
	getchar(); // Need add this line. I don't know why the first time the stream read anything!!! But works now!!!

	for(int i = 0; i < T; i++)
	{
			getline(cin, line);
			istringstream stream(line);

			int index = 0;
			while(stream >> numbers[index])
				index++;

			int result = 0;
			for (int j = 0; j < index; j++)
			{
				for (int k = j+1; k < index; k++)
				{
						result = max(result, gcd(numbers[j], numbers[k]));
				}
			}
			cout << result << endl;
	}
	return 0;
}
