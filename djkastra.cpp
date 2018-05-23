#include <iostream>
#include <queue>
#include <list>
#include <limits.h>
using namespace std;

struct Graph {
    int n;
    int **arr;
};

void dijkstra (Graph* g, int s) {
    priority_queue <pair<int,int>, vector<pair<int, int > >, greater<pair<int, int> > > pq;
    vector<int> dist(g->n, INT_MAX), included(g->n, false);

    pq.push(make_pair(0, s));
    dist[s] = 0;
    included[s] = true;

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        for (int i=0; i< g->n; i++) {
            if (dist[i] > dist[u] + g->arr[u][i] && !included[i] && g->arr[u][i] != 0) {
                dist[i] = dist[u] + g->arr[u][i];
                included[i] = true;
                pq.push(make_pair(dist[i], i));
            }
        }
    }
    for (int i=0; i<g->n; i++){
        cout << i << " " << dist[i] << endl;
    }
}

Graph* newGraph (int s) {
    Graph *g = new Graph;
    g->n = s;
    g->arr = new int*[g->n];

    for (int i=0; i< g->n; i++) {
        g->arr[i] = new int[g->n];
        for (int j=0; j< g->n; j++) {
            g->arr[i][j] = 0;
        }
    }
    return g;
}

int main() {

    int n = 9;
    // cin >> n;

    Graph *g = newGraph(n);
    int arr1[n][n] = {{0, 4, 0, 0, 0, 0, 0, 8, 0},
                      {4, 0, 8, 0, 0, 0, 0, 11, 0},
                      {0, 8, 0, 7, 0, 4, 0, 0, 2},
                      {0, 0, 7, 0, 9, 14, 0, 0, 0},
                      {0, 0, 0, 9, 0, 10, 0, 0, 0},
                      {0, 0, 4, 14, 10, 0, 2, 0, 0},
                      {0, 0, 0, 0, 0, 2, 0, 1, 6},
                      {8, 11, 0, 0, 0, 0, 1, 0, 7},
                      {0, 0, 2, 0, 0, 0, 6, 7, 0}
                     };

    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            g->arr[i][j] = arr1[i][j];
        }
    }
    dijkstra(g, 0);

    return 0;
}
