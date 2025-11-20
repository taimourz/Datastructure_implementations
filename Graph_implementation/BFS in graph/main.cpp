#include <iostream>
#include <fstream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <set>
#include<list>

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

void prepareAdjList(unordered_map<int, set<int>> &adjList, const vector<pair<int, int>> &edges)
{
    for (const auto &edge : edges)
    {
        int u = edge.first;
        int v = edge.second;

        adjList[u].insert(v);
        adjList[v].insert(u);
    }
}

vector<int> bfs(unordered_map<int, set<int>> &adjList, unordered_map<int, bool> &visited, vector<int> &ans, int node)
{
    queue<int> q;

    q.push(node);
    visited[node] = true;

    while (!q.empty())
    {
        int frontNode = q.front();
        q.pop();

        ans.push_back(frontNode);

        for (int neighbor : adjList[frontNode])
        {
            if (!visited[neighbor])
            {
                q.push(neighbor);
                visited[neighbor] = true;
            }
        }
    }

    return ans;
}

void printAdj(unordered_map<int, set<int>> &adjList)
{
    for (auto i : adjList)
    {
        fout << i.first << " -> ";
        for (auto j : i.second)
        {
            fout << j << " ";
        }
        fout << endl;
    }
}

vector<int> BFS(int vertex, vector<pair<int, int>> edges)
{
    unordered_map<int, set<int>> adjList;
    vector<int> ans;
    unordered_map<int, bool> visited;

    prepareAdjList(adjList, edges);

    // Traverse all nodes from 0 to vertex-1
    for (int i = 0; i < vertex; i++)
    {
        if (!visited[i])
        {
            bfs(adjList, visited, ans, i);
        }
    }

    return ans;
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

    for (int i = 0; i < m; i++)
    {
        int u, v;
        fin >> u >> v;
        g.addEdge(u, v, 0); // 0 means that it is an undirected graph
    }

    // printing the graph
    g.printAdjList();

    // Perform BFS
    vector<pair<int, int>> edges;
    for (const auto &edge : g.adj)
    {
        int u = edge.first;
        for (int v : edge.second)
        {
            edges.push_back({u, v});
        }
    }

    vector<int> result = BFS(n, edges);

    fout << "BFS Traversal: ";
    for (int i : result)
    {
        fout << i << " ";
    }
    fout << endl;

    return 0;
}