#include <bits/stdc++.h>
using namespace std;

int solve(vector <int> &m, vector <int> &d, int idx, int M, int city) {
    if (idx == 0) {
        if (city == 0) {
            return d[idx];
        }

        else {
            return m[idx];
        }
    }

    if (city == 0) {
        int cost1 = d[idx] + solve(m, d, idx - 1, M, 0);
        int cost2 = d[idx] + M + solve(m, d, idx - 1, M, 1);
        return min(cost1, cost2);
    }

    else {
        int cost1 = m[idx] + solve(m, d, idx - 1, M, 1);
        int cost2 = m[idx] + M + solve(m, d, idx - 1, M, 0);
        return min(cost1, cost2);
    }
}

int tabulated(vector <int> &m, vector <int> &d, int M, int n) {
    vector <vector <int>> dp(2, vector <int> (m.size(), 0));
    dp[0][0] = d[0];
    dp[0][1] = m[0];
    int cost1, cost2; 

    for (int i = 1; i < n; i++) {
        cost1 = d[i] + dp[i - 1][0];
        cost2 = d[i] + M + dp[i - 1][1];
        dp[i][0] = min(cost1, cost2);

        cost1 = m[i] + dp[i - 1][1];
        cost2 = m[i] + M + dp[i - 1][0];
        dp[i][1] = min(cost1, cost2);
    }

    return min(dp[n - 1][0], dp[n - 1][1]);
}