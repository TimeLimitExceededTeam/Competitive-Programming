#include<bits/stdc++.h>
using namespace std;

int main(){
    string word;
    cin >> word;
	char arr[200];
	int c = 0;
	for(int i  = 0; i < word.size(); i++){
		if(word[i]>='A' and word[i] <= 'Z')
			word[i] = word[i]+32;
		if(word[i]!= 'a' and word[i]!= 'e' and word[i]!= 'i' and word[i]!= 'o' and word[i]!= 'u' and word[i]!= 'y'){
			arr[c] = '.';
			c++;
			arr[c] = word[i];
			c++;
		}
	}
	for(int i = 0 ; i < c ; i++)cout << arr[i];

	cout << endl;
	return 0;
}
