//Building a directed and an undirected graph

#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> undirected_graph() {
    int nodes, edges;
    cin >> nodes >> edges;
    vector<vector<int>> adjlist(nodes);
    while (edges--) {
        int a, b; cin >> a >> b;
        adjlist[a].push_back(b);
        adjlist[b].push_back(a);
    } return adjlist;
}
vector<vector<int>> directed_graph() {
    int nodes, edges;
    cin >> nodes >> edges;
    vector<vector<int>> adjlist(nodes);
    while (edges--) {
        int a, b; cin >> a >> b;
        adjlist[a].push_back(b);
    } return adjlist;
}
int main() {
    int directed;
    cin >> directed;
    vector<vector<int>> res = (directed) ? directed_graph():undirected_graph();
    for (int i=0; i<res.size(); i++) {
        cout << i << ":" << "  [";
        for (int j=0; j<res[i].size(); j++) cout << res[i][j] << " ";
        cout << "]" << endl;
    } return 0;
}