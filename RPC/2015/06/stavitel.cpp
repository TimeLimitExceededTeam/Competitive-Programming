#include<bits/stdc++.h>
using namespace std;
int n, k;

int main(){
	cin >> n;
	while(n--){
		cin >> k;
		int a[k];
		int b[k];
		fill_n(a,k,0);
		fill_n(b,k,0);
		int c = 0, d = 0;

		for(int i = 0; i < k; i++){
			cin >> a[i];
			c += a[i];
		}

		for(int i = 0; i < k; i++){
			cin >> b[i];
			d += b[i];
		}

		int L = c > d ? c : d;
		int M = 0;

		stable_sort(a,a+k);
		stable_sort(b,b+k);
		int _a = a[0], _b = b[0];
		int last = 0;
		bool flag = 1, changes = true;
		_a = _b = 0;
		if(L!=0)
		while(flag){
			changes = false;
			for(int i = _a; i < k; i++){
				if(a[i] > last){
					_a = i;
					i = k+1;
					changes = true;
				}
			}
			for(int i = _b; i < k; i++){
				if(b[i] > last){
					_b = i;
					i = k+1;
					changes = true;
				}
			}
			if(changes){
				int indMin = min(a[_a], b[_b]);
				M += (indMin - last)*((k-_a)*(k-_b));
				last = min(a[_a], b[_b]);
			}
			if(a[_a] == b[_b] and a[k-1]== a[_a])
				flag = false;
		}

		int i = 0; int j = 0; L = 0;
		while(i+1 < k or j +1 < k){
			if(a[i]==b[j]){
				L += a[i];
				i = min(i+1,k-1);
				j = min(j+1,k-1);
				continue;
			}
			if(a[i] < b[j]){
				L += a[i];
				i = min(i+1,k-1);
				continue;
			}
			if(b[j] < a[i]){
				L+=b[j];
				j = min(j+1,k-1);
			}
		}
		if(a[i]==b[j]){
			L += a[i];
			i = min(i+1,k-1);
			j = min(j+1,k-1);
		}else if(a[i] < b[j]){
			L += a[i];
			i = min(i+1,k-1);
		}else if(b[j] < a[i]){
			L+=b[j];
			j = min(j+1,k-1);
		}

		cout << "Minimalni budova obsahuje " << L <<" kostek, maximalni "<< M <<" kostek." << endl;


	}
    return 0;
}
