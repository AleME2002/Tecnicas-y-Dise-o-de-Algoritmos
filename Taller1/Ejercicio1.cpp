#include <iostream>
#include <vector>

using namespace std;


vector < int > vendedores;

/*
vendedores = [6,2,3,4,-1,4,3] esta es una representacion, la posicion reprecenta al empleado y lo q esta en esa posicion representa a su superior, 
                                                         salvo por el 0 q representa la cantidad total de empleados

        4    (nivel 1)
       / \
      3   5  (nivel 2)
     / \
    2   6    (nivel 3)
   /
  1          (nivel 4)
  

Necesito saber en cuantas mesas tengo q separar a los empleados para q no esten sentados juntos a sus jefes, mi peor caso seria q haya solo una rama de largo n y q por ende necesite n mesas.
Por ende solo necesito la longitud de la rama mas larga de el grafo para saber la cantidad minima de mesas q voy a necesitar

Me fijo a q distancia esta el empleado en la posicion i hasta la raiz, poniendo un contador que va sumando 1 mientras pasa por cada nodo hasta llegar a la raiz
*/

int cantDeMesas (int n){
    int alturaMax = 0;
    for (int i = 1; i <= n; i++){               // Itero sobre todos los vendedores, salteandome el 0 ya q no es un vendedor
        int alturaAct = 0;                      
        int actual = i;                         // Guardo la posicion del empleado inicial
        while(actual != -1){                    // Itero mientras no llegue a una raiz
            actual = vendedores[actual];        // Paso al jefe del empleado y lo transformo en el actual
            alturaAct += 1;                     // Sumo uno a la altura de la rama
        }
        if (alturaAct > alturaMax){             // Me fijo si la rama q acabo de chequear es la mas larga, y si lo es la remplazo
            alturaMax = alturaAct;
        }
    }
    return alturaMax;
}





