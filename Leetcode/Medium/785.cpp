//785. Is Graph Bipartite
//Approach: Depth First Search

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> color;
    bool dfs(int root, int clr, vector<vector<int>>& graph) {
        if (color[root]!=-1) return true;
        color[root] = clr;
        for (int x:graph[root]) {
            if (color[x]==clr) return false;
            else if (color[x]==-1) {
                int nxt_clr = (clr==1) ? 0:1;
                if (!dfs(x, nxt_clr, graph)) return false;
            }
        } return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size(); color.assign(n, -1);
        for (int i=0; i<n; i++) {
            if (!dfs(i, 0, graph)) return false;
        } return true;
    }
};