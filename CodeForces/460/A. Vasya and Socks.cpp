#include<bits/stdc++.h>
using namespace std;

int main(){

	int n,m;
	cin >> n >> m;
	int i = 1;
	int days = 0;
	while(n>0){
		n--;
		days++;
		if(i==m){
			n++;
			i = 1;
		}else{
			i++;
		}
	}
	cout << days << endl;
	return 0;
}
