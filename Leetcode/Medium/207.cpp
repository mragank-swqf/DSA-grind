//207: Course Schedule
//Approach: BFS + Topo Sort

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> visited(numCourses); queue<int> q;
        vector<int> indegree(numCourses); int ans = 0;
        vector<vector<int>> adj(numCourses);
        for (auto &edge:prerequisites) {
            adj[edge[0]].push_back(edge[1]);
            indegree[edge[1]]++;
        } for (int i=0; i<numCourses; i++) 
            if (indegree[i]==0)
                q.push(i);
        while (!q.empty()) {
            int tp = q.front(); ans++;
            q.pop();
            for (int neigh:adj[tp]) {
                indegree[neigh]--;
                if (indegree[neigh]==0) q.push(neigh);
            }
        } return ans == numCourses;
    }
};