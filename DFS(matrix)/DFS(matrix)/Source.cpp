#include <iostream> 
using namespace std;

constexpr int MAXN = 102;
bool graph[MAXN][MAXN];
bool vis[MAXN];

void dfs(int v, int n)
{
    vis[v] = true;
    for (int u = 1; u <= n; ++u) {
        if (graph[v][u] && !vis[u]) {
            dfs(u, n);
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
        graph[a][b] = true;
        graph[b][a] = true;
    }

    for (int i = 1; i <= n; ++i) {
        vis[i] = false;
    }

    for (int i = 1; i <= n; ++i) {
        if (!vis[i]) {
            dfs(i, n);
        }
    }
    return 0;
}