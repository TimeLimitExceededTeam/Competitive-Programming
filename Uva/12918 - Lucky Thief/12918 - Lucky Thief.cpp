#include<bits/stdc++.h>
using namespace std;
long long sum(long x){
	return x*(x+1)/2;
}
int main(){
	int n,keys,houses;
	cin >> n;
	while(n--){
		cin >> keys >> houses;
        if(keys == 1 and houses == 1){
			cout << "1" << endl;
            continue;
        }
        if(keys==1){
			cout << houses - 1 << endl;
			continue;
        }

		cout << sum(houses-1) - sum(houses-keys-1) << endl;

	}
	return 0;
}
