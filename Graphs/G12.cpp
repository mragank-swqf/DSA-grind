//Floyd Warshall Algorithm

#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> floyd(vector<vector<int>>& adj_mat) {
    int n = adj_mat.size();
    for (int k=0; k<n; k++) 
        for (int i=0; i<n; i++) 
            for (int j=0; j<n; j++) 
                if (adj_mat[i][k]!=INT_MAX && adj_mat[k][j]!=INT_MAX) 
                    adj_mat[i][j] = min(adj_mat[i][j], adj_mat[i][k]+adj_mat[k][j]);
    return adj_mat;            
}
int main() {
    int nodes, edges;
    cin >> nodes >> edges;
    vector<vector<int>> adj(nodes, vector<int>(nodes, INT_MAX));
    for (int i=0; i<nodes; i++) adj[i][i] = 0; 
    while (edges--) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u][v] = w;
    } vector<vector<int>> res = floyd(adj);
    int queries; cin >> queries;
    while (queries--) {
        int a, b; 
        cin >> a >> b;
        cout << (res[a][b]==INT_MAX ? -1 : res[a][b]) << endl;
    } return 0;
}