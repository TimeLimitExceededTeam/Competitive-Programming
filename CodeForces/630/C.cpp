#include <bits/stdc++.h>
using namespace std;
int main() {	long long c = 0;
	int n;
	cin >> n;
	
	for(int i = 1; i <= n; i++){
		c += pow(2,i);
	}
	cout << c << endl;

	return 0;
}
