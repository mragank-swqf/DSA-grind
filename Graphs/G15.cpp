//Kruskal's algorithm: Minimum Spanning Trees
//Using Union By Size

#include <bits/stdc++.h>
using namespace std;

vector<int> size, parent;
int findUPar(int node) {
    if (node == parent[node]) return node;
    return parent[node] = findUPar(parent[node]);
}
void unionBySize(int u, int v) {
    int p_u = findUPar(u);
    int p_v = findUPar(v);
    if (p_u==p_v) return;
    if (size[p_u]<size[p_v]) {parent[p_u]=p_v; size[p_v]+=size[p_u];}
    else {parent[p_v]=p_u; size[p_u]+=size[p_v];}
}
int main() {
    int nodes, edges; int ans = 0;
    cin >> nodes >> edges;
    size.resize(nodes, 1);
    parent.resize(nodes);
    for (int i=0; i<nodes; i++) parent[i] = i;
    vector<vector<int>> edge_list;
    while (edges--) {
        int w, u, v;
        cin >> w >> u >> v;
        edge_list.push_back({w, u, v});
    } sort(edge_list.begin(), edge_list.end());
    for (auto& edge:edge_list) {
        if (findUPar(edge[1])!=findUPar(edge[2])) {
            unionBySize(edge[1], edge[2]);
            ans += edge[0];
        }
    } cout << ans << endl;
    return 0;
}