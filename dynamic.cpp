// #include<iostream>
// using namespace std;

// int nBricksRec(int n, int *arr) {
//     if (n == 0 || n == 1) {
//         arr[n] = 1;
//         return 1;
//     }

//     if (arr[n] != -1) return arr[n];

//     int y = nBricksRec(n-2,arr);
//     int z = nBricksRec(n-1,arr);
//     arr[n] = y+z;
//     return arr[n];
// }

// int nBricks (int n) {
//     int* arr = new int[n+1];
//     for (int i=0; i<n+1; i++) arr[i] = -1;
//     return nBricksRec(n,arr);
// }

// void maxRodPriceRec (int *arr, int size, int n) {
//     if (size < n) return;
// }

// int maxRodPrice (int* arr, int size) {
//     maxRodPriceRec(arr, size, 0);
//     return arr[size];
// }

// // int matrixChainOrder () {

// // }

// int main() {
//     cout << nBricks (47) << endl;
//     // int arr[] = {1, 5, 8, 9, 10, 17, 17, 20};
//     // int size = sizeof(arr)/sizeof(arr[0]);
//     // cout << maxRodPrice (arr, size) << endl;
// }

// int fibonacciUtil (int n, long long int* arr) {
//     // cout << n << endl;
//     if (n == 0) return 0;
//     if (n == 1) return 1;

//     if (arr[n] != -1) return arr[n];
//     arr[n] = fibonacciUtil (n-1, arr) + fibonacciUtil (n-2, arr)% 1000000007;
//     return arr[n];
// }

// int fibonacci (int n) {
//     long long int * arr = new long long int[n+1];
//     for (int i=0; i<n+1; i++) arr[i] = -1;
//     return fibonacciUtil (n, arr);
// }

// long long int factorial (int n) {
//     if (n == 0) return 1;
//     return n * factorial(n-1);
// }

// int ncr (int n, int r) {
//     return (factorial(n)/(factorial(r) * factorial(n-r)))%100000007;
// }

// int main() {
// 	int t, n, r;
// 	cin >> t;
// 	while (t--) {
// 	    cin >> n >> r;
// 	    cout << ncr (n, r) << endl;
// 	}
// 	return 0;
// }


// int main() {
//     cout << nBricks (47) << endl;
//     // int arr[] = {1, 5, 8, 9, 10, 17, 17, 20};
//     // int size = sizeof(arr)/sizeof(arr[0]);
//     // cout << maxRodPrice (arr, size) << endl;
// }

// int fibonacciUtil (int n, long long int* arr) {
//     // cout << n << endl;
//     if (n == 0) return 0;
//     if (n == 1) return 1;

//     if (arr[n] != -1) return arr[n];
//     arr[n] = (fibonacciUtil (n-1, arr) + fibonacciUtil (n-2, arr))% 1000000007;
//     return arr[n] ;
// }

// int fibonacci (int n) {
//     long long int * arr = new long long int[n+1];
//     for (int i=0; i<n+1; i++) arr[i] = -1;
//     return fibonacciUtil (n, arr);
// }

#include <iostream>
#include <boost/multiprecision/cpp_int.hpp>
using boost::multiprecision::cpp_int;

using namespace std;

cpp_int catalanNumbersUtil (int n, cpp_int* arr) {
    if (n == 0 || n == 1) return 1;
    if (arr[n] != -1) return arr[n];
    cpp_int sum = 0;
    for (int i=0; i<n; i++) sum += catalanNumbersUtil (i, arr) * catalanNumbersUtil (n-1-i, arr);
    arr[n] = sum;
    return sum;
}

cpp_int catalanNumbers (int n) {
    cpp_int* arr = new cpp_int[n+1] ;
	for (int i=0; i<n+1; i++) arr[i] = -1;
	return catalanNumbersUtil (n, arr);
}

int main() {
	int t;
	cin >> t;
	while (t--) {
	    int n;
	    cin >> n;
	    cout << catalanNumbers(n) << endl;
	}
	return 0;
}

