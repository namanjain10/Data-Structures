#include <iostream>
#define SIZE(arr) (sizeof(arr)/sizeof(arr[0]))
using namespace std;

struct Node {
    int data;
    Node *next;
    Node *child;
};

void printList(struct Node *head) {
    while (head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << "\n";
}

void flattenList(Node *head) {
    Node* add[10000] = {};
    int count = 0;
    int now = -1;

    while (count != now) {
        if (head->next == NULL) {
            head->next = add[now];
            now++;
        }
        if (head->child != NULL) {
            if (count == 0) now++;

            add[count++] = head->child;
        }
        head = head->next;
    }

}
struct Node *createList(int *arr, int n) {
    struct Node *head = NULL;
    struct Node *p;

    int i;
    for (i = 0; i < n; ++i) {
        if (head == NULL)
            head = p = new Node;
        else {
            p->next = new Node;
            p = p->next;
        }
        p->data = arr[i];
        p->next = p->child = NULL;
    }
    return head;
}
struct Node *createList(void) {
    int arr1[] = {10, 5, 12, 7, 11};
    int arr2[] = {4, 20, 13};
    int arr3[] = {17, 6};
    int arr4[] = {9, 8};
    int arr5[] = {19, 15};
    int arr6[] = {2};
    int arr7[] = {16};
    int arr8[] = {3};

    /* create 8 linked lists */
    struct Node *head1 = createList(arr1, SIZE(arr1));
    struct Node *head2 = createList(arr2, SIZE(arr2));
    struct Node *head3 = createList(arr3, SIZE(arr3));
    struct Node *head4 = createList(arr4, SIZE(arr4));
    struct Node *head5 = createList(arr5, SIZE(arr5));
    struct Node *head6 = createList(arr6, SIZE(arr6));
    struct Node *head7 = createList(arr7, SIZE(arr7));
    struct Node *head8 = createList(arr8, SIZE(arr8));

    head1->child = head2;
    head1->next->next->next->child = head3;
    head3->child = head4;
    head4->child = head5;
    head2->next->child = head6;
    head2->next->next->child = head7;
    head7->child = head8;

    return head1;
}

int main() {
    struct Node *head = NULL;
    head = createList();
    cout << "created\n";
    flattenList(head);
    printList(head);
    return 0;
}
