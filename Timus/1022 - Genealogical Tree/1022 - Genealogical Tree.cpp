#include<bits/stdc++.h>
using namespace std;

struct Node{
    int parentCount;
    int num;
    vector<int> childs;
    Node(){parentCount = 0;}
};
Node *nodes;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, child;
    cin >> n;
    nodes = new Node[n];
    for(int i = 0; i < n ; i++){
        nodes[i].num = i+1;
        while(cin>>child){
            if(child==0)
                break;
            nodes[child-1].parentCount++;
            nodes[i].childs.push_back(child-1);
        }
    }
    queue<Node> q;
    for(int i = 0; i < n ; i++)
        if(nodes[i].parentCount==0)
            q.push(nodes[i]);

    Node node;
    while(!q.empty()){
        node = q.front();
        q.pop();
        cout << node.num << " ";
        for(int i = 0; i < node.childs.size(); i++){
            nodes[node.childs[i]].parentCount--;
            if(nodes[node.childs[i]].parentCount==0){
                q.push(nodes[node.childs[i]]);
            }
        }
    }
    return 0;
}
