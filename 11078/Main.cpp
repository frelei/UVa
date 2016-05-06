/// https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=22&page=show_problem&problem=2019

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>

using namespace std;

int main()
{
 int  MIN_BEST = -100000;
 int T, N, qi, result, best;
 cin >> T;

  while (T > 0) 
  {
	    best = result = MIN_BEST;
	    cin >> N;

	    while (N > 0) 
	    {
	      cin >> qi;

	      if (best - qi > result)
	        result = best - qi;

	      if (qi > best)
	        best = qi;

	    	N--;
	    }

	    cout << result << endl;
	    T--;
   }
  return 0;
}