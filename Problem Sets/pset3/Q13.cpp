#include <bits/stdc++.h>
using namespace std;


vector<int> LLP(vector <vector <pair <int, int>>> &adj, unordered_set <int> &cycleNodes, int V, int src) {
    vector<int> dist(V, INT_MIN);
    dist[src] = 0;

    priority_queue<pair<int, int>> pq;
    pq.push({0, src});

    while (!pq.empty()) {
        pair<int, int> pr = pq.top();
        pq.pop();

        int distance = pr.first;
        int node = pr.second;

        if (distance != dist[node]) {
            continue;
        }

        for (auto it : adj[node]) {
            int adjNode = it.first;
            int edgeWt = it.second;

            if (cycleNodes.find(adjNode) != cycleNodes.end()) {
                continue;
            }

            if (distance + edgeWt > dist[adjNode]) {
                dist[adjNode] = distance + edgeWt;
                pq.push({dist[adjNode], adjNode});
            }
        }
    }

    return dist;
}


void modDFS(int node, vector <vector <pair <int, int>>> &adj, vector <int> &visited, vector <int> &pathVisited, unordered_set <int> &cycleNodes) {
    visited[node] = 1;
    pathVisited[node] = 1;

    for (auto it : adj[node]) {
        int adjNode = it.first;

        if (pathVisited[adjNode]) {
            cycleNodes.insert(adjNode);
        }

        if (!visited[adjNode]) {
            modDFS(adjNode, adj, visited, pathVisited, cycleNodes);
        }
    }

    pathVisited[node] = 0;
}


void DFS(int node, vector <vector <pair <int, int>>> &adj, vector <int> &visited, unordered_set <int> &cycleNodes) {
    visited[node] = 1;

    for (auto it : adj[node]) {
        int adjNode = it.first;

        if (!visited[adjNode]) {
            cycleNodes.insert(adjNode);
            DFS(adjNode, adj, visited, cycleNodes);
        }
    }
}


int main() {
    int V, E;
    cin >> V >> E;
    int src;
    cin >> src;

    vector <vector <pair <int, int>>> adj(V);

    for (int i = 0; i < E; i++) {
        int u, v, wt;
        cin >> u >> v >> wt;
        adj[u].push_back({v, -wt});
    }

    unordered_set <int> cycleNodes;
    vector <int> visited(V, 0);
    vector <int> pathVisited(V, 0);

    modDFS(src, adj, visited, pathVisited, cycleNodes);

    // convert the cycleNodes to vector
    vector <int> temp = vector <int> (cycleNodes.begin(), cycleNodes.end());

    // Reset visited array
    fill(visited.begin(), visited.end(), 0);

    // apply dfs again on this vector to collect all nodes which can be reached via cycle
    for (int i = 0; i < temp.size(); i++) {
        if (!visited[temp[i]]) {
            DFS(temp[i], adj, visited, cycleNodes);
        }
    }

    vector <int> dist = LLP(adj, cycleNodes, V, src);

    if (cycleNodes.find(src) != cycleNodes.end()) {
        dist[src] = INT_MIN;
    }

    for (int i = 0; i < V; i++) {
        if (dist[i] == INT_MIN) {
            if (cycleNodes.find(i) == cycleNodes.end()) {
                dist[i] = INT_MAX;
            }
        }

        else {
            dist[i] = -dist[i];
        }
    }

    // print answer
    for (int i = 0; i < V; i++) {
        if (dist[i] == INT_MAX) {
            cout << "INF" << " ";
        }

        else if (dist[i] == INT_MIN) {
            cout << "-INF" << " ";
        }

        else {
            cout << dist[i] << " ";
        }
    }

    cout << endl;

    return 0;
}