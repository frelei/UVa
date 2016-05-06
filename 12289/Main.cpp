/// https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=607&page=show_problem&problem=3710

#include <iostream>
#include <vector>
#include <vector>
#include <queue>
#include <set>
#include <stack>
#include <string.h>

using namespace std;

int main(){

	int T; 
	cin >> T;
 	int MAX_WORD_SIZE = 5;

    while ( T > 0 )
    {
        char word[MAX_WORD_SIZE + 1]; 
        cin >> word;
 
        if ( strlen (word) == MAX_WORD_SIZE )
        {
         cout << 3 << endl;
     	}
        else
        {
            int count = 0;
            if ( word [0] == 't' ) 
            	count++;
            if ( word [1] == 'w' ) 
            	count++;
            if ( word [2] == 'o' ) 
            	count++;
 
            if ( count >= 2 ) 
            	cout << "2" << endl;
            else 
            	cout << "1" << endl;
        }
        T--;
    }

	return 0;
}