#include <iostream> 
#include <fstream> 
using namespace std;

struct Node
{
    int num, weight;
    Node* next;
};


void add_undirected_unweighted_edge(Node** list, int a, int b)
{
    Node* tmp;

    tmp = new Node;
    tmp->num = b;
    tmp->next = list[a];
    list[a] = tmp;

    tmp = new Node;
    tmp->num = a;
    tmp->next = list[b];
    list[b] = tmp;
}

void add_undirected_weighted_edge(Node** list, int a, int b, int c)
{
    Node* tmp;

    tmp = new Node;
    tmp->num = b;
    tmp->weight = c;
    tmp->next = list[a];
    list[a] = tmp;

    tmp = new Node;
    tmp->num = a;
    tmp->weight = c;
    tmp->next = list[b];
    list[b] = tmp;
}

void add_directed_unweighted_edge(Node** list, int a, int b)
{
    Node* tmp;

    tmp = new Node;
    tmp->num = b;
    tmp->next = list[a];
    list[a] = tmp;
}

void add_directed_weighted_edge(Node** list, int a, int b, int c)
{
    Node* tmp;

    tmp = new Node;
    tmp->num = b;
    tmp->weight = c;
    tmp->next = list[a];
    list[a] = tmp;
}

bool is_edge(Node** list, int a, int b)
{
    Node* tmp;
    tmp = list[a];
    while (tmp != nullptr) {
        if (tmp->num == b) {
            return true;
        }
        tmp = tmp->next;
    }
    return false;
}

int main()
{
    ifstream file1, file2;

    file1.open("graph1.txt");

    int n, m, a, b, c;

    file1 >> n >> m;

    Node** list1;
    list1 = new Node * [n + 1];
    for (int i = 1; i <= n; ++i) list1[i] = nullptr;

    for (int i = 1; i <= m; ++i) {
        file1 >> a >> b;
        add_undirected_unweighted_edge(list1, a, b);
    }

    file1.close();

    file2.open("graph3.txt");

    file2 >> n >> m;

    Node** list2;
    list2 = new Node * [n + 1];
    for (int i = 1; i <= n; ++i) list2[i] = nullptr;

    for (int i = 1; i <= m; ++i) {
        file2 >> a >> b >> c;
        add_undirected_weighted_edge(list2, a, b, c);
    }

    file2.close();
    return 0;
}