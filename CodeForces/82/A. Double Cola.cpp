#include<bits/stdc++.h>
using namespace std;

int main(){
	int n;
	string names[5]  ={"Sheldon", "Leonard", "Penny", "Rajesh", "Howard"};
	cin >> n;

	int peoples = 5;
	long long limit = 5;
	int c = 1;
	while(n>limit){
		c++;
		n-=limit;
		limit*=2;
	}

	for(int i = 1; i<=5; i++){
		if(n-1<(limit/5)*i){
			cout << names[i-1] << endl;
			return 0;
		}
	}
	return 0;
}
