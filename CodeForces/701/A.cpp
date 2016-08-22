#include<bits/stdc++.h>
using namespace std;

int n, *arr, sum;
int *orig;

int i_of(int num, bool *arrUsed){
    for(int i = 0; i < n; i++ )
        if(num==orig[i] && !arrUsed[i]){
            arrUsed[i] = true;
            return i+1;
        }
}

int main(){

    cin >> n;
    arr = new int[n];
    orig =  new int[n];
    bool used[n+200] = {false};
    fill_n(used, false, n);
    sum = 0;
    for(int i = 0; i < n ; i++)
    {
        cin >> arr[i];
        sum += arr[i];
    }
    sum/=n/2;
    for(int i = 0; i < n ; i++){
        orig[i] = arr[i];
    }

    sort(arr, arr+n);
    for(int i = 0; i < n/2 ; i++){
        cout << i_of(arr[i],used) << " " << i_of(arr[n-1-i],used) << endl;
    }
    return 0;
}
