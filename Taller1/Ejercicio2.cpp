#include <iostream>
#include <vector>

using namespace std;

vector <vector <int >> arbol;
vector <int > lista;
vector <int > color; // -1 = sin visitar , 0 y 1 = los dos colores

// Sin identificar = -1
// Viendo Actualmente = 0
// Ya visto = 1

vector<vector<int>> aristas;

bool dfs(int v, int c) {
    color[v] = c;
    for (int u : aristas[v]) {
        if (color[u] == -1) {
            if (!dfs(u, 1 - c)) { // pinto al vecino del color opuesto
                return false;
            }
        } else if (color[u] == c) { // vecino con mi mismo color -> no bipartito
            return false;
        }
    }
    return true;
}

bool esBipartito(int n) {
    color.assign(n, -1);
    for (int v = 0; v < n; v++) {
        if (color[v] == -1) {
            if (!dfs(v, 0)) {
                return false;
            }
        }
    }
    return true;
}

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
    color.assign(n, -1);
}


bool recoridoMisterioso(){
    for(int i = 1; i < arbol.size(); i++){
        
    }
}





