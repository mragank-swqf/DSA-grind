//Cycle detection in directed graph using topo sort
#include <bits/stdc++.h>
using namespace std;

vector<int> indegree;
bool bfs(vector<vector<int>>& adj_list) {
    queue<int> q; stack<int> st; vector<int> res;
    for (int i=0; i<indegree.size(); i++) if (indegree[i]==0) q.push(i);
    while (!q.empty()) {
        int tp = q.front(); q.pop();
        st.push(tp); res.push_back(tp);
        for (int i=0; i<adj_list[tp].size(); i++) {
            indegree[adj_list[tp][i]]--;
            if (indegree[adj_list[tp][i]]==0) q.push(adj_list[tp][i]);
        }
    } return (res.size()==adj_list.size());
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
        } cout << bfs(adj_list) << endl;
    } return 0;
}