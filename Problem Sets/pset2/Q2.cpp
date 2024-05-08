#include <bits/stdc++.h>
using namespace std;

int solve(vector <int> &coord, vector <int> &revenue, int n, int idx, int M) {
    if (idx == n - 1) {

    }

    int pick = INT_MIN;

    // pick case

    for (int j = idx + 1; j < n; j++) {
        if (coord[j] - coord[idx] > 5) {
            pick = solve(coord, revenue, n, j, M);
        }
    }

    // not pick case

    int notPick = solve(coord, revenue, n, idx + 1, M);
}