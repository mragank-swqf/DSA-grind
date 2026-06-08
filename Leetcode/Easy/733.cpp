//733. Flood FIll
//Approach: Breadth First Search

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        queue<pair<int, int>> q; q.push({sr, sc});
        int m = image.size(), n = image[0].size();
        vector<vector<int>> visited(m, vector<int>(n, 0));
        while (!q.empty()) {
            pair<int, int> p = q.front(); q.pop();
            int u = p.first, v = p.second;
            int temp = image[u][v];
            image[u][v] = color;
            if (u>0 && image[u-1][v]==temp && !visited[u-1][v]) {visited[u-1][v]=1; q.push({u-1,v});}
            if (v>0 && image[u][v-1]==temp && !visited[u][v-1]) {visited[u][v-1]=1; q.push({u,v-1});}
            if (u<m-1 && image[u+1][v]==temp && !visited[u+1][v]) {visited[u+1][v]=1; q.push({u+1,v});}
            if (v<n-1 && image[u][v+1]==temp && !visited[u][v+1]) {visited[u][v+1]=1; q.push({u,v+1});}
        } return image;
    }
};