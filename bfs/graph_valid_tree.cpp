#include <iostream>
#include <vector>
#include <unordered_set>
#include <queue>

using namespace std;

void    buildGraph(vector<vector<int> > &graph, int from , int to)
{
    graph[from].push_back(to);
    graph[to].push_back(from);
}

bool    bfs(vector<vector<int> >&graph)
{
    unordered_set<int> s;
    queue<int> q;
    vector<int> vis(graph.size(), 0);

    q.push(0);
    vis[0] = 1;
    while (!q.empty())
    {
        int cur = q.front();
        q.pop();
        int f = 0;
        for (int i : graph[cur])
        {
            if (vis[i])
                f++;
            if (f == 2)
                return (false);
            if (!vis[i])
            {
                q.push(i);
                vis[i] = 1;
            }
        }
    }
    return (true);
}
bool    validTree(int nodes, vector<vector<int> >&edges)
{
    vector<vector<int> > graph(nodes);
    for (vector<int> j : edges)
        buildGraph(graph, j[0], j[1]);
    // using this approach i assume it is a connected graph
    return(bfs(graph));   
}

int main()
{
    // int n = 6;
    // vector<vector<int> > e = {{0,1}, {1,2}, {2,3}, {1,4}, {1,3}};
    // cout << validTree(n, e) << "\n";

    int n = 8;
    vector<vector<int> > e = {{0,1}, {1,2}, {2,3}, {4,3}, {1,5}, {4,7}, {4,6}};
    cout << validTree(n, e) << "\n";
    return 0;
}
