/// https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=14&page=show_problem&problem=1193
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>

using namespace std;

int main()
{
	string a,b;

	while(getline(cin,a) && getline(cin,b))
	{
		sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        int a_index = 0, b_index = 0;

        // GET TO THE END 
        while(a_index < a.size() && b_index < b.size())
        {
        	if (a[a_index] == b[b_index])
        	{
        		cout << a[a_index];
        		a_index += 1;
        		b_index += 1;
        	}
        	else
        	{
        		// CHECK LETTERS
        		if(b[b_index] > a[a_index]) 
        		{
        			a_index += 1;
        		}
        		else
        		{
        			b_index += 1;
        		}
        	}
    	}
    	cout << endl;
	}
	return 0;
}