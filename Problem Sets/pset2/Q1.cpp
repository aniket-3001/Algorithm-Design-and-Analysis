#include <bits/stdc++.h>
using namespace std;

int maximizeScore(vector <int> songs, vector <int> wait, int idx, int n, vector <int> &dp) {
    if (idx >= n) {
        return 0;
    }

    if (dp[idx] != -1) {
        return dp[idx];
    }

    int pick = songs[idx] + maximizeScore(songs, wait, idx + wait[idx] + 1, n, dp);
    int notPick = maximizeScore(songs, wait, idx + 1, n, dp);

    return dp[idx] = max(pick, notPick);
}