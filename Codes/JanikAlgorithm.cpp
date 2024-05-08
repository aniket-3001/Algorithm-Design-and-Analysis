#include <bits/stdc++.h>
using namespace std;

int minimumSpanningTree(vector<vector<int>>& edges, int n) {
    vector<vector<pair<int, int>>> adj(n);

    for (auto edge : edges) {
        int u = edge[0];
        int v = edge[1];
        int wt = edge[2];
        adj[u].push_back({v, wt});
        adj[v].push_back({u, wt});
    }

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    // this means that our priority queue would be of the type {weight, node}, it would be of the form of a vector, containing the element with the least weight at the top

    vector<int> visited(n, 0);
    pq.push({0, 0});
    int sum = 0;

    while (!pq.empty()) {
        auto it = pq.top();
        pq.pop();
        int wt = it.first;
        int node = it.second;

        if (visited[node]) continue;
        
        visited[node] = 1;
        sum += wt;

        for (auto it : adj[node]) {
            int adjNode = it.first;
            int edgeWt = it.second; 

            if (!visited[adjNode]) {
                pq.push({edgeWt, adjNode});
            }
        }
    }

    return sum;
}