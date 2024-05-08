#include <bits/stdc++.h>
using namespace std;

int solve(vector <vector <int>> &P, int idx1, int idx2, vector <vector <int>> &dp) {
    // base case:

    if (idx1 == 0 && idx2 == 0) {
        return P[idx1][idx2];
    }

    if (dp[idx1][idx2] != -1) {
        return dp[idx1][idx2];
    }

    // our options:
    // make no cut
    // make cut along the horizontal line
    // make cut along the vertical line

    // if we wish to make cut along horizontal line, we need to iterate over all the rows, and make selection on maximum value obtained
    int max_horizontal = INT_MIN;

    for (int i = 0; i < idx1; i++) {
        int sp = solve(P, i, idx2, dp) + solve(P, idx1 - i - 1, idx2, dp); // computing selling price in recursive call
        max_horizontal = max(max_horizontal, sp);
    }

    // if we wish to make cut along vertical line, we need to iterate over all the columns, and make selection on maximum value obtained
    int max_vertical = INT_MIN;

    for (int i = 0; i < idx2; i++) {
        int sp = solve(P, idx1, i, dp) + solve(P, idx1, idx2 - i - 1, dp); // computing selling price in recursive call
        max_vertical = max(max_vertical, sp);
    }

    // now we just simply return the maximum value obtained from the above two options, and the current option
    return dp[idx1][idx2] = max(max(max_horizontal, max_vertical), P[idx1][idx2]);
}

int main() {
    vector <vector <int>> P = {{10, 10, 10, 1000, 1000, 10, 10, 10}};
    // vector <vector <int>> P = {{1, 2, 3, 4, 5}, {2, 3, 4, 5, 6}, {3, 4, 5, 6, 7}};
    // vector <vector <int>> P = {{2, 4, 1}, {4, 1, 3}};
    // vector <vector <int>> P = {{4, 4, 1}, {4, 1, 3}};
    // vector <vector <int>> P = {{1, 1, 1}, {1, 1, 7}};

    int m = 1, n = 8;

    vector <vector <int>> dp(m, vector <int> (n, -1));

    cout << solve(P, m - 1, n - 1, dp) << endl;

    return 0;
}