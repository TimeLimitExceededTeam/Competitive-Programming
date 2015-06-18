#include<bits/stdc++.h>
using namespace std;

int main(){
    int test,a,b,alo= 1;
    cin >> test;
    while(test--){
        cin>>a>>b;
        int res = 0;
        for(int i = a; i <=b; i++)
            res = i%2==0?res:res+i;
        cout << "Case " << alo++<< ": " << res << endl;
    }
    return 0;
}
