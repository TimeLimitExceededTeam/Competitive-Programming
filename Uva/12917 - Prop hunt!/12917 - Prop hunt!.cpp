#include<bits/stdc++.h>
using namespace std;

int main(){
	int p,h,o;
	string props = "Props win!";
	string hunts = "Hunters win!";

	while(cin >> p >> h >> o){
        o = o-p;
        if(h-o>0){
			cout << hunts << endl;
        }else{
			cout << props << endl;
        }
	}
	return 0;
}
