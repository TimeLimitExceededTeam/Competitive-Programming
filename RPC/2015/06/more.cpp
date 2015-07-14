#include<bits/stdc++.h>
using namespace std;
int current_pos = 0;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	string x;
	while(cin>>x){
		if(x=="11"){
			cout << 0 << endl;
			continue;
		}
		if(x=="0"){
			cout << 1 << endl;
			continue;
		}
		if(x=="1"){
			cout << "110" << endl;
			continue;
		}
        current_pos = x.size()-2;

        bool flag = true;
        while(flag){
			if(current_pos<0){
				x[0] = '0';
				string t = "11";
				t += x;
				x = t;
				flag = false;
			}
			if(x[current_pos] == '0' & x[current_pos+1]=='1' & flag){
				x[current_pos] = '1';
				x[current_pos+1]='0';
				current_pos-=2;
			}
			if(x[current_pos] == '1' & x[current_pos+1]=='0' & flag){
				x[current_pos+1] = '1';
				flag = false;
			}
			if(x[current_pos] == '1' & x[current_pos+1]=='1' & flag){
				x[current_pos] = '0';
				x[current_pos+1]='0';
				flag = false;
			}
			if(x[current_pos] == '0' & x[current_pos+1]=='0' & flag){
				x[current_pos+1]='1';
				flag = false;
			}
        }
        flag = true;
        current_pos = 0;

        while(flag){
			if(x[current_pos]=='0'){
				x.erase(0,1);
			}else{
				flag = false;
			}
        }

		cout << x << endl;
	}
	return 0;
}

/*
10
11
00
01
*/
