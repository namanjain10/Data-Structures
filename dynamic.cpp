#include<iostream>
using namespace std;

int nBricksRec(int n, int *arr) {
    if (n == 0 || n == 1) {
        arr[n] = 1;
        return 1;
    }

    if (arr[n] != -1) return arr[n];

    int y = nBricksRec(n-2,arr);
    int z = nBricksRec(n-1,arr);
    arr[n] = y+z;
    return arr[n];
}

int nBricks (int n) {
    int* arr = new int[n+1];
    for (int i=0; i<n+1; i++) arr[i] = -1;
    return nBricksRec(n,arr);
}

void maxRodPriceRec (int *arr, int size, int n) {
    if (size < n) return;
}

int maxRodPrice (int* arr, int size) {
    maxRodPriceRec(arr, size, 0);
    return arr[size];
}

// int matrixChainOrder () {

// }

int main() {
    cout << nBricks (47) << endl;
    // int arr[] = {1, 5, 8, 9, 10, 17, 17, 20};
    // int size = sizeof(arr)/sizeof(arr[0]);
    // cout << maxRodPrice (arr, size) << endl;
}
