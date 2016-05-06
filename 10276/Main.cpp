///https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=645&page=show_problem&problem=1217

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <stack>
#include <cmath>

using namespace std;

bool is_perfect_square(int n) {
    if (n < 0)
        return false;
    int root(round(sqrt(n)));
    return n == root * root;
}

int main()
{
	int N;
	int value;

	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> value;
		vector<int> pegs(value,0);

		int ball = 1;
		while(true)
		{
			bool pushed = false;
			for(int i = 0; i < pegs.size(); i++)
			{
				if (pegs[i] == 0 || is_perfect_square(pegs[i]+ ball))
				{
					pegs[i] = ball;
					pushed = true;
					break;
				}
			}
			if (!pushed) break;
			ball++;
		}
		cout << (ball - 1) << endl;
	}
	return 0;
}
