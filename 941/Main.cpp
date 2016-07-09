// https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=11&page=show_problem&problem=882

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <stack>

using namespace std;

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

vector<string> permutation(string &s, int size)
{
	int k = 0;
	vector<string> permut;
	do
   {
   	  permut.push_back(s);
   	  if (k == size) break;
   	  k++;
   }while(std::next_permutation(s.begin(),s.end()));

   return permut;
}

int main()
{
	int N, index;
	string a;
	cin >> N;

	for(int i = 0; i < N; i++)
	{
		cin >> a >> index;
		val.clear();
		vector<string> values = permutation(a, index); //permute(a, 0, a.length() - 1);
		cout << values[index] << endl;
	}
	return 0;
}