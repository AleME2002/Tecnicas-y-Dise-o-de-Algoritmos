#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>

using namespace std;

int costoGasoducto(string ruta, int ct, int cp){
    int costo1 = cp; 
    int costo2 = -1;

    for (int i = 0; i < ruta.size(); i++){
        int nuevo1 = -1;
        int nuevo2 = -1; 

        if (ruta[i] == '1'){
            if (costo2 != -1){ 
                nuevo2 = costo2 + ct + 2*cp;
            }
        } 
        else{ 
            if (costo1 != -1 && costo2 != -1) {
                nuevo1 = min(costo1 + ct + cp, costo2 + 2*ct + cp); 
            }else if (costo1 != -1) {
                nuevo1 = costo1 + ct + cp;
            }else if (costo2 != -1){
                nuevo1 = costo2 + 2*ct + cp;
            }
 
            if (costo1 != -1 && costo2 != -1) {
                nuevo2 = min(costo1 + 2*ct + 2*cp, costo2 + ct + 2*cp);
            }else if (costo1 != -1) {
                nuevo2 = costo1 + 2*ct + 2*cp;
            }else if (costo2 != -1){
                nuevo2 = costo2 + ct + 2*cp; 
            }
        }
        costo1 = nuevo1; 
        costo2 = nuevo2;
    } 
    return costo1;
}

int main() {
    int t;
    cin >> t;
     
    for (int i = 0; i < t; i++){
        int n, costoTubo, costoPilar;
        string ruta;

        cin >> n >> costoTubo >> costoPilar >> ruta;
        cout << costoGasoducto(ruta, costoTubo, costoPilar) << '\n';
    }
}