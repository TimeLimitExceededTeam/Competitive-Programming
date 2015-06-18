#include<bits/stdc++.h>
using namespace std;
int _SIZE = 10005;
int arr[10005], fil[20];
int n, k;
void addTo(int x, int val){
    for(int i= x; i > 0; i -= (i&(-i))){
        arr[i] += val;
    }
}
int consultar( int x){
    int s = 0;
    for(int i = x; i <= n ; i+=(i&(-i))){
        s+= arr[i];
    }
    return s;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t, r = -1, p = 0 ;
    cin >> n >> k;
    for(int i = 0; i < k; i++){
        for(int j = 0; j < n; j++){
            cin >> t;
            fil[i]+= consultar(t);
            addTo(t,1);
        }
        for(int j = 0; j < _SIZE; j++)arr[j]=0;
        if(fil[i]>r){
            r = fil[i];
            p = i;
        }
    }
    cout << p +1 << endl;
    return 0;
}
