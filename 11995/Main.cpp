/// https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=3146
#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

bool isStack(vector<int>& operation, vector<int>& values) 
{
	stack<int> stacking;

	for(int i = 0; i < operation.size(); i++)
	{
		if (operation[i] == 1)
		{
			stacking.push(values[i]);
		}
		else
		{
			if (!stacking.empty() && stacking.top() == values[i])
			{
				stacking.pop();
			}
			else
			{
				return false;
			}
		}
	}
	return true;
}

bool isQueue(vector<int>& operation, vector<int>& values)
{
	queue<int> queueing;
	for(int i = 0; i < operation.size(); i++)
	{
		if (operation[i] == 1)
		{
			queueing.push(values[i]);
		}
		else
		{
			if (!queueing.empty() && queueing.front() == values[i])
			{
				queueing.pop();
			}
			else
			{
				return false;
			}
		}
	}
	return true;
}

bool isPriorityQueue(vector<int>& operation, vector<int>& values)
{
	priority_queue<int> priorityQueue; 
	for(int i = 0; i < operation.size(); i++)
	{
		if (operation[i] == 1)
		{
			priorityQueue.push(values[i]);
		}
		else
		{
			if (!priorityQueue.empty() && priorityQueue.top() == values[i])
			{
				priorityQueue.pop();
			}
			else
			{
				return false;
			}
		}
	}
	return true;
}


int main()
{
	int N;
	while(cin >> N)
	{
		// BASE VALUES
		vector<int> operations (N);
		vector<int> values (N);

		for (int i = 0; i < N; i++)
		{
			int operation, value;
			cin >> operation >> value;
			// READ VALUES 
			operations[i] = operation;
			values[i] = value;
		}

		if (isStack(operations, values) == true && 
			isQueue(operations, values) == false &&
			isPriorityQueue(operations, values) == false)
		{
			cout << "stack" << endl;
		}
		else  if (isStack(operations, values) == false && 
				  isQueue(operations, values) == true &&
			      isPriorityQueue(operations, values) == false)
		{
			cout << "queue" << endl;
		}
		else  if (isStack(operations, values) == false && 
				  isQueue(operations, values) == false &&
			      isPriorityQueue(operations, values) == true)
		{
			cout << "priority queue" << endl;
		}
		else if (isStack(operations, values) == false && 
				  isQueue(operations, values) == false &&
			      isPriorityQueue(operations, values) == false)
		{
			cout << "impossible" << endl;
		}
		else
		{
			cout << "not sure" << endl;
		}
	}


	return 0;
}