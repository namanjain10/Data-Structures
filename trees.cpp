#include <iostream>
#include <queue>
#include <map>

using namespace std;

struct Node {
	int val;
	Node* left;
	Node* right;
};

struct Tree {
	Node* root;
};

Tree* newTree () {
	Tree* p = new Tree;
	p->root = NULL;
	return p;
}

void insert (Tree* tree, int x) {

	Node* add = tree->root;

	if (add == NULL) {
		tree->root = new Node;
		tree->root->val = x;
		tree->root->left = NULL;
		tree->root->right = NULL;
	}

	else {
		Node* temp = new Node;
		temp->val = x;
		temp->left = NULL;
		temp->right = NULL;

		while (add != NULL) {
			if (add->val < x) {
				if (add->right == NULL) {
					add->right = temp;
					break;
				}
				add = add->right;
			}
			else {
				if (add->left == NULL) {
					add->left = temp;
					break;
				}
				add = add->left;
			}
		}
	}
}

void printIn (Node* tree) {

	if (tree == NULL) return;

	printIn (tree->left);
	cout << tree->val << " ";
	printIn (tree->right);
}

void printPre (Node* tree) {

	if (tree == NULL) return;

	cout << tree->val << " ";

	printPre (tree->left);
	printPre (tree->right);
}

void printPost(Node* tree) {
	if (tree == NULL) return;

	printPost (tree->left);
	printPost (tree->right);
	cout << tree->val << " ";

}

int countNodes (Node* node) {

	if (node == NULL) return 0;

	int left = countNodes(node->left);
	int right = countNodes(node->right);

	return left+right+1;
}

int height (Node* node) {

	if (node == NULL) return 0;

	int left = height(node->left);
	int right = height(node->right);

	return max(left, right) + 1;
}

bool sum(Node* node, int x, int y) {
	bool t, r;

	if (node->right == NULL) {
		if(node->left == NULL) {
			if (node->val+x == y) return true;
			else return false;
		}
		else return sum(node->left, node->val + x, y);
	}
	else {
		if (node->left == NULL) return sum(node->right, node->val + x, y);

		else {
			t = sum(node->left, node->val + x, y);
			r = sum(node->right, node->val + x, y);

			return r||t;
		}
	}
}

int abs (int y) {
	if (y < 0) return -y;
	else return y;
}

bool balanced(Node* node) {
	if (node == NULL) return 1;
	int right = height(node->right);
	int left = height(node->left);

	if (abs(right-left) > 1) return 0;
	else return 1;
}

int diameter (Node* node) {
	if (node == NULL) return 0;

	int right = height(node->right);
	int left = height(node->left);

	return (right+left) + 1;
}

bool childrenSumProperty (Node* node) {
	if (node == NULL) return 1;

	bool r, l;

	if (node->right == NULL) {
		if (node->left == NULL) {
			return 1;
		}
		else {
			if (node->val == node->left->val) {
				return childrenSumProperty (node->left);
			}
			else return 0;
		}
	}
	else {
		if (node->left == NULL) {
			if (node->val == node->right->val) {
				return childrenSumProperty (node->right);
			}
			else return 0;
		}
		else {
			if (node->val == (node->left->val + node->right->val)) {
				r = childrenSumProperty (node->right);
				l = childrenSumProperty (node->left);
				return r&&l;
			}
			else return 0;
		}
	}
}

int countLeafNodes (Node* node, int x) {
	if (node == NULL) return x;

	if (node->left == NULL) {
		if (node->right == NULL) return x+1;
		else return countLeafNodes (node->right, x);
	}

	else {
		if (node->right == NULL) return countLeafNodes (node->left, x);
		else {
			int l = countLeafNodes (node->left, x);
			int r = countLeafNodes (node->right, x);
			return l+r;
		}
	}
}

void printPath (Node* node, int* path, int pathLength) {
	if (node != NULL) {
		path[pathLength] = node->val;
		pathLength ++;
	}

	if (node->left == NULL) {
		if (node->right == NULL) {
			for (int i=0; i<pathLength; i++) cout << path[i] << " ";
			cout << endl;
		}
		else printPath (node->right, path, pathLength);
	}
	else {
		if (node->right == NULL) printPath (node->left, path, pathLength);
		else {
			printPath (node->left, path, pathLength);
			printPath (node->right, path, pathLength);
		}
	}
}

void printRootLeafPaths (Node* root) {
	int path[1000];
	printPath (root, path, 0);
}

void printAncestorsRecursion (Node* node, int key, int* path, int pathLength) {
	if (node != NULL) {
		path[pathLength] = node->val;
		pathLength ++;

		if (node->val == key) {
			for (int i=pathLength-2; i>=0; i--) cout << path[i] << " ";
				cout << endl;
		}
	}
	if (node->left == NULL) {
		if (node->right == NULL) {
			return;
		}
		else printAncestorsRecursion (node->right, key, path, pathLength);
	}
	else {
		if (node->right == NULL) printAncestorsRecursion (node->left, key, path, pathLength);
		else {
			printAncestorsRecursion (node->left, key, path, pathLength);
			printAncestorsRecursion (node->right, key, path, pathLength);
		}
	}
}

void printAncestors (Node* root, int key) {
	int path[1000];
	printAncestorsRecursion (root, key, path, 0);
}

int findNode(int* in, int x, int start, int end) {
	for (int i=start; i<=end; i++) {
		if (in[i] == x) return i;
	}
}

Node* constTreeInPre1 (int* in, int* pre, int start, int end, int* preCount){

	if (end-start < 0) return NULL;

	Node* add = new Node;
	add->val = pre[*preCount];
	(*preCount)++;

    for(int i=start;i<end;i++) {
        if(in[i]==pre[(*preCount)-1]) break;
    }

	int i = findNode(in, add->val, start, end);
	add->left = constTreeInPre1(in, pre, start, i-1, preCount);
	add->right = constTreeInPre1(in, pre, i+1, end, preCount);
	return add;
}

Node* constTreeInPre (int* in, int* pre, int start, int end){
	int preCount = 0;
	return constTreeInPre1 (in, pre, start, end, &preCount);
}

Node* constTreeInPost (int* in, int* post, int postStart, int postEnd, int start, int end) {

	if (end - start < 0) return NULL;

	Node* add = new Node;
	add->val = post[postEnd];

	int i = findNode(in, post[postEnd], start, end);
	int number = i-start;

	add->left = constTreeInPost(in, post, postStart, postStart+number-1, start, i-1);
	add->right = constTreeInPost(in, post, postStart+number, postEnd-1, i+1, end);

	return add;
}

int sumLeftLeaf(Node* add, int sum) {

	if (add == NULL) return 0;

	if (add->left != NULL && add->left->left == NULL && add->left->right == NULL) {
		int x = sumLeftLeaf(add->right, sum);
		return sum + add->left->val + x;
	}
	else {
		int y = sumLeftLeaf(add->left, sum);
		int z = sumLeftLeaf(add->right, sum);
		return y+z;
	}
}

int sumLeaf(Node* add, int sum) {

	if (add == NULL) return 0;

	if (add->left == NULL && add->right == NULL) return sum + add->val;

	else {
		int y = sumLeaf(add->left, sum);
		int z = sumLeaf(add->right, sum);
		return y+z;
	}
}

int maximum(int max, int y, int z) {
	if (max < y) max = y;
	if (max < z) max = z;
	return max;
}

int minimum(int max, int y, int z) {
	if (max > y) max = y;
	if (max >

		 z) max = z;
	return max;
}

int maxElement (Node* add, int max) {
	if (add == NULL) return max;

	if (add->val > max) max = add->val;
	int y = maxElement(add->left, max);
	int z = maxElement(add->right, max);

	return maximum(max,y,z);
}

int minLeafDist (Node* add, int min) {
	if (add == NULL) return min;
	if (add->left == NULL && add->right == NULL) return 0;
	int x = minLeafDist (add->left, min);
	int y = minLeafDist (add->right, min);
	return minimum(x+1, y+1, min);
}

int minLeafNode (Node* add, int a) {
	if (add == NULL) return 100000;
	if (add->val == a) {
		return minLeafDist (add, 1000000);
	}
	int x = minLeafNode (add->left, a);
	int y = minLeafNode (add->right, a);
	if (x<y) return x;
	else return y;
}

void minMax(Node* add, int* min, int* max, int h) {
	if (add == NULL) return;
	if (*min > h) *min = h;
	if (*max < h) *max = h;

	minMax(add->left, min, max, h-1);
	minMax(add->right, min, max, h+1);
}

void printLevel(Node* add, int h, int k) {
	if (add == NULL) return;
	if (h == k) cout << add->val << ' ';
	printLevel(add->left, h-1, k);
	printLevel(add->right, h+1, k);
}

void verticalPrint(Node* add) {
	int min = 0, max = 0;
	minMax(add, &min, &max, 0);
	for (int i=min; i<=max; i++) {
		printLevel(add, 0, i);
		cout << '\n';
	}
}

void printSameLevel(Node* add, int h, int k) {
	if (add == NULL) return;
	if (h == k) {
		cout << add->val << ' ';
		return;
	}
	printSameLevel(add->left, h+1, k);
	printSameLevel(add->right, h+1, k);
}

void printLevelOrder(Node* add) {
	int h = height (add);
	for (int i=0; i<=h; i++) {
		printSameLevel(add, 0, i);
	}
}

void printLevelOrderQueue(Node* add) {
	if (add == NULL) return;
	queue <Node *> q;
	q.push(add);

	while (!q.empty()) {
		Node* temp = q.front();
		cout << temp->val << " ";
		q.pop();
		if (temp->left != NULL) q.push(temp->left);
		if (temp->right != NULL) q.push(temp->right);
	}
}

void printNoSiblings (Node* add) {
	if (add == NULL) return;

	if (add->right != NULL && add->left != NULL) {
		printNoSiblings (add->right);
		printNoSiblings (add->left);
	}
	else if (add->right != NULL) {
		cout << add->right->val << " ";
		printNoSiblings (add->right);
	}
	else if (add->left != NULL) {
		cout << add->left->val << " ";
		printNoSiblings (add->left);
	}
}

void printDiagonalMakeDict (map <int, vector<int> > *dict, Node* add, int s) {
	if (add != NULL) {
		(*dict)[s].push_back(add->val);
	}
	else return;
	if (add->left != NULL) printDiagonalMakeDict(dict, add->left, s+1);
	if (add->right != NULL) printDiagonalMakeDict(dict, add->right, s);
}

void printDiagonal (Node* add) {
	map <int, vector<int> > dict;
	printDiagonalMakeDict(&dict, add, 0);
	map <int, vector<int> > :: iterator itr;
	vector<int> :: iterator p;

	for (itr = dict.begin(); itr != dict.end(); ++itr)    {
        for (p = itr->second.begin(); p != itr->second.end(); ++p) {
			cout << *p << " ";
		}
		cout << "\n";
    }
}

void printCornerNodesUtil (Node* add, int level, int* max_level) {
	if (add == NULL) return;

	if (*max_level < level) {
        cout << add->val << " ";
        *max_level = level;
    }
	printCornerNodesUtil(add->left, level+1, max_level);
	printCornerNodesUtil(add->right, level+1, max_level);
}

void printCornerNodes (Node* add) {
	int max_level = 0;
	printCornerNodesUtil(add, 1, &max_level);
}

// incomplete print leftmost and rightmost node at each level
void printLevelOrder1 (Node* add) {
	queue <pair<int, Node*> > arr;
	int level = 0;
	arr.push(make_pair(level+1, add));
	Node* prev = NULL;
	Node* left;

	while (!arr.empty()) {
		Node* x = arr.front().second;
		int y = arr.front().first;
		arr.pop();
		
		if (x->left != NULL) arr.push(make_pair(y+1, x->left));
		if (x->right != NULL) arr.push(make_pair(y+1, x->right));
		
		if (y != level) {
			if (prev != NULL && x != prev && left != prev) cout << prev->val << " ";
			cout << x->val << " ";
			left = x;
			level = y;
		}
		prev = x;
	}
	if (left != prev)
	cout << prev->val ;
}


Node* newNode (int data) {
    Node* node = new Node;
    node->val  = data;
    node->left  = node->right = NULL;
    return (node);
}

Node* lcaBst (Node* root, int a, int b) {

	Node* add = root;

	int min = (a < b)? a:b;
	int max = (a >= b)? a:b;

	cout << min << " " << max << endl;

	while (add != NULL) {
		if (add->val > max && add->val > min) add = add->left;
		else if (add->val < max && add->val < min) add = add->right;
		else break;
	} 
	return add;
}

// incomplete lca for binary tree
void getArray (Node* root, int x, vector<int> &arr) {
	if (root == NULL) return;
	if (root->val == x) {
		return;
	}

	arr.push_back(root->val);
	getArray (root->left, x, arr);
	getArray (root->right, x, arr);

	arr.pop_back();
}

Node* lca (Node* root, int a, int b) {

	vector<int> arr1, arr2;
	getArray (root, a, arr1);
	getArray (root, b, arr2);

	vector <int> :: iterator i;
	cout << "start now\n";

	for (i = arr1.begin(); i != arr1.end(); ++i)
        cout << *i << '\t';

	return root;
}

void sumVerticalRec (Node* root, int pos, map<int, int>& hash) {
	if (root == NULL) return;
	if (hash.count(pos) == 0) hash.insert(pair<int, int>(pos,root->val));
	else hash.find(pos)->second += root->val;

	sumVerticalRec (root->left, pos-1, hash);
	sumVerticalRec (root->right, pos+1, hash);
}

void sumVertical (Node* root) {
	map<int, int> hash;
	sumVerticalRec(root, 0, hash);
	map<int, int> :: iterator ittr; 
	for (ittr = hash.begin(); ittr != hash.end(); ++ittr) cout << ittr->first << " " << ittr->second << "\n"; 
}

int main() {
	// Tree* p = newTree();
	// insert (p, 30);
	// insert (p, 20);
	// insert (p, 10);
	// insert (p, 5);
	// insert (p, 25);
	// insert (p, 40);
	// printIn (p->root);
	// cout << "\n";
	// cout << "count " << countNodes(p->root) << endl;
	// cout << "height " << height(p->root) << endl;

	// if(sum(p->root, 0, 60))
	// 	cout << "There is a root-to-leaf path with sum " << 60 << endl;
	// else
	// 	cout << "There is no root-to-leaf path with sum " << 60 << endl;

	// if(sum(p->root, 0, 65))
	// 	cout << "There is a root-to-leaf path with sum " << 65 << endl;
	// else
	// 	cout << "There is no root-to-leaf path with sum " << 65 << endl;

	// cout << "balanced " << balanced(p->root) << endl;
	// cout << "diameter " << diameter(p->root) << endl;
	// cout << "children sum " << childrenSumProperty(p->root) << endl;
	// cout << "count leaf " << countLeafNodes(p->root, 0) << endl;
	// //printRootLeafPaths (p->root);
	// printAncestors (p->root, 10);

	// int pre[] = {1,2,4,5,6,3,7,8};
	// int in[] = {5,4,6,2,1,3,8,7};
	// int post[] = {5,6,4,2,8,7,3,1};

	// Node* add = constTreeInPre (in, pre, 0, 7);
	// cout << "PreIn\n";
	// printIn(add);
	// cout << "\n";
	// printPre(add);
	// cout << "\n";
	// printPost(add);
	// cout << "\n";

	// Node* inPost = constTreeInPost (in, post, 0, 7, 0, 7);
	// cout << "postIn \n";
	// printIn(inPost);
	// cout << "\n";
	// printPre(inPost);
	// cout << "\n";
	// printPost(inPost);
	// cout << "\n";

	// cout << "Left leaf sum " << sumLeftLeaf(inPost, 0) << endl;
	// cout << "all leaf sum " << sumLeaf(inPost, 0) << endl;
	// cout << "max element " << maxElement(inPost, -1000000) << endl;
	// cout << "min Leaf dist of 2 is " << minLeafNode(inPost, 2) << endl;
	// cout << "min Leaf dist of 4 is " << minLeafNode(inPost, 4) << endl;
	// cout << "min Leaf dist of 1 is " << minLeafNode(inPost, 1) << endl;

	int pre1[] = {1,2,3,4,5,6,7,8,9,10};
	int in1[] = {3,2,7,6,8,5,4,1,10,9};

	Node* inPre1 = constTreeInPre (in1, pre1, 0, 9);
	// printPre(inPre1);
	// cout << '\n';
	// printPre(inPre1);
	// cout << '\n';

	// cout << "min Leaf dist of 2 is " << minLeafNode(inPre1, 2) << endl;
	// cout << "min Leaf dist of 4 is " << minLeafNode(inPre1, 4) << endl;
	// cout << "verticalPrint " << '\n';
	// verticalPrint(inPre1);
	// cout << "printLevelOrder" << '\n';
	// printLevelOrder(inPost);
	// cout << '\n';
	// cout << "printLevelOrder" << '\n';
	// printLevelOrder(inPre1);
	// cout << '\n';
	// cout << "printLevelOrderQueue" << '\n';
	// printLevelOrderQueue(inPre1);
	// cout << '\n';
	// printNoSiblings(inPre1);
	// cout << '\n';
	// cout << "DiagonalPrint\n";
	// printDiagonal (inPre1);
	// cout << "print corner nodes ";
	// printCornerNodes (inPre1);
	// cout << "\n";
	cout << "left right ";
	printLevelOrder1 (inPre1);
	cout << "\n";

	struct Node *root        = newNode(20);
    root->left               = newNode(8);
    root->right              = newNode(22);
    root->left->left         = newNode(4);
    root->left->right        = newNode(12);
    root->left->right->left  = newNode(10);
    root->left->right->right = newNode(14);

	printLevelOrder (root);
	cout << endl;

	Node* add = lcaBst (root, 10, 14);
	cout << add->val << endl;
	add = lcaBst (root, 8, 14);
	cout << add->val << endl;
	add = lcaBst (root, 10, 22);
	cout << add->val << endl;

	lca (root, 8, 14);
	cout << "vertical " << endl;
	sumVertical  (root);
}

/*
struct tNode *root = newtNode(1);
root->left	 = newtNode(2);
root->left->left	 = newtNode(3);
root->left->right	 = newtNode(4);
root->left->right->left = newtNode(5);
root->left->right->left->left  = newtNode(6);
root->left->right->left->left->left  = newtNode(7);
root->left->right->left->left->right  = newtNode(8);
root->right = newtNode(9);
root->right->left = newtNode(10);
*/
