#include <bits/stdc++.h>
using namespace std;

int twosum(vector <int> &arr, int n, int target) {
    sort(arr.begin(), arr.end());
    vector <vector <int>> ans;

    int i = 0;
    int j = n - 1;

    while (i < j) {
        int sum = arr[i] + arr[j];

        if (sum < target) {
            i++;
        }

        else if (sum > target) {
            j--;
        }

        else {
            ans.push_back({i, j});
            i++, j--;
            while (i < j && arr[i] == arr[i - 1]) i++;
            while (i < j && arr[j] == arr[j + 1]) j--;
        }
    }
}