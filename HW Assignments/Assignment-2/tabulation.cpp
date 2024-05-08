#include <bits/stdc++.h>
using namespace std;

void MAXCHICKS(vector<int>& A, int ring, int ding, int n, vector<vector<vector<int>>> &dp) {
    for (int i = 0; i < n; i++) {
        if (i == 0) {
            for (int j = 0; j < 4; j++) { // ring
                for (int k = 0; k < 4; k++) { // ding
                    if (j == 3) {
                        dp[i][j][k] = -A[i];
                    }

                    else if (k == 3) {
                        dp[i][j][k] = A[i];
                    }

                    else {
                        dp[i][j][k] = abs(A[i]);
                    }
                }
            }
        }

        else {
            for (int j = 0; j < 4; j++) { // ring
                for (int k = 0; k < 4; k++) { // ding
                    if (k == 3) {
                        dp[i][j][k] = A[i] + dp[i - 1][1][0];
                    }

                    else if (j == 3) {
                        dp[i][j][k] = -A[i] + dp[i - 1][0][1];
                    }

                    else {
                        dp[i][j][k] = max(A[i] + dp[i - 1][j + 1][0], -A[i] + dp[i - 1][0][k + 1]);
                    }
                }
            }
        }
    }
}

int main() {
    vector<int> A = {-100, 2, 1, -3, -2, -3, -1, -4, -2, 1, 6, 3, 4, -5};
    int n = A.size();
    vector<vector<vector<int>>> dp(n, vector<vector<int>>(4, vector<int>(4, -1)));
    MAXCHICKS(A, 0, 0, n, dp);
    cout << dp[n - 1][0][0] << endl;
    return 0;
}
