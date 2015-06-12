#include<bits/stdc++.h>
using namespace std;
int n;
int couples[1010];

int calcOut(){
    int val = 0;
    for(int i = 0; i < n; i+=2){

        val += couples[i+1]-couples[i];
    }
    return val;
}
int calcIn(){
    int val = 0;
    for(int i = 0; i < n; i += 2){
        int a = couples[i+1], b = couples[i+2];
        val  += b-a;

    }
    return val;
}
int main(){
    freopen("input", "r",stdin);
    while(cin>>n){
        for(int i = 0; i < n; i++){
            cin>>couples[i];
        }
        sort(couples, couples+n);
        couples[n] = couples[0]+24;
        int res = min(calcOut(), calcIn());
        cout << res << endl;
    }
}
