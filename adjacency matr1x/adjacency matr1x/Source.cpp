#include <iostream> 
#include <vector> 
#include <fstream> 
using namespace std;

void load_undirected_unweighted(ifstream& file, int m, vector<vector<int>>& graph)
{
    int a, b;
    for (int i = 1; i <= m; ++i) {
        file >> a >> b;
        graph[a][b] = 1;
        graph[b][a] = 1;
    }
}

void load_undirected_weighted(ifstream& file, int m, vector<vector<int>>& graph)
{
    int a, b, c;
    for (int i = 1; i <= m; ++i) {
        file >> a >> b >> c;
        graph[a][b] = c;
        graph[b][a] = c;
    }
}

void load_directed_unweighted(ifstream& file, int m, vector<vector<int>>& graph)
{
    int a, b;
    for (int i = 1; i <= m; ++i) {
        file >> a >> b;
        graph[a][b] = 1;
    }
}

void load_directed_weighted(ifstream& file, int m, vector<vector<int>>& graph)
{
    int a, b, c;
    for (int i = 1; i <= m; ++i) {
        file >> a >> b >> c;
        graph[a][b] = c;
    }
}

bool edge_exists(vector<vector<int>>& graph, int a, int b)
{
    if (graph[a][b] != 0) {
        return true;
    }
    return false;
}

int main()
{
    ifstream file1, file2;

    file1.open("graph1.txt");

    int n, m;
    file1 >> n >> m;

    vector<vector<int>> graph1(n + 1, vector<int>(n + 1, 0));

    load_undirected_unweighted(file1, m, graph1);

    file1.close();

    file2.open("graph2.txt");

    file2 >> n >> m;

    vector<vector<int>> graph2(n + 1, vector<int>(n + 1, 0));

    load_undirected_weighted(file2, m, graph2);

    file2.close();

    return 0;
}