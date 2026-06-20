//Prim's Algorithm -- Minimum Spanning Trees

#include <bits/stdc++.h>
using namespace std;

int prim(vector<vector<pair<int, int>>>& adj_list) {
    priority_queue<array<int, 3>, vector<array<int, 3>>, greater<array<int, 3>>> pq;
    pq.push({0, 0, -1}); vector<int> visited(adj_list.size(), 0); int ans = 0;
    while (!pq.empty()) {
        auto tp = pq.top(); pq.pop();
        int wt = tp[0], node = tp[1], parent = tp[2];
        if (visited[node]) continue;
        visited[node] = 1;
        ans += wt;
        for (auto &p:adj_list[node]) 
            if (!visited[p.first]) 
                pq.push({p.second, p.first, node});
    } return ans;
}
int main() {
    int nodes, edges;
    cin >> nodes >> edges;
    vector<vector<pair<int, int>>>adj_list(nodes);
    while (edges--) {
        int u, v, w;
        cin >> u >> v >> w;
        adj_list[u].push_back({v, w});
        adj_list[v].push_back({u, w});
    } int mst = prim(adj_list);
    cout << mst << endl;
    return 0;
}