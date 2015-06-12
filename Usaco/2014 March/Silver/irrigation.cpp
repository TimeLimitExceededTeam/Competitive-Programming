#include<bits/stdc++.h>
using namespace std;
int c;
int counter = 0;
int total = 0;
int mLast = 0;
struct DisjointSet{
    int P[2050], R[2050];
    int arcCounter;
    DisjointSet(){
        for(int i = 0; i < 2050; i++){
            P[i] = -1;
        }
    }
    int root(int i) {
        while (P[i] != -1)
            i = P[i];
        return i;
    }

    bool merge(int a, int b) {
        a = root(a);
        b = root(b);
        if (a == b) {
            return false;
        }
        if (R[a] > R[b])
            P[b] = a;
        else if (R[b] > R[a])
            P[a] = b;
        else {
            P[a] = b;
            R[b]++;
        }
        counter++;
        return true;
    }
} disjointSet;

struct Edge{
    int cost,a,b;
    Edge(int _a, int _b, int _cost){
        a = _a;
        b = _b;
        cost = _cost;
    }
};
vector<Edge> allEdges;

struct Node{
    int x, y, id;
    Node(){}
    Node(int xi, int yi, int idi){
        x = xi;
        y = yi;
        id = idi;
    }
    void join(Node n) {
        int cost = ((x - n.x) * (x - n.x))
                + ((y - n.y) * (y - n.y));
        if (cost == c){
            disjointSet.merge(id, n.id);
            total += cost;
            return;
        }
        if (cost > c) {
            allEdges.push_back(Edge(id, n.id, cost));
            mLast++;
            return;
        }
    }
};

Node nodes[2050];
bool compare(Edge a, Edge o){
    //Verdadero si a < b
    if (a.cost < o.cost)
        return true;
    if (a.cost > o.cost)
        return false;
    if (nodes[a.a].id < nodes[o.a].id)
        return true;
    else
        return false;
}

int main(){
    freopen("irrigairrigationtion.in","r",stdin);
    freopen("irrigation.out","w",stdout);

    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int n;
    cin >> n >> c;
    int x, y;
    for(int i = 0; i < n ; i++){
        cin >> x >> y;
        nodes[i] = Node(x,y,i);
    }
    for (int i = 0; i < n - 1; i++)
			for (int j = i + 1; j < n; j++)
				nodes[i].join(nodes[j]);

    sort(allEdges.begin(),allEdges.end(),compare);

    for(int i =0; i < mLast && disjointSet.arcCounter < n; i++){
        Edge edge = allEdges[i];
			if (disjointSet.merge(nodes[edge.a].id, nodes[edge.b].id))
				total += edge.cost;
    }

    bool flag = counter + 1 == n;
    if(flag)
        cout << total << endl;
    else
        cout << -1 << endl;
    return 0;
}
