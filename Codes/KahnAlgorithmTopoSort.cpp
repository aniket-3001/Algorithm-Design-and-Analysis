#include <bits/stdc++.h>
using namespace std;

vector<int> topologicalSort(vector<vector<int>> &graph, int edges, int nodes) {
    vector <vector <int>> adj(nodes);

    for (auto edge: graph) {
        adj[edge[0]].push_back(edge[1]);
    }
    
    vector <int> inDegree(nodes, 0);

    for (int i = 0; i < nodes; i++) {
        for (auto adjNode: adj[i]) {
        inDegree[adjNode]++;
    }
}

    queue <int> q;

    for (int i = 0; i < nodes; i++) {
        if (inDegree[i] == 0) {
            q.push(i);
        }
    }

    vector <int> topo;

    while (!q.empty()) {
        int node = q.front();
        q.pop();
        topo.push_back(node);

        for (auto adjNode: adj[node]) {
            inDegree[adjNode]--;

            if (inDegree[adjNode] == 0) {
                q.push(adjNode);
            }
        }
    }

    return topo;
}
