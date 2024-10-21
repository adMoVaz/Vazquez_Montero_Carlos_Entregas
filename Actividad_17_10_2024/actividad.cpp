#include <iostream>
using namespace std;

int descomponerEnDenominaciones(int valor, int arr[], int n) {
    int totalDenominaciones = 0;
    
    for (int i = n - 1; i >= 0; i--) {
        int cantidad = valor / arr[i];
        if (cantidad > 0) {
            totalDenominaciones += cantidad;
            valor %= arr[i];
        }
    }
    
    return totalDenominaciones;
}

int main(){
    cout << "Ejercicio 17/10/2024" << endl;

    int arr[9] = {1, 2, 5, 10, 20, 50, 100, 500, 1000}; 
    int num = 0;

    cout << "Ingrese el numero a cambiar: ";
    cin >> num;

    int total = descomponerEnDenominaciones(num, arr, 9);
    
    cout << total << endl;

    return 0;
}
