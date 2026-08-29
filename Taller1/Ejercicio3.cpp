#include <iostream>
#include <vector>

using namespace std;

vector <vector <char >> letras;
vector <string > nombres;

string lexicoNoSeQue(){
    
    int longitudPalabraActual = 0;
    for (int i = 0; i < nombres.size() - 1; i++){
        longitudPalabraActual = nombres[i].size();
        if (nombres[i] == nombres[i + 1])
            break;
        for (int j = 0; j < nombres[longitudPalabraActual].size(); j++){
            string nombre1 = nombres[i];
            string nombre2 = nombres[i + 1];
            if (nombre1[j] == nombre2[j]){
                break;
            }
            else if (nombre1[j] != nombre2[j]){
                
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