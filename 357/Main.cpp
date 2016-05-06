///https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=5&page=show_problem&problem=293

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>

using namespace std;

int main()
{

	int coins[5] = {1,5,10,25,50};
	long result[30001] = {0};
	result[0] = 1;
		for(int i = 0; i < 5; i++)
		{
        	for(int j = coins[i]; j <= 30000; j++)
        	{
        		  result[j] += result[j - coins[i]];
        	}
    	}

    int value;
	while(cin >> value)
	{
		if (result[value] == 1)
		{
			 cout << "There is only "<< result[value] <<" way to produce "<< value <<" cents change." << endl; 
		}
		else
		{
			cout << "There are "<< result[value] <<" ways to produce "<< value <<" cents change." << endl; 
		}
	}
	return 0;
}