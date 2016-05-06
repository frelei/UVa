//https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=652&page=show_problem&problem=1071

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <stack>
#include <queue>
#include <vector>
#include <sstream>

using namespace std;
 
int main ()
{
    int input;
    int MAX_OBJECT = 1000;
    int MAX_WEIGHT = 30;

 	cin >> input;
    while ( input > 0 ) 
    {
        int values [MAX_OBJECT + 1];
        int weight [MAX_OBJECT + 1];
 
 		// Fill array
 		int objects;
        cin >> objects;
        for ( int i = 0; i < objects; i++ )
        {
        	cin >> values[i];
        	cin >> weight[i];
        }
 
 		// Packing
        int pack [MAX_WEIGHT + 5];
        for (int i = 0; i < MAX_WEIGHT + 5; i++)
			pack[i] = 0;

        for ( int j = 0; j < objects; j++ ) 
        {
            for ( int i = MAX_WEIGHT; i >= 0; i-- ) 
            {
                if ( weight[j] <= i && pack[i] < pack[i - weight[j]] + values[j] )
                    pack[i] = pack[i - weight[j]] + values[j];
            }
        }
 
 		// Calc Pirce
        int group;
 		cin >> group;
        int price = 0;
 
        while ( group > 0 ) 
        {
            int volume;
            cin >> volume;
            price += pack[volume];
            group--;
        }

	 	input--;
	 	cout << price << endl;
    }
 
    return 0;
}