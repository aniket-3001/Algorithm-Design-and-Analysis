#include <bits/stdc++.h>
using namespace std;

// we just need to check if there exist 2 partitions of sum n/3, since the third would automatically be n/3

bool threePartition(vector <int> &arr, int sum1, int sum2, int idx) {
    if (sum1 == 0 && sum2 == 0) {
        return true;
    }

    if (sum1 < 0 || sum2 < 0) {
        return false;
    }

    if (idx == 0) {
        if (sum1 - arr[idx] == 0 && sum2 == 0) {
            return true;
        }

        if (sum1 == 0 && sum2 - arr[idx] == 0) {
            return true;
        }

        return false;
    }

    return threePartition(arr, sum1 - arr[idx], sum2, idx - 1) || threePartition(arr, sum1, sum2 - arr[idx], idx - 1) || threePartition(arr, sum1, sum2, idx - 1);
}

bool tabulated(vector <int> &arr, i, int n) {
    int sum = accumulate(arr.begin(), arr.end(), 0);

    if (sum % 3 != 0) {
        return false;
    }
    
    vector <vector <vector <int>>> dp(n, vector <vector <int>>((sum / 3) + 1, vector <int>((sum / 3) + 1, -1)));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= sum / 3; j++) {
            for (int k = 0; k <= sum / 3; k++) {
                if (j == 0 && k == 0) {
                    dp[i][j][k] = 1;
                }

                else if (i == 0) {
                    if (j == arr[i] && k == 0) {
                        dp[i][j][k] = 1;
                    }

                    else if (j == 0 && k == arr[i]) {
                        dp[i][j][k] = 1;
                    }

                    else {
                        dp[i][j][k] = 0;
                    }
                }
            }
        }
    }
}