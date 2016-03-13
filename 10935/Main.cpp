/// https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=21&page=show_problem&problem=1876
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int main()
{

	int N;
	while(cin >> N)
	{
		// EXIT PROGRAM
		if (N == 0) break;
		vector<int> throwed;
		queue<int> cards;

		for (int i = 1; i < N+1; i++)
			cards.push(i);

		for (int i = 0; i < N; i++)
		{
			if (cards.size() == 1) break;

			int discard = cards.front();
			throwed.push_back(discard);
			cards.pop();
			int topCard = cards.front();
			cards.pop();
			cards.push(topCard);
		}

        if (throwed.size() == 0)
			cout << "Discarded cards:";
		else
			cout << "Discarded cards: ";
		for (int i = 0; i < throwed.size(); i++)
		{
			if (i == throwed.size() - 1)
				cout << throwed[i];
			else
				cout << throwed[i] << ", ";
		}
		cout << endl;
		cout << "Remaining card: " << cards.back() << endl;
	}
	

	return 0;
}