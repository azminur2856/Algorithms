// Bellman Ford.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <limits>

using namespace std;

struct Edge {
    int source, destination, weight;
};

void BellmanFord(const vector<Edge>& edges, int vertices, int source) {
    vector<int> distance(vertices, numeric_limits<int>::max());
    distance[source] = 0;

    // Relax edges repeatedly
    for (int i = 0; i < vertices - 1; ++i) {
        for (const auto& edge : edges) {
            int u = edge.source;
            int v = edge.destination;
            int weight = edge.weight;

            if (distance[u] != numeric_limits<int>::max() && distance[u] + weight < distance[v]) {
                distance[v] = distance[u] + weight;
            }
        }
    }

    // Check for negative cycles
    for (const auto& edge : edges) {
        int u = edge.source;
        int v = edge.destination;
        int weight = edge.weight;

        if (distance[u] != numeric_limits<int>::max() && distance[u] + weight < distance[v]) {
            cout << "Graph contains negative cycle!" << endl;
            return;
        }
    }

    // Print distances from the source vertex
    cout << "Vertex distances from source:" << endl;
    for (int i = 0; i < vertices; ++i) {
        cout << "Vertex " << i << ": " << distance[i] << endl;
    }
}

int main() {
    // Example graph
    vector<Edge> edges = {
        {0, 1, 4},
        {0, 2, 3},
        {1, 2, -2},
        {1, 3, 6},
        {2, 3, 3},
        {2, 4, 2},
        {3, 4, 1},
        {3, 3, 2}
    };
    int vertices = 5; // Number of vertices in the graph
    int source = 0; // Source vertex

    BellmanFord(edges, vertices, source);

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
