#include <iostream> 
#include <vector> 
using namespace std;

#define VVI vector<vector<int>> 

void DFSHamilton(int n, VVI& G, int v, vector<bool>& vis, vector<int>& S)
{
    S.push_back(v);
    if (S.size() >= n)
    {
        int test = false;
        for (int u : G[v])
        {
            if (u == 1)
            {
                test = true;
            }
        }
        if (test)
        {
            cout << "Hamilton Cycle: ";
        }
        else
        {
            cout << "Hamilton Path: ";
        }
        for (int i : S)
        {
            cout << i << ' ';
        }
        if (test)
            cout << 1;
    }
    else
    {
        vis[v] = true;
        for (int u : G[v])
        {
            if (!vis[u])
            {
                DFSHamilton(n, G, u, vis, S);
            }
        }
        vis[v] = false;
    }
    S.pop_back();
}

int main()
{
    int n, m;
    cin >> n >> m;

    VVI G(n + 1, vector<int>());

    int a, b;
    for (int i = 1; i <= m; ++i)
    {
        cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    vector<bool> vis(n + 1);
    vector<int> S;

    DFSHamilton(n, G, 1, vis, S);

    return 0;
}