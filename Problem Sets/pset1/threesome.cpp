#include <bits/stdc++.h>
using namespace std;

vector <vector <int>> threesum(vector <int> &arr, int n, int target) {
    vector <vector <int>> ans;
    sort(arr.begin(), arr.end());

    for (int i = 0; i < n; i++) {
        if (i > 0 && arr[i] == arr[i - 1]) continue;
        int j = i + 1;
        int k = n - 1;

        while (j < k) {
            int sum = arr[i] + arr[j] + arr[k];

            if (sum < target) {
                j++;
            }

            else if (sum > target) {
                k--;
            }

            else {
                ans.push_back({i, j, k});
                j++, k--;
                while (j < k && arr[j] == arr[j + 1]) j++;
                while (j < k && arr[k] == arr[k - 1]) k--;
            }
        }
    }

    return ans;
}