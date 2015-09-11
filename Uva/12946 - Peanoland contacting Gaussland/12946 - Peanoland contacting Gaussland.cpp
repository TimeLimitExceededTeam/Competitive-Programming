/*
	Author: Aldo Rincon Mora (@HatsuMora)
 	12946 - Peanoland contacting Gaussland
	Uva Submission ID: 16083456 Accepted
*/

#include<bits/stdc++.h>
using namespace std;
unsigned int n;
int mat[40][41];
int r=0, c=0;
void init(){
    mat[0][0] = 1;
    mat[1][0] = 1;
    mat[1][1] = 1;
    bool sg = true;
    for(int i = 2; i <= 33 ; i++){
        mat[i][0]=1;
        for(int j = 1; j < i+1; j++){
            mat[i][j]=mat[i-1][j-1]+mat[i-1][j];
        }
        mat[i][i] = 1;
    }
}

void solve(int i){
    int I = i;
    int flag = 1;
    for(int j = 0; j <= I; j++){
        if(i%4==0){
            r += mat[I][j]*flag;
        }else if(i%4==1){
            c += mat[I][j]*flag;
        }else if(i%4==2){
            r -= mat[I][j]*flag;
        }else if(i%4==3){
            c -=  mat[I][j]*flag;
        }
        flag *= -1;
        i = (i-1+4)%4;
    }
}

int main(){
    init();
    while(cin >> n){
        r = 0;
        c = 0;
        if(n<=1){
            cout << n << " " << 0 << endl;
            continue;
        }
        for(int i = 0; i<31; i++){
            if((1<<i & n)>0){
                solve(i);
            }
        }
        cout << r << " " << c << endl;
    }
    return 0;
}
