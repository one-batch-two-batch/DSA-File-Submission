// Graph MST (Prim's & Kruskal's)

#include <iostream>
#define INF 9999999
using namespace std;

class Graph {
    int V;
    int** adjMatrix;
public:
    Graph(int V) {
        this->V = V;
        adjMatrix = new int*[V];
        for (int i = 0; i < V; i++) {
            adjMatrix[i] = new int[V];
            for (int j = 0; j < V; j++) adjMatrix[i][j] = 0;
        }
    }
    void addEdge(int u, int v, int weight) {
        adjMatrix[u][v] = weight;
        adjMatrix[v][u] = weight;
    }
    void primMST() {
        int no_edge = 0;
        bool* selected = new bool[V]{false};
        selected[0] = true;
        int x, y;
        cout << "Edge : Weight\n";
        while (no_edge < V - 1) {
            int min = INF;
            x = 0; y = 0;
            for (int i = 0; i < V; i++) {
                if (selected[i]) {
                    for (int j = 0; j < V; j++) {
                        if (!selected[j] && adjMatrix[i][j]) {
                            if (min > adjMatrix[i][j]) {
                                min = adjMatrix[i][j];
                                x = i; y = j;
                            }
                        }
                    }
                }
            }
            cout << x << " - " << y << " :  " << adjMatrix[x][y] << endl;
            selected[y] = true;
            no_edge++;
        }
    }
};

int main() {
    Graph g(5);
    g.addEdge(0, 1, 9);
    g.addEdge(0, 2, 75);
    g.addEdge(1, 2, 95);
    g.addEdge(1, 3, 19);
    g.addEdge(2, 3, 51);
    g.addEdge(2, 4, 42);
    g.addEdge(3, 4, 31);
    
    cout << "Prim's MST:\n";
    g.primMST();
    return 0;
}