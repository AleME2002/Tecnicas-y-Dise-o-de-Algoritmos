#include <iostream>
#include <vector>

using namespace std;

vector <vector <int >> arbol;
vector <int > lista;
vector <int > color ; // -1 = sin visitar , 0 y 1 = los dos colores

// Sin identificar = -1

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


bool recoridoMisterioso(){

}