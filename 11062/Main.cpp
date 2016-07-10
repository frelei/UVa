/// https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=22&page=show_problem&problem=2003
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <string>
#include <sstream>

using namespace std;

char validate(char c)
{
	char ch = tolower(c);

	if ( (ch >= 'a' && ch <= 'z') || (ch == '-') || (ch == ' ') || (ch == '\n'))
	{
		return ch;
	}
	else
	{
		return ' ';
	}
}

vector<string> split(const string &s, char delim) {
    stringstream ss(s);
    string item;
    vector<string> tokens;
    while (getline(ss, item, delim)) {
        tokens.push_back(item);
    }
    return tokens;
}


int main()
{
	string word;
	set<string> dictionary;
	vector<string> temp;
	string line;
	string text;

	// READ INPUT
	while(cin >> word)
	{
		// CHECK LAST CHAR
		if(word[word.size() - 1] == '-')
		{
			string s = word.substr(0, word.size()-1);
			transform(s.begin(), s.end(), s.begin(), ::validate);
			temp.push_back(s);
		}
		else
		{

			if (temp.size() > 0)
			{
				string hyfenWord;
				for (int i = 0; i < temp.size(); i++)
				{
					hyfenWord += temp[i];
				}

				hyfenWord += word;

				transform(hyfenWord.begin(), hyfenWord.end(), hyfenWord.begin(), ::validate);

				size_t found = hyfenWord.find_first_of("--");
				size_t found2 = hyfenWord.find_last_of("--");
				if (found != string::npos && found2 != string::npos && found + 2 == found2)
				{
					string s1 = hyfenWord.substr(0, found + 1);
					string s2 = hyfenWord.substr(found2, hyfenWord.size());
					if (!s1.empty())
					{
						s1.erase(remove_if(s1.begin(), s1.end(), ::isspace), s1.end());
						dictionary.insert(s1);
					}
					if (!s2.empty())
					{
						s2.erase(remove_if(s2.begin(), s2.end(), ::isspace), s2.end());
						dictionary.insert(s2);
					}
				}
				else
				{
					if (!hyfenWord.empty())
					{
						hyfenWord.erase(remove_if(hyfenWord.begin(), hyfenWord.end(), ::isspace), hyfenWord.end());
						dictionary.insert(hyfenWord);
					}
				}

				temp.clear();
			}
			else
			{
				transform(word.begin(), word.end(), word.begin(), ::validate);
				vector<string> c = split(word, ' ');
				if (c.size() > 1)
				{
					for (int i = 0; i < c.size(); i++)
					{
						string k = c[i];
						k.erase(remove_if(k.begin(), k.end(), ::isspace), k.end());
						if (!k.empty())
						{
							dictionary.insert(k);
						}
					}
				}
				else
				{
					word.erase(remove_if(word.begin(), word.end(), ::isspace), word.end());
					dictionary.insert(word);
				}
			}
		}
	}

	for(set<string>::iterator it = dictionary.begin();it != dictionary.end(); it++)
	{
		cout << *it << endl;
	}
	cout << endl;
	return 0;
}
