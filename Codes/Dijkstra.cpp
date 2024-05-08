// Code for Dijkstra's Algorithm:

#include <bits/stdc++.h>
using namespace std;

vector <int> Dijkstra(vector <vector <pair <int, int>>> &adj, int V, int src) {
    vector <int> dist(V, INT_MAX);
    dist[src] = 0;
    priority_queue <pair <int, int>, vector <pair <int, int>>, greater <pair <int, int>>> pq;
    pq.push({0, src});

    while (!pq.empty()) {
        pair <int, int> pr = pq.top();
        pq.pop();
        int distance = pr.first;
        int node = pr.second;

        // Check if this distance is outdated (a shorter path is found)
        if (distance != dist[node]) {
            continue;
        }

        for (auto it : adj[node]) {
            int adjNode = it.first;
            int edgeWt = it.second;

            if (distance + edgeWt < dist[adjNode]) {
                dist[adjNode] = distance + edgeWt;
                pq.push({dist[adjNode], adjNode});
            }
        }
    }

    return dist;
}