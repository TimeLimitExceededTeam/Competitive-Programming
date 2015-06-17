#include<bits/stdc++.h>
using namespace std;

struct SegmentTree{
    int fr, to;
    int prod;
    SegmentTree *l, *r;
    SegmentTree(int arr[], int a, int b){
        fr = a; to = b;
        if(a==b){
            l = r = NULL;
            if (arr[a]<0)
				prod = -1;
			if(arr[a]==0)
				prod = 0;
			if(arr[a]>0)
				prod = 1;
        }else{
            l=new SegmentTree (arr,a,(a+b)/2);
            r=new SegmentTree (arr,(a+b)/2+1,b);
            prod = l->prod * r-> prod;
        }
    }
    void update(int x, int y){
        if(fr==x && to == x){
            if(y < 0)
				prod = -1;
			if(y==0)
				prod = 0;
			if(y > 0)
				prod = 1;
            return;
        }
        if(x<=l->to)
            l->update(x,y);
        else
            r->update(x,y);
        prod = l->prod * r->prod;
    }
    int query(int i, int j){
        if(fr==i && to == j)
            return prod;
        if(j<=l->to)
            return l->query(i,j);
        if(i>=r->fr)
            return r->query(i,j);
        return l->query(i,l->to) * r->query(r->fr,j);
    }
};

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int n, k;
    while(cin >> n >> k){
        int arr[n+1];
        arr[0]=1;
        for(int i = 0; i < n; i++){
            cin >> arr[i+1];
        }
        SegmentTree st = SegmentTree(arr,0,n+1);


        for(int i = 0; i < k; i++){
            string var;
            int _i, _j;
            cin >> var;
            cin >> _i >> _j;
            if(var == "C")
                st.update(_i,_j);
            else {
                _i = st.query(_i,_j);
                if(_i < 0)
                    cout << "-";
                else if(_i==0)
                    cout << "0";
                else
                    cout << "+";
            }
        }
        cout << endl;
    }
}
