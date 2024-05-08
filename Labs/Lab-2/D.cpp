#include <bits/stdc++.h>
using namespace std;
    
#define ll long long
    
vector<ll> dijkstra(vector<vector<pair<ll, ll>>>& adj, ll src, ll n) {
    vector<ll> dist(n + 1, 1e16);
    dist[src] = 0;
    
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;
    pq.push({0, src});
    
    while (!pq.empty()) {
        ll u = pq.top().second;
        pq.pop();
    
        for (auto edge : adj[u]) {
            ll v = edge.first;
            ll w = edge.second;
    
            if (dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }
    
    return dist;
}
    
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    ll N, M;
    cin >> N >> M;
    
    vector<vector<pair<ll, ll>>> adj((2 * N) + 1);
    
    for (ll i = 1; i <= N; i++) {
        adj[i].push_back({i + N, 0});
    }
    
    for (ll i = 0; i < M; i++) {
        ll u, v, w;
        cin >> u >> v >> w;
    
        adj[u].push_back({v, w});
        adj[v + N].push_back({u + N, w});
    }
    
    vector<ll> ans = dijkstra(adj, 1, 2 * N);
    
    for (ll i = N + 2; i <= 2 * N; i++) {
        if (ans[i] == 1e16) ans[i] = -1;
        cout << ans[i] << " ";
    }
    
    return 0;
}