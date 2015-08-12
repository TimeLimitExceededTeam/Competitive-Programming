#include<bits/stdc++.h>
using namespace std;

int main(){
	int cases, n;
	cin >> cases;
	while(cases--){
		cin >> n;
		int nums[n+10], counter = 0;
		string str;
		int num;
        for(int i = 1; i <= n; i++){
			cin >> str;
			if(str == "LEFT"){
				counter--;
				nums[i] = -1;
				continue;
			}
			if(str == "RIGHT"){
				counter++;
				nums[i] = 1;
				continue;
			}
			cin >> str;
			cin >> num;
			nums[i] = nums[num];
			counter += nums[i];
        }
        cout << counter << endl;
	}
	return 0;
}
