//Articulation point in a graph

#include <bits/stdc++.h>
using namespace std;

vector<int> visited, tim, low;
unordered_set<int> art_pt;
void articulation(int root, int& timer, int par, vector<vector<int>>& adj_list) {
    visited[root] = 1;
    tim[root] = low[root] = timer++;
    int children = 0;
    for (int x:adj_list[root]) {
        if (x!=par && visited[x]) 
            low[root] = min(low[root], tim[x]);
        else if (!visited[x]) {
            children++;
            articulation(x, timer, root, adj_list);
            low[root] = min(low[root], low[x]);
            if (low[x]>=tim[root] && par!=-1) 
                art_pt.insert(root);
        }
    } if (par==-1 && children>1) art_pt.insert(root);
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
            articulation(i, timer, -1, adj_list);
    vector<int> art(art_pt.begin(), art_pt.end());
    cout << "Articulation points are: " << endl;
    for (int x:art) cout << x << " ";
    cout << endl;
    return 0;
}