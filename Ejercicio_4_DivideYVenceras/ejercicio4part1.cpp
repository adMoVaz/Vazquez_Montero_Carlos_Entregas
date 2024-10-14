#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <cmath>
#include <iomanip>
#include <chrono>

using namespace std;
using namespace chrono;

struct Coordenada {
    float x;
    float y;
};

float generarNumeroAleatorio(float min, float max) {
    return min + static_cast<float>(rand()) / (static_cast<float>(RAND_MAX / (max - min)));
}

bool compararPorX(const Coordenada& a, const Coordenada& b) {
    return a.x < b.x;
}

float calcularDistancia(const Coordenada& a, const Coordenada& b) {
    return sqrt(pow(b.x - a.x, 2) + pow(b.y - a.y, 2));
}

int main() {
    srand(time(0)); 
    int cantidad;

    cout << "Ingresa la cantidad de coordenadas a generar: ";
    cin >> cantidad;

    vector<Coordenada> coordenadas;

    for (int i = 0; i < cantidad; ++i) {
        Coordenada coord;
        coord.x = generarNumeroAleatorio(-10.0f, 10.0f);
        coord.y = generarNumeroAleatorio(-10.0f, 10.0f);
        coordenadas.push_back(coord);
    }

    auto start = high_resolution_clock::now();

    sort(coordenadas.begin(), coordenadas.end(), compararPorX);

    cout << fixed << setprecision(1);

    cout << "\nCoordenadas generadas y ordenadas por X:\n";
    for (const auto& coord : coordenadas) {
        cout << "(" << coord.x << ", " << coord.y << ")\n";
    }

    float distanciaMinima = numeric_limits<float>::max();
    Coordenada punto1, punto2;

    for (size_t i = 0; i + 1 < coordenadas.size(); i += 2) {
        float distancia = calcularDistancia(coordenadas[i], coordenadas[i + 1]);
        if (distancia < distanciaMinima) {
            distanciaMinima = distancia;
            punto1 = coordenadas[i];
            punto2 = coordenadas[i + 1];
        }
    }

    auto end = high_resolution_clock::now();
    duration<double> tiempo = end - start;

    cout << "\nLa distancia más corta es: " << distanciaMinima << "\n";
    cout << "Entre los puntos (" << punto1.x << ", " << punto1.y << ") y ("
         << punto2.x << ", " << punto2.y << ")\n";

    cout << "Tiempo de ejecución: " << tiempo.count() << " segundos\n";

    return 0;
}
