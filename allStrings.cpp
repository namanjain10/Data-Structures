#include <iostream>
#include <math.h>
using namespace std;

void printStrings(int n, string s) {
    if (n == 0) {
        cout << s << endl;
        return;
    }
    printStrings(n-1, s+"0");
    printStrings(n-1, s+"1");
}


int largestContSum (int* arr, int n) {
    int largest = 0, large_till = 0;

    for (int i=0; i<n; i++) {
        large_till += arr[i];
        if (large_till > largest) largest = large_till;

        else if (large_till < 0) large_till = 0;
    }
    return largest;
}

//Find all Egyptian fractions

void egyptian (int nr, int dr) {
    // cout << "nr " << nr << " dr " << dr << endl;
    if (nr%dr == 0) {
        return;
    }

    else if (nr > dr) {
        int r = nr/dr;
        cout << r << " + ";
        egyptian (nr - r*dr, dr);
    }

    else {
        int r = ceil(float (dr)/nr);
        cout << "1/" << r << " + ";
        egyptian (nr*r - dr, r*dr);
    }
}

int main() {
    // int i;
    // // cin >> i;
    // i = 18;
    // printStrings (i, "");
    // egyptian (2, 11223);
    int arr[] = {-2, -3, 4, -1, -2, 1, 5, -3};
    int y = largestContSum (arr, 8);
    cout << y ;
    cout << "\n";
}
