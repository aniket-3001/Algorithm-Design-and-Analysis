// Single Source Shortest Path problem in DAG
// O(V+E) 

#include <bits/stdc++.h>
using namespace std;

vector <int> SLP(vector <vector <pair <int, int>>> &adj, stack <int> &topoSort, int V, int src) {
    vector <int> dist(V, INT_MAX);
    dist[src] = 0;

    while (!topoSort.empty()) {
        int node = topoSort.top();
        topoSort.pop();

        if (dist[node] != INT_MAX) {
            for (auto it : adj[node]) {
                int adjNode = it.first; 
                int edgeWt = it.second;

                if (dist[adjNode] > dist[node] + edgeWt) {
                    dist[adjNode] = dist[node] + edgeWt;
                }
            }
        }
    }

    return dist;
}