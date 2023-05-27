#include <iostream> 
#include <vector> 
using namespace std;

constexpr int MAXN = 102;
vector<int> graph[MAXN];
bool vis[MAXN];

void dfs(int v)
{
    vis[v] = true;
    for (int u : graph[v]) {
        if (!vis[u]) {
            dfs(u);
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
        vis[i] = false;
    }

    for (int i = 1; i <= n; ++i) {
        if (!vis[i]) {
            dfs(i);
        }
    }
    return 0;
}