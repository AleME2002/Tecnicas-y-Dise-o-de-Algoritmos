#include <iostream>
#include <vector>

using namespace std;

vector < vector < int>> arbol;
vector < int> lista;

int main() {
    int n;
    cin >> n;
    arbol.resize(n + 1);
    for (int i = 1; i <= n - 1; i++) {
        int u,v;
        cin >> u >> v;
        arbol[u].push_back(v);
        arbol[v].push_back(u);
    }
    lista.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> lista[i];
    }
    return 0;
}