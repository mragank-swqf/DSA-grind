//Shortest path in Undirected Graph with Unit Weights

#include <bits/stdc++.h>
using namespace std;

int shortest_dist(int src, int dest, vector<vector<int>>& adj_list) {
    vector<int> dist(adj_list.size(), INT_MAX); queue<pair<int, int>> q; q.push({src, 0});
    dist[src] = 0;
    while (!q.empty()) {
        pair<int, int> tp = q.front(); q.pop();
        for (int x:adj_list[tp.first]) {
            if (dist[x] == INT_MAX) {
                dist[x] = tp.second+1;
                q.push({x, dist[x]});
            }
        }
    } return (dist[dest]==INT_MAX)?-1:dist[dest];
}
int main() {
    int nodes, edges;
    cin >> nodes >> edges;
    int src, dest;
    cin >> src >> dest;
    vector<vector<int>> adj_list(nodes);
    while (edges--) {
        int a, b;
        cin >> a >> b;
        adj_list[a].push_back(b);
        adj_list[b].push_back(a);
    } cout << shortest_dist(src, dest, adj_list) << endl;
    return 0;
}