#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

bool ordering (int i,int j) 
{ 
	return (i<j); 
}

int main(){
	
	while(true)
	{
		int N;
		int total = 0;
		priority_queue< int, vector<int>, greater<int> >queue;
		
		// READ INITIAL VALUE
		cin >> N;

		// ITS OVER
		if (N == 0) 
			break;

		for (int i = 0; i < N; i++)
		{
			int val;
			cin >> val;
			queue.push(val);
		}

		while(queue.size() > 1)
		{
			int a = queue.top();
			queue.pop();
			int b = queue.top();
			queue.pop();

			int sum = a + b;
			total += sum;
			queue.push(sum);
		}
		cout << total << endl;
	}

	return 0;
}