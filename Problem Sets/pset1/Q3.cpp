#include <bits/stdc++.h>
using namespace std;

int f(vector <int> &arr, int n, int target) {
    int low = 0, high = n - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;
        
        if (arr[mid] == mid) return mid;
        else if (arr[mid] < mid) low = mid + 1;
        else high = mid - 1;
    }

    return -1;
}