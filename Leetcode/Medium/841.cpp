//841. Keys and Rooms
//Approach: Breadth First Search
//Time Complexity: O(V+E); V=vertices; E=Edges
//Space Complexity: O(V): queue as well as a visited array

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        vector<int> visited(n); vector<int> res;
        queue<int> q;
        q.push(0); visited[0] = 1;
        while (!q.empty()) {
            int tp = q.front(); q.pop();
            res.push_back(tp);
            for (int i=0; i<rooms[tp].size(); i++) {
                if (!visited[rooms[tp][i]]) {
                    q.push(rooms[tp][i]);
                    visited[rooms[tp][i]] = 1;
                }
            }
        } return res.size()==n;
    }
};