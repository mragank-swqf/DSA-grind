//Disjoint Set: Union by Rank

#include <bits/stdc++.h>
using namespace std;

class DisjointSet {
    vector<int> rank, parent, size;
public:
    DisjointSet(int n) {
        rank.resize(n+1, 0);
        parent.resize(n+1, 0);
        size.resize(n+1, 1);
        for (int i=0; i<=n; i++) parent[i] = i;
    }
    int findUPar(int node) {
        if (node==parent[node]) return node;
        return parent[node] = findUPar(parent[node]);
    }
    void unionByRank(int u, int v) {
        int p_u = findUPar(u);
        int p_v = findUPar(v);
        if (p_u == p_v) return;
        if (rank[p_u]<rank[p_v]) parent[p_u] = p_v;
        else if (rank[p_v]<rank[p_u]) parent[p_v] = p_u;
        else {
            parent[p_v] = p_u;
            rank[p_u]++;
        }
    }
    void unionBySize(int u, int v) {
        int p_u = findUPar(u);
        int p_v = findUPar(v);
        if (p_u == p_v) return;
        if (size[p_u]<size[p_v]) {
            parent[p_u] = p_v;
            size[p_v] += size[p_u]; 
        } else {
            parent[p_v] = p_u;
            size[p_u] += size[p_v];
        } 
    }
};

int main() {
    DisjointSet ds(7);
    ds.unionBySize(1, 2);
    ds.unionBySize(2, 3);
    ds.unionBySize(4, 5);
    ds.unionBySize(6, 7);
    ds.unionBySize(5, 6);
    if (ds.findUPar(3) == ds.findUPar(7)) {
        cout << "Same" << endl;
    } else cout << "Not Same" << endl;
    ds.unionBySize(3, 7);
    if (ds.findUPar(3) == ds.findUPar(7)) {
        cout << "Same" << endl;
    } else cout << "Not Same" << endl;
    return 0;
}