#include<bits/stdc++.h>
using namespace std;

int main(){
	int c = 0,n;
	cin >> n;
	int arr[6]= {0,0,0,0,0,0};
	for(int i = 0; i < n ; i++){
		int var = 0;
		cin >> var;
		arr[var]+=1;
	}
	c+= arr[4];
	c+= arr[3];
	arr[1] -= arr[3];
	c+= arr[2]/2;
	c+= arr[2]%2;
	//cout << "arr[2]%2: " << arr[2]%2 << endl;

	arr[1]-=(arr[2]%2)*2;
	if(arr[1]>	0){
		c += arr[1]/4;
		c += arr[1]%4>0?1:0;
	}
	cout << c << endl;
	return 0;
}
