#include<bits/stdc++.h>
using namespace std;

int main(){
	int n, k, barrier;
	cin >> n >> k;
	int c = 0;
	int arr[n+2];

    for(int i = 1; i <= n; i++){
		cin >> arr[i];
		if(i==k)
			barrier = arr[i];
	}

	for(int i = 1; i <= n; i++){
		if(arr[i]>0 and arr[i]>=barrier)
			c++;
	}
	cout << c << endl;
	return 0;
}
