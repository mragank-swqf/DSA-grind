//Cycle Detection in an undirected graph

#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> undirected_graph() {
    int nodes, edges;
    cin >> nodes >> edges;
    vector<vector<int>> adjlist(nodes+1);
    while (edges--) {
        int a, b; cin >> a >> b;
        adjlist[a].push_back(b);
        adjlist[b].push_back(a);
    } return adjlist;
}

bool cycle_detect(vector<vector<int>>adj_list) {
    queue<pair<int, int>> q;
    q.push({1, -1}); int n = adj_list.size(); 
    vector<int> visited(n+1); visited[1] = 1;
    while (!q.empty()) {
        int curr = q.front().first; int parent = q.front().second;
        q.pop();
        for (int i=0; i<adj_list[curr].size(); i++) {
            int temp = adj_list[curr][i];
            if (temp==parent) continue;
            if (visited[temp]) return true;
            else {visited[temp]=1; q.push({temp, curr});}
        } 
    } return false;
}
int main() {
    int t; cin >> t;
    while (t--) {
        int d; cin >> d;
        if (d==0) {
            vector<vector<int>> adj_list = undirected_graph();
            cout << cycle_detect(adj_list) << endl;
        }
    }
    return 0;
}