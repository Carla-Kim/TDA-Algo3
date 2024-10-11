#include <iostream>
#include <algorithm> // sort
#include <cmath> // floor
#include <vector>
using namespace std;

// con el tema de las vacas, buscar la mayor distancia minima implica redicir las distancias entre vacas y en cada candidato a minima elegida (mid) preguntarse si todas las vacas entran, si no reducir el candidato para hacer mas espacio a las cavas y si entran peguntarse si hay una mayor distancia minima 

vector<int> stalls;

bool vacasBienPosicionadas(vector<int> stalls, int cows, int mid) {
    int ultimoStall = stalls[0];
    int totVacasPosicionadas = 1;

    for(int i = 1; i < stalls.size(); i++) { //O(N)
        if(stalls[i] - ultimoStall >= mid) { // la distancia puede ser mayor o igual pero no menor que el candidato a minimo
            ultimoStall = stalls[i];
            totVacasPosicionadas ++; // se suman las vaquitas posicionadas en relacion a la distancia minima

            if(totVacasPosicionadas == cows) {
                return true;
            }
        }
    }
    return false;
}

int aggrCow(int cows, vector<int> stalls) {

    sort(stalls.begin(), stalls.end()); // O(N log N)

    int res = 1; // maxima distancia minima
    int izq = 0;
    int der = stalls[stalls.size() - 1] - stalls[0]; //se hace en respecto a los elementos del vector en vez de la posicion por su relevancia con el ejercicio y no por la posicion del elemento

    while(izq <= der) { // O(log N)
        int mid = floor((der + izq) / 2); //candidato a distancia minima

        if(vacasBienPosicionadas(stalls, cows, mid)) {
            res = mid; // encontramos el mid
            izq = mid + 1; // probamos si no hay otra mayor distancia minima
        } else {
            der = mid - 1; // todavia no se encontro la distancia minima
        }
    }

    return res;
}

int main() {
    int T;
    cin >> T;

    vector<int> resultados;  // guarda los resultados de todos los casos de prueba

    for(int j = 0; j < T; j++) {

        int N; //establos
        int C; //vacas
        cin >> N >> C;

        stalls.resize(N);
    
        for(int i = 0; i < N; i++) {
            cin >> stalls[i];
        }

        resultados.push_back(aggrCow(C, stalls));
    }

    for (int res : resultados) {
        cout << res << endl;
    }

    return 0;
}