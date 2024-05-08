#include <bits/stdc++.h>
using namespace std;

pair <int, int> kthElementIn2SortedArrays(vector<int> &arr1, vector<int>& arr2, int m, int n, int k) {
    if (n < m) return kthElementIn2SortedArrays(arr2, arr1, n, m, k);
    
    int low = max(0, k - n);
    int high = min(k, m);

    while (low <= high) {
        int cut1 = low + (high - low) / 2;
        int cut2 = k - cut1;

        int left1 = cut1 == 0? INT_MIN: arr1[cut1 - 1];
        int left2 = cut2 == 0? INT_MIN: arr2[cut2 - 1];

        int right1 = cut1 == m? INT_MAX: arr1[cut1];
        int right2 = cut2 == n? INT_MAX: arr2[cut2];
    
        if (left1 <= right2 && left2 <= right1) return make_pair(max(left1, left2), min(right1, right2));
        else if (left1 > right2) high = cut1 - 1;
        else low = cut1 + 1;
    }

    return {};
}

int kthElementIn3SortedArrays(vector<int> &arr1, vector<int>& arr2, vector<int>& arr3, int n1, int n2, int n3, int k) {
    if ((n2 < n1 && n2 <= n3) || (n2 <= n1 && n2 < n3)) {
        return kthElementIn3SortedArrays(arr2, arr1, arr3, n2, n1, n3, k);
    }

    if ((n3 <= n1 && n3 < n2) || (n3 < n1 && n3 <= n2)) {
        return kthElementIn3SortedArrays(arr3, arr1, arr2, n3, n1, n2, k);
    }

    int low = max(0, k - (n2 + n3));
    int high = min(k, n1);

    while (low <= high) {
        int cut1 = low + (high - low) / 2;
        int cut2 = k - cut1;

        int left1 = cut1 == 0 ? INT_MIN: arr1[cut1 - 1];
        int right1 = cut1 == n1 ? INT_MAX: arr1[cut1];

        pair <int, int> p = kthElementIn2SortedArrays(arr2, arr3, n2, n3, cut2);
        int left2 = p.first;
        int right2 = p.second;

        if (left1 <= right2 && left2 <= right1) return max(left1, left2);
        else if (left1 > right2) high = cut1 - 1;
        else low = cut1 + 1;
    }

    return -1;
}

int main() {
    vector<int> arr1 = {1, 5, 6, 8, 12, 15};
    vector<int> arr2 = {18, 25, 27, 29, 37, 100};
    vector<int> arr3 = {5, 17, 22, 28, 29, 81};

    int n = arr1.size();
    int m = arr2.size();
    int p = arr3.size();

    int k = 8;

    int kthElement = kthElementIn3SortedArrays(arr1, arr2, arr3, n, m, p, k);

    if (kthElement != -1) {
        cout << "The " << k << "th element is: " << kthElement << endl;
    } else {
        cout << "Invalid value of k." << endl;
    }

    return 0;
}
