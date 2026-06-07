//Problem 210: Course Schedule II
//Approach: BFS+Topo Sort

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> res; queue<int> q;
        vector<vector<int>> adj(numCourses);
        vector<int> indegree(numCourses);
        for (auto &edge:prerequisites) {adj[edge[1]].push_back(edge[0]); indegree[edge[0]]++;}
        for (int i=0; i<numCourses; i++) 
            if (!indegree[i]) q.push(i);
        while (!q.empty()) {
            int tp = q.front(); q.pop();
            res.push_back(tp);
            for (int neigh:adj[tp]) {
                indegree[neigh]--;
                if (!indegree[neigh]) q.push(neigh);
            }
        } if (res.size()==numCourses) return res;
        return {};
    }
};