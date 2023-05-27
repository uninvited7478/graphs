#include <iostream> 
#include <vector> 
#include <algorithm> 
using namespace std;

constexpr int MAXN = 101;
vector<int> graph[MAXN];
bool vis[MAXN];
int pred[MAXN];

void dfs(int v, int p)
{
    vis[v] = true;
    pred[v] = p;
    for (int u : graph[v]) {
        if (!vis[u]) {
            dfs(u, v);
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

    dfs(start, -1);

    vector<int> path = construct_path(end);
    cout << "Some path from " << start << " to " << end << ":\n";
    cout << start;
    for (int i : path) {
        cout << " -> " << i;
    }
}