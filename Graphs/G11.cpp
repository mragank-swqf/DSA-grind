//Bellman Ford Algorithm

#include <bits/stdc++.h>
using namespace std;

int ford(int src, int dest, int nodes, vector<vector<int>>& edgess) {
    vector<int> dist(nodes, INT_MAX); dist[src] = 0;
    for (int i=0; i<nodes-1; i++) 
        for (int j=0; j<edgess.size(); j++) 
            if (dist[edgess[j][0]] != INT_MAX && dist[edgess[j][0]]+edgess[j][2] < dist[edgess[j][1]])
                dist[edgess[j][1]] = dist[edgess[j][0]]+edgess[j][2];
    return (dist[dest]==INT_MAX)?-1:dist[dest];
}
int main() {
    int nodes, edges;
    cin >> nodes >> edges;
    int src, dest;
    cin >> src >> dest;
    vector<vector<int>> edgess(edges, vector<int>(3));
    for (int i=0; i<edges; i++) {
        int u, v, w;
        cin >> edgess[i][0] >> edgess[i][1] >> edgess[i][2];
    } cout << ford(src, dest, nodes, edgess) << endl;
}