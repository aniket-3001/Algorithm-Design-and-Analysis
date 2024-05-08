#include <bits/stdc++.h>
using namespace std;

int max_chicks(vector <int> &A, int idx, int n, vector<int> tup) {
    // tup keeps track of the last three ring's/ding's
    // 2 represents ring, 1 represents ding, 0 represents neither

    if (idx == n - 1) {
        if (tup[0] == 2 && tup[1] == 2 && tup[2] == 2) { // three ring's in a row
            return -A[idx]; // ding
        } else if (tup[0] == 1 && tup[1] == 1 && tup[2] == 1) { // three ding's in a row
            return A[idx]; // ring
        } else {
            return abs(A[idx]); // max(ring, ding)
        }
    }

    if (tup[0] == 2 && tup[1] == 2 && tup[2] == 2) { // three ring's in a row
        tup[idx % 3] = 1; // ding
        return -A[idx] + max_chicks(A, idx + 1, n, tup); // ding
    }

    else if (tup[0] == 1 && tup[1] == 1 && tup[2] == 1) { // three ding's in a row
        tup[idx % 3] = 2; // ring
        return A[idx] + max_chicks(A, idx + 1, n, tup); // ring
    }

    else {
        tup[idx % 3] = 2; // ring
        int a = A[idx] + max_chicks(A, idx + 1, n, tup); // ring
        tup[idx % 3] = 1; // ding
        int b = -A[idx] + max_chicks(A, idx + 1, n, tup); // ding
        return max(a, b); // return max(ring, ding)
    }
}

int main() {
    vector <int> A = {-1, -2, -3, -4, 1, 2, 3, 4};
    int n = A.size();
    vector <int> tup = {0, 0, 0};
    int ans = max_chicks(A, 0, n, tup);
    cout << ans << endl;
    return 0;
}