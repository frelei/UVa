/// https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=7&page=show_problem&problem=503

#include <iostream>
#include <vector>
#import <algorithm>

using namespace std;

int coins[105] = {0};

int main(){
  int T, num_coins = 0, sum = 0, average;
  cin >> T;

  for(int i = 0; i < T; i++)
  {
    cin >> num_coins;

    // CLEAR ARRAY
    for(int i = 0; i < 105; i++)
      coins[i] = 0;

    // SUM ALL COIN VALUES
    sum = 0;
    for( int i = 1 ; i <= num_coins ; ++i )
    {
      cin >> coins[i];
      sum += coins[i];
    }

    // COMPUTE
    average = sum / 2;
    vector<int> result( average + 10, 0 );
    for( int i = 1 ; i <= num_coins ; ++i )
    {
      for( int j = average ; j >= coins[i] ; --j )
      {
        result[j] = max( result[j], result[j-coins[i]] + coins[i] );
      }
    }

    cout << sum - 2 * result[average]  << endl;
  }

  return 0;
}
