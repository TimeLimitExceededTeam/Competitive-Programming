/* Luis David García(Natchz) 12/06/2015 */
#include <bits/stdc++.h>
using namespace std;
int main(){
    char s[1000000];
    while(scanf("%s", &s)>0){
        long long result=0;
        int to=strlen(s);
        int mod[12]={0,1,2,0,1,2,0,1,2,0,1,2};
        for(int i=0;i<to;i++){
            if(s[i]>='0' && s[i]<='9'){
                int p[3]={1,0,0};
                int n=0;
                while(s[i]>='0' && s[i]<='9'){
                    n+=s[i]-'0';
                    if(n>2)n=mod[n];
                    result+=p[n];
                    p[n]++;
                    i++;
                }
            }
        }
        printf("%lld\n",result);
    }
    return 0;
}
