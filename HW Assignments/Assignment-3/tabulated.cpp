#include <bits/stdc++.h>
using namespace std;

int maxSellingprice(vector <vector <int>> &P, int m, int n, vector <vector <int>> &dp) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (i == 0 && j == 0) {
                dp[i][j] = P[i][j];
            }
            else {
                int max_horizontal = INT_MIN; // max possible selling price if we cut horizontally

                if (i % 2 == 0) { // if i is even, we can cut the rectangle into two equal halves
                    for (int k = 0; k < (i / 2); k++) {
                        int sp = dp[k][j] + dp[i - k - 1][j]; // recurrences
                        max_horizontal = max(max_horizontal, sp);
                    }
                }
                else { // if i is odd, we can cut the rectangle into two halves such that one half has one more row than the other
                    for (int k = 0; k < (i / 2) + 1; k++) {
                        int sp = dp[k][j] + dp[i - k - 1][j]; // recurrences
                        max_horizontal = max(max_horizontal, sp);
                    }
                }

                int max_vertical = INT_MIN; // max possible selling price if we cut vertically

                if (j % 2 == 0) { // if j is even, we can cut the rectangle into two equal halves
                    for (int k = 0; k < (j / 2); k++) {
                        int sp = dp[i][k] + dp[i][j - k - 1]; // recurrences
                        max_vertical = max(max_vertical, sp);
                    }
                }
                else { // if j is odd, we can cut the rectangle into two halves such that one half has one more column than the other
                    for (int k = 0; k < (j / 2) + 1; k++) {
                        int sp = dp[i][k] + dp[i][j - k - 1]; // recurrences
                        max_vertical = max(max_vertical, sp);
                    }
                }

                dp[i][j] = max(max(max_horizontal, max_vertical), P[i][j]); // max of horizontal, vertical and current selling price
            
            }
        }
    }

    return dp[m - 1][n - 1]; // subproblem that solves the original problem
}

int main() {
    int m, n;
    cin >> m >> n;

    vector <vector <int>> P(m, vector <int> (n));
    vector <vector <int>> dp(m, vector <int> (n, -1));

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> P[i][j];
        }
    }

    cout << maxSellingprice(P, m, n, dp) << endl;

    return 0;
}