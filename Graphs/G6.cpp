//Topo Sort using BFS
#include <bits/stdc++.h>
using namespace std;

vector<int> indegree;
vector<int> bfs(vector<vector<int>>& adj_list) {
    queue<int> q; stack<int> st; vector<int> res;
    for (int i=0; i<indegree.size(); i++) if (indegree[i]==0) q.push(i);
    while (!q.empty()) {
        int tp = q.front(); q.pop();
        st.push(tp); res.push_back(tp);
        for (int i=0; i<adj_list[tp].size(); i++) {
            indegree[adj_list[tp][i]]--;
            if (indegree[adj_list[tp][i]]==0) q.push(adj_list[tp][i]);
        }
    } return res;
}
int main() {
    int t; cin >> t;
    while (t--) {
        int nodes, edges;
        cin >> nodes >> edges;
        indegree.assign(nodes, 0); 
        vector<vector<int>> adj_list(nodes);
        while (edges--) {
            int a, b;
            cin >> a >> b;
            adj_list[a].push_back(b);
            indegree[b]++;
        } vector<int> res = bfs(adj_list);
        for (int i=0; i<res.size(); i++) cout << res[i] << " ";
        cout << endl;
    } return 0;
}