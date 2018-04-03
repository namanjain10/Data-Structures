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

void printList (Node* start) {
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

// incomplete
void MaxSumList (List* list1, List* list2) {
	Node* add1 = list1->head, *add2 = list2->head, *temp1 = list1->head, *temp2 = list2->head, addHead;

	int count1 = 0, count2 = 0, q = 1, listNum = 1;

	Node *add = &addHead;
	addHead.next = NULL;

	while (1) {
		if (add1 == NULL) break;
		if (add2 == NULL) break;

		cout << "add " << add1->val << " "<< add2->val << endl;

		if (add1->val == add2->val) {
			if (q == 0) {
				temp1 = add1;
				temp2 = add2;
				q = 1;
			}
			else {
				if (count1 > count2) {
					while (temp1 != add1) {
						cout << "doing1 \n";
						add->next = temp1;
						add = add->next;
						temp1 = temp1->next;
					}
				}
				else {
					while (temp2 != add2) {
						cout << "doing2 \n";
						add->next = temp2;
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
	list1->head = addHead.next;
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

int intersectionLinked (List* list1, List* list2) {
	int length1 = 0, length2 = 0;
	Node* add1 = list1->head, *add2 = list2->head, *add = NULL;

 	length1 = findLengthItter(list1);
 	length2 = findLengthItter(list2);

 	int y;

 	if (length1 > length2) {
 		y  = length1-length2 ;
 		while (y--) {
 			add1 = add1->next;
 		}
 	}
	else {
 		y  = length2-length1 ;
		while (y--) {
 			add2 = add2->next;
 		}
	}

 	while (add1 != NULL) {
 		if (add1 == add2) {
 			add = add1;
 			break;
 		}
 		add1 = add1->next;
 		add2 = add2->next;
 	}
 	if (add == NULL) return 0;
 	return add->val;
}

void reversePrint (Node* add) {
	if (add == NULL) return;
	reversePrint (add->next);
	cout << add->val << " ";
}

void removeDuplicateSorted (List* list) {
	Node* add = list->head, *temp;

	while (add->next != NULL) {
		if (add->next->val == add->val) {
			temp = add->next->next;
			delete add->next;							// not worked if deleted add
			add->next = temp;
		}
		else add = add->next;
	}
}

void swapNum (Node* x, Node* y) {
	int temp = x->val;
	x->val = y->val;
	y->val = temp;
}

void oddEven (List* f) {
	Node* add = f->head;
	Node* put, *next1, *temp, *temp1;

	if (add->val %2 == 0) {
		put = add;
		while (put->next != NULL && put->next->val %2 != 1) {
			put = put->next;
		}
		next1 = put;

		while (next1->next != NULL) {
			if (next1->next->val %2 == 0) {
				temp = put->next;
				temp1 = next1->next->next;
				put->next = next1->next;
				put = put->next;
				put->next = temp;
				next1->next = temp1;
			}
			else {
				next1 = next1->next;
			}
		}
	}
	else {
		put = add;
		while (put->next != NULL && put->next->val %2 != 0) {
			put = put->next;
		}
		next1 = put;

		while (next1->next != NULL) {
			if (next1->next->val %2 == 1) {
				temp = put->next;
				temp1 = next1->next->next;
				put->next = next1->next;
				put = put->next;
				put->next = temp;
				next1->next = temp1;
			}
			else {
				next1 = next1->next;
			}
		}
		temp = add;
		add = put->next;
		Node* s = add;
		while (s->next!= NULL) {
			s = s->next;
		}
		s->next = temp;
		while (s->next!= put) {
			s = s->next;
		}
		s->next = NULL;
		f->head = add;
	}
}

void mergeAlternate (Node* add1, Node* add2) {
	Node *temp1, *temp;
	while (add1 != NULL || add2 != NULL) {
		temp1 = add1->next;
		temp = add2	;
		if (add2 != NULL) {
			add2 = add2->next;
			add1->next = temp;
			add1->next->next = temp1;
		}
		if (add1->next != NULL) {
			if (add1->next->next != NULL) {
				add1 = add1->next->next;
			}
			else break;
		}
		else break;
	}
	if (add2 != NULL) {
		while (add1->next != NULL) {
			add1 = add1->next;
		}
		add1->next = add2;
	}
}

Node* mergedAlternate (Node* add1, Node* add2) {
	Node* add;
	add = add1;
	add1 = add->next;

}

void ReverseAlternateKNodes (List* list, int k) {
	int count = 0;
	Node* add = list->head;
	Node* start, *end;

	while (count != k) {
		if (count == 0) start = add;
		if (count == k) end = add;

		// add
	}
}

void sumLinked (List* list1, List* list2) {
	reverse(list1);
	reverse(list2);

	Node* add1 = list1->head, *add2 = list2->head;
	int carry = 0, k = 0;

	while (add1 != NULL || add2 != NULL) {
		k = add1->val + add2->val + carry;
		add1->val = k%10;
		carry = k/10;

		if (add1->next == NULL) break;
		add1 = add1->next;

		if (add2->next == NULL) break;
		add2 = add2->next;
	}

	while (add1 != NULL) {
		k = carry + add1->val;
		carry = k/10;
		add1->val = k%10;
		if (add1->next == NULL) break;
		add1 = add1->next;
	}

	if (carry != 0) {
		add1->next = new Node;
		add1->next->val = carry;
		add1->next->next = NULL;
	}
	reverse (list1);
}

void subLinked (List* list1, List* list2) {
	reverse(list1);
	reverse(list2);

	Node* add1 = list1->head, *add2 = list2->head;
	int borrow = 0, k = 0;

	while (add1 != NULL || add2 != NULL) {
		if (borrow == 1) {
			add1->val--;
			borrow = 0;
		}
		if (add1->val >= add2->val) add1->val = add1->val - add2->val;
		else {
			add1->val = add1->val + 10 - add2->val;
			borrow = 1;
		}

		if (add1->next == NULL) break;
		add1 = add1->next;

		if (add2->next == NULL) break;
		add2 = add2->next;
	}
	while (borrow != 0) {
		add1->val--;
		borrow = 0;
		if (add1->val < 0) {
			add1->val = add1->val + 10;
			borrow = 1;
		}
		add1 = add1->next;
	}
	reverse (list1);
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
	pushList (list1, 20);
	pushList (list1, 30);
	pushList (list1, 30);
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
	pushList (list2, 71);
	pushList (list2, 91);

	print (list2);

	// removeDuplicateSorted (list1);
	// print (list1);

	List* list3 = newList();

	pushList (list3, 10);
	pushList (list3, 20);
	pushList (list3, 21);
	pushList (list3, 30);
	pushList (list3, 31);
	pushList (list3, 49);
	pushList (list3, 51);
	pushList (list3, 60);
	pushList (list3, 71);

	// oddEven1(list3->head);
	oddEven(list3);
	cout << "list3 " ;
	print (list3);

	mergeAlternate (list2->head, list3->head);
	print (list2);

	List* list4 = newList();

	// pushList (list4, 5);
	pushList (list4, 1);
	pushList (list4, 1);
	pushList (list4, 0);
	pushList (list4, 0);
	pushList (list4, 6);

	print (list4);

	List* list5 = newList();

	// pushList (list5, 8);
	// pushList (list5, 8);
	// pushList (list5, 5);
	pushList (list5, 7);

	print (list5);

	subLinked (list4, list5);
	print (list4);

}
