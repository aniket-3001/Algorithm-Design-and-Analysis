#include <bits/stdc++.h>
using namespace std;

// note: this problem cannot be solved without using the flag. Reason being, that a variable is needed to keep track whether an element has been picked or not
. 
// We cannot accept the sum when no element has been picked.
bool isDivisible(vector <int> &A, int idx, int len, int num, bool flag, int sum) {
    if (flag && sum % num == 0) {
        return true;
    }

    if (idx == len) {
        return false;
    }

    int pick = isDivisible(A, idx + 1, len, num, 1, sum + A[idx]);
    int notPick = isDivisible(A, idx + 1, len, num, flag, sum);

    return pick || notPick;
}

bool solve(vector <int> A, int len, int num) {
    if (len == 1) {
        return false;
    }

    for (int i = 0; i < len; i++) {
        int removed = A[i];
        A.erase(A.begin() + i);

        if (!isDivisible(A, 0, len - 1, num, 0, 0)) {
            return false;
        }

        A.insert(A.begin() + i, removed);
    }

    return true;
}

int main() {
    int t, m, n;

    cin >> t;

    for (int i = 0; i < t; i++) {
        cin >> m >> n;

        vector <int> A(m);

        for (int i = 0; i < m; i++) {
            cin >> A[i];
        }

        if (solve(A, m, n)) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }

    return 0;
}

