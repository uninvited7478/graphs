#include <iostream> 
#include <vector> 
#include <queue> 
using namespace std;

constexpr int MAXN = 102;
constexpr int INF = 1e9;
vector<int> graph[MAXN];
int dist[MAXN];

void bfs(int start)
{
    queue<int> Q;

    dist[start] = 0;
    Q.push(start);

    while (!Q.empty()) {
        int v = Q.front();
        Q.pop();
        for (int u : graph[v]) {
            if (dist[u] == INF) {
                dist[u] = dist[v] + 1;
                Q.push(u);
            }
        }
    }
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

    for (int i = 1; i <= n; ++i) {
        dist[i] = INF;
    }

    for (int i = 1; i <= n; ++i) {
        if (dist[i] == INF) {
            bfs(i);
        }
    }

    return 0;
}