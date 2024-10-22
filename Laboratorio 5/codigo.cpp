#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct Elemento {
    int valor;
    int listaIndex;
    int elementoIndex;
    bool operator>(const Elemento& otro) const {
        return valor > otro.valor;
    }
};

vector<int> fusionarKListas(vector<vector<int>>& listas) {
    priority_queue<Elemento, vector<Elemento>, greater<Elemento>> minHeap;
    for (int i = 0; i < listas.size(); i++) {
        if (!listas[i].empty()) {
            minHeap.push({listas[i][0], i, 0});
        }
    }
    
    vector<int> resultado;

    while (!minHeap.empty()) {
        Elemento actual = minHeap.top();
        minHeap.pop();
        
        resultado.push_back(actual.valor);

        if (actual.elementoIndex + 1 < listas[actual.listaIndex].size()) {
            minHeap.push({listas[actual.listaIndex][actual.elementoIndex + 1], actual.listaIndex, actual.elementoIndex + 1});
        }
    }

    return resultado;
}

int main() {
    vector<vector<int>> listas = {{1, 4, 5}, {1, 3, 4}, {2, 6}, {4,10,21}};
    
    vector<int> resultado = fusionarKListas(listas);
    
    cout << "Lista fusionada: ";
    for (int num : resultado) {
        cout << num << " ";
    }
    cout << endl;
    
    return 0;
}
