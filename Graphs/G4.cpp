//Detecting a cycle in a directed graph using DFS

#include <bits/stdc++.h>
using namespace std;

vector<int> visited; vector<int> path;
bool detect(int root, vector<vector<int>>& adj_list) {
    if (visited[root]) return false;
    visited[root] = 1; path[root] = 1;
    for (int i=0; i<adj_list[root].size(); i++) {
        if (visited[adj_list[root][i]] && path[adj_list[root][i]]) return true;
        else if (!visited[adj_list[root][i]]) {
            if (detect(adj_list[root][i], adj_list)) return true;
        }
    } path[root] = 0;
    return false;
}
int main() {
    int nodes, edges;
    cin >> nodes >> edges;
    vector<vector<int>> adj_list(nodes+1);
    visited.resize(nodes+1); path.resize(nodes+1);
    while (edges--) {
        int a, b; cin >> a >> b;
        adj_list[a].push_back(b);
    } bool cycle = false;
    for (int i=1; i<=nodes; i++) {
        if (detect(i, adj_list)) {cycle = true; break;}
    } cout << cycle << endl;
    return 0;
}