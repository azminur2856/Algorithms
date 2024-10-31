// BFS.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <queue>
using namespace std;

class Graph {
    static const int MAX_NODES = 13;
    bool adj[MAX_NODES][MAX_NODES];
    int V;

public:
    Graph(int V) {
        this->V = V;
        for (int i = 0; i < V; i++)
            for (int j = 0; j < V; j++)
                adj[i][j] = false;
    }

    void addEdge(int v, int w) {
        adj[v][w] = true;
        adj[w][v] = true; // For undirected graph
    }

    void BFS(int startNode) {
        bool visited[MAX_NODES] = { false };
        queue<int> q;

        visited[startNode] = true;
        q.push(startNode);

        while (!q.empty()) {
            int current = q.front();
            cout << current << " ";
            q.pop();

            for (int i = 0; i < V; i++) {
                if (adj[current][i] && !visited[i]) {
                    visited[i] = true;
                    q.push(i);
                }
            }
        }
    }
};

int main() {
    Graph g = (13); // Number of nodes in the graph

    // Adding edges based on the given connections
    g.addEdge(0, 7);
    g.addEdge(0, 8);
    g.addEdge(0, 11);
    g.addEdge(1, 9);
    g.addEdge(1, 10);
    g.addEdge(2, 3);
    g.addEdge(2, 12);
    g.addEdge(3, 4);
    g.addEdge(3, 7);
    g.addEdge(5, 6);
    g.addEdge(6, 7);
    g.addEdge(7, 11);
    g.addEdge(8 , 9);
    g.addEdge(8 , 10);
    g.addEdge(9 , 12);
    
    
    

    int startNode = 10; // Change the starting node here
    cout << "BFS Traversal from node " << startNode << ": ";
    g.BFS(startNode);
    cout << endl;

    return 0;
}


// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
