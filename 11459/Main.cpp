#include <stdlib.h>
#include <iostream>
#include <vector>
#include <map>
#include <string>

using namespace std;

int main(){

	// Variables
	int player, snake, die, testcase;
	
	// Read Testcases
	cin >> testcase;
	
	// RUN TESTCASES
	for (int i = 0; i < testcase; i++)
	{
		// GET VALUES
		cin >> player >> snake >> die;
		vector<int> position (player, 1);
		int n_die = die;

		// TEMPORARY VALUES
		map<int, pair<int,int> > dicPair;
		int begin, end;
		
		// WHERE ARE THE SNAKES?
		for (int a = 0; a < snake; a++)
		{
			cin >> begin >> end;
			dicPair[begin] = make_pair(begin,end);
		}	

		// ROLL DIES

		for(int j = 0, count = 0; j < die; j++)
		{
			int dieValue;
			cin >> dieValue;
			n_die--;

			if (count == (position.size() - 1))
			{
				int newPosition = position[count] + dieValue;
				int isSnakePosition = get<0>(dicPair[newPosition]);

				if (isSnakePosition > 0)
				{
					newPosition = get<1>(dicPair[newPosition]);
					position[count] = (newPosition >= 100) ? 100 : newPosition;
					if (position[count] == 100) break;
					
				}
				else
				{
					position[count] = (newPosition >= 100) ? 100 : newPosition;
				    if (position[count] == 100) break;
				}
				count = 0;
			}
			else
			{
				int newPosition = position[count] + dieValue;
				int isSnakePosition = get<0>(dicPair[newPosition]);
				if (isSnakePosition > 0)
				{
					newPosition =  get<1>(dicPair[newPosition]);
					position[count] = (newPosition >= 100) ? 100 : newPosition;
					if (position[count] == 100) break;
					
				}
				else
				{
					position[count] = (newPosition >= 100) ? 100 : newPosition;
					if (position[count] == 100) break;
					
				}
				count++;
			}
		}
		// READ THE VALUES THAT WAS NOT READ, BECAUSE A PLAYER WON THE GAME
		for (int i = n_die; i > 0; i--)
		{
			int temp;
			cin >>  temp;
		}

		for (int i = 0; i < position.size(); i++)
		{
			cout << "Position of player " << (i + 1) << " is " << position[i] << ".\n";

		}	

	}

	return 0;
}