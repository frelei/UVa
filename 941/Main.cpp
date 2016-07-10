// https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=11&page=show_problem&problem=882

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <string>

using namespace std;

long long factorial[21];
void computeFactorial()
{
   factorial[0] = 1;
   for(int i = 1; i < 21; ++i)
      factorial[i] = factorial[i - 1] * i;
}


void swap(char &x, char &y)
{
    char temp;
    temp = x;
    x = y;
    y = temp;
}

vector<string> val;
vector<string> permute(string s, int i, int n)
{
    int j;
    if (i == n)
        val.push_back(s);
    else
    {
        for (j = i; j < s.length(); j++)
        {
            swap(s[i],s[j]);
            permute(s, i + 1, n);
            swap(s[i],s[j]);
        }
    }
    return val;
}

string permutation(string &s, long long index)
{
  string result(s);

   for(int i = 0; i < s.size(); ++i)
   {
      sort(result.begin() + i, result.end());
      if (index == 0)
         break;
      int charPos = i + index / factorial[s.size() - i - 1];
      swap(result[i], result[charPos]);
      index = index % factorial[s.size() - i - 1];
   }

   return result;
}

int main()
{
	int N;
  long long index;
	string a;
	cin >> N;

  computeFactorial();
	for(int i = 0; i < N; i++)
	{
		cin >> a >> index;
		a = permutation(a, index);
		cout << a << endl;
	}
	return 0;
}
