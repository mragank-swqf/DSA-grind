#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> undirected_graph() {
    int nodes, edges;
    cin >> nodes >> edges;
    vector<vector<int>> adjlist(nodes);
    while (edges--) {
        int a, b; cin >> a >> b;
        adjlist[a].push_back(b);
        adjlist[b].push_back(a);
    } return adjlist;
}
vector<vector<int>> directed_graph() {
    int nodes, edges;
    cin >> nodes >> edges;
    vector<vector<int>> adjlist(nodes);
    while (edges--) {
        int a, b; cin >> a >> b;
        adjlist[a].push_back(b);
    } return adjlist;
}
vector<int> BFS(vector<vector<int>>& adj_list) {
    int n = adj_list.size(); vector<int> res;
    vector<int> visited(n, 0);
    queue<int> q; q.push(0); visited[0] = 1;
    while (!q.empty()) {
        int tp = q.front(); q.pop();
        res.push_back(tp);
        for (int i=0; i<adj_list[tp].size(); i++) {
            if (!visited[adj_list[tp][i]]) {
                q.push(adj_list[tp][i]);
                visited[adj_list[tp][i]] = 1;
            }
        }
    } return res;
}
vector<int> dfs;
void DFS(int root, vector<vector<int>>& adj_list, vector<int>& visited) {
    visited[root] = 1;
    dfs.push_back(root);
    for (int i=0; i<adj_list[root].size(); i++) {
        if (!visited[adj_list[root][i]]) {
            DFS(adj_list[root][i], adj_list, visited);
        }
    }    
}
int main() {
    int t; cin >> t;
    vector<vector<int>> adj_list = (t==0) ? undirected_graph():directed_graph();
    vector<int> bfs = BFS(adj_list);
    cout << "BFS: ";
    for (int x: bfs) cout << x << " ";
    cout << endl;
    vector<int> visited(adj_list.size(), 0);
    DFS(0, adj_list, visited);
    cout << "DFS: ";
    for (int x:dfs) cout << x << " ";
    cout << endl;
    return 0; 
}