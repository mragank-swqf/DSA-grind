//Topological Sort

#include <bits/stdc++.h>
using namespace std;

stack<int> st; vector<int> visited;
void topo_sort(int root, vector<vector<int>>& adj_list) {
    if (visited[root]) return;
    visited[root] = 1;
    for (int i=0; i<adj_list[root].size(); i++) {
        if (!visited[adj_list[root][i]]) topo_sort(adj_list[root][i], adj_list);
    } st.push(root);
}
int main() {
    int t; cin >> t;
    while (t--) {
        int nodes, edges;
        cin >> nodes >> edges;
        vector<vector<int>> adj_list(nodes+1);
        visited.assign(nodes+1, 0);
        while (edges--) {
            int a, b;
            cin >> a >> b;
            adj_list[a].push_back(b);
        } for (int i=0; i<nodes; i++) topo_sort(i, adj_list);
        while (!st.empty()) {
            cout << st.top() << " ";
            st.pop();
        } cout << endl;
    } return 0;
}