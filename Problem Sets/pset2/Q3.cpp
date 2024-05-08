#include <bits/stdc++.h>
using namespace std;

int minimizePenalty(vector <int> &A, int idx) {
    if (idx == 0) {
        return 0;
    }

    int mini = INT_MAX;

    for (int j = idx - 1; j >= 0; j--) {
        int penalty = pow(250 - (A[idx] - A[j]), 2) + minimizePenalty(A, j);
        mini = min(mini, penalty);
    }

    return mini;
}

int tabulatedMinimizePenalty(vector <int> &A, int n) {
    vector <int> dp(n, 0);

    for (int i = 1; i < n; i++) {
        int mini = INT_MAX;

        for (int j = i - 1; j >= 0; j--) {
            int penalty = pow(250 - (A[i] - A[j]), 2) + dp[j];
            mini = min(mini, penalty);
        }

        dp[i] = mini;
    }

    return dp[n - 1];
}