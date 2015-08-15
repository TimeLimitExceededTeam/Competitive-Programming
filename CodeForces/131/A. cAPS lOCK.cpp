#include <bits/stdc++.h>
using namespace std;

bool check(string word){
	bool flag = true;
	for(int i = 1; i < word.size() and flag; i++){
        flag = flag && (word[i] >= 'A') && (word[i] <= 'Z');
	}
	return flag;
}

char change(char c){
	if(c == 'Z')
		return 'z';
	if(c>='A' and c >= 'Z')
		return c-32;
	return c +32;
}

string apply(string word){

	for(int i = 0; i < word.size(); i++)
		word[i] = change(word[i]);
	return word;
}

int main(){
	string word;
	while(cin >> word){
		if(check(word)){
			word = apply(word);
		}
		cout << word << endl;
    }
	return 0;
}
