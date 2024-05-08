#include <bits/stdc++.h>
using namespace std;

int predA(vector <int> &arr, int n, int target) {
    int low = 0, high = n - 1;
    int ans = n;

    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] < target) {
            low = mid + 1;
            ans = mid;
        }
        
        else {
            high = mid - 1;
        }
    }

    return ans;
}