/* Luis David García(Natchz) 11/06/2015 */
#include <bits/stdc++.h>
using namespace std;
int main(){
    long long x,y;
    char s[5000];
    while(scanf("%lld %lld", &x, &y)>0){
        y=x-y;
        long long mov=0,result=0,b=0,w=0;
        scanf("%s", &s);
        int n=strlen(s),fw=0,lb=n;
        for(int i=0;i<n;i++)
            if(s[i]=='W')w++;
            else mov+=w;
        for(int i=n-1;i>=0;i--)
            if(s[i]=='B'){lb=i;break;}
        for(int i=0;i<n;i++)
            if(s[i]=='W'){fw=i;break;}
        w=0;
        for(int i=fw;i<=lb;i++)
            if(s[i]=='B')b++;
            else w++;
        while(mov){
            if(x>=y*(b+w-1)){
                result+=mov*y;
                mov=0;
            }else{
                result+=x;
                mov-=b+w-1;
                w--;
                b--;
                fw++;
                lb--;
                while(fw<=lb && s[fw] == 'B'){fw++;b--;}
                while(lb>=fw && s[lb] == 'W'){lb--;w--;}
            }
        }
        printf("%lld\n",result);
    }
    return 0;
}
