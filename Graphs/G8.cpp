//Shortest path in Directed Acyclic Graph
#include <bits/stdc++.h>
using namespace std;

stack<int> st; vector<int> visited;
void topo_sort(int root, vector<vector<pair<int, int>>>& adj_list) {
    if (visited[root]) return;
    visited[root] = 1;
    for (auto &x:adj_list[root]) 
        if (!visited[x.first])
            topo_sort(x.first, adj_list);
    st.push(root);
}
int dist(int src, int dest, vector<vector<pair<int, int>>>& adj_list) {
    int nodes = adj_list.size();
    vector<int> dist(nodes, INT_MAX);
    dist[src] = 0;
    while(!st.empty()) {
        int tp = st.top(); st.pop();
        int par = dist[tp];
        for (auto& x: adj_list[tp]) 
            if (par!=INT_MAX)
                dist[x.first] = min(dist[x.first], x.second+par);       
    } return (dist[dest]==INT_MAX)?-1:dist[dest];
}
int main() {
    int nodes, edges;
    cin >> nodes >> edges;
    visited.assign(nodes, 0);
    int src, dest;
    cin >> src >> dest;
    vector<vector<pair<int, int>>> adj_list(nodes);
    while (edges--) {
        int u, v, w;
        cin >> u >> v >> w;
        adj_list[u].push_back({v, w});
    } for (int i=0; i<nodes; i++) 
        topo_sort(i, adj_list);
    cout << dist(src, dest, adj_list) << endl;
    return 0;
}