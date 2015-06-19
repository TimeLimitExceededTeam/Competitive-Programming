//http://acm.tju.edu.cn/toj/showp2758.html
#include<bits/stdc++.h>
using namespace std;
int a, b, c;
struct Edge{
    int to,cost;
    Edge(){}
    Edge(int to, int cost){
        this-> to = to;
        this-> cost = cost;
    }

};
struct Node{
    int cost,id;
    bool visited;
    Node(){
        this->cost = INT_MAX;
        this->visited = false;
    }
    vector<Edge> outEdges;
};
Node *original, *inverse;

void dijkstra(Node arr[], int x){
    queue<Node> q;
    q.push(arr[x]);
    while(!q.empty()){
            Node node = q.front();
            q.pop();
            for(int i = 0; i < node.outEdges.size(); i++){
                int var = arr[node.outEdges[i].to].cost;
                arr[node.outEdges[i].to].cost = min(arr[node.outEdges[i].to].cost,node.cost+node.outEdges[i].cost);
                if(arr[node.outEdges[i].to].cost!=var and node.outEdges[i].to!= x){
                    q.push(arr[node.outEdges[i].to]);
                }
            }
    }

}
int main(){
    int n,m , x;
    cin >> n >> m >> x;
    original = new Node[n+4];
    inverse = new Node[n+4];
    for(int i = 0 ; i <= n ; i++)
    {
        original[i].id = i;
        inverse[i].id = i;
    }
    for(int i = 0 ; i < m; i++){
        cin >> a >> b >> c;
        original[a].outEdges.push_back(Edge(b,c));
        inverse[b].outEdges.push_back(Edge(a,c));
    }

    inverse[x].cost = 0;
    original[x].cost = 0;

    dijkstra(original,x);
    dijkstra(inverse, x);
    int max = -1;

    for(int i = 1; i <= n; i++)
        if(original[i].cost+inverse[i].cost > max)
            max = original[i].cost+inverse[i].cost;
    cout << max << endl;
    return 0b0;
}
