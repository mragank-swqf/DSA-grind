//994. Rotting Oranges
//Approach: Breadth First Search

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int minutes = 0, m = grid.size(), n = grid[0].size();
        vector<vector<int>> rotted(m, vector<int>(n, 0)); queue<pair<int, int>> q;
        for (int i=0; i<m; i++) 
            for (int j=0; j<n; j++) 
                if (grid[i][j]==2) {q.push({i, j}); rotted[i][j]=1;}  
        while(!q.empty()) {
            int sz = q.size();
            for (int i=0; i<sz; i++) {
                pair<int, int> p = q.front();
                int u = p.first, v = p.second;
                if (u>0 && grid[u-1][v]==1 && !rotted[u-1][v]) {rotted[u-1][v]=1; q.push({u-1, v});}
                if (v>0 && grid[u][v-1]==1 && !rotted[u][v-1]) {rotted[u][v-1]=1; q.push({u, v-1});}
                if (u<m-1 && grid[u+1][v]==1 && !rotted[u+1][v]) {rotted[u+1][v] = 1; q.push({u+1, v});}
                if (v<n-1 && grid[u][v+1]==1 && !rotted[u][v+1]) {rotted[u][v+1]=1; q.push({u, v+1});}
                q.pop();
            } minutes++;
        } for (int i=0; i<m; i++)
            for (int j=0; j<n; j++)
                if (grid[i][j] && !rotted[i][j])
                    return -1;
        return minutes?minutes-1:0;
    }
};