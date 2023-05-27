#include <iostream> 
#include <queue> 
#include <vector> 
#include <algorithm> 
using namespace std;

void dijkstra(int n, vector<vector<pair<int, int>>>& graph, int start, int end)
{
    vector<int> distances(n + 1, INT32_MAX);
    vector<int> predecessors(n + 1, -1);

    distances[start] = 0;

    priority_queue<pair<int, int>> Q;
    Q.push({ 0, start });

    while (!Q.empty())
    {
        int v = Q.top().second;
        Q.pop();

        for (pair<int, int> p : graph[v]) {
            int u = p.first;
            int w = p.second;

            if (distances[v] + w < distances[u]) {
                distances[u] = distances[v] + w;
                predecessors[u] = v;
                Q.push({ -w, u });
            }
        }
    }

    vector<int> path;
    int c = end;
    while (predecessors[c] != -1) {
        c = predecessors[c];
        path.push_back(c);
    }
    reverse(path.begin(), path.end());

    cout << "Distances from " << start << " to:\n";
    for (int i = 1; i <= n; ++i) {
        cout << i << ": " << distances[i] << '\n';
    }

    cout << "\nShortest path from " << start << " to " << end << '\n';
    for (int i : path) {
        cout << i << " => ";
    }
    cout << end;
}

int main()
{
    int n, m;
    cin >> n >> m;

    vector<vector<pair<int, int>>> graph(n + 1, vector<pair<int, int>>());

    int a, b, w;
    for (int i = 0; i < m; ++i)
    {
        cin >> a >> b >> w;
        graph[a].push_back({ b, w });
    }

    dijkstra(n, graph, 1, n);

    return 0;
}