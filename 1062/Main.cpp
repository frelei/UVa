//https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=628&page=show_problem&problem=3503

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <stack>

using namespace std;

int main()
{
	string input;
	stack<char> letter;
	bool added;
	int cases = 1;

	getline(cin,input);
	while(input != "end")
	{		

		vector<stack<char> > containers;

		for (int i = 0; i < input.size(); i++)
		{
			added = false;
			for (int j = 0; j < containers.size(); j++)
			{
				// ADD IN THE STACK THE CONTAINERS IN ORDER
				if (input[i] <= containers[j].top())
				{	
					added = true;
					containers[j].push(input[i]);
					break;
				}
			}
			// NOT ABLE TO INSERT ON THE CONTAINER, CREATE NEW ONE
			if (added == false)
			{
				letter.push(input[i]);
				containers.push_back(letter);
				letter.pop();
			}
		}
		
		cout << "Case " << cases << ": " << containers.size() << endl;
		cases++;
		getline(cin,input);
	}

	return 0;
}