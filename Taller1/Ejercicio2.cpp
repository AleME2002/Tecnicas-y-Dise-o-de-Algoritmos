#include <iostream>
#include <vector>
#include <queue>
#include <set>

using namespace std;

vector <vector <int >> arbol;
vector <int > lista;
vector <int > color;

// Sin visitar = -1
// Siendo visitado = 0
// Ya visitado = 1

/*
vector<vector<int>> arbol = {
    {},          // Posición 0 (no se usa, para que los índices vayan del 1 al n)
    {2, 3},      // Vecinos del nodo 1
    {4, 1},      // Vecinos del nodo 2
    {1},         // Vecinos del nodo 3
    {2}          // Vecinos del nodo 4
};

      1
    /   \
   2     3
  /
 4
*/
/*
La idea es poner el vertice inicial en la cola, a partir de ahi meto sus vecinos en la cola y saco al vertice v cambiandole el color a visitado, y repito esto con todos los vertices
*/
string recorridoMisterioso() {
    queue<int> cola;
    cola.push(1);                                       // Le meto el primer nodo
    color[1] = 1;                                       // Lo pongo como ya visitado
    int puntero = 0;            

    if (lista[puntero] != 1){                           // Me fijo si el primer nodo el el 1, sino ya paro
        return "No";
    }
    puntero++;
    while (!cola.empty()){
        int v = cola.front();                           // Guardo el nodo que estoy visitando
        cola.pop();                                     // Lo saco de la cola

        int vNoVisitados = 0;
        set<int> vecinosNoVisitados; 

        for (int i = 0; i < arbol[v].size(); i++){      // Itero sobre los vecinos
            if (color[arbol[v][i]] != 1){               // Si no estan visitados, los meto en la cola
                cola.push(arbol[v][i]);
                vNoVisitados++;
            }
        }

        for (int i = 0; i < vNoVisitados; i++){
            if (!vecinosNoVisitados.count(lista[puntero + i])){
                return "No";
            }
        }
    }
    return "Yes";
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
    color.assign(n + 1, -1);
    recorridoMisterioso();
}





