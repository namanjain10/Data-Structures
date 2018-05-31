#include <iostream>
using namespace std;

void removeSpaces (char* a) {
    int count = 0;

    for (int i=0; a[i]; i++) {
        if (a[i] != ' ') a[count++]  = a[i];
    }
    a[count] = '\0';
}

int main() {
    char a[] = "naman jain hai naam mera";

    removeSpaces(a);
    cout << a << endl;
    return 0;
}
