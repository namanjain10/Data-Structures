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

	cout << "val " << node->val << " ret " << max(left, right) + 1 << endl;

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

}