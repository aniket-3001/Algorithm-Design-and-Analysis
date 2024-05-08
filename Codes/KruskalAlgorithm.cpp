#include <bits/stdc++.h>
using namespace std;

class DisjointSet {
    vector <int> rank, size, parent;
public:
    DisjointSet(int n) {
        // works for both 0-based and 1-based indexing
        rank.resize(n + 1, 0);
        size.resize(n + 1, 1);
        parent.resize(n + 1);

        for (int i = 0; i <= n; i++) {
            parent[i] = i;
        }
    }

    int findUPar(int node) {
        if (node == parent[node]) {
            return node;
        }

        return parent[node] = findUPar(parent[node]);
        
        // note that height gets distorted after this path compression and union by rank is not valid anymore
    }

    void unionByRank(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);

        if (ulp_u == ulp_v) {
            return;
        }

        if (rank[ulp_u] < rank[ulp_v]) {
            parent[ulp_u] = ulp_v;
        } else if (rank[ulp_u] > rank[ulp_v]) {
            parent[ulp_v] = ulp_u;
        } else {
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }

    void unionBySize(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);

        if (ulp_u == ulp_v) {
            return;
        }

        if (size[ulp_u] < size[ulp_v]) {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};

bool compareSecondElement(const vector<int>& a, const vector<int>& b) {
    return a[2] < b[2]; // Compare based on the second element of the inner vectors
}

vector <pair <int, int>> minimumSpanningTree(vector<vector<int>>& edges, int n) {
	DisjointSet ds(n);
	sort(edges.begin(), edges.end(), compareSecondElement);
    vector <pair<int, int>> mst;
	int mstWt = 0;

	for (auto edge: edges) {
		int u = edge[0];
		int v = edge[1];
		int wt = edge[2];

		if (ds.findUPar(u) != ds.findUPar(v)) {
			mstWt += wt;
			ds.unionBySize(u, v);
            mst.push_back({u, v});
		}
	}

	return mst;
}