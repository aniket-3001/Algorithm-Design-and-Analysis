#include <bits/stdc++.h>
using namespace std;

int cnt1 = 0;
int cnt2 = 0;

int max_chicks(vector<int> &A, int idx, int n, vector<int> tup, unordered_map<string, int> &memo) {
    // note: 2 -> "ding", 1 -> "ring", 0 -> neither (initial case)

    string key = to_string(idx) + "|" + to_string(tup[0]) + "|" + to_string(tup[1]) + "|" + to_string(tup[2]);

    if (memo.find(key) != memo.end()) {
        cnt2++;
        return memo[key];
    }

    if (idx == n - 1) {
        if (tup[0] == 2 && tup[1] == 2 && tup[2] == 2) { // three ring's in a row
            memo[key] = -A[idx]; // ding
        } else if (tup[0] == 1 && tup[1] == 1 && tup[2] == 1) { // three ding's in a row
            memo[key] = A[idx]; // ring
        } else {
            memo[key] = abs(A[idx]); // max(ring, ding)
        }
    } else {
        if (tup[0] == 2 && tup[1] == 2 && tup[2] == 2) { // three ring's in a row
            tup[idx % 3] = 1; // ding
            cnt1++;
            memo[key] = -A[idx] + max_chicks(A, idx + 1, n, tup, memo); // ding
        } else if (tup[0] == 1 && tup[1] == 1 && tup[2] == 1) { // three ding's in a row
            tup[idx % 3] = 2; // ring
            cnt1++;
            memo[key] = A[idx] + max_chicks(A, idx + 1, n, tup, memo); // ring
        } else {
            cnt1 += 2;
            tup[idx % 3] = 2; // ring
            int a = A[idx] + max_chicks(A, idx + 1, n, tup, memo); // ring
            tup[idx % 3] = 1; // ding
            int b = -A[idx] + max_chicks(A, idx + 1, n, tup, memo); // ding
            memo[key] = max(a, b); // return max(ring, ding)
        }
    }

    return memo[key];
}

int main() {
    vector<int> A = {-100, 2, 1, -3, -2, -3, -1, -4, -2, 1, 6, 3, 4, -5};
    int n = A.size();
    vector<int> tup = {0, 0, 0};
    unordered_map<string, int> memo;
    int ans = max_chicks(A, 0, n, tup, memo);
    cout << ans << " " << cnt1 << " " << cnt2 << endl;
    return 0;
}