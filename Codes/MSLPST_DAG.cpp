// Code for finding the maximum path length for multiple sources to a single target. Uses iterative DP.
// Works in O(V + E) time.

#include <bits/stdc++.h>
using namespace std;

vector <int> LLP(vector <vector <pair <int, int>>> &adj, int t, vector <int> &postorder, int V) {
    vector <int> llp(V);

    for (int i = 0; i < V; i++) {
        int node = postorder[i];

        if (node == t) {
            llp[node] = 0;
        }

        else {
            llp[node] = INT_MIN;

            for (auto it : adj[node]) {
                int adjNode = it.first;
                int edgeWt = it.second;

                // Relaxation
                if (llp[node] < edgeWt + llp[adjNode]) {
                    llp[node] = edgeWt + llp[adjNode];
                }
            }
        }
    }

    for (int i = 0; i < V; i++) {
        if (llp[i] == INT_MIN) {
            llp[i] = INT_MAX; // No path exists, so set distance to positive infinity
        }
    }

    return llp;
}
