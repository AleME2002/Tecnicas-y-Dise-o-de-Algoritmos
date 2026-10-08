#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>

using namespace std;

vector <int > vacaciones;

/*
 es 0 si el gimnasio está cerrado y no se realiza la competencia por internet.
 es 1 si el gimnasio está cerrado, pero se realiza la competencia por internet.
 es 2 si el gimnasio está abierto y no se realiza la competencia por internet.
 es 3 si el gimnasio está abierto y se realiza la competencia por internet.

 ult es lo que hizo el dia anteriror
 0 descanso
 1 comnpitio
 2 gym

 */


int diasDeDescanzo(int i, int ult){
    int res = 0; 
    if (i == vacaciones.size()){
        return 0;
    }
    int n = vacaciones[i];
    if (n == 1 && ult != 1) {
        res = diasDeDescanzo(i + 1, 1); 
    } 
    else if (n == 2 && ult != 2) {
        res = diasDeDescanzo(i + 1, 2); 
    }  
    else if (n == 3){
        if (ult == 1){
            res = diasDeDescanzo(i + 1, 2); 
        }
        else if (ult == 2){
            res = diasDeDescanzo(i + 1, 1); 
        }
        else {
            res = min(diasDeDescanzo(i + 1, 1), diasDeDescanzo(i + 1, 2));
        }
    }
    else {  
        res = 1 + diasDeDescanzo(i + 1, 0); 
    }
    
    return res;
}


int main() {
    int n;
    cin >> n;

    vacaciones.resize(n);

    for (int i = 0; i < n; i++) {
        cin >> vacaciones[i];
    }
    cout << diasDeDescanzo(0, 0);
}