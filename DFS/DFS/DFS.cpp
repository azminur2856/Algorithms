// DFS.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <unordered_map>
#include <stack>

using namespace std;

class Graph {
private:
    unordered_map<char, unordered_map<char, bool>> adjList;

public:
    void addEdge(char v, char w) {
        adjList[v][w] = true;
    }

    void DFS(char startVertex) {
        unordered_map<char, bool> visited;
        stack<char> stack;

        for (const auto& pair : adjList) {
            visited[pair.first] = false;
        }

        stack.push(startVertex);
        visited[startVertex] = true;

        while (!stack.empty()) {
            char current = stack.top();
            stack.pop();
            cout << current << " ";

            for (const auto& pair : adjList[current]) {
                char adjacent = pair.first;
                if (!visited[adjacent]) {
                    stack.push(adjacent);
                    visited[adjacent] = true;
                }
            }
        }
    }
};

int main() {
    Graph graph;
    graph.addEdge('H', 'K');
    graph.addEdge('F', 'H');
    graph.addEdge('C', 'F');
    graph.addEdge('A', 'B');
    graph.addEdge('B', 'D');
    graph.addEdge('D', 'J');
    graph.addEdge('J', 'K');
    graph.addEdge('A', 'C');
    graph.addEdge('B', 'C');
    graph.addEdge('C', 'E');
    graph.addEdge('G', 'E');
    graph.addEdge('F', 'G');
    graph.addEdge('E', 'F');
    graph.addEdge('D', 'I');
    graph.addEdge('I', 'J');
    graph.addEdge('K', 'I');
    graph.addEdge('H', 'I');

    cout << "Depth-First Search starting from vertex 'A': ";
    graph.DFS('A');
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

