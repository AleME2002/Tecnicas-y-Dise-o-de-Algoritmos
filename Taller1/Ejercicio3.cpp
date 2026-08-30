#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector <vector <char >> letras;
vector <string > nombres;

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

    
    return "";
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