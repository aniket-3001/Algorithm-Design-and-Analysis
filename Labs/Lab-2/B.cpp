#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;
const int MAX = 1024;
vector <int> dp(MAX, 0);
vector <int> temp(MAX, 0);

void update(int x) {
    for (int i = 0; i < MAX; i++) {
        int bitIDX = i | x;
        dp[bitIDX] = (dp[bitIDX] + temp[i]) % MOD;
    }

    copy(dp.begin(), dp.end(), temp.begin());
}

int main() {
    int Q;
    cin >> Q;
    dp[0] = 1, temp[0] = 1;

    while (Q--) {
        int M, x;
        cin >> M >> x;
        (M == 1) ? (update(x), 0) : (cout << dp[x] << endl, 0);
    }
    
    return 0;
}