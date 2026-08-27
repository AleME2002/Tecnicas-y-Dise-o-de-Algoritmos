#include <iostream>
#include <vector>

using namespace std;

vector <vector <int >> arbol;
vector <int > lista;
vector <int > color; // -1 = sin visitar , 0 y 1 = los dos colores

// Sin identificar = -1
// Viendo Actualmente = 0
// Ya visto = 1