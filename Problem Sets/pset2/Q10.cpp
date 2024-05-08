#include<bits/stdc++.h>
using namespace std;

int getMaxPoints(int ind, int last, vector<int>& cards) {
    if (ind > last) {
        return 0;
    }
    
    // Two cases: either we take a card from the left or from the right.
    int right = cards[ind] + min(getMaxPoints(ind + 1, last - 1, cards), getMaxPoints(ind + 2, last, cards));
    int left = cards[last] + min(getMaxPoints(ind, last - 2, cards), getMaxPoints(ind + 1, last - 1, cards));
    return max(left, right);
}

int main() {
    vector<int> cards = {1,2,3,4};
    cout << getMaxPoints(0, 3, cards) << endl;
    return 0;
}