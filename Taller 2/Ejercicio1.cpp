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


int diasDeDescanzo(vector <int > v){
    int ultimo = 0;                                     //Guarda lo q hizo el dia anterior, 0 si descanzo, 1 si compitio, 2 si fue al gym
    int res = 0; 
    for (int i : v) {
        if ((i == 1 || i == 3) && ultimo != 1) {
            ultimo = 1;  
        } 
        else if ((i == 2 || i == 3) && ultimo != 2) {
            ultimo = 2;
        }  
        else {  
            res++;
            ultimo = 0; 
        }
    }
    return res;
}

int main() {
    int n;
    cin >> n;

    vector <int > vacaciones(n);

    for (int i = 1; i < n; i++) {
        cin >> vacaciones[i];
    }
    cout << diasDeDescanzo(vacaciones);
}