#include <iostream> 
#include <queue> 
using namespace std;

const int MAXN = 1'001;
bool graph[MAXN][MAXN];
int vis[MAXN];

void checkConnectivity(int v, int n, int& vCounter)
{
    vis[v] = true;
    vCounter++;
    for (int u = 1; u <= n; ++u)
    {
        if (graph[v][u])
        {
            if (!vis[u])
            {
                checkConnectivity(u, n, vCounter);
            }
        }
    }
}

bool isEulerCyclePossible(int n)
{
    int vCounter = 0;
    checkConnectivity(1, n, vCounter);

    if (vCounter != n)
    {
        cout << "Given graph is not connected!\n";
        return false;
    }

    for (int v = 1; v <= n; ++v)
    {
        int vDegree = 0;
        for (int i = 1; i <= n; ++i)
        {
            if (graph[v][i])
            {
                vDegree++;
            }
        }
        if (vDegree % 2 == 1)
        {
            cout << "Given graph has vertex with odd degree!\n";
            return false;
        }
    }
    return true;
}

void eulerDFS(int v, int n, queue<int>& Q)
{
    for (int u = 1; u <= n; ++u)
    {
        if (graph[v][u])
        {
            graph[v][u] = false;
            graph[u][v] = false;
            eulerDFS(u, n, Q);
        }
    }
    Q.push(v);
}

void eulerCycle(int n)
{
    queue<int> Q;

    eulerDFS(1, n, Q);

    while (!Q.empty())
    {
        cout << Q.front() << ' ';
        Q.pop();
    }
}

int main()
{
    int n, m;
    cin >> n >> m;

    int a, b;
    for (int i = 1; i <= m; ++i)
    {
        cin >> a >> b;
        graph[a][b] = true;
        graph[b][a] = true;
    }

    if (isEulerCyclePossible(n))
    {
        cout << "Euler cycle:\n";
        eulerCycle(n);
    }
    else
    {
        cout << "Euler cycle not possible\n";
    }

    return 0;
}