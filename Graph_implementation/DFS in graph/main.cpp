#include <iostream>
#include <fstream>
#include <unordered_map>
#include <list>
#include <vector>

using namespace std;
ifstream fin("input.txt");
ofstream fout("output.txt");


class graph
{
public:
    unordered_map<int, list<int>> adj;

    void addEdge(int u, int v, bool direction)
    {
        // direction = 0 -> undirected
        // direction = 1 -> directed graph

        // create an edge from u to v
        adj[u].push_back(v);

        if (direction == 0)
        {
            adj[v].push_back(u);
        }
    }

    void printAdjList()
    {
        for (auto i : adj)
        {
            fout << i.first << "->";
            for (auto j : i.second)
            {
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
    // Taking input the number of nodes
    int V;
    fin >> V;

    // Taking input the number of edges
    int E;
    fin >> E;

    graph g;

    for (int i = 0; i < V; i++)
    {
        int u, v;
        fin >> u >> v;
        g.addEdge(u, v, false);
    }

    // DFS
    unordered_map<int, list<int>> adjList = g.adj;

    vector<vector<int>> ans;
    unordered_map<int, bool> visited;

    for (int i = 0; i < V; i++)
    {
        if (!visited[i])
        {
            vector<int> component;
            dfs(i, visited, adjList, component);
            ans.push_back(component);
        }
    }

    fout << "DFS Traversal: ";
    for (vector<int> i : ans)
    {
        for (int n : i)
            fout << n << " ";
        fout << endl;
    }

    return 0;
}
