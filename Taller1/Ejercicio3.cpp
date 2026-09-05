#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>

using namespace std;

vector <vector <int >> letras;
vector <string > nombres;
vector<int> color; 
vector<int> orden;

// sin visitar = -1
// Siendo visitados = 0
// Ya visitados = 1

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

string dfs(int v) {
    
    color[v] = 0;
    for (int u : letras[v]) {           // Itero entre las letras
        if (color[u] == -1) {           // Me fijo si el color de la letra es -1
            string res = dfs(u);        // pinto al vecino del color opuesto
            if (res == "Impossible"){
                return "Impossible";
            }
        }else if (color[u] == 0) {      // vecino con mi mismo color -> hay un ciclo
            return "Impossible";
        }
    }
    orden.push_back(v);
    color[v] = 1;
    string res = "";
    return res;
}
 
bool pertenece(char l, vector<int> lista){
    for (int i = 0; i < lista.size(); i++){
        if (lista[i] == l){
            return true;
        }
    }
    return false;
}

string lexicoNoSeQue(){
    
    color.assign(26, -1);
    int longitudPalabraActual = 0;
    for (int i = 0; i < nombres.size() - 1; i++){                                   // Itero sobre los nombres
        bool hayDif = false;
        longitudPalabraActual = min(nombres[i].size(), nombres[i+1].size());        // Agarro la palabra mas chica ya que si nombre[i+1] fuera mas chica, habria problemas
        for (int j = 0; j < longitudPalabraActual; j++){                            // Itero entre las letras de las palabras
            char letra1 = nombres[i][j];
            char letra2 = nombres[i + 1][j];
            if (letra1 != letra2){                                                  // Si son distintas, meto a la letra1 en la lista de la letra2
                if (!pertenece(letra2 - 'a', letras[letra1 - 'a'])){                // Me fijo si la letra2 ya pertenece a la lista de la letra1
                    letras[letra1 - 'a'].push_back(letra2 - 'a');
                }
                hayDif = true;
                break;                                                              // Lo corto para q no siga comparando letras
            }
        }
        if (!hayDif && nombres[i].size() > nombres[i + 1].size()) {
            return "Impossible";
        }
    }

    for (int i = 0; i < 26; i++){               // Me fijo letra por letra si ya fueron chequeadas y sino hago dfs adentro
        if (color[i] == -1){
            string res = dfs(i);
            if (res == "Impossible"){
                return res;
            }            
        }
    }

    reverse(orden.begin(), orden.end());

    string res = "";
    for (int i : orden){
        res += (char)(i + 'a');
    }

    return res;
}


int main() {
    int n;
    cin >> n;
    nombres.resize(n);
    letras.resize(26);
    for (int i = 0; i < n; i++) {
        cin >> nombres[i];
    }
    cout << lexicoNoSeQue() << "\n";
}