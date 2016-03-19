#include <iostream>
#include <string>
#include <algorithm>
#include <set>
#include <sstream>

using namespace std;


// DONT WORK ):
// string match_word_terminated_by_hiphen(string the_word){

// 	string next_word;
// 	cin >> next_word;
// 	//cout << the_word << endl;
// 	if (the_word[the_word.size()-1] == '-'){
// 		string the_word_whithout_hyphen = the_word.substr(0, the_word.size()-1);
// 		return match_word_terminated_by_hiphen(the_word_whithout_hyphen + next_word);
// 	}
// 	else
// 		return the_word;

// }

char process(char c){
	char ch = tolower(c);

	if ( (ch <= 'z' && ch >= 'a') || (ch == '-') || (ch == ' ') || (ch == '\n'))
		return ch;
	else
		return ' ';
}


int main(){

	string c;
	set<string> dictionary;
	string line;
	string the_corpus = "";
	while (getline(cin, line)){
		the_corpus += (line+"\n");
	}

	transform(the_corpus.begin(), the_corpus.end(), the_corpus.begin(), process);

	istringstream stream(the_corpus);

	while(stream >> c){

		//preprocess

		string the_word = c;
		string new_word = "";
		while ((the_word[the_word.size()-1] == '-')){

			if ((the_word[0] == '-') && (the_word.size() == 1))
				break;

			string the_word_whithout_hyphen = the_word.substr(0, the_word.size()-1);
			new_word += the_word_whithout_hyphen;
			stream >> the_word;
		}
	
		if (!the_word.compare("-")){
			continue;
		}
		else if (the_word[0] == '-'){
			dictionary.insert(new_word+"-");
			dictionary.insert(the_word);

		} else {
			new_word += the_word;
			dictionary.insert(new_word);
		}
		
	}

		for(set<string>::iterator it = dictionary.begin();it != dictionary.end();it++)
			cout << *it << endl;

	return 0;
}