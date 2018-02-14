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

int main() {
	List* list = newList();
	pushList (list, 10);
	pushList (list, 15);
	pushList (list, 25);
	pushList (list, 45);
	pushList (list, 10);
	pushList (list, 15);
	pushList (list, 25);
	pushList (list, 45);
	print (list);
}

