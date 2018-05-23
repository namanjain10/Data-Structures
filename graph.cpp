#include <iostream>
using namespace std;

struct PriorQueue {
    int size;
    int* arr;
};

void swap (int* arr, int i, int j) {
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

void heapify (PriorQueue* heap) {
    int i = heap->size - 1;

    while (heap->arr[(i-1)/2] < heap->arr[i] && i>=0) {
        swap (heap->arr, (i-1)/2, i);
        i = (i-1)/2;
    }
}

PriorQueue* newPriorQueue() {
    PriorQueue* p = new PriorQueue;
    p->size = 0;
    p->arr = new int [100];
    return p;
}

void pushPriorQueue (PriorQueue* p, int k) {
    p->arr[p->size] = k;
    p->size++;
    heapify(p);
}

int frontPriorQueue (PriorQueue* p) {
    if (p->size > 0) {
        return p->arr[0];
    }
}

void popPriorQueue (PriorQueue* heap) {
    int j = 0;
    heap->arr[j] = heap->arr[heap->size-1];
    heap->size --;

    int i = 0;

    while (2*i+1 < heap->size) {

        int pos, val;

		if (heap->arr[2*i+1] < heap->arr[2*i+2]) {
			val = heap->arr[2*i+1];
			pos = 2*i+1;
		}
		else {
			val = heap->arr[2*i+2];
			pos = 2*i+2;
		}

		if (val < heap->arr[i]) {
			swap(heap->arr, pos, i);
		}
		i++;
    }
}

void merge (int* arr, int s, int m, int e) {

    int n1 = m-s+1;
    int n2 = e-m;
    int t[n1], q[n2];
    int i,j,k;

    for (int i=0; i<n1; i++) {
        t[i] = arr[s+i];
    }
    for (int i=0; i<n2; i++) {
        q[i] = arr[m+1+i];
    }

    i=0, j=0, k=s;
    while (i < n1 && j < n2) {
        if (t[i] < q[j]) {
            arr[k] = t[i];
            i++;
            k++;
        }
        else {
            arr[k] = q[j];
            j++;
            k++;
        }
    }
    while (i < n1) {
        arr[k] = t[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = q[j];
        j++;
        k++;
    }

}

void sort (int* arr, int start, int end) {

    if (start < end) {
        int mid = (start + end)/2;
        sort(arr, start, mid);
        sort(arr, mid+1, end);
        merge(arr, start, mid, end);
    }
}

struct QueueNode {
    int val;
    QueueNode* next;
};

struct Queue {
    QueueNode* head;
    int size;
    int maxSize;
};

Queue* newQueue(int n) {
    Queue* q = new Queue;
    q->maxSize = n;
    q->size = 0;
    q->head = NULL;
    return q;
}

void pushQueue(Queue* q, int k) {
    if (q->maxSize > q->size) {
        QueueNode* temp = new QueueNode;
        temp->val = k;
        temp->next = NULL;

        if (q->head == NULL) {
            q->head = temp;
        }
        else {
            QueueNode* add = q->head;
            while (add->next != NULL) {
                add = add->next;
            }
            add->next = temp;
        }
        q->size ++;
    }
}

void popQueue(Queue* q) {
    QueueNode* temp = q->head->next;
    QueueNode* w = q->head;
    delete w;
    q->head = temp;
    q->size --;
}

int frontQueue(Queue* q) {
    return q->head->val;
}

struct StackNode {
    int val;
    StackNode* next;
};

struct Stack {
    int size;
    int maxSize;
    StackNode* head;
};

Stack* newStack(int n) {
    Stack* s = new Stack;
    s->head = NULL;
    s->maxSize = n;
    s->size = 0;
    return s;
}

void pushStack (Stack* s, int k) {
    if (s->maxSize > s->size) {
        StackNode* temp = new StackNode;
        temp->val = k;
        temp->next = NULL;

        if (s->head == NULL) {
            s->head = temp;
        }
        else {
            StackNode* p = s->head;
            s->head = temp;
            s->head->next = p;
        }
        s->size ++;
    }
}

void popStack (Stack* s) {
    if (s->head != NULL) {
        StackNode* temp = s->head->next;
        StackNode* p = s->head;
        delete p;
        s->head = temp;
        s->size --;
    }
}

int frontStack (Stack* s) {
    return s->head->val;
}

struct GraphNode{
    int val;
    int weight;
    GraphNode* next;
};

struct Graph {
    GraphNode** arr;
    int n;
};

Graph* newGraph(int size) {
    Graph* p = new Graph;
    p->n = size;
    p->arr = new GraphNode* [size];

    for (int i=0; i<size; i++) {
        p->arr[i] = new GraphNode;
        p->arr[i]->val = i;
        p->arr[i]->weight = 0;
        p->arr[i]->next = NULL;
    }
    return p;
}

bool alreadyEdge(Graph* graph, int y, int k) {
    GraphNode* add = graph->arr[y];
    while (add != NULL) {
        if (add->val == k) return 0;
        add = add->next;
    }
    return 1;
}

void addEdge(Graph* graph, int y, int k, int w) {
    if (!alreadyEdge(graph, y, k)) {
        GraphNode* temp = new GraphNode;
        temp->val = k;
        temp->weight = w;
        temp->next = NULL;
        cout << "yes\n";

        if (graph->arr[y]->next == NULL) {
            graph->arr[y]->next = temp;
        }
        else {
            GraphNode* tem = graph->arr[y]->next;
            graph->arr[y]->next = temp;
            graph->arr[y]->next->next = tem;
        }
        addEdge(graph, k, y, w);
    }
}

int shortestPath(Graph* p, int a, int b) {
    GraphNode* add = p->arr[1];
    while (add!= NULL) {
        cout << "hey " << add->val << endl;
        add = add->next;
    }
    return 0;
}

int main() {
    // int arr[] = {2,6,4,7,8,5,1};
    // sort(arr, 0, 6);
    //
    // for (int i=0; i<7; i++) {
    //     cout << arr[i] << " ";
    // }cout << '\n';
    Graph* p = newGraph(9);
    cout << "yes\n";
    addEdge(p,0,1,4);
    addEdge(p,0,7,8);
    addEdge(p,1,7,11);
    addEdge(p,1,2,8);
    addEdge(p,7,8,7);
    addEdge(p,7,6,1);
    addEdge(p,2,3,7);
    addEdge(p,2,5,4);
    addEdge(p,2,8,2);
    addEdge(p,8,6,6);
    addEdge(p,5,6,2);
    addEdge(p,3,5,14);
    addEdge(p,5,4,10);
    addEdge(p,3,4,9);
    shortestPath(p,0,4);

    return 0;
}
