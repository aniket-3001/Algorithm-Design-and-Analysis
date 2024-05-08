#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>> minimumSpanningTree(vector<vector<int>>& edges, int n) {
    vector<vector<pair<int, int>>> adj(n);

    for (auto edge : edges) {
        int u = edge[0];
        int v = edge[1];
        int wt = edge[2];
        adj[u].push_back({v, wt});
        adj[v].push_back({u, wt});
    }

    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
    // this means that our priority queue would be of the type {weight, {parent, node}}, it would be of the form of a vector, containing the element with the least weight at the top

    vector<bool> visited(n, false);
    pq.push({0, {-1, 0}}); // {weight, {parent, node}}
    vector<pair<int, int>> mst; // stores the edges of the MST
    int sum = 0;

    while (!pq.empty()) {
        auto current = pq.top();
        pq.pop();
        int wt = current.first;
        int parent = current.second.first;
        int node = current.second.second;

        if (visited[node]) continue;
        
        visited[node] = true;
        sum += wt;

        if (parent != -1)
            mst.push_back({parent, node});

        for (auto neighbor : adj[node]) {
            int adjNode = neighbor.first;
            int edgeWt = neighbor.second; 

            if (!visited[adjNode]) {
                pq.push({edgeWt, {node, adjNode}});
            }
        }
    }

    return mst;
}
