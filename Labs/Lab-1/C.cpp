#include <bits/stdc++.h>
using namespace std;

long long isPerfect(string& s, long long low, long long high, char c, long long n) {
    if (low == high) {
        if (s[low] == c)
            return 0;
        else
            return 1;
    }

    if (c == 'z') {
        return -1;
    }

    long long mid = low + (high - low) / 2;

    // first half would comprise of low...mid and second half would comprise of mid+1...high

    bool firstHalf = true;
    bool secondHalf = true;

    // check if all characters in first half are same as c
    for (long long i = low; i <= mid; i++) {
        if (s[i] != c) {
            firstHalf = false;
            break;
        }
    }

    // check if all characters in second half are same as c
    for (long long i = mid + 1; i <= high; i++) {
        if (s[i] != c) {
            secondHalf = false;
            break;
        }
    }

    if (firstHalf && secondHalf) {
        return n / 2;
    }

    if (firstHalf) {
        return isPerfect(s, mid + 1, high, c + 1, n / 2);
    }

    if (secondHalf) {
        return isPerfect(s, low, mid, c + 1, n / 2);
    }

    // now comes the trick part where neither halves are perfect

    // case 1: we would like to make first half consisting of all c's, and second half to be a perfect string for c+1

    long long firstHalfCost1 = 0;

    for (long long i = low; i <= mid; i++) {
        if (s[i] != c) {
            firstHalfCost1++;
        }
    }

    long long secondHalfCost1 = isPerfect(s, mid + 1, high, c + 1, n / 2);

    if (secondHalfCost1 == -1) {
        return -1;
    }

    // case 2: we would like to make second half consisting of all c's, and first half to be a perfect string for c+1

    long long secondHalfCost2 = 0;

    for (long long i = mid + 1; i <= high; i++) {
        if (s[i] != c) {
            secondHalfCost2++;
        }
    }

    long long firstHalfCost2 = isPerfect(s, low, mid, c + 1, n / 2);

    if (firstHalfCost2 == -1) {
        return -1;
    }

    // now we just need to return the minimum of the two cases
    return min(firstHalfCost1 + secondHalfCost1, firstHalfCost2 + secondHalfCost2);
}

int main() {
    long long t; // number of test cases
    cin >> t;

    for (long long i = 0; i < t; i++) {
        long long n; // length of string
        cin >> n;

        string s;
        cin >> s;

        cout << isPerfect(s, 0, n - 1, 'a', n) << endl;
    }

    return 0;
}
