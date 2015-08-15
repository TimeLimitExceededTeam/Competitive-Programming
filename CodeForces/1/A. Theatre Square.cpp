#include<bits/stdc++.h>
using namespace std;

int main(){
	long long a, b, c;

	cin >> a >> b >> c;
	a = a%c > 0? a/c+1: a/c;
	b = b%c > 0? b/c+1: b/c;

	cout << a*b << endl;
	return 0;
}
