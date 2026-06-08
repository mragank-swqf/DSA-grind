//547. Number of Provinces
//Approach: Identifying connected components using DFS
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> visited;
    void dfs (int root, vector<vector<int>>& adj, int n) {
        visited[root] = 1;
        for (int i=0; i<n; i++) 
            if (!visited[i] && adj[root][i]) 
                dfs(i, adj, n);
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size(); int ans = 0;
        visited.assign(n, 0);
        for (int i=0; i<n; i++) 
            if (!visited[i]) {
                dfs(i, isConnected, n);
                ans++;
            } 
        return ans;
    }
};