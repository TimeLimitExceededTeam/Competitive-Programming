#include<bits/stdc++.h>
using namespace std;

int main(){
    //freopen("input","r",stdin);
    //freopen("output","w",stdout);
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    bool bit;
    while(cin >> bit){
        bool bits[5];
        bits[0] = bit;
        for(int i = 1 ; i < 5; i++){
            cin >> bits[i];
        }
        bool flag = true;
        for(int i = 0; i < 5; i++){
            cin >> bit;
            if(flag){
                flag = bit != bits[i];
            }
        }

        if(flag)
            cout << "Y" << endl;
        else
            cout << "N" << endl;
    }
    return 0;
}
