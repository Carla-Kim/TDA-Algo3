#include <iostream>
#include <algorithm> //sort
#include <vector>
using namespace std;

bool ordenarPorSegundo(const vector<int>& a, const vector<int>& b) {
    return a[1] < b[1]; 
}
//sort funciona tomando dos elementos del vector y los compara por el comparador personalizado, si es true lo mantiene si es false los swapea
//el const asegura para el que lee y el compilador que los datos no se van a cambiar nunca

int busy(vector<vector<int>>& h){

    //sort para un vector<vector(2)> que ordena por el segundo. Es la decision greedy, elegimos el horario que mas temprano termina asi podemos meter mas actividades
    //sort le indicamos desde donde hasta donde ordenar y luego la condicion de comparacion (bool)
    sort(h.begin(), h.end(), ordenarPorSegundo); //O(h log h)
    
    int cantAct = 1; //se comienza con una actividad si la lista no es vacia
    int ultimaAct= h[0][1]; //primer actividad

    for(int i = 1; i < h.size(); i++){ //O(h)
        if(ultimaAct <= h[i][0]) {
            cantAct++;
            ultimaAct = h[i][1]; //actualizamos y evaluamos para la siguiente actividad
        }
    }
    return cantAct;
}

int main() {
    int T; // cantidad de casos tests
    cin >> T;

    for(int j = 0; j < T; j++){
        int N;
        cin >> N;
        
        // Si no hay actividades, return 0
        if (N == 0) { 
            cout << 0 << endl;
            continue; //tecniva para saltearse un pasito del for
        }
        
        vector<vector<int>> horarios(N, vector<int>(2));
        //N filas y 2 columnas
        
        for(int i = 0; i < N; i++){
            cin >> horarios[i][0] >> horarios[i][1];
        }
        
        cout << busy(horarios) << endl;
        //endl por como lo muestra en el output test
    }

    return 0;
}