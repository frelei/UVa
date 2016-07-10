// https://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=3678
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <stack>
#include <map>
#include <string>

using namespace std;


int main()
{
	int T, size, low, high, cases, price;
  string key;
  map<string,pair<int,int> > database;

int count = 0;
  cin >> T;
  for(int i = 0; i < T; i++)
  {
    cin >> size;
    database.clear();
    for(int j = 0; j<size; j++)
    {
      cin >> key;
      cin >> low;
      cin >> high;
      database[key] = make_pair(low, high);
    }

    // END READING
    cin >> cases;

    for(int j=0; j < cases; j++)
    {
      cin >> price;
      vector<string> car;
      car.push_back("enter");
      car.clear();
      for(auto const &val : database)
      {
        if (price >= val.second.first && price <= val.second.second)
        {
         if ( !(find(car.begin(), car.end(), val.first) != car.end()) )
              car.push_back(val.first);
        }
      }

      //CHECK RESPONSE
      if (car.size() > 1 || car.size() == 0)
      {
       cout << "UNDETERMINED" << endl;
      }
      else
      {
      cout  << car[0] << endl;

      }
    }
    if (i != T - 1)
      cout << endl;
  }
	return 0;
}
