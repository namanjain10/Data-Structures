#include <iostream>
using namespace std;

struct Node {
	int val;
	Node* next;
};

struct List {
	Node* head;	
};

List* newList () {
	List* temp = new List;
	temp->head = NULL;
	return temp;
}

void pushList(List* list, int x) {
	Node* start = list->head;

	Node* add = new Node;
	add->val = x;
	add->next = NULL;

	if (start == NULL) {
		list->head = add;
	}
	else {
		while (start->next != NULL) {
			start = start->next;
		}
		start->next = add;
	}
}

void print (List* add) {
	Node* start = add->head;
	if (start == NULL) {
		return;
	}

	while (start != NULL) {
		cout << start->val << " ";
		start = start->next;
	}
	cout << "\n";
}

void reverse (List* list) {
	Node* add = list->head;
	Node* prev = NULL;
	Node* next;

	while (add->next != NULL) {
		next = add->next;	
		add->next = prev;
		prev = add;
		add = next;
	}
	add->next = prev;
	list->head = add; 
}

int findLengthItter (List* list) {
	Node* add = list->head;
	int count = 0;
	while (add != NULL) {
		count++;
		add = add->next;
	}
	return count;
}

int findLengthRecursive (Node* add, int count) {
	if (add == NULL) {
		return count;
	}
	else {
		return findLengthRecursive(add->next, count+1); 
	}
}

void deleteNode (List* list, int x) {
	// if want to delete all ther remove break and else 
	Node* temp, *add =  list->head; 
	if (add->val == x) {
		list->head = add->next;
		delete add;
	}

	else {
		while(add->next != NULL) {
			if (add->next->val == x) {
				temp = add->next->next;
				delete add->next;
				add->next = temp;
				break;
			}
			add = add->next;
		}
	}
}

int main() {
	List* list = newList();
	cout << findLengthItter(list) << endl;
	cout << findLengthRecursive(list->head, 0) << endl;
	
	pushList (list, 10);
	pushList (list, 15);
	pushList (list, 25);
	pushList (list, 45);
	pushList (list, 10);
	pushList (list, 15);
	pushList (list, 25);
	pushList (list, 45);
	print (list);
	reverse (list);
	print (list);
	cout << findLengthRecursive(list->head, 0) << endl;
	deleteNode (list, 45);
	print(list);
	cout << findLengthItter(list) << endl;
}

