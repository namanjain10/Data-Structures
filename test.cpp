// #include <iostream>
// using namespace std;
// int main () {
//     int min_x, min_y, max_x, max_y, n, x1, y1, x2, y2, r;
//     char c;
//
//     cin >> n;
//     int y = 1;
//
//     while (n--) {
//         cin >> c;
//         if (c == 'p') {
//             cin >> x1 >> y1;
//             if (y == 1) {
//                 min_x = max_x = x1;
//                 min_y = max_y = y1;
//                 y = 0;
//             }
//             else {
//                 if (x1 < min_x) min_x = x1;
//                 if (x1 > max_x) max_x = x1;
//                 if (y1 < min_y) min_y = y1;
//                 if (y1 > max_y) max_y = y1;
//             }
//         }
//         else if (c == 'c'){
//             cin >> x1 >> y1 >> r;
//             if (y == 1) {
//                 min_x = x1-r;
//                 min_y = y1-r;
//                 max_x = x1+r;
//                 max_y = y1+r;
//                 y = 0;
//             }
//             else {
//                 if (x1 + r > max_x) max_x = x1 + r;
//                 if (x1 - r < min_x) min_x = x1 - r;
//                 if (y1 + r > max_y) max_y = y1 + r;
//                 if (y1 - r < min_y) min_y = y1 - r;
//             }
//         }
//         else if (c == 'l'){
//             cin >> x1 >> y1 >> x2 >> y2;
//             if (y == 1) {
//                 min_x = (x1<x2)?x1:x2;
//                 max_x = (x1>x2)?x1:x2;
//                 min_y = (y1<y2)?y1:y2;
//                 max_y = (y1>y2)?y1:y2;
//                 y = 0;
//             }
//             else {
//                 if (x1 < min_x) min_x = x1;
//                 if (x1 > max_x) max_x = x1;
//                 if (x2 < min_x) min_x = x2;
//                 if (x2 > max_x) max_x = x2;
//
//                 if (y1 < min_y) min_y = y1;
//                 if (y1 > max_y) max_y = y1;
//                 if (y2 < min_y) min_y = y2;
//                 if (y2 > max_y) max_y = y2;
//             }
//         }
//     }
//     cout << min_x << " " << min_y << " " << max_x << " " << max_y << '\n';
// }

// spiral print

// #include <iostream>
// using namespace std;
// int main() {
//
//     int arr[6][6] = { {1,  2,  3,  4,  5,  6},
//                     {7,  8,  9,  10, 11, 12},
//                     {13, 14, 15, 16, 17, 18},
//                     {19, 20, 21, 22, 23, 24},
//                     {25, 26, 27, 28, 29, 30},
//                     {1 , 1 , 2 , 2 , 3 , 3 }
//                     };
//     int i=0, j=0, n=6;
//
//     for (int k=0; k<(n/2)+1;) {
//
//         while (j<n-k-1) {
//             cout << arr[i][j] << " ";
//             j++;
//         }
//         while (i<n-k-1) {
//             cout << arr[i][j] << " ";
//             i++;
//         }
//         while (j>0+k) {
//             cout << arr[i][j] << " ";
//             j--;
//         }
//         k++;
//         while (i>0+k) {
//             cout << arr[i][j] << " ";
//             i--;
//         }
//     }cout << '\n';
// }

// numbers to words (not accurate but will do)

// #include <iostream>
// using namespace std;
//
// int main() {
//     string units[] = {"one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
//     string tens[] = {"twenty", "thirty", "fourty", "fifty", "sixty", "seventy", "eighty", "ninety"};
//     string one[] = {"ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"};
//     string higher[] = {"hundred", "thousand"};
//
//     int number, digit = 0, arr[100];
//     cin >> number;
//
//     while (number != 0) {
//         arr[digit++] = number%10;
//         number = number/10;
//     }
//
//     for (int i=0; i<digit; i++) {
//         if (i == 1) {
//             if (arr[i] == 1) cout << one[arr[0]] << " ";
//             else if (arr[i] != 0) cout  << tens[arr[i]-2] << " ";
//         }
//         if (i == 0 && arr[i] != 0 && arr[i+1] != 1) cout << units[arr[i]-1] << " ";
//         if (i > 1 && arr[i] != 0) cout << units[arr[i]-1] << " " << higher[i-2] << " " ;
//     }
// }

// parenthesis check

// #include <iostream>
// #include <stack>
// #include <map>

// using namespace std;

// int balancedParentheses (string s) {
//     stack <char> arr;
//     map <char,char> valid;

//     valid.insert(pair <char, char> ('}','{'));
//     valid.insert(pair <char, char> (')','('));
//     valid.insert(pair <char, char> (']','['));
    
//     for (int i=0; i<s.length(); i++) {
//         if (arr.empty()) arr.push(s[i]);
//         else {
//             if (arr.top() == valid.find(s[i])->second) {
//                 arr.pop();
//             }
//             else arr.push(s[i]);
//         }
//     }
//     if (arr.empty()) return 1;
//     else return 0;
// } 

// int main () {
    
//     string s = "[()]{}{[()(])()}";
//     int q = balancedParentheses(s);
//     cout << q << '\n';
// }

// implement queue from stack (using 2 stacks)

#include <iostream>
#include <stack>

using namespace std;

class queue {
    
    stack <int> s1, s2;
    int size;
    
    void adjust () {
        while (!s1.empty()) {
            s2.push (s1.top());
            s1.pop();
        }
    }

    public:

    queue () {
        size = 0;
    }
    void push (int x) {
        s1.push(x);
        size++;
    }    
    void pop () {
        if (size > 0) {
            adjust();
            s2.pop();
            size--;
        }
    }
    int top () {
        if (size > 0) {
            adjust();
            return s2.top();
        }
    }    
    bool empty () {
        return (size == 0 ? 1:0);
    }
};

int main() {
    queue q1;
    q1.push(2);
    q1.push(1);
    q1.push(3);
    q1.push(4);
    cout << q1.top() << endl;
    q1.pop();
    q1.pop();q1.pop();
    cout << q1.top() << endl;
    cout << q1.empty() << endl;
}