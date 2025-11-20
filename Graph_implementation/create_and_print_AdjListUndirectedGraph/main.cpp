#include <iostream>
#include <fstream>
#include <unordered_map>
#include <list>
using namespace std;

ifstream fin("input.txt");
ofstream fout("output.txt");

class graph {
public:
    unordered_map<int, list<int>> adj;

    void addEdge(int u, int v, bool direction) {
        // direction = 0 -> undirected
        // direction = 1 -> directed graph

        //create an edge from u to v
        adj[u].push_back(v);

        if (direction == 0) {
            adj[v].push_back(u);
        }
    }

    void printAdjList() {
        for (auto i : adj) {
            fout << i.first << "->";
            for (auto j : i.second) {
                fout << j << ", ";
            }
            fout << endl;
        }
    }

};


void dfs(int node, unordered_map<int, bool>& visited,
    unordered_map<int, list<int>>& adj, vector<int>& component)
{

    component.push_back(node);
    visited[node] = true;

    // recursive call for every connected node
    for (auto i : adj[node])
    {
        if (!visited[i])
        {
            dfs(i, visited, adj, component);
        }
    }
}


int main()
{
    // taking input the no of nodes
    int n;
    fin >> n;

    // taking input the no of edges
    int m;
    fin >> m;

    graph g;

    for (int i = 0; i < m; i++) {
        int u, v;
        fin >> u >> v;
        g.addEdge(u, v, 0); // 0 means that it is an undirected graph
    }


    //printing the graph
    g.printAdjList();

    

    return 0;


  
}
