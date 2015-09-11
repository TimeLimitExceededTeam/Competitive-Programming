#include <bits/stdc++.h>

using namespace std;

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);
	int n;
	cin >> n;
	for(int i=0;i<n;i++){
        string line;
		cin>>line;

		int lim=1;
		int rev;
		for(int j=0;j<line.length();j++){
			rev=(j%lim);
			if(line[j]!=line[rev]){
				lim=j+1;
			}
		}
		if(line.length()%lim==0){
			cout<<lim<<"\n";
		}else{
			cout<<line.length()<<"\n";
		}
	}
	return 0;
}
