#include <bits/stdc++.h>
using namespace std;

int chickens(vector<int>& A, int idx, int ring, int ding, int n, vector<vector<vector<int>>>& memo) {
    if (memo[idx][ring][ding] != -1) {
        return memo[idx][ring][ding];
    }
    
    if (idx == 0) {
        if (ring == 3) {
            memo[idx][ring][ding] = -A[idx];
        }
        else if (ding == 3) {
            memo[idx][ring][ding] = A[idx];
        }
        else {
            memo[idx][ring][ding] = abs(A[idx]);
        }
    }

    else {
        if (ding == 3) {
            memo[idx][ring][ding] = chickens(A, idx - 1, 1, 0, n, memo) + A[idx];
        } else if (ring == 3) {
            memo[idx][ring][ding] = chickens(A, idx - 1, 0, 1, n, memo) - A[idx];
        } else {
            memo[idx][ring][ding] = max(
                chickens(A, idx - 1, ring + 1, 0, n, memo) + A[idx],
                chickens(A, idx - 1, 0, ding + 1, n, memo) - A[idx]
            );
        }
    }

    return memo[idx][ring][ding];
}

int main() {
    vector<int> A = {-1, -2, -3, -4, 1, 2, 3, 4};
    int n = A.size();
    vector<vector<vector<int>>> memo(n, vector<vector<int>>(4, vector<int>(4, -1)));

    cout << chickens(A, n - 1, 0, 0, n, memo) << endl;

    return 0;
}
