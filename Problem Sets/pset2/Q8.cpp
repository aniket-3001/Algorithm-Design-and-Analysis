// the question asks us to find the number of subsets of a given set with n elements, such that the subset has only k elements out of n. However, we are not allowed to use permutations or combinations. We can solve this problem using recursion. 

#include <bits/stdc++.h>
using namespace std;

// memoization solution
int solve(int n, int k, vector <vector <int>> &dp) {
    if (k == 0) {
        return 1;
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

int main() {
    int n = 5;
    int k = 3;
    vector <vector <int>> dp(n + 1, vector <int> (k + 1, -1));
    cout << solve(n, k, dp) << endl;

    return 0;
}