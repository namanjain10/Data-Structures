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
	// if want to delete all then remove break and else 
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

void swapNode(Node*& a, Node*& b) {
 
    Node* temp = a;
    a = b;
    b = temp;
}

void swap (Node** head, int x, int y) {
	if (x == y) return; 

	Node** add = head, **temp1, **temp2, **a, **b, **temp;
	int count = 0, q = 0;

	while ((*add) != NULL) {
		if ((*add)->val == x) {
			temp1 = add;
			count ++;
		}
		else if ((*add)->val == y) {
			temp2 = add;
			count ++;
		}
		if (count == 2) {
			break;
		}
		add = &((*add)->next);
	}
	if (count != 2) return ;

	swap(*temp1, *temp2);
    swap(((*temp1)->next), ((*temp2)->next));
}

int nthNode (List* list, int i) {
	Node* add = list->head;
	int q = 0;

	while (i > 0) {
		if (add == NULL) {
			q = 1;
			break;
		}
		add = add->next;
		i --;
	}
	if (q == 0) return add->val;
	else return -1;
}

int middleNode (List* list) {
	Node* add = list->head, *doub = list->head;
	while (doub != NULL) {
		if (doub->next == NULL || doub->next->next == NULL) {
			break;
		}
		doub = doub->next->next;
		add = add->next;
		
	}
	return add->val;
}

int nthNodeEnd (List* list, int i) {
	Node* add = list->head, *ref = list->head;
	while (i--) {
		add = add->next;
	}
	while (add != NULL) {
		add = add->next;
		ref = ref->next; 
	}
	return ref->val; 
}

int main() {
	List* list = newList();
	cout << findLengthItter(list) << endl;
	cout << findLengthRecursive(list->head, 0) << endl;
	pushList (list, 10);
	pushList (list, 15);
	pushList (list, 25);
	pushList (list, 45);
	pushList (list, 20);
	pushList (list, 35);
	pushList (list, 55);
	pushList (list, 47);
	print (list);
	reverse (list);
	print (list);
	cout << "nth from last " << nthNodeEnd (list, 2) << endl;
	swap (&list->head, 47, 15);
	print (list);
	cout << nthNode (list, 10) << endl;
	cout << "middle " << middleNode (list) << endl;

	cout << findLengthRecursive(list->head, 0) << endl;
	deleteNode (list, 45);
	print(list);
	cout << "middle " << middleNode (list) << endl;

	cout << findLengthItter(list) << endl;
}

