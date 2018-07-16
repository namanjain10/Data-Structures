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

// #include <iostream>
// #include <stack>

// using namespace std;

// class queue {
    
//     stack <int> s1, s2;
//     int size;
    
//     void adjust () {
//         while (!s1.empty()) {
//             s2.push (s1.top());
//             s1.pop();
//         }
//     }

//     public:

//     queue () {
//         size = 0;
//     }
//     void push (int x) {
//         s1.push(x);
//         size++;
//     }    
//     void pop () {
//         if (size > 0) {
//             adjust();
//             s2.pop();
//             size--;
//         }
//     }
//     int top () {
//         if (size > 0) {
//             adjust();
//             return s2.top();
//         }
//     }    
//     bool empty () {
//         return (size == 0 ? 1:0);
//     }
// };

// int main() {
//     queue q1;
//     q1.push(2);
//     q1.push(1);
//     q1.push(3);
//     q1.push(4);
//     cout << q1.top() << endl;
//     q1.pop();
//     q1.pop();q1.pop();
//     cout << q1.top() << endl;
//     cout << q1.empty() << endl;
// }

// Implement stack using queue

// #include <iostream>
// #include <queue>

// using namespace std;

// class stack {
//     queue <int> q1, q2;
//     int size;

//     public:

//     stack () {
//         size = 0;
//     }
//     void push (int x) {
//         size++ ;
//         q2.push(x);
//         while (!q1.empty()) {
//             q2.push(q1.front());
//             q1.pop();
//         }
//         queue <int> q = q1;
//         q1 = q2;
//         q2 = q;
//     }
//     void pop () {
//         if (size > 0) {
//             q1.pop();
//             size--;
//         }
//     }
//     int top () {
//         if (size > 0) {
//             return q1.front();
//         }
//     }
//     bool empty () {
//         return (size == 0 ? 1:0);
//     }
// };

// int main () {
//     stack s;
//     s.push(1);
//     s.push(2);
//     s.push(3);
//     s.push(4);
//     cout << s.top() << endl;    
//     s.pop();s.pop();s.pop();
//     cout << s.top() << endl;
//     s.pop();
//     cout << s.empty() << endl;
// }

// Engineer Doctor Problem
// Everybody has two children.
// First child of an Engineer is an Engineer and second child is a Doctor.
// First child of an Doctor is Doctor and second child is an Engineer.
// All generations of Doctors and Engineers start with Engineer.

// #include <iostream> 
// using namespace std;
// int main () {
    

// } 


// Find the minimum element in Sorted and Rotated array

// #include <iostream>
// using namespace std;

// int minElement (int *arr, int start, int end) {

//     if (start - end == 0) return arr[start] ;

//     int m = (start + end)/2;
//     int mid = arr[m];

//     if (m-1 > start) {
//         if (m+1 < end) {
//             if (mid < arr[m-1]) {
//                 if (mid < arr[m+1]) {
//                     return mid;
//                 }
//             }
//             else if (mid < arr[m-1] && mid > arr[m+1]) {
//                 return minElement (arr, mid, end);
//             }
//             else if (mid > arr[m-1] && mid < arr[m+1]) {
//                 return minElement (arr, start, mid);
//             }
//         }

//         else {

//         }        
//     }
    
// }

// int main () {
//     int arr[] = {5,2,3,4};
//     int n = sizeof(arr)/ sizeof(int);

//     cout << minElement(arr, 0, n) << endl;
// }


// Find if two rectangles overlap

// #include <iostream>
// using namespace std;

// struct Point {
//     int x, y;
// };

// bool doOverlap (Point l1, Point r1, Point l2, Point r2) {
//     if (l1.x > r2.x || l2.x` x > r1.x) return false;
//     else if (l1.y < r2.y || l2.y < r1.y) return false;
//     return true;
// }

// int main () {

//     Point l1 = {0, 10}, r1 = {10, 0};
//     Point l2 = {5, 5}, r2 = {15, 0};
//     if (doOverlap(l1, r1, l2, r2)) cout << "Rectangles Overlap\n" ;
//     else cout << "Rectangles Don't Overlap\n";
// }


// kth smallest element of 2-d matrix

// #include <iostream> 
// #include <queue>
// using namespace std;

// struct Point {
//     int val, i, j;
// };

// class myComparator {
// public:
//     int operator() (const Point& p1, const Point& p2) {
//         return p1.val > p2.val;
//     }
// };

// int kthSmallestNumber (int ** arr , int k, int n) {

//     int x = 0, y = 0;
//     priority_queue <Point, vector<Point>, myComparator > p;

//     int ** check = new int*[n];

//     for (int i=0; i<n; i++) {
//         check[i] = new int[n];
//         for (int j=0; j<n; j++) {
//             check[i][j] = 0;
//         }
//     }

//     Point a;
//     a.val = arr[x][y], a.i = 0, a.j = 0;
//     p.push(a);

//     while (k-- && !p.empty()) {
//         x = p.top().i;
//         y = p.top().j;  
        
//         p.pop();

//         if (x+1 <= n-1 && check[x+1][y] == 0 ) {
//             a.val = arr[x+1][y], a.i = x+1, a.j = y;
//             p.push(a);
//             check[x+1][y] = 1;
//         }
//         if (y+1 <= n-1 && check[x][y+1] == 0) {
//             a.val = arr[x][y+1], a.i = x, a.j = y+1;
//             p.push(a);
//             check[x][y+1] = 1;
//         }
//     }
//     return p.top().val;
// }

// int main () {
//     int n = 4;

//     int ** arr = new int*[n];

//     for (int i=0; i<n; i++) {
//         arr[i] = new int[n];
//         for (int j=0; j<n; j++) {
//             cin >> arr[i][j];
//         }
//     }
//     cout << kthSmallestNumber (arr, 5, n) << endl;
// } 

// 10 20 30 40
// 15 25 35 45
// 27 29 37 48
// 32 33 39 50


// incomplete 

// #include <iostream>
// #include <map>
// using namespace std;

// struct Node {
//     string val;
//     Node* next;
// };

// int main() {
    
//     map <string, Node*> dict;
//     int n;
//     Node* head;

//     cin >> n;

//     while (n--) {

//         string a, b;    
//         Node* temp, *add;

//         cin >> a >> b;

//         if (dict.count (a) > 0) {
//             temp = dict.find(a)->second;

//             add = new Node;
//             add->val = b;
//             add->next = NULL;
            
//             dict.insert(pair <string, Node*> (add->val, add));
//             temp->next = add;
//         }

//         else {
//             add = new Node;
//             add->val = a;
//             add->next = NULL;

//             dict.insert(pair <string, Node*> (add->val, add));

//             if (dict.count (b) > 0) {
//                 temp = dict.find(b)->second;

//             }
//             else {
//                 temp = new Node;
//                 temp->val = b;
//                 temp->next = add;

//                 dict.insert(pair <string, Node*> (temp->val, temp));
//             }
//         }

//     }

//     while (head != NULL) {
//         cout << head->val << " -> " ;
//         head = head->next;
//     }

// }


// maximum average path 2-d array

// #include <iostream> 
// using namespace std;

// int maxPathUtil (int ** arr, int n, int i, int j, int cost, int** dp) {

//     if (i >= n || j>= n) return cost;

//     if (dp[i][j] != -1) return dp[i][j];

//     int x = maxPathUtil(arr, n, i+1, j, cost + arr[i][j], dp);
//     int y = maxPathUtil(arr, n, i, j+1, cost + arr[i][j], dp);

//     dp[i][j] = (x>y) ? x:y ; 
//     return dp[i][j];
// }

// int maxPath (int ** arr, int n) {

//     int ** dp = new int*[n];

//     for (int i=0; i<n; i++) {
//         dp[i] = new int[n];
//         for (int j=0; j<n; j++) {
//             dp[i][j] = -1;
//         }
//     }
//     return maxPathUtil(arr, n, 0, 0, 0, dp);
// }

// int main () {   

//     int n = 6;

//     int ** arr = new int*[n];        

//     for (int i=0; i<n; i++) {
//         arr[i] = new int[n];
//         for (int j=0; j<n; j++) {
//             cin >> arr[i][j];
//         }
//     }

//     cout << maxPath (arr, n)/n << endl;
// } 


// incomplete
// collect all coins in min number of steps

// #include <iostream>
// using namespace std;

// int minSteps (int * arr, int start, int end) {

//     int min = INT16_MAX, temp;
//     for (int i=start; i<end; i++) {
//         if (arr[i] < min) min = arr[i];
//     }
    
// }

// int main () {
//     int n;
//     cin >> n;

//     int *arr = new int[n];

//     for (int i=0; i<n; i++) {
//         cin >> arr[i];
//     }    

//     cout << minSteps (arr, 0, n-1) << endl; 

// }


// incomplete

// next number from a given string of numbers

// #include <iostream>
// #include <string.h>

// using namespace std;

// int desc (string number, int k) {
//     int greatest = number[k], greatestPos = k;

//     for (int i=k+1; i<number.length(); i++) {
//         if (number[i] > greatest) {
//             greatest = number[i] ;
//             greatestPos = i; 
//         }
//     }
//     return greatestPos;
// }

// string asc (string number, int x, int y) {
//     string num;
//     for (int i=x; i<number.length(); i++) {
//         if (i == y) i++;
//         num += number[i]; 
//     }
//     return num;
// }

// int main () {
//     string number, str1;  
//     cin >> number;

//     for (int i=number.length()-2; i>=0; i--) {
//         // cout << number[i] << " ";
//         int k = desc(number, i);

//         if (k != i) {
//             str1 = number.substr(0, i) ;
//             str1 += number[k];
//             str1 += asc(number, i, k);
//             break;
//         }
//         // else cout << "\n";
//     }
//     cout << str1 << '\n'; 
// }


// find the element in the sorted array not appaering twice

// #include <iostream>
// using namespace std;

// int binarySearch (int * arr, int start, int end, int k) {

//     if (end - start <= 0) return start;

//     int mid = (start + end)/2; 

//     if (arr[mid] < k) return binarySearch (arr, mid+1, end, k);
//     else return binarySearch (arr, start, mid-1, k);
// } 

// int searchNonDuplicate (int * arr, int start, int end, int n) {

//     if (end == start) return arr[start];

//     int mid = (start + end)/2;

//     // cout << "start " << start << " end " << end << endl;
//     // cout << "mid " << mid << " value " << arr[mid] << endl;

//     if ((mid - start) %2 != 0) {
//         if (mid-1 >= 0 and arr[mid] == arr[mid-1]) {
//             if ((end - mid) % 2 == 0) return searchNonDuplicate (arr, mid, end, n);
//             else return searchNonDuplicate (arr, mid+1, end, n) ;
//         }

//         else {
//             if (mid+1 < n and arr[mid] != arr[mid+1]) return arr[mid];
//             else {
//                 if ((mid - start) % 2 == 0) return searchNonDuplicate(arr, start, mid, n);
//                 else return searchNonDuplicate (arr, start, mid-1, n);
//             }
//         }
//     }

//     else {
//         if (mid-1 >= 0 and arr[mid] == arr[mid-1]) {
//             if ((mid - start) % 2 == 0) return searchNonDuplicate(arr, start, mid, n);
//             else return searchNonDuplicate (arr, start, mid-1, n);
//         }

//         else {
//             if (mid+1 < n and arr[mid] != arr[mid+1]) return arr[mid];
//             else {
//                 if ((end - mid) % 2 == 0) return searchNonDuplicate (arr, mid, end, n);
//                 else return searchNonDuplicate (arr, mid+1, end, n) ;
//             }
//         }
//     }
// }

// int main () {
//     int arr[] = {0,0,1,1,2,2,3,3,4,4,5,5,6,6,7,7,8,8,9,9,10,10,11,11,12};
//     int n = sizeof (arr)/ sizeof (int);

//     cout << searchNonDuplicate (arr, 0, n-1, n) << endl;
// }


// toppers of class

// #include <iostream>
// #include <algorithm>
// #include <limits.h>
// using namespace std;

// struct student{
//     int id, marks;
// };

// int func (student a, student b) {
    
//     if(a.marks > b.marks) return true;
//     if(a.marks == b.marks) return a.id < b.id;
//     return false;
// }

// int main() {
	
// 	int t;
// 	cin >> t;
	
// 	while (t--) {
// 	    int n, k; 
// 	    student arr[10000];
	    
// 	    cin >> n;
	    
// 	    for (int i=0; i<n; i++) {
// 	        arr[i].id = i;
// 	        cin >> arr[i].marks;
// 	    }
	    
// 	    cin >> k;
	    
// 	    sort (arr, arr+n, func);
	    
// 	    int small = INT_MAX;
	    
// 	    for (int i=0; i<n; i++) {
	        
// 	        if (small > arr[i].marks) {
// 	            small = arr[i].marks;
// 	            k--;
// 	        }
// 	        if (k == -1) break;
// 	        cout << arr[i].id << " ";
	        
// 	    }
// 	    cout << '\n';
// 	}
// 	return 0;
// }


// magnet problem

// #include <iostream>
// #include <iomanip>
// using namespace std;

// long double findZero (long double start, long double end, int * arr, int k, int n) {

// 	// cout << "entering " << start << " " << end << " " << end - start << "\n";

// 	if (end - start <= 0.0000000000001) return start;

// 	long double mid = (start + end) / 2;
// 	long double sum = 0;

// 	for (int i=0; i<=k; i++) {
// 		sum += 1/(arr[i] - mid);
// 	}

// 	for (int i=k+1; i<n; i++) {
// 		sum += 1/(arr[i] - mid);
// 	}

// 	if (sum == 0) return mid;
// 	else if (sum > 0) return findZero (start, mid, arr, k, n);
// 	else return findZero (mid, end, arr, k, n);
// }

// double round (long double k) {
// 	double value = (int)(k * 100 + .5);
//     return (double)value / 100;
// }  

// int main() {
	
// 	int arr[] = {0, 10, 20, 30};
// 	int n = sizeof(arr) / sizeof(int);

// 	for (int i=0; i<n-1; i++) {
// 		cout << fixed << setprecision(2) << findZero (arr[i], arr[i+1], arr, i, n) << " ";
// 	}
// 	cout << '\n';
// }
 

// sum of 2 elements of an array equal to k 

// #include <iostream>
// #include <map>
// using namespace std;

// void getPair(int * arr, int n, int k) {
// 	map <int, int> hash;

// 	for (int i=0; i<n; i++) {
// 		hash.insert(pair<int, int> (arr[i], i));
// 	}
// 	map<int, int> :: iterator i;
//     map<int, int> check;

// 	for (i = hash.begin(); i != hash.end(); i++) {

// 		if (hash.count(k - i->first) > 0) {
            
//             if (hash.find(k - i->first)->second != i->second && check.count(hash.find(k - i->first)->second) == 0 && check.count(i->second) == 0){

//                 cout << i->first << ", " << hash.find(k - i->first)->first << "\n";
//                 check.insert(pair<int, int>(i->second, 1));
//                 check.insert(pair<int, int>(hash.find(k - i->first)->second, 1));
//             }
//         }
// 	}
// } 

// int main () {

// 	int arr[] = {8, 3, 5, 1, 2, 2, 7};
// 	int n = sizeof(arr) / sizeof(int);
// 	int k = 10;

// 	getPair (arr, n, k); 
// }


// search the smallest number in a sorted rotated array

// #include <iostream>
// using namespace std;

// int findSmallest (int * arr, int n, int start, int end) {
//     if (end -start <= 0) return arr[start];

//     int mid = (start + end) /2;
    
//     cout << "start " << start << " end " << end << " arr[mid] " << arr[mid] << endl;

//     if (arr[mid-1] > arr[mid]) return arr[mid];
//     else if (arr[mid] < arr[n-1]) return findSmallest (arr, n, start, mid-1);
//     else return findSmallest (arr, n, mid+1, end);
// }
 
// int main () {
//     int arr[] = {3,4,5,6,1,2};
//     int n = sizeof(arr)/sizeof(int);

//     cout << findSmallest (arr, n, 0, n-1) << endl;
// }


// search an element in a sorted rotated array

// #include <iostream>
// using namespace std;

// int findSmallest (int * arr, int n, int start, int end) {
//     if (end -start <= 0) return start;

//     int mid = (start + end) /2;
    
//     if (arr[mid-1] > arr[mid]) return mid;
//     else if (arr[mid] < arr[n-1]) return findSmallest (arr, n, start, mid-1);
//     else return findSmallest (arr, n, mid+1, end);
// }

// int binarySearch (int* arr, int start, int end, int k) {
//     if (end - start <= 0) {
//         if (arr[start] == k)
//         return start;
//         return -1;
//     }
//     int mid = (start + end) /2;

//     if (arr[mid] == k) return mid;
//     else if (arr[mid] > k) return binarySearch (arr, start, mid-1, k);
//     else return binarySearch (arr, mid+1, end, k);
// }

// int findElement (int * arr, int n, int start, int end, int k) {
//     int i = findSmallest (arr, n, start, end);
//     int x = binarySearch (arr, start, i, k);
//     if (x != -1) return x;
//     int y = binarySearch (arr, i+1, end, k); 
//     if (y != -1) return y;
//     return -1;
// }

// int main() {
//     int arr[] = {4,5,6,1,2,3};
//     int n = sizeof(arr)/sizeof(int);
//     cout << findElement (arr, n, 0, n-1, 3) << endl;
// }

// find the majority element

// #include <iostream>
// #include <map>
// using namespace std;

// void findMajorityElement (int * arr, int n) {
//     map <int, int> hash;
//     for (int i=0; i<n; i++) {
//         if (hash.count(arr[i]) == 0) {
//             hash.insert(pair<int,int> (arr[i], 1));
//         }
//         else {
//             map<int, int>:: iterator itr = hash.find(arr[i]);
//             itr->second ++; 
//         } 
//     }
//     map<int, int>:: iterator itr;
//     for (itr = hash.begin(); itr != hash.end(); ++itr) {
//         if (itr->second >= n/2) {
//             cout << itr->first << endl;
//             return;
//         }
//     }
//     cout << "NO Majority Element\n";
// }

// int main() {
//     int arr[] = {4,4,14,24,2,3};
//     int n = sizeof(arr)/sizeof(int);
//     findMajorityElement (arr, n);
// }


// incomplete check if mathematical expressions are same

// #include <iostream>
// #include <stack>
// using namespace std;

// int same (string s1, string s2) {
//     stack <pair<char, int> > brackets;
//     int sign = 0;

//     for (int i=0; i<s1.length(); i++) {
//         if (s1[i] == '-') sign = 1;
//         if (s1[i] == '(') ;
//     }
// }

// int main() {
//     string s1, s2;
//     cin >> s1 >> s2;
//     cout << same(s1, s2) << endl; 
// }

// smallest number digit product k  

// #include <iostream>
// #include <math.h>
// using namespace std;

// int smallestNumber(int k) {
//     int i = 9, arr[1000], m = 0;
    
//     while (i>1 && k > 1) {
//         if (k%i == 0) {
//             arr[m++] = i;
//             k = k/i;
//             i = 9;
//         }
//         else i--;
//     }
    
//     int sum = 0;
//     if (k != 1) return -1;

//     while (m--) {
//         sum += pow(10,m) * arr[m];
//     } 
//     return sum;   
// }

// int main() {
//     cout << smallestNumber (27) << endl;
// }


// incomplete combinational sum 

// #include <iostream>
// using namespace std;

// void combinationalSumUtil (int * arr, int n, int i, int sum, int x) {
    
//     int k = i;
//     while (sum < x && k<n) {        
//         cout << "adding " << arr[k] << " to sum " << sum << " " ;
//         sum = sum + arr[k];
//         // cout << "sum is " << sum << "\n";
//         if (sum == x) {
//             cout << "got it\n";
//             return;
//         }
//         combinationalSumUtil (arr, n, k, sum, x);
//         // sum = sum - arr[k];
//         k++;
//     }
//     // cout << "exit\n";
//     return;
// }   

// void combinationalSum (int * arr, int n, int x) {
//     int i=0; 
//     while (i != n) {
//         cout << "for " << arr[i] << ".........\n";
//         combinationalSumUtil (arr, n, i, 0, x);
//         i++;
//     }    
// }

// int main () {
//     int arr[] = {2,4,6,8};
//     int n = sizeof (arr) / sizeof (int);
//     combinationalSum (arr, n, 8);
// }


// incomplete segregate and order odd even

// #include <iostream>
// using namespace std;

// void swap (int * arr, int a, int b) {
//     int temp = arr[a];
//     arr[a] = arr[b];
//     arr[b] = temp;
// }

// void segregateOddEven (int *arr, int n) {
//     int a = 0, b = 0;
//     cout << "entered\n";
//     while (a != n-1 && b != n-1) {
//         while (arr[a]%2 != 0) {
//             a++;
//         }
//         cout << "a is " << a << endl; 
//         while (arr[b]%2 != 1) {
//             b++;
//         }
//         cout << "b is " << b << '\n';
//         if (b < a) {
//             cout << "swap " << arr[a] << " " << arr[b] << '\n';
//             swap(arr, a, b);
//         }
//         a++;
//         b++;
//     }  

// }

// int main () {
//     int arr[] = {3,4,1,7,2,6,9};
//     int n = sizeof(arr)/sizeof(int);

//     segregateOddEven (arr, n);

//     for (int i=0; i<n; i++) cout << arr[i] << " ";
//     cout << '\n';
// }


// maximum sum after k negations

// # include <iostream>
// # include <queue>
// #include <algorithm>
// using namespace std;

// int maximizeSum (int * arr, int n, int k) {
//     priority_queue <int, vector<int>, greater<int> > queue;

//     for (int i=0; i<n; i++)
//     queue.push (arr[i]);

//     while (k--) {
//         int x = queue.top();
//         queue.pop();
//         queue.push (-x);
//     }
//     int sum = 0;
//     for (int i = 0; i < n; i++) {
//         sum += queue.top();
//         queue.pop();
//     }
//     return sum;
// }

// int main () {
//     int arr[] = {-2, 0, -5, -1, -2};
//     int n = sizeof(arr)/sizeof(int);
//     cout << maximizeSum (arr, n, 4) << endl; 
// }

// Maximum Intervals Overlap

// #include <iostream>
// #include <algorithm>
// using namespace std; 

// int maxGuests (int *arri, int *exit, int n) {
        
//     sort (arri, arri+n);
//     sort (exit, exit+n);
    
//     int max = 0, count = 0, i=0, j=0;
    
//     while (i <= n-1) {
//         if (arri[i] <= exit[j]) {
//             count ++;
//         if (count > max) max = count;
//             i++;
//         }
//         else {
//             count --;
//             j++;
//         }
//         
//     }
//     return count;
// }

// int main() {
//     int arri[] = {1, 2, 9, 5, 5};
//     int exit[] = {4, 5, 12, 9, 12};

//     int n = sizeof(arri)/sizeof(int);

//     cout << maxGuests(arri, exit, n) << endl;
// }

// Nth root of M

// #include <iostream>
// #include <math.h>
// using namespace std;

// double NthRootUtil (int n, int m, double start, double end) {
//     if (end - start <= 0.000001) return start;
//     double mid = (start + end)/2;
//     double k = pow(mid, n);
    
//     if (k == m) return mid;
//     else if (k > m) return NthRootUtil(n, m, start, mid);
//     else return NthRootUtil(n, m, mid, end);
// }

// double NthRoot (int n, int m) {
//     return NthRootUtil (n, m, 0, m);
// }

// int main () {
//     cout << NthRoot (4, 9) << endl;
// }


// incomplete find extra element

// #include <iostream>
// using namespace std;

// int findExtraUtil (int *arr1, int start1, int end1, int *arr2, int start2, int end2) {

//     cout << "start1 " << arr1[start1] << " end1 " << arr1[end1] << " start2 " << arr2[start2] << " end2 " << arr2[end2] << endl;

//     if (end1 - start1 <= 0) return start1;
//     if (end2 - start2 <= 0) {
//         if (arr1[start1] == arr2[start2]) return end1;
//         else return start1;
//     }

//     int mid1 = (start1 + end1)/2;

//     int mid2 = (start2 + end2)/2;
//     if ((end2 - start2)%2 == 1) mid2 ++;

//     cout << "mid1 " << mid1 << " mid2 " << mid2 << " arr1 " << arr1[mid1] << " arr2 " << arr2[mid2] << endl;

//     if (arr1[mid1] < arr2[mid2]) return findExtraUtil(arr1, start1, mid1, arr2, start2, mid2-1);
//     else return findExtraUtil(arr1, mid1, end1, arr2, mid2+1, end2);
// }

// int findExtra (int *arr1, int n1, int *arr2, int n2) {
//     return findExtraUtil (arr1, 0, n1-1, arr2, 0, n2-1); 
// }

// int main () {

//     int arr1[1000], arr2[1000], n;
//     cin >> n;

//     for (int i=0; i<n; i++) cin >> arr1[i];
//     for (int i=0; i<n-1; i++) cin >> arr2[i];

//     cout << findExtra (arr1, n, arr2, n-1) << endl;
// }


// Min Steps in Infinite Grid

// #include <iostream>
// using namespace std;

// struct Point {
//     int x, y;
// };

// int abs (int a) {
//     return a < 0 ? -a : a; 
// }
// int min (int a, int b) {
//     return a < b ? a:b;
// }
// int minSteps (Point * arr, int n) {
//     int count=0, x = arr[0].x, y = arr[0].y, c, d;

//     for (int i=1; i<n; i++) {
//         c = abs(arr[i].x - x) ,d = abs(arr[i].y - y);
//         count += min(c,d) + abs(c-d);
//         x = arr[i].x, y = arr[i].y;
//     }
//     return count;
// }

// int main () {
//     Point arr[1000];
//     int n;
//     cin >> n;
//     for (int i=0; i<n; i++) {
//         cin >> arr[i].x >> arr[i].y; 
//     }
//     cout << minSteps (arr, n) << endl;
// }


// Find a number in minimum steps on infinite number line

// #include <iostream>
// #include <queue>
// using namespace std;

// int smallestPath (int n) {
//     queue <pair<int, int> > arr;
//     arr.push(pair<int, int>(0, 0));
//     int x, y;

//     while (1) {
//         x = arr.front().first;
//         y = arr.front().second;
//         if (x == n) break;
//         arr.pop();
//         arr.push(pair<int, int>(x + (y+1), y+1));
//         arr.push(pair<int, int>(x - (y+1), y+1));
//     }
//     return y; 
// }

// int main() {
//     cout << smallestPath(5) << endl;
// }

// Kth smallest element from 2-D matrix (using min heap)

// #include <iostream>
// #include <queue>
// using namespace std;

// struct Point {
//     int val, x, y;
// };

// class myComparator {
// public:
//     int operator() (const Point& p1, const Point& p2) {
//         return p1.val > p2.val;
//     }
// };

// int minElement (int ** arr, int n, int k) {

//     priority_queue <Point, vector<Point>, myComparator > hash;

//     for (int i=0; i<n; i++) {
//         Point a;
//         a.val = arr[0][i], a.x = 0, a.y = i;
//         hash.push(a);
//     }
//     Point a;
//     while (k--) {
//         a = hash.top();
//         // cout << a.val << " " << a.x << " " << a.y << '\n';
//         hash.pop();
//         if (a.x < n-1) {
//             Point b;
//             b.val = arr[a.x+1][a.y] ;
//             b.x = a.x+1;
//             b.y = a.y;
//             hash.push(b);
//         }        
//     }
//     return a.val;
// }

// int main() {
//     int n, k;
//     cin >> n;
//     int ** arr = new int*[n]; 

//     for (int i=0; i<n; i++) {
//         arr[i] = new int[n];
//         for (int j=0; j<n; j++) {
//             cin >> arr[i][j];
//         }
//     }
//     cin >> k;
//     cout << minElement (arr, n, k) << endl;    
// }


// Find the smallest missing number

// #include <iostream>
// using namespace std;

// int smallestMissingNumberUtil (int *arr, int start, int end) {
//     if (end - start <= 0) return start;

//     if (start != arr[start]) return start;
    
//     int mid = (start + end)/2;
//     // cout << mid << endl;
//     if (mid == arr[mid]) return smallestMissingNumberUtil(arr, mid+1, end);
//     else return smallestMissingNumberUtil(arr, start, mid);
// }

// int smallestMissingNumber (int *arr, int n) {
//     return smallestMissingNumberUtil(arr, 0, n-1);
// }

// int main() {
//     int arr[] = {0, 1, 2, 3, 4, 5, 6, 7, 10};
//     int n = sizeof (arr) / sizeof(int);

//     cout << smallestMissingNumber (arr, n) << endl;
// }


// k-th prime factor of a given number

// #include <iostream>
// using namespace std;

// int* findPrimeNumbers (int k) {
//     int* arr = new int[k+1];
//     for (int i=2; i<k+1; i++) arr[i] = -1;

//     for (int i=2; i<k+1; i++) {
//         if (arr[i] != 0) {
//             arr[i] = 1;
//             int l = 2;
//             while (i*l < k+1) {
//                 arr[i*l] = 0;
//                 l++; 
//             }
//         }
//     }
//     return arr;
// }

// int KthPrimeFactor (int n, int k) {
//     int* prime = findPrimeNumbers(n/2);
//     int y=0, i=2;

//     while (i <= n/2 || k == 1) {  
//         if (prime[i] != 0) {
//             if (n%i == 0) {
//                 n = n/i;
//                 k--;
//             }
//             else i++;
//         }
//         else i++;

//         if (k <= 0) {
//             y = i;
//             break;
//         }
//     }
//     if (y == 0) return -1;
//     return y;
// }

// int main () {
//     cout << KthPrimeFactor (81, 5) << endl;
// }


// print pascal triangle

#include <iostream>
using namespace std;

void swap (int a, int b) {
    int temp = a;
    a = b;
    b = temp;
}

void pascalTriangle (int n) {
    int* a = new int [n];
    int* b = new int [n];

    for (int i=0; i<n; i++) {
        for (int j=0; j<=i; j++) {
            if (j == 0 || j == i) {
                b[j] = 1;
                cout << "1 ";
            }
            else {
                b[j] = a[j-1] + a[j];
                cout << b[j] << " ";
            }
        }
        swap (a, b);
        cout << '\n';
    }
}

// int binomialCoeff(int n, int k) {
//     int res = 1;
//     if (k > n - k) k = n - k;
    
//     for (int i = 0; i < k; ++i) {
//         res *= (n - i);
//         res /= (i + 1);
//     }     
//     return res;
// }

// void pascalTriangle (int n) {
//     int* a = new int [n];
//     int* b = new int [n];

//     for (int i=0; i<n; i++) {
//         for (int j=0; j<=i; j++) {
//             if (j == 0 || j == i) {
//                 cout << "1 ";
//             }
//             else {
//                 int b = binomialCoeff(i,j);
//                 cout << b << " ";
//             }
//         }
//         cout << '\n';
//     }
// }

int main() {
    pascalTriangle (14);
}
