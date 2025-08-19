#include<iostream>
#include<vector>
using namespace std;


class Graph {
    int V;
    vector<vector<int>> adj;

public:
    Graph(int V) {
        this-> V  = V;
        adj = vector<vector<int>> (V);
    }

    void addEdges(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    printAdj() {
        for(int i=0; i<V; i++) {
            cout << i << " : ";
            for(int neighbour : adj[i]){
                cout << neighbour << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    Graph g(5);

    g.addEdges(0, 1);
    g.addEdges(1,2);
    g.addEdges(1,3);
    g.addEdges(4, 2);

    g.printAdj();

    return 0;
}


/*
 OUTPUT

0 : 1 
1 : 0 2 3 
2 : 1 4 
3 : 1 
4 : 2 
*/