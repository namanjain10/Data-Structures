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

}