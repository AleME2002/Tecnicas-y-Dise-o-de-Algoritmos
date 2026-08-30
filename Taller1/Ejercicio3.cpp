#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

vector <vector <char >> letras;
vector <string > nombres;
vector<int> color; // -1 = sin visitar, 0 y 1 = los dos colores

// a=0, b=1, ..., z=25

//  g    p
// [p], [ ]

/*
Si una letra esta antes q otra, pongo a la letra1 en la lista de la letra2
Ejemplo
nombres = ["pedro", "alejo"]         
'p' esta antes q 'a' por lo tanto queda
        a   b        p       z
letras[[ ],[ ],...,['a'],...[ ]]

*/

string lexicoNoSeQue(){
    
    queue<int> cola;
    color.assign(26, -1);
    int longitudPalabraActual = 0;
    for (int i = 0; i < nombres.size() - 1; i++){                                   // Itero sobre los nombres
        longitudPalabraActual = min(nombres[i].size(), nombres[i+1].size());        // Agarro la palabra mas chica ya que si nombre[i+1] fuera mas chica, habria problemas
        if (nombres[i] == nombres[i + 1])                                           // Si son el mismo nombre la corta
            break;
        for (int j = 0; j < longitudPalabraActual; j++){                            // Itero entre las letras de las palabras
            char letra1 = nombres[i][j];
            char letra2 = nombres[i + 1][j];
            if (letra1 != letra2){                                                  // Si son distintas, meto a la letra1 en la lista de la letra2
                letras[letra2 - 'a'].push_back(letra1);
                break;                                                              // Lo corto para q no siga comparando letras
            }
        }
    }
    string res = "";

    for (int i = 0; i < 26; i++){
        if (letras[i].empty()){
            res += i + 'a';
        }else{
            for (int j = 0; j < letras[i].size(); j++){
                res += letras[i][j] + 'a';
            }
            res += i + 'a';
        }
    }
    return res;
}

bool dfs(int v, int c) {
    color[v] = c;
    for (int u : aristas[v]) {
        if (color[u] == -1) {
            if (!dfs(u, 1 - c)) // pinto al vecino del color opuesto
                return false;
        } else if (color[u] == c) { // vecino con mi mismo color -> no bipartito
            return false;
        }
    }
    return true;
}


int main() {
    int n;
    cin >> n;
    nombres.resize(n);
    letras.resize(26);
    for (int i = 0; i <= n; i++) {
        cin >> nombres[i];
    }
    cout << lexicoNoSeQue() << "\n";
}