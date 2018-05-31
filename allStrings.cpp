#include <iostream>
#include <math.h>
using namespace std;

void printStrings(int n, string s) {
    if (n == 0)
    {
        cout << s << endl;
        return;
    }
    printStrings(n - 1, s + "0");
    printStrings(n - 1, s + "1");
}

int largestContSum(int *arr, int n) {

    int largest = 0, large_till = 0;

    for (int i = 0; i < n; i++)
    {
        large_till += arr[i];
        if (large_till > largest)
            largest = large_till;

        else if (large_till < 0)
            large_till = 0;
    }
    return largest;
}

//Find all Egyptian fractions

void egyptian(int nr, int dr)
{
    // cout << "nr " << nr << " dr " << dr << endl;
    if (nr % dr == 0)
        return;

    else if (nr > dr)
    {
        int r = nr / dr;
        cout << r << " + ";
        egyptian(nr - r * dr, dr);
    }

    else
    {
        int r = ceil(float(dr) / nr);
        cout << "1/" << r << " + ";
        egyptian(nr * r - dr, r * dr);
    }
}

int binarySearchStart(int arr[], int start, int end, int k)
{
    if (end < start)
        return -1;

    int mid = (start + end) / 2;
    if (arr[mid] == k)
    {
        if (mid == 0)
            return mid;
        else
        {
            if (arr[mid - 1] != k)
                return mid;
            else
                return binarySearchStart(arr, start, mid - 1, k);
        }
    }

    else if (arr[mid] > k)
    {
        return binarySearchStart(arr, start, mid - 1, k);
    }
    else
    {
        return binarySearchStart(arr, mid + 1, end, k);
    }
}

int binarySearchEnd(int arr[], int start, int end, int k, int n)
{
    if (end < start)
        return -1;

    int mid = (start + end) / 2;

    if (arr[mid] == k)
    {
        if (mid == n - 1)
            return mid;
        else
        {
            if (arr[mid + 1] != k)
                return mid;
            else
                return binarySearchEnd(arr, mid + 1, end, k, n);
        }
    }
    else if (arr[mid] > k)
    {
        return binarySearchEnd(arr, start, mid - 1, k, n);
    }
    else
    {
        return binarySearchEnd(arr, mid + 1, end, k, n);
    }
}

int binarySearch(int arr[], int start, int end, int k)
{
    int i = binarySearchStart(arr, start, end, k);
    int j = binarySearchEnd(arr, start, end, k, end + 1);
    if (i == -1 || j == -1)
        return 0;
    return j - i + 1;
}

void decimalValues(int n, int k)
{
    int num = 10;
    int den = n;

    for (int i = 0; i < k; i++)
    {
        cout << num / den;
        num = (num % den) * 10;
    }
    cout << "\n";
}

string rearrangeDistance(string s, int d)
{
    int freq[26] = {0};

    for (int i = 0; i < s.length(); i++)
    {
        freq[s[i] - 'a']++;
    }
    for (int i = 0; i < 26; i++)
    {
        cout << freq[i] << " ";
    }
    return s;
}

int main()
{
    // int i;
    // // cin >> i;
    // i = 18;
    // printStrings (i, "");
    // egyptian (2, 11223);
    int arr[] = {-2, -3, 4, -1, -2, 1, 5, -3};
    int y = largestContSum(arr, 8);
    cout << y;
    cout << "\n";
    int arr1[] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 3, 3, 3, 3, 3, 3, 3, 5, 5, 5, 5, 5, 5, 5, 7, 7, 7, 7, 7, 7, 7, 8, 8, 8, 8, 8, 9};
    int size = sizeof(arr1) / sizeof(arr1[0]);
    cout << "1 binary " << binarySearch(arr1, 0, size - 1, 1) << endl;

    // cout << "3 binary " << binarySearch(arr1, 0, size-1, 3) << endl;
    // cout << "5 binary " << binarySearch(arr1, 0, size-1, 5) << endl;

    cout << "0.";
    decimalValues(61, 6);

    string a = rearrangeDistance("abb", 2);
    cout << a;
}
