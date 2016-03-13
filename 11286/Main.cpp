/// https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=2261
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;


int main()
{
	while(true)
	{
		int N;
		cin >> N;

		// EXIT
		if (N == 0) 
			break;

		map<vector<int>, int> dictionary;
		vector<int> discipline(5);
		int val, combination = 1;

		// READ VALUES
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < 5; j++)
			{
				cin >> val;
				discipline[j] = val;
			}
			sort(discipline.begin(), discipline.end());
			if (!dictionary[discipline])
			{
				dictionary[discipline] = 1;
			}
			else
			{
				if (combination < dictionary[discipline] + 1)
					combination = dictionary[discipline] + 1;
				dictionary[discipline] = dictionary[discipline] + 1;
			}
		}

		int bestCombination = 0;
		for (auto const& x : dictionary)
		{
			if (x.second == combination)
			{
				bestCombination += combination;
			}
		}
		cout << bestCombination << endl;
	}

	return 0;
}