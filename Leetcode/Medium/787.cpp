//787. Cheapest FLights within K stops
//Approach: Bellman Ford Algorithm

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<int> dist(n, INT_MAX); dist[src] = 0;
        for (int i=0; i<=k; i++) {
            vector<int> temp = dist;
            for (auto &flight:flights) {
                int u = flight[0], v = flight[1], d = flight[2];
                if (dist[u]!=INT_MAX && dist[u]+d < temp[v]) temp[v] = dist[u]+d; 
            }dist = temp;
        }return (dist[dst]==INT_MAX)?-1:dist[dst];
    }
};