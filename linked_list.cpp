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

void deleteLinkedList (List* list) {
	Node* add = list->head, *temp;
	while (add != NULL) {
		temp = add->next;
		delete add;
		add = temp; 
	}
	list->head = NULL; 
}

int countFreq (List *list, int x) {
	Node* add = list->head;
	int count = 0;

	while (add != NULL) {
		if (add->val == x) count++;
		add = add->next;
	}
	return count; 
}

int loop (List* list) {
	Node* add = list->head, *doub = list->head;
	int q = 0;

	while (doub != NULL) {
		if (doub->next == NULL || doub->next->next == NULL) {
			break;
		}
		doub = doub->next->next;
		add = add->next;
		if (doub == add) {
			q = 1;
			break;
		}
	}
	return q;
}

void MaxSumList (List* list1, List* list2) {
	Node* add1 = list1->head, *add2 = list2->head, *temp1 = list1->head, *temp2 = list2->head, *a, *b, *add;
	int count1 = 0, count2 = 0, q = 1, listNum = 1;

	while (1) {
		if (add1 == NULL) break;
		if (add2 == NULL) break;

		if (add1->val == add2->val || add1 == NULL || add2 == NULL) {
			if (q == 0) {
				temp1 = add1;
				temp2 = add2;
				q = 1;
			}
			else {
				if (count1 > count2) {
					while (temp1 != add1) {
						add = temp1;
						add = add->next;
						temp1 = temp1->next;
					}
				}
				else {
					while (temp2 != add2) {
						add = temp2;
						add = add->next;
						temp2 = temp2->next;
					}
				}
				q = 0;
				count1 = 0;
				count2 = 0;
			}
		}

		if (q == 1) {
			count1 += add1->val;
			count2 += add2->val; 
		}
		add1 = add1->next;
		add2 = add2->next;
	}
	list1->head = add;
}

void MergeSortedList (List* list1, List* list2) {
	Node* add1 = list1->head, *add2 = list2->head, addHead;
	Node *add = &addHead;

	addHead.next = NULL;

	while (1) {
		if (add1 == NULL) {
			add->next = add2;
			break;
		}

		if (add2 == NULL) {
			add->next = add1;
			break;
		}
		cout << "add " << add1->val << " "<< add2->val << endl;

		if (add1->val < add2->val) {
			add->next = add1;
			add1 = add1->next;
			add = add->next;	
		}
		else {
			add->next = add2;
			add2 = add2->next;
			add = add->next;
		}
	}
	list1->head = addHead.next;
}

int main() {
	// List* list = newList();
	// cout << findLengthItter(list) << endl;
	// cout << findLengthRecursive(list->head, 0) << endl;
	// pushList (list, 10);
	// pushList (list, 15);
	// pushList (list, 25);
	// pushList (list, 45);
	// pushList (list, 20);
	// pushList (list, 35);
	// pushList (list, 15);
	// pushList (list, 47);
	// print (list);
	// reverse (list);
	// print (list);
	// cout << "nth from last " << nthNodeEnd (list, 2) << endl;
	// swap (&list->head, 47, 15);
	// print (list);
	// cout << nthNode (list, 10) << endl;
	// cout << "middle " << middleNode (list) << endl;
	// cout << "count " << countFreq (list, 85) << endl;

	// cout << findLengthRecursive(list->head, 0) << endl;
	// deleteNode (list, 45);
	// print(list);
	// cout << "middle " << middleNode (list) << endl;

	// cout << findLengthItter(list) << endl;
	// deleteLinkedList(list);
	// print (list);
	List* list1 = newList();
	List* list2 = newList();

	pushList (list1, 10);
	pushList (list1, 20);
	pushList (list1, 23);
	pushList (list1, 30);
	pushList (list1, 33);
	pushList (list1, 49);
	pushList (list1, 50);
	pushList (list1, 60);

	print (list1);

	pushList (list2, 5);
	pushList (list2, 12);
	pushList (list2, 20);
	pushList (list2, 32);
	pushList (list2, 36);
	pushList (list2, 49);
	pushList (list2, 70);

	print (list2);

	MergeSortedList (list1, list2);
	print (list1);
}

