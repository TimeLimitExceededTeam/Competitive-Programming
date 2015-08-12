	#include<bits/stdc++.h>

	int const LIMIT = 1000001;
	using namespace std;

	struct SegmentTree{
		int fr,to, _max;
		SegmentTree *l,*r;
		SegmentTree(int arr[], int fr, int to){
			this->fr = fr;
			this->to = to;
			if(fr == to){
				l = r = NULL;
				_max = arr[to];
			}else{
				l = new SegmentTree(arr,fr,(to+fr)/2);
				r = new SegmentTree(arr,((to+fr)/2)+1,to);
				_max  = max(l->_max, r->_max);
			}
		}

		int maxIJ(int i, int j){
			if(fr==i and to == j)
				return _max;
			if(j <= l->to)
				return l->maxIJ(i,j);
			if(i >= r->fr)
				return r->maxIJ(i,j);
			return max(maxIJ(i, l->to),maxIJ(r->fr,j));
		}
	};

	int arr[1000100];

	int calc(unsigned int n, int c){
		if( n == 1)
			return c +1;
		if( n < LIMIT-1 and arr[n] > 0)
			return arr[n] + c ;
		int m;
		if(n%2==1)
			m = 3*n + 1;
		else
			m = n / 2;
		m = calc(m,c);
		if(n<LIMIT-1)
			arr[n]=m+1;
		return m+1;
	}
	void ensure(){
		for(int i = 1; i < LIMIT ; i++)
			if(arr[i] == 0){
				arr[i] = calc(i,0);
			}
	}

	int main(){
		cin.tie(0);
		ios_base::sync_with_stdio(0);
		fill_n(arr,LIMIT,0);
		arr[1] = 1;
		ensure();
		SegmentTree st = SegmentTree(arr,1,1000000);
		int i,j;
		while(cin >> i >> j){
			int k = min(i,j);
			int l = max(i,j);

			cout << i << " " << j <<" " << st.maxIJ(k,l) << endl;
		}

		return 0;
	}
