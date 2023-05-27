#include<iostream>  
#include<fstream> 
#include<vector> 

using namespace std;

int main()
{

    int n, m;

    fstream plik("graf1.txt", ios::in | ios::out);
    plik >> n >> m;

    vector<vector<int>> G(n + 1);

    int a, b;
    while (plik >> a >> b) {
        G[a].push_back(b);
        G[b].push_back(a);
    }

    int res = -1;

    for (int i = 0; i < n; i++)
    {
        cout << G[i].size() << endl;

        res = max(res, int(G[i].size()));
    }

    cout << res;
    plik.close();
    return 0;
}