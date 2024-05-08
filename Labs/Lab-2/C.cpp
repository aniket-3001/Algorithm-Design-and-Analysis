#include <bits/stdc++.h>
using namespace std;
    
int dfs(int node, vector<vector<int>> &adj, vector <int> &dp) {
    dp[node]++;
    int ans = dp[node];
    
    for (int adjNode: adj[node]) {
        if (adjNode <= node) {
            if (dp[adjNode]) {
                ans = max(ans, dp[adjNode] + 1);
            } else {
                ans = max(ans, dfs(adjNode, adj, dp) + 1);
            }
        }
    }
    
    dp[node] = ans;
    return ans;
}
    
vector <int> computeFaces(vector<vector<int>>& adj, int n) {
    vector <int> dp(n + 1, 0);
    
    for (int i = 1; i <= n; i++) {
        if (!dp[i]) {
            dfs(i, adj, dp);
        }
    }
    
    return dp;
}
    
int main() {
    int n, m;
    cin >> n >> m;
    
    vector<vector<int>> adj(n + 1);
    
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    vector <int> faces = computeFaces(adj, n);
    int maxi = 0;
    
    for (int i = 1; i <= n; i++) {
        int hands = adj[i].size();
        int face = faces[i];
        int beauty = face * hands;
        maxi = max(maxi, beauty);
    }
    
    cout << maxi;
    
    return 0;
}