//Bridges in graph using Tarjan's Algorithm

#include <bits/stdc++.h>
using namespace std;

vector<int> visited;
vector<int> tim;
vector<int> low;
vector<vector<int>> bridges;
void tarjan(int root, int par, int& timer, vector<vector<int>>& adj_list) {
    visited[root] = 1;
    tim[root] = low[root] = timer++;
    for (int x: adj_list[root]) {
        if (x!=par && visited[x]) 
            low[root] = min(low[root], low[x]); 
        if (!visited[x]) {
            tarjan(x, root, timer, adj_list);
            low[root] = min(low[root], low[x]);
            if (low[x]>tim[root]) 
                bridges.push_back({root, x});
        }
    }
}
int main() {
    int nodes, edges;
    cin >> nodes >> edges;
    vector<vector<int>> adj_list(nodes);
    while (edges--) {
        int u, v;
        cin >> u >> v;
        adj_list[u].push_back(v);
        adj_list[v].push_back(u);
    } tim.assign(nodes, INT_MAX);
    visited.assign(nodes, 0);
    low.assign(nodes, INT_MAX);
    int timer = 0;
    for (int i=0; i<nodes; i++) 
        if (!visited[i])
            tarjan(i, -1, timer, adj_list);
    cout << "Bridges are: " << endl;
    for (auto &bridge: bridges) {
        cout << bridge[0] << " " << bridge[1] << endl;
    } return 0;
}