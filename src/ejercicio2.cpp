#include <iostream>
#include <vector>
using namespace std;

// estructura para retornar multiples valores //
struct ResultadoMinMax {
    double valorMaximo;
    double valorMinimo;
    int posicionMaximo;
    int posicionMinimo;
};

// funcion para encontrar los valores minimo y maximo //
ResultadoMinMax encontrarMinMax(const vector<double>& arreglo) {
    ResultadoMinMax resultado;

    // validar que el arreglo no este vacio //

    if (arreglo.empty()) {
        cout << "ERROR: El arreglo esta vacio" << endl;
        resultado.valorMaximo = 0;
        resultado.valorMinimo = 0;
        resultado.posicionMaximo = -1;
        resultado.posicionMinimo = -1;
        return resultado;
    }

    // inicializar con el primer elemento del arreglo //

    resultado.valorMaximo = arreglo[0];
    resultado.valorMinimo = arreglo[0];
    resultado.posicionMaximo = 0;
    resultado.posicionMinimo = 0;

    // Recorrer el resto del arreglo buscando maximo y minimo //

    for (size_t i = 1; i < arreglo.size(); i++) {
        // buscar maximo //
        if (arreglo[i] > resultado.valorMaximo) {
            resultado.valorMaximo = arreglo[i];
            resultado.posicionMaximo = i;
        }

        // buscar minimo //
        if (arreglo[i] < resultado.valorMinimo) {
            resultado.valorMinimo = arreglo[i];
            resultado.posicionMinimo = i;
        }
    }

    return resultado;
}

int main() {
    int n;

    cout << "=== EJERCICIO 2: Maximo y Minimo de un Arreglo ===" << endl;
    cout << "\nIngrese el tamano del arreglo: ";
    cin >> n;

    // validar entrada
    if (n <= 0) {
        cout << "ERROR: El tamano debe ser mayor a 0" << endl;
        cout << "\nPresione Enter para salir...";
        cin.ignore();
        cin.get();
        return 1;
    }

    // crear vector de tamano n //
    vector<double> arreglo(n);

    // llenar el arreglo con valores ingresados por el usuario //
    cout << "\nIngrese los " << n << " elementos del arreglo:" << endl;
    for (int i = 0; i < n; i++) {
        cout << "Elemento [" << i << "]: ";
        cin >> arreglo[i];
    }

    // aqui llamamos la funcion //
    ResultadoMinMax resultado = encontrarMinMax(arreglo);

    // tabla de resultados //
    cout << "\n--- Resultados ---" << endl;
    cout << "Valor maximo: " << resultado.valorMaximo
        << " (posicion: " << resultado.posicionMaximo << ")" << endl;
    cout << "Valor minimo: " << resultado.valorMinimo
        << " (posicion: " << resultado.posicionMinimo << ")" << endl;

    cout << "\nPresione Enter para salir...";
    cin.ignore();
    cin.get();

    return 0;
}
