//743. Network Delay Time
//Aproach: Dijkstra's Algorithm
//Time Cocd ..mplexity: O(VlogE)

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>> adj_list(n + 1);
        for (auto &time:times) adj_list[time[0]].push_back({time[1], time[2]});
        vector<int> res(n+1, INT_MAX); 
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, k}); res[k] = 0; int ans = -1;
        while (!pq.empty()) {
            auto tp = pq.top(); pq.pop();
            if (tp.first>res[tp.second]) continue;
            for (auto x:adj_list[tp.second]) {
                int temp = tp.first+x.second;
                if (temp<res[x.first]) {
                    res[x.first] = temp;
                    pq.push({temp, x.first});
                }
            }
        } for (int i=1; i<=n; i++) {
            if (res[i]==INT_MAX) return -1;
            ans = max(ans, res[i]);
        } return ans;
    }
};