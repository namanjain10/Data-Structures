#include <iostream>
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

void print (Node* tree) {

	if (tree == NULL) return;
	
	cout << tree->val << " ";
	print (tree->left);
	print (tree->right); 
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

int main() {
	Tree* p = newTree();
	insert (p, 30);
	insert (p, 20);
	insert (p, 10);
	insert (p, 5);
	insert (p, 25);
	insert (p, 40);
	print (p->root);
	cout << "\n";
	cout << "count " << countNodes(p->root) << endl;
	cout << "height " << height(p->root) << endl;

	if(sum(p->root, 0, 60))
		cout << "There is a root-to-leaf path with sum " << 60 << endl;
	else
		cout << "There is no root-to-leaf path with sum " << 60 << endl;

	if(sum(p->root, 0, 65))
		cout << "There is a root-to-leaf path with sum " << 65 << endl;
	else
		cout << "There is no root-to-leaf path with sum " << 65 << endl;

	cout << "balanced " << balanced(p->root) << endl;
	cout << "diameter " << diameter(p->root) << endl;
	cout << "children sum " << childrenSumProperty(p->root) << endl;
	cout << "count leaf " << countLeafNodes(p->root, 0) << endl;
}