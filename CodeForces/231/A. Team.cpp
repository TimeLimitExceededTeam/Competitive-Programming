#include<bits/stdc++.h>
using namespace std;

int main(){
	int n,a, r=0;
	int c = 0;
	cin >> n;
	while(n--){
		r = 0;
		cin >> a;
		r += a;
		cin >> a;
		r += a;
		cin >> a;
		r += a;
		if(r>= 2)
			c++;
	}
	cout << c << endl;
}
