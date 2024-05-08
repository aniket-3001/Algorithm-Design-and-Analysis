#include <bits/stdc++.h>
using namespace std;

vector<vector<vector<int>>> memo;

int solve2(int idx, int ctr, int Ysum, vector<pair<int, int>>& YX, int totJuice) {
    if (ctr == 0) {
        if (Ysum >= totJuice) {
            return 0;
        } else {
            return INT_MIN;
        }
    }

    if (idx == -1) {
        return INT_MIN;
    }
    
    if (memo[idx][ctr][Ysum] != -1) {
        return memo[idx][ctr][Ysum];
    }
    
    int pick = YX[idx].second + solve2(idx - 1, ctr - 1, Ysum + YX[idx].first, YX, totJuice);
    int notPick = solve2(idx - 1, ctr, Ysum, YX, totJuice);

    return memo[idx][ctr][Ysum] = max(pick, notPick);
}

pair<int, int> solve1(int totJuice, vector<pair<int, int>>& YX, int N) {
    int containersReq = 0;
    int capacitySum = 0;

    do {
        capacitySum += YX[containersReq].first;
        containersReq++;
    } while (capacitySum < totJuice && containersReq < N);

    int effort = totJuice - solve2(N - 1, containersReq, 0, YX, totJuice);

    return {containersReq, effort};
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    vector<int> X;
    vector<pair<int, int>> YX;

    cin >> N;

    for (int i = 0; i < N; i++) {
        int x;
        cin >> x;
        X.push_back(x);
    }

    for (int i = 0; i < N; i++) {
        int y;
        cin >> y;
        YX.push_back({y, X[i]});
    }

    memo.resize(N, vector<vector<int>>(N + 1, vector<int>(accumulate(X.begin(), X.end(), 0) + 1, -1)));

    // Sort the vector of pairs based on the Y values in descending order
    sort(YX.begin(), YX.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
        return a.first > b.first;
    });

    int totJuice = accumulate(X.begin(), X.end(), 0);

    pair<int, int> ans = solve1(totJuice, YX, N);

    cout << ans.first << " " << ans.second << endl;

    return 0;
}