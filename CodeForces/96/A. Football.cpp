#include<bits/stdc++.h>
using namespace std;

int main(){
	string word;
	cin >> word;
	char c = word[0];
    int counter = 1;
    int maxC = 0;
    for(int i = 1; i < word.size(); i++){
		if(word[i] == c){
			counter++;
			continue;
		}else{
			maxC = max(counter, maxC);
			counter = 1;
			c = word[i];
		}
    }
	maxC = max(counter, maxC);
    if(maxC<7)
		cout << "NO" <<endl;
	else
		cout << "YES" << endl;

	return 0;
}
