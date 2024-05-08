// Single Source Longest Path in DAG
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

vector <int> LLP(vector <vector <pair <int, int>>> &adj, stack <int> &topoSort, int V, int src) {
    // The trick is to simply multiply all edge weights by -1 and then run the SLP algorithm. Then again multiply all edge weights by -1 to get the actual longest path lengths.

    for (int i = 0; i < V; i++) {
        for (auto &it : adj[i]) {
            it.second *= -1;
        }
    }

    vector <int> dist = SLP(adj, topoSort, V, src);

    for (int i = 0; i < V; i++) {
        for (auto &it : adj[i]) {
            it.second *= -1;
        }
    }

    for (int i = 0; i < V; i++) {
        if (dist[i] != INT_MAX) {
            dist[i] *= -1;
        }
    }

    return dist;
}