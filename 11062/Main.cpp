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


vector<string> split(string str, char delimiter) 
{
  vector<string> internal;
  stringstream ss(str); 
  string tok;
  
  while(getline(ss, tok, delimiter)) 
  {
    internal.push_back(tok);
  }
  return internal;
}

// string removeNoChar(string str)
// {
// 	str.erase(remove_if(str.begin(), str.end(), [](char c) { return !isalpha(c); } ), str.end());
// 	return str;
// }

void print(const std::string& item)
{
    std::cout << item << std::endl;
}


// bool invalidChar (char c) 
// {  
//     return !(c >= 0 && c < 128);   
// } 
// void stripUnicode(string &str) 
// { 
//     str.erase(remove_if(str.begin(),str.end(), invalidChar), str.end());  
// }


char validate(char c){
	if (isalpha(c) || c == '-')
	{
		return c;
	}
	else
	{
		return '';
	}
	
}

int main()
{

	string word;
	set<string> dictionary;
	vector<string> temp;

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
				transform(hyfenWord.begin(), hyfenWord.end(), hyfenWord.begin(), ::tolower);
				transform(hyfenWord.begin(), hyfenWord.end(), hyfenWord.begin(), ::validate);

				temp.clear();
				dictionary.insert(hyfenWord);
			}
			else
			{
				transform(word.begin(), word.end(), word.begin(), ::tolower);
				transform(word.begin(), word.end(), word.begin(), ::validate);

				dictionary.insert(word);				
			}
		}
	}

	for_each(dictionary.begin(), dictionary.end(), &print);	

	return 0;
}
