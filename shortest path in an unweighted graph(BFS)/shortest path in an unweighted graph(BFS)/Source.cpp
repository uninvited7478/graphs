#include <iostream> 
#include <vector> 
#include <queue> 
#include <algorithm> 
using namespace std;

constexpr int MAXN = 101;
vector<int> graph[MAXN];
int dist[MAXN];
int pred[MAXN];

constexpr int INF = 1e9;

void bfs(int start, int n)
{
    for (int i = 0; i <= n; ++i) {
        dist[i] = INF;
    }
    queue<int> q;
    q.push(start);
    dist[start] = 0;
    pred[start] = -1;
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        for (int u : graph[v]) {
            if (dist[u] == INF) {
                dist[u] = dist[v] + 1;
                pred[u] = v;
                q.push(u);
            }
        }
    }
}

vector<int> construct_path(int end)
{
    vector<int> path;
    int curr = end;
    while (pred[curr] != -1) {
        path.push_back(curr);
        curr = pred[curr];
    }
    reverse(path.begin(), path.end());
    return path;
}

int main()
{
    int n, m;
    cin >> n >> m;
    int a, b;
    for (int i = 1; i <= m; ++i) {
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    int start, end;
    cin >> start >> end;

    bfs(start, n);

    vector<int> path = construct_path(end);
    cout << "Shortest path from " << start << " to " << end << ":\n";
    cout << start;
    for (int i : path) {
        cout << " -> " << i;
    }
}