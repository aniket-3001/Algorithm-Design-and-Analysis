#include <bits/stdc++.h>
using namespace std;

unordered_set <int> memo;

void compute(vector <int> friendliness, int n) {
    int sum = accumulate(friendliness.begin(), friendliness.end(), 0);
    int minEl = *min_element(friendliness.begin(), friendliness.end());
    int maxEl = *max_element(friendliness.begin(), friendliness.end());

    memo.insert(sum);

    if (n == 1 || minEl == maxEl) { // array of size 1 can't be split further and array with all elements equal can also not be split further
        return;
    }

    int mid = (minEl + maxEl) / 2;

    vector <int> lesser, greater;
    int n1, n2;
    n1 = n2 = 0;

    for (int i = 0; i < n; i++) {
        if (friendliness[i] <= mid) {
            lesser.push_back(friendliness[i]);
            n1++;
        } else {
            greater.push_back(friendliness[i]);
            n2++;
        }
    }

    compute(lesser, n1);
    compute(greater, n2);
}

int main() {
    int t;

    cin >> t;

    for (int i = 0; i < t; i++) {
        int n, q;
        cin >> n >> q;

        vector <int> A(n);
        vector <int> B(q);

        for (int j = 0; j < n; j++) {
            cin >> A[j];
        }

        for (int j = 0; j < q; j++) {
            cin >> B[j];
        }

        compute(A, n);

        for (int j = 0; j < q; j++) {
            if (memo.find(B[j]) != memo.end()) {
                cout << "YES" << endl;
            } else {
                cout << "NO" << endl;
            }
        }

        memo.clear();
    }

    return 0;
}