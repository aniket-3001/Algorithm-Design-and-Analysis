#include <bits/stdc++.h>
using namespace std;

long long bSearch(vector<pair<long long, long long>>& vec, long long target, long long n) {
    long long low = 0;
    long long high = n - 1;
    long long res = -1;

    while (low <= high) {
        long long mid = low + (high - low) / 2;

        if (vec[mid].first <= target) {
            res = mid;
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    return res;
}

vector <long long> solve(vector<long long>& A, vector<pair<long long, long long>>& B, long long n1, long long n2) {
    vector <long long> temp(n1);

    for (long long i = 0; i < n1; i++) {
        long long x = bSearch(B, A[i], n2);

        if (x == -1) {
            temp[i] = 0;
            continue;
        }

        temp[i] = B[x].second;
    }

    return temp;
}

int main() {
    long long n, b;
    cin >> n >> b;

    vector<long long> A(n);

    for (long long i = 0; i < n; i++) {
        cin >> A[i];
    }

    vector<pair<long long, long long>> B(b);

    for (long long i = 0; i < b; i++) {
        cin >> B[i].first >> B[i].second;
    }

    sort(B.begin(), B.end());

    for (long long i = 1; i < b; i++) {
        B[i].second += B[i - 1].second;
    }

    vector <long long> temp = solve(A, B, n, b);

    for (long long i = 0; i < n; i++) {
        cout << temp[i] << " ";
    }

    return 0;
}