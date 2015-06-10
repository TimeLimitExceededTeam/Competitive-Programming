#include<bits/stdc++.h>
using namespace std;
int nums[220][220];
int sum[220][220];
int n;
int m;
int road[220];
struct S{
    int cost, row;
    S(){}
    S(int i, int costs){
        cost = costs;
        row = i;
    }
    bool operator < (const S a) const {
     if(this->cost!=a.cost)
        return this->cost < a.cost;
     return this->row < a.row;
    }
};
int minNum(int a, int b, int c) {
    if (a <= b && a <= c)
        return a;
    if (b <= a && b <= c)
        return b;
    if (c <= a && c <= b)
        return c;
    return c;
}
int acum(int i, int j) {
    if (j == 0){
        return nums[i][j];}
    if (sum[i][j] != INT_MIN){
        return sum[i][j];}
    int j1 = j - 1;
    int i1 = ((i - 1 + m)%m);
    int i2 = ((i + 1) % m);

    int a = acum(i, j1);
    int b = acum(i1, j1);
    int c = acum(i2, j1);

    int valMin = minNum(a, b, c);

    sum[i][j] = valMin + nums[i][j];
    return sum[i][j];
}
S arre[3];
void traceRoute(int i, int j) {
    road[j] = i;
    if (j - 1 < 0)
        return;
    int j1 = j - 1;
    int i1 = ((i - 1 + m) % m);
    int i2 = ((i + 1) % m);


    int b = acum(i1, j1);
    int a = acum(i, j1);
    int c = acum(i2, j1);
    arre[0] = S(i,a);
    arre[1] = S(i1,b);
    arre[2] = S(i2,c);

    sort(arre, arre+3);

    int valMin = minNum(a, b, c);
    traceRoute(arre[0].row,j1);
}

int main(){
    //freopen("matriz.inp","r",stdin);
    //freopen("matriz.out","w",stdout);
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    int var;
    while(cin >> m >> n){
        for(int i = 0; i < m; i++){
             for(int j = 0; j < n; j++){
                    cin >> var;
                    nums[i][n-1-j] = var;
                    sum[i][j]= INT_MIN;
             }
             sum[i][0] = nums[i][0];
         }
         int minVal = INT_MAX;
         for (int i = m - 1; i >= 0; i--) {
            int temp = acum(i, n - 1);
            if (temp <= minVal) {
                minVal = temp;
                road[n - 1] = i;
            }
         }
        traceRoute(road[n - 1], n - 1);

        for(int i = 0; i < n-1 ; i++){
            cout << road[n-1-i]+1 << " ";
        }
        cout << road[0]+1<< endl;
        cout << minVal << endl;
    }

    return 0;
}
