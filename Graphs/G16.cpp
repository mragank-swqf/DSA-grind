//Strongly Connected Components -- Kosaraju's algorithm

#include <bits/stdc++.h>
using namespace std;

vector<int> visited; stack<int> st;
void dfs(int node, vector<vector<int>>& adj_list) {
    visited[node] = 1;
    for (int x: adj_list[node]) 
        if (!visited[x]) 
            dfs(x, adj_list);
    st.push(node);
}
void kosaraju(int node, vector<vector<int>>& adj_list, vector<int>& curr) {
    visited[node] = 1;
    for (int x:adj_list[node]) 
        if (!visited[x])
            kosaraju(x, adj_list, curr);
    curr.push_back(node);
}
int main() {
    int nodes, edges; int scc = 0;
    vector<vector<int>> SCC; 
    cin >> nodes >> edges;
    vector<vector<int>> adj_list(nodes), rev_adj_list(nodes);
    while (edges--) {
        int u, v; cin >> u >> v;
        adj_list[u].push_back(v);
        rev_adj_list[v].push_back(u);
    } visited.assign(nodes, 0);
    for (int i=0; i<nodes; i++) 
        if (!visited[i])
            dfs(i, adj_list);
    visited.assign(nodes, 0);
    while (!st.empty()) {
        int node = st.top(); st.pop();
        if (!visited[node]) {
            vector<int> curr;
            kosaraju(node, rev_adj_list, curr);
            SCC.push_back(curr);
            scc++;
        }
    } cout << scc << endl;
    for (auto& comp: SCC) {
        for (int x:comp) cout << x << " ";
        cout << endl;
    } return 0;
}