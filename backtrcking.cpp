#include <iostream>
using namespace std;

void printAllPaths (int **arr, int m, int n, int i, int j) {

    if (i <= m-1) {
        printAllPaths(arr, m, n, i+1, j);
    }
    if (j <= n-1) {
        printAllPaths(arr, m, n, i, j+1);
    }
    return;
}

int main() {
    // int arr[2][5] = {{1,2,3,4,5},{6,7,8,9,0}};
    int **arr = new int*[2];
    for (int i=0; i<2; i++) {
        arr[i] = new int[5];
        for (int j=0; j<5; j++) {
            arr[i][j] = i+j;
        }
    }
    printAllPaths (arr,2,5,0,0);
    cout << "\n";
    return 0;
}
