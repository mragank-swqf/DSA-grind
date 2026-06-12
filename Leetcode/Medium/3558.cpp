//Problem of the Day: 11th June 2026
//3558. No of ways to Assign Edge Weights I
//Approach: Depth First Search to find the maximum depth

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> visited; long long MOD = 1e9+7;
    long long dfs(int root, vector<vector<int>>& adj_list) {
        visited[root] = 1; long long depth = 0;
        for (int x:adj_list[root]) 
            if (!visited[x]) 
                depth = max(depth, 1+dfs(x, adj_list));
        return depth;
    }
    int assignEdgeWeights(vector<vector<int>>& edges) {
        int depth = 0; int n = 0;
        for (auto &e:edges) {n = max(n, max(e[0], e[1]));}
        vector<vector<int>> adj_list(n+1); visited.assign(n+1, 0);
        for (auto &edge:edges) {
            adj_list[edge[0]].push_back(edge[1]);
            adj_list[edge[1]].push_back(edge[0]);
        } long long dep = dfs(1, adj_list);
        long long k = 1;
        for (int i=0; i<dep-1; i++) k = (k*2)%MOD;
        return k;
    }
};