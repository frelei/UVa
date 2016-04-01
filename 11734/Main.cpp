//https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=628&page=show_problem&problem=3503

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <stack>
#include <stdlib.h>

using namespace std;

string removespace(string line) {
 while (1){
   int letter = line.find(' ');
   if (letter == -1 ){
     break;
   }
   line = line.erase(letter, 1);
 }
 return line;
}


int main()
{
	int t;
	string j;
	string c;
	int counter = 1;
	bool containSpace;

	cin >> t;
	getline(cin,c);

	for(int i = 0; i < t; i++)
	{
		getline(cin,c);
		getline(cin,j);

		if (!j.compare(c))
		{
			cout << "Case "<< counter << ": " << "Yes" << endl;
			counter++;
			continue;
		}

		containSpace = false;
		 while (true)
		 {
  			 int letter = c.find(' ');
   			 if (letter == -1 )
   			 {
   			   break;
   			 }
  			 c = c.erase(letter, 1);
  			 containSpace = true;
 		}
    	
    	if (containSpace)
    	{	

    		if (!j.compare(c))
    		{
    			cout << "Case "<< counter << ": " << "Output Format Error" << endl;
    		}
    		else
    		{
    			cout << "Case "<< counter << ": " << "Wrong Answer" << endl; 
    		}
    	}
    	else
		{
			if (!j.compare(c))
    		{
    			cout << "Case "<< counter << ": " << "YES" << endl;
    		}
    		else
    		{
    			cout << "Case "<< counter << ": " << "Wrong Answer" << endl; 
    		}
		}
		counter++;
    }

	return 0;
}