#include <bits/stdc++.h>
using namespace std;

void DFS(vector <vector <int>> &adj, vector <int> &visited, int node, stack <int> &st) {
    visited[node] = 1;

    for (int adjNode : adj[node]) {
        if (!visited[adjNode]) {
            DFS(adj, visited, adjNode, st);
        }
    }

    st.push(node);
}

void LabelDFS(vector <vector <int>> &adj, int node, vector <int> &root, int label) {
    root[node] = label;

    for (int adjNode : adj[node]) {
        if (root[adjNode] == -1) {
            LabelDFS(adj, adjNode, root, label);
        }
    }
}

vector <int> KosarajuSharir(vector <vector <int>> &adj, vector <vector <int>> &adjT, int n) {
    stack <int> st;
    vector <int> visited(n + 1, 0);
    vector <int> root(n + 1, -1);

    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            DFS(adjT, visited, i, st);
        }
    }

    while (!st.empty()) {
        int node = st.top();
        st.pop();

        if (root[node] == -1) {
            LabelDFS(adj, node, root, node);
        }
    }

    return root;
}

vector <vector <int>> CreateCondensationGraph(vector <vector <int>> &adj, vector <int> &root, int scc, int n) {
    vector <vector <int>> condensationGraph(scc + 1);

    // write code here

    return condensationGraph;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector <vector <int>> adj(n + 1), adjT(n + 1);

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adjT[v].push_back(u);
    }

    vector <int> root = KosarajuSharir(adj, adjT, n);

    // The number of SCCs is the number of distinct elements in the array root
    int scc = 0;
    unordered_set <int> s;

    for (int i = 1; i <= n; i++) {
        if (s.find(root[i]) == s.end()) {
            scc++;
            s.insert(root[i]);
        }
    }

    vector <vector <int>> condensationGraph = CreateCondensationGraph(adj, root, scc, n);

    return 0;
}