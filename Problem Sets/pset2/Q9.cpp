// the questions says that we are given a set S of n players, and we need to determine the number of tuples (A, x) where A is a subset of S and x belongs to A. Also, |A| = k. Solve using recursion.

#include <bits/stdc++.h>
using namespace std;

int helper(int n, int k) {
    if (k == 0) {
        return n;
    }

    if (n == 0) {
        return 0;
    }

    int pick = solve(n - 1, k - 1);
    int notPick = solve(n - 1, k);

    return pick + notPick;
}

int solve(int n, int k) {
    return helper(n, k) * pow(2, k);
}

// memoise solution

int solve(int n, int k, vector <vector <int>> &dp) {
    if (k == 0) {
        return n;
    }

    if (n == 0) {
        return 0;
    }

    if (dp[n][k] != -1) {
        return dp[n][k];
    }

    int pick = solve(n - 1, k - 1, dp);
    int notPick = solve(n - 1, k, dp);

    return dp[n][k] = pick + notPick;
}