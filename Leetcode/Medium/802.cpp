//802: Eventual safe state
//Approach: Depth First Search, Topo Sort
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool dfs(int root, vector<vector<int>>& graph, vector<int>& state) {
        if (state[root] != 0) return state[root] == 2;
        state[root] = 1;
        for (int nxt:graph[root]) 
            if (!dfs(nxt, graph, state)) 
                return false;
        state[root] = 2;
        return true;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int nodes = graph.size(); vector<int> res; vector<int> state(nodes);
        for (int i=0; i<nodes; i++) 
            if (dfs(i, graph, state)) 
                res.push_back(i);
        return res;
    }
};