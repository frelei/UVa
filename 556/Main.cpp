#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;


enum DIRECTION { WEST = 1, NORTH, EAST, SOUTH };


DIRECTION findDirection(int sizeX, int sizeY, vector<vector<char> > maze, int positionX, int positionY, DIRECTION direction)
{
	if (direction == EAST)
	{
		if (positionX - 1 < sizeX &&  positionX - 1 >= 0 && maze[positionX - 1][positionY] == '0')
		{
			return NORTH;
		}
		if (positionY - 1 < sizeY && positionY - 1 >= 0 && maze[positionX][positionY - 1] == '0')
		{
			return EAST;
		}
		else
		{
			return findDirection(sizeX, sizeY, maze, positionX, positionY, SOUTH);
		}
	}
	else if (direction == NORTH)
	{
		if (positionY + 1 < sizeY && positionY + 1 >= 0 && maze[positionX][positionY + 1] == '0')
		{
			return WEST;
		}
		if (positionX - 1 < sizeX && positionX - 1 >= 0 && maze[positionX - 1][positionY] == '0')
		{
			return NORTH;
		}
		else
		{
			return findDirection(sizeX, sizeY, maze, positionX, positionY, EAST);
		}

	}
	else if (direction == SOUTH)
	{
		if (positionY - 1 < sizeY && positionY - 1 >= 0 &&  maze[positionX][positionY - 1] == '0')
		{
			return EAST;
		}
		if (positionX + 1 < sizeX && positionX + 1 >= 0  && maze[positionX + 1][positionY] == '0')
		{
			return SOUTH;
		}
		else
		{
			return findDirection(sizeX, sizeY, maze, positionX, positionY, WEST);
		}

	}
	else
	{
			if (positionX + 1 < sizeX &&  positionX + 1 >= 0 && maze[positionX + 1][positionY] == '0')
			{			
				return SOUTH;
			}
			else if (positionY + 1 < sizeY && positionY + 1 >= 0 && maze[positionX][positionY + 1] == '0')
			{				
				return WEST;
			}
			else
			{			
				return findDirection(sizeX, sizeY, maze, positionX, positionY, NORTH);

			}
	}

}


void performMoviment(int *robotX, int *robotY, DIRECTION direction)
{
	switch(direction)
	{
		case NORTH: *robotX -= 1;   break;
		case SOUTH: *robotX += 1;  break;
		case WEST: *robotY += 1;  break;
		case EAST: *robotY -= 1;  break;
	}
}


int main(){
	while(true)
	{

	// VARIABLES
	int b, w;

	// READ MATRIX VALUES
	cin >> b >> w;

	// End Program
	if (b == 0 && w == 0) break;


	int visited[b][w];
	vector< vector<char> > maze(b, vector<char>(w));

	int startX = b - 1;
	int startY = 0;

	int robotX = startX;
	int robotY = startY;
	DIRECTION direction = WEST;

	for(int i = 0; i < b; i++){
		for (int j = 0; j < w; j++){

			cin >> maze[i][j];
			if (maze[i][j] == '0')
				visited[i][j] = 0;
			else
				visited[i][j] = -1;
			//cout << maze[i][j] << " ";
		}
		//cout << "\n";
	}
	//cin >> endfile >> endfile;

	int count = 0;
	
	while(true)
	{

		direction = findDirection(b, w, maze, robotX, robotY, direction);
		performMoviment(&robotX, &robotY, direction);
		visited[robotX][robotY] += 1; 
		if (robotX == startX && robotY == startY) break;
	}


// FIND LAST RESULT
	int result[5];
	int countVals = 0;
	for (int val = 0; val < 5; val++)
	{
		for(int i = 0; i < b; i++)
		{
			for(int j = 0; j < w; j++)
			{
				if (visited[i][j] == val)
				{
					countVals += 1;
				}
			}
		}
		result[val] = countVals;
		countVals = 0;
	}

	for (int val = 0; val < 5; val++)
	{
	   //cout << result[val] << " ";
	   cout << setfill(' ') << setw(3) << result[val];
	}
	cout << endl;
}

	return 0;
}