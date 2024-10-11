#include <iostream>
#include <vector>
using namespace std;


bool subset_sum(vector<int>& conj, int length, int valor, vector<vector<int>>& soluciones, vector<int>& solucion) {

    if (valor == 0) {
        soluciones.push_back(solucion);
        return true;
    }

    // caso base: Si no hay elementos o el valor objetivo es menor a 0
    if (length == 0 || valor < 0) {
        return false;
    }

    // caso donde no incluyo el elemento actual
    solucion[length - 1] = 0;
    subset_sum(conj, length - 1, valor, soluciones, solucion);

    // Caso donde incluyo el elemento actual
    solucion[length - 1] = 1;
    subset_sum(conj, length - 1, valor - conj[length - 1], soluciones, solucion);

    // Resetea la decisión para la siguiente llamada, es mi backtrack
    solucion[length - 1] = 0;

    return !soluciones.empty();

}

void imprimirRes(vector<vector<int>> soluciones, int length) {
    cout << "{";
    for(int i = 0; i < soluciones.size(); i++) {
        cout << "{";
        for(int j = 0; j < length; j++){
            cout << soluciones[i][j];
            if(j < length - 1){
                cout << ", ";
            } 
        }
        cout << "}";
        if(i < soluciones.size() - 1){
            cout << ", ";
        }
    }
    cout << "}";
}

int main() {

    vector<int> lista = {6,12,6};
    int length = lista.size();
    int k = 12;

    vector<vector<int>> soluciones;
    vector<int> solucion(length, 0);

    if(!subset_sum(lista,length,k, soluciones, solucion)) {
        cout << "No hay solucion." << endl;
        return 0;
    }

    cout << "Los subconjuntos posibles que su suma hacen k son: ";
    imprimirRes(soluciones, length);

    // lo que quiero es que me devuelva {{1,0,1}, {0,1,0}} 

    return 0;
}