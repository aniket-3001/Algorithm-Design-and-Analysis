#include <bits/stdc++.h>
using namespace std;

// partition function:
// pivot is placed in its correct position in the array
// all elements less than pivot are placed to the left of pivot
// all elements greater than pivot are placed to the right of pivot
int partition(vector<int> &A, int pivot) {
    int i = 0;

    for (int j = 0; j < A.size(); j++) {
        if (A[j] < pivot) {
            swap(A[i], A[j]);
            i++; 
        }
    }

    swap(A[i], A[A.size()-1]);
    return i;
}

// MOMSELECT function:
// selects the kth smallest element from the array A
// if the size of the array is less than or equal to 25, the array is sorted and the kth smallest element is returned
// otherwise, the array is divided into groups of 5 elements each
// the median of each group is calculated and stored in a new array M
// the median of M is calculated and stored in the variable mom
// the array A is partitioned using the median of medians mom
// if k is less than the position of mom, the function is called recursively with the first half of the array
// if k is greater than the position of mom, the function is called recursively with the second half of the array
// if k is equal to the position of mom, mom is returned
int MOMSELECT(vector<int> &A, int k) {
    int n = A.size();

    if (n <= 25) {
        sort(A.begin(), A.end());
        return A[k-1]; 
    }

    else {
        int m = n / 5;
        vector <int> M(m, 0);
        
        for (int i = 0; i < m; i++) {
            vector<int> B(5);

            for (int j = 0; j < 5; j++) {
                B[j] = A[5*i + j];  
            }

            sort(B.begin(), B.end());
            M[i] = B[2]; 
        }
        
        int mom = MOMSELECT(M, m/2); 
        int r = partition(A, mom);
        
        if (k < r) {
            return MOMSELECT(A, k);
        }
        else if (k > r) {
            return MOMSELECT(A, k-r); 
        }
        else {
            return mom;
        }
    }
}

int main() {
    vector<int> A = {10, 5, 3, 8, 7, 12, 14, 4, 19, 11};
    int n = A.size();
    int k = 5;
    int kth = MOMSELECT(A, k);

    cout << kth << endl;

    return 0;
}