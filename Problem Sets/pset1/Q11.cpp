int findLoc (int *arr, int q) { 
    int i = 0, right, left;
    
    if (arr[i] == q) return i;
    
    for (i = 1; arr[i] != -1; i = i*2) {
        if (arr[i] == q) return i;
        if (arr[i] > q) {
            break;
        }
    }
    
    right = i;
    left = i / 2;

    while (right >= left) {
        int mid = (right + left) / 2;
        if (arr[mid] == q) return mid;
        else if (arr[mid] > q || arr[mid] == -1) right = mid - 1;
        else left = mid + 1;
    }
    
    return -1;
}