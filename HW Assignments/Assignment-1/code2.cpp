#include <bits/stdc++.h>
using namespace std;

int Median(vector <int> arr, int low, int high) {
    int len = high - low + 1;
    if (len == 0) return 0;
    if (len % 2 == 0) return arr[low + (len / 2) - 1];
    return arr[low + (len / 2)];
}

pair <int, int> Eliminate_right(int median, double pivot, int length, int size, int counter) {
    if (median > pivot) {
        if (length % 2 == 0) {
            counter -= length / 2;
            size -= length / 2;
        }
        else {
            counter -= ((length / 2) + 1);
            size -= ((length / 2) + 1);
        }
    }
    
    return {size, counter};
}

tuple <int, int, int> Eliminate_left(int median, double pivot, int length, int size, int counter, int k) {
    if (median < pivot) {
        if (length % 2 == 0) {
            counter += length / 2;
            size -= length / 2;
            k -= length / 2;
        }
        else {
            counter += ((length / 2) + 1);
            size -= ((length / 2) + 1);
            k -= ((length / 2) + 1);
        }
    }
    
    return {size, counter, k};
}

int find_k(vector <int> arr1, vector <int> arr2, vector <int> arr3, int l1, int r1, int l2, int r2, int l3, int r3, int k, bool valid1, bool valid2, bool valid3) {
    int len1 = 0, len2 = 0, len3 = 0, T = 0, m1 = 0, m2 = 0, m3 = 0;
    double M = 0.0;
    
    if (valid1) {
        len1 = r1 - l1 + 1;
        m1 = Median(arr1, l1, r1);
    }
    
    if (valid2) {
        len2 = r2 - l2 + 1;
        m2 = Median(arr2, l2, r2);
    }
    
    if (valid3) {
        len3 = r3 - l3 + 1;
        m3 = Median(arr3, l3, r3);
    }
    
    T = len1 + len2 + len3;
    
    if (m1 == 0 && m2 == 0) M = m3;
    else if (m2 == 0 && m3 == 0) M = m1;
    else if (m1 == 0 && m3 == 0) M = m2;
    else if (m1 * m2 * m3 == 0) M = (m1 + m2 + m3) / 2.0;
    else {
        vector <int> arr = {m1, m2, m3};
        sort(arr.begin(), arr.end());
        M = arr[1];
    }
    
    if (k <= T / 2) {
        if (valid1) {
            tie(T, r1) = Eliminate_right(m1, M, len1, T, r1);
        }
        
        if (valid2) {
            tie(T, r2) = Eliminate_right(m2, M, len2, T, r2);
        }

        if (valid3) {
            tie(T, r3) = Eliminate_right(m3, M, len3, T, r3);
        }
    }

    else {
        if (valid1) {
            tie(T, l1, k) = Eliminate_left(m1, M, len1, T, l1, k);
        }
        
        if (valid2) {
            tie(T, l2, k) = Eliminate_left(m2, M, len2, T, l2, k);
        }

        if (valid3) {
            tie(T, l3, k) = Eliminate_left(m3, M, len3, T, l3, k);
        }
    }

    if (l1 > r1) {
        valid1 = false;
    }

    if (l2 > r2) {
        valid2 = false;
    }

    if (l3 > r3) {
        valid3 = false;
    }

    if (valid1 && !valid2 && !valid3) {
        return arr1[l1+ k-1];
    }

    else if (!valid1 && valid2 && !valid3) {
        return arr2[l2+k-1];
    }

    else if (!valid1 && !valid2 && valid3) {
        return arr3[l3+k-1];
    }

    return find_k(arr1, arr2, arr3, l1, r1, l2, r2, l3, r3, k, valid1, valid2, valid3);
}

int main() {
    vector<int> arr1 = {1, 3, 5, 7, 9};
    vector<int> arr2 = {2, 4, 6, 8, 10};
    vector<int> arr3 = {8, 11, 12, 13, 14};

    int l1 = 0, r1 = arr1.size() - 1;
    int l2 = 0, r2 = arr2.size() - 1;
    int l3 = 0, r3 = arr3.size() - 1;

    int k = 7;

    bool valid1 = true, valid2 = true, valid3 = true;

    int result = find_k(arr1, arr2, arr3, l1, r1, l2, r2, l3, r3, k, valid1, valid2, valid3);

    cout << "The kth smallest element is: " << result << endl;

    return 0;
}
