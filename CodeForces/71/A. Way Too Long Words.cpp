#include<bits/stdc++.h>
using namespace std;

int main(){
	string word;
	int n;

	cin >> n;
	while(n--){
		cin >> word;
		int c = word.size();
		if(c <= 10){
			cout << word << endl;
			continue;
		}
		cout << word[0]<< c-2 << word[c-1] << endl;
	}

	return 0;
}
