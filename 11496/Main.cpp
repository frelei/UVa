//https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=628&page=show_problem&problem=3503

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <stack>
#include <stdlib.h>

using namespace std;

void Print (const vector<int>& v){
  for (int i=0; i<v.size();i++){
    cout << v[i] << " ";
    }
    cout << endl;
}

int main()
{
	int N;

	while(cin >> N)
	{
		if (N == 0) break;
		
		vector<int> samples (N+2,0) ;
		int result = 0;
		
		// READ VALUES
		for(int i = 1; i < N+1; i++)
		{
			int sample;
			cin >> sample;
			if (sample != 0)
				samples[i] = sample;
		}
		samples[0] = samples[samples.size() - 2];
		samples[samples.size() - 1] =  samples[1];


		// DETECTING PEAKS
		for (int i = 0; i < samples.size() - 2; i++)
		{
			if( (samples[i] > samples[i+1] && samples[i+1] < samples[i+2]) ||
				(samples[i] < samples[i+1] && samples[i+1] > samples[i+2]) )
			{
				result++;
			}
		}

		cout << result << endl;
		result = 0;
	}

	return 0;
}