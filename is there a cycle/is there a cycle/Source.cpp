#include<iostream> 
#include<vector> 
#include <stack> 

using namespace std;

constexpr int MAX_N = 1'000'000;
vector<int> G[MAX_N];
bool vis[MAX_N];

bool isCycle(int start)
{
    stack<pair<int, int>> S;

    S.push({ start, start });
    vis[start] = true;

    while (!S.empty()) {
        int v = S.top().first;
        int p = S.top().second;
        S.pop();

        for (int u : G[v]) {
            if (!vis[u]) {
                vis[u] = true;
                S.push({ u, v });
            }
            else if (u != p) {
                return true;
            }
        }
    }
    return false;
}


int main()
{
    int n, m;
    cin >> n >> m;

    int a, b;
    for (int i = 1; i <= m; ++i) {
        cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    for (int i = 1; i <= n; ++i) {
        if (!vis[i]) {
            if (isCycle(i)) {
                cout << "Cycle exists\n";
                return 0;
            }
        }
    }
    cout << "Cycle does not exists\n";

    return 0;
}