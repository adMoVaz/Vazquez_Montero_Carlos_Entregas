#include <iostream>
#include <vector>
using namespace std;

int main() {
    /*En esta primera sección definimos variables para los ciclos posteriores*/
    int n = 1;
    int k = 0;
    int i = 0;

    /*En esta parte utilizamos vector, la cual nos permite crear vectores dinámicos, en este caso en especifico, el vector es de valores enteros*/
    vector<int> numeros = {1, 1, 2, 3, 3, 4, 5, 6, 7, 8, 8};


    /*Hay diferentes formas de escribir bucles para imprimir, esta es una forma mucho más simple*/
    cout << "Arreglo ordenado con duplicados: ";
    for (int num : numeros) {
        cout << num << " ";
    }
    cout << endl;

    /*En esta parte utilizamos el bucle para obtener la cantidad de "k", tenemos como parametro que n sea menor a al tamaño del vector.
    La complejidad algoritmica de esta sección es de O(n)  */
    while (n < numeros.size()) {
        if (numeros[n] == numeros[n - 1]) {
            k++;
        }
        n++;
    }

    /*En esta parte, es similar al anterior, sin embargo, la función erase se encarga de eliminar y desplzar el siguiente numero, lo que por si sola tiene complejidad de
     O(n), y considerando el ciclo donde esta, el peor caso tomaría O(n²)*/

    while (i < numeros.size() - 1) {
        if (numeros[i] == numeros[i + 1]) {
            numeros.erase(numeros.begin() + i + 1);
        } else {
            i++;
        }
    }

    /*En esta parte del código simplemente se vuelve a imprimir el arreglo pero sin los duplicados*/
    cout << "Arreglo sin duplicados: ";
    for (int num : numeros) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
