#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// tenemos tres estados posibles caudno evaluamos: 
    //pintar negro si ascendente
    //pintar blanco si descendente
    //no pintar si Ninguno de los dos 
// procedemos a llamar recursivamente evaluando los tres casos posibles chequeando en el dpmemo si ya fue definido o no.

vector<vector<vector<int>>> dpMemo;
vector<int> c;

int bOrW(int indice, int black, int white) {

    //estructura de memoizacion: Matriz de NxNxN
    if(dpMemo[indice][black][white] != -1) {
        return dpMemo[indice][black][white];
    }

    if(indice == c.size()){
        return 0;
    }

    //opcion base: sin pintar
    int res = 1 + bOrW(indice + 1, black, white);
    
    //descendiente
    //se reemplzaba el black por el indice anterior en el numero black
    if(black == c.size() || c[black] < c[indice]){
        res = min(res, bOrW(indice + 1, indice, white));
    }

    //descendiente
    // se reemplaza el white por el indice anterior en el nuevo white
    if(white == c.size() || c[white] > c[indice]){
        res = min(res, bOrW(indice + 1, black, indice));
    }
    
    //dado el elemento actual evaluamos los dos casos posibles
        //si el actual es mayor al anterior o se pinta de negro o se deja
        //si el actual es menor al anterior o se pinta de blanco o se deja
    //comparamos 

    dpMemo[indice][black][white] = res;

    return dpMemo[indice][black][white];
    
}

int main() {
    vector<int> resultados;  // guarda los resultados de todos los casos de prueba
    
    while (true) {
        int N;
        cin >> N;

        if (N == -1) {
            break;  // si se lee -1, terminamos los casos de prueba
        }

        //memoizacion
        dpMemo.assign(N + 1, vector<vector<int>>(N + 1, vector<int>(N + 1, -1)));

        c.resize(N);
        for (int i = 0; i < N; i++) {
            cin >> c[i];
        }

        resultados.push_back(bOrW(0, N, N));
    }

    for (int res : resultados) {
        cout << res << endl;
    }

    return 0;
}

//input
//8
//1 4 2 3 3 2 4 1
//12
//7 8 1 2 4 6 3 5 2 1 8 7
//-1

//ouput
//0
//2
