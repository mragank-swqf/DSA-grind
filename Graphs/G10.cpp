//Dijkstra's Algorithm -- Using Priority Queue

#include <bits/stdc++.h>
using namespace std;

int dijkstra(int src, int dest, vector<vector<pair<int, int>>>& adj_list) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, src}); vector<int> dist(adj_list.size(), INT_MAX);
    while (!pq.empty()) {
        pair<int, int> tp = pq.top(); pq.pop();
        int par = tp.first;
        for (auto& x:adj_list[tp.second]) {
            int temp = par + x.second;
            if (temp < dist[x.first]) {
                dist[x.first] = temp;
                pq.push({dist[x.first], x.first});
            }
        }
    } return (dist[dest]==INT_MAX)?-1:dist[dest];
}
int main() {
    int nodes, edges;
    cin >> nodes >> edges;
    int src, dest;
    cin >> src >> dest;
    vector<vector<pair<int, int>>> adj_list(nodes);
    while(edges--) {
        int u, v, w;
        cin >> u >> v >> w;
        adj_list[u].push_back({v, w});
        adj_list[v].push_back({u, w});
    } cout << dijkstra(src, dest, adj_list) << endl;
    return 0;
}