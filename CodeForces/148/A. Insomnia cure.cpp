#include<bits/stdc++.h>
using namespace std;

int *arr;

int main(){
	int k,l,m,n,d;
	cin >> k >> l >> m >> n >> d;

	int data[4] = {k,l,m,n};
	int c;
	arr = new int[d+10];
	fill_n(arr,d+2,0);

	for(int i = 0; i < 4 ; i++){
		c = data[i];
		while(c<=d){
			arr[c]=1;
			c += data[i];
		}
	}
	c = 0;
	for(int i = 1; i <= d; i++)
		if(arr[i]>0)
			c++;

	cout << c << endl;


	return 0;
}
