// Code for finding the minimum path length for multiple sources to a single target. Uses iterative DP.
// Works in O(V + E) time.

#include <bits/stdc++.h>
using namespace std;

vector <int> SLP(vector <vector <pair <int, int>>> &adj, int t, vector <int> &postorder, int V) {
    vector <int> slp(V);

    for (int i = 0; i < V; i++) {
        int node = postorder[i];

        if (node == t) {
            slp[node] = 0;
        }
        
        else {
            slp[node] = INT_MAX;

            for (auto it : adj[node]) {
                int adjNode = it.first;
                int edgeWt = it.second;

                // Relaxation
                if (slp[node] > edgeWt + slp[adjNode]) {
                    slp[node] = edgeWt + slp[adjNode];
                }
            }
        }
    }

    return slp;
}
