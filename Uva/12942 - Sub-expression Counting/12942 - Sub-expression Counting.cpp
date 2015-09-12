#include<iostream>
#include<cstring>
#include<cctype>
#include<cstdio>
using namespace std;
 
int v[400000];
 
void table(string p)
{
    v[0]=0;
    v[1]=0;
 
    int cur=0;
    for(int j=2;j<p.size();j++)
    {
        while(cur!=0 && p[cur]!=p[j-1])
        cur=v[cur];
 
        if(p[cur]==p[j-1]) 
        cur=cur+1;
 
        v[j]=cur;
    }
}
 
int kmp(string p,string text)
{
    table(p);
    int cur=0, r=0;
    for(int j=0;j<text.size();j++)
    {
        while(cur>0 && p[cur]!=text[j])
        cur=v[cur];
 
        if(p[cur]==text[j])
            if(++cur==p.size()){
            	cur = 0;
            	r++;
			} 
    }
    return r;
}
 
string changeText(string text){
    bool flag = false;
    string t = "";
    for(int i = 0; i < text.length(); i++){
       	int temp = (int) text[i];
        if(flag == false && (temp >= 48 && temp <= 57 || temp >= 97 && temp <= 122)){
        	t += "0";
        	flag = true;
        	continue;
       	}
       	if(temp >= 42 && temp <= 47){
       		t += "1";
       		flag = false;
       		continue;
       	}
       	if(temp >= 40 && temp <= 41){
       		t += "2";
       		flag = false;
       		continue;
       	}
       }
    return t;
}

int main()
{
    string text,p;
    while(cin>>p>>text){
    	p = changeText(p);
    	text = changeText(text);
        cout<<kmp(p,text)<<endl;	
	}
}
