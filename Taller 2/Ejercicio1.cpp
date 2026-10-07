#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>

using namespace std;

/*
 es 0 si el gimnasio está cerrado y no se realiza la competencia por internet.
 es 1 si el gimnasio está cerrado, pero se realiza la competencia por internet.
 es 2 si el gimnasio está abierto y no se realiza la competencia por internet.
 es 3 si el gimnasio está abierto y se realiza la competencia por internet.
*/



int organizarVacaciones(vector <int > v){
    vector<bool > descanso(2, false);                       // Si es falso significa q no necesita descansar, el 1ero es para gym y el 2do para estudiar
    int res;
    for (int i: v){
        if (i == 0){
            res += 1;
            fill(descanso.begin(), descanso.end(), false);
        }
        else if (i == 1){
            
        }
    }
}

int main() {
    int n;
    cin >> n;

    vector <int > vacaciones(n);

    for (int i = 1; i <= n; i++) {
        cin >> vacaciones[i];
    }
    cout << organizarVacaciones(vacaciones);
}