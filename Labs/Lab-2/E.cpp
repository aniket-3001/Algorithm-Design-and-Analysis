#include <bits/stdc++.h>
using namespace std;

// function to apply dfs on the vertices that are part of a cycle or self-loop, and mark reachable vertices as -1 in the answer array
void alt2DFS(int node, vector<vector<int>> &adj, vector<int> &visited, vector <int> &ans) {
    visited[node] = 1;

    for (int adjNode: adj[node]) {
        if (!visited[adjNode]) {
            ans[adjNode] = -1;
            alt2DFS(adjNode, adj, visited, ans);
        }
    }
}

// function to apply dfs on the vertices that can be reached from the source via multiple paths, and mark reachable vertices as 2 in the answer array
void alt1DFS(int node, vector<vector<int>> &adj, vector<int> &visited, vector <int> &ans) {
    visited[node] = 1;

    for (int adjNode: adj[node]) {
        if (!visited[adjNode]) {
            ans[adjNode] = 2;
            alt1DFS(adjNode, adj, visited, ans);
        }
    }
}

void dfs(int node, vector<vector<int>> &adj, vector<int> &visited, vector<int> &pathVisited, vector<int> &ans, vector <int> &loopVertices, vector <int> &verticesWithMultiplePaths) {
    visited[node] = 1;
    pathVisited[node] = 1;

    for (int adjNode: adj[node]) {
        if (pathVisited[adjNode]) { // found a cycle or self-loop
            loopVertices.push_back(adjNode);
        } else if (!visited[adjNode]) {
            ans[adjNode] = 1;
            dfs(adjNode, adj, visited, pathVisited, ans, loopVertices, verticesWithMultiplePaths);
        } else if (visited[adjNode] && !pathVisited[adjNode]) { // found a vertex with multiple paths
            verticesWithMultiplePaths.push_back(adjNode);
        }
    }

    pathVisited[node] = 0;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;

    while (T--) {
        int N, M; // N: Vertices, M: Edges
        cin >> N >> M;
        vector<vector<int>> adj(N + 1); // 1-indexed
        vector<int> visited(N + 1, 0);
        vector<int> pathVisited(N + 1, 0);
        vector<int> ans(N + 1, 0);
        vector <int> loopVertices;
        vector <int> verticesWithMultiplePaths;

        // build the graph
        for (int j = 0; j < M; j++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        ans[1] = 1;
        dfs(1, adj, visited, pathVisited, ans, loopVertices, verticesWithMultiplePaths);

        fill(visited.begin(), visited.end(), 0);

        for (int node: verticesWithMultiplePaths) {
            ans[node] = 2;
            alt1DFS(node, adj, visited, ans); // apply dfs on the vertices that can be reached from the source via multiple paths
        }

        fill(visited.begin(), visited.end(), 0);

        for (int node: loopVertices) {
            ans[node] = -1;
            alt2DFS(node, adj, visited, ans); // apply dfs on the vertices that are part of a cycle or self-loop
        }

        for (int j = 1; j <= N; j++) {
            cout << ans[j] << " ";
        }
        
        cout << endl;
    }

    return 0;
}