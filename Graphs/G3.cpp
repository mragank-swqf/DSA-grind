//Cycle Detection in an undirected graph using BFS and DFS
//To detect cycle in an undirected graph, idea is same for both
//BFS and DFS, its about tracking the visited nodes as well as parent check


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

bool cycle_detect_BFS(vector<vector<int>>&adj_list) {
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
bool cycle_detect_DFS(int root, int parent, vector<vector<int>>&adj_list, vector<int>&visited) {
    if (visited[root]) return true;
    visited[root] = 1;
    for (int i=0; i<adj_list[root].size(); i++) {
        if (adj_list[root][i] == parent) continue;
        if (!visited[adj_list[root][i]]) { if (cycle_detect_DFS(adj_list[root][i], root, adj_list, visited)) return true; }
        else return true;
    } return false;
}
int main() {
    int t; cin >> t;
    while (t--) {
        int d; cin >> d;
        if (d==0) {
            vector<vector<int>> adj_list = undirected_graph();
            int n = adj_list.size();
            vector<int> visited(n+1, 0);
            cout << cycle_detect_DFS(1, 0, adj_list, visited) << endl;
        }
    }
    return 0;
}