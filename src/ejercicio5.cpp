#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>
using namespace std;

// definimos tipo matriz//
typedef vector<vector<double>> Matriz;

//imprimir matriz con formato//
void imprimirMatriz(const Matriz& matriz) {
    for (const auto& fila : matriz) {
        for (double valor : fila) {
            //si el numero es entero, mostrarlo sin decimales//
            if (valor == (int)valor) {
                cout << setw(12) << (int)valor << " ";
            }
            else {
                cout << setw(12) << setprecision(2) << fixed << valor << " ";
            }
        }
        cout << endl;
    }
}

//transponer matriz (intercambiar filas por columnas)//
Matriz transponer(const Matriz& matriz) {
    int filas = matriz.size();
    int columnas = matriz[0].size();
    Matriz transpuesta(columnas, vector<double>(filas));

    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            transpuesta[j][i] = matriz[i][j];
        }
    }

    return transpuesta;
}

//multiplicar dos matrices//
Matriz multiplicarMatrices(const Matriz& A, const Matriz& B) {
    int filasA = A.size();
    int columnasA = A[0].size();
    int columnasB = B[0].size();

    Matriz C(filasA, vector<double>(columnasB, 0.0));

    for (int i = 0; i < filasA; i++) {
        for (int j = 0; j < columnasB; j++) {
            for (int k = 0; k < columnasA; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }

    return C;
}

//caculamos el determinante//
double calcularDeterminante(const Matriz& matriz) {
    int n = matriz.size();

    //caso base: matriz 1x1//
    if (n == 1) {
        return matriz[0][0];
    }

    //caso base: matriz 2x2//
    if (n == 2) {
        return matriz[0][0] * matriz[1][1] - matriz[0][1] * matriz[1][0];
    }

    //para matrices mas grandes: eliminacion gaussiana//
    Matriz temp = matriz;
    double det = 1.0;

    for (int i = 0; i < n; i++) {
        //buscar el pivote (elemento mas grande en la columna)//
        int maxRow = i;
        for (int k = i + 1; k < n; k++) {
            if (abs(temp[k][i]) > abs(temp[maxRow][i])) {
                maxRow = k;
            }
        }

        //si el pivote es cero, el determinante es cero//
        if (abs(temp[maxRow][i]) < 1e-10) {
            return 0.0;
        }

        //intercambiar filas si es necesario//
        if (maxRow != i) {
            swap(temp[i], temp[maxRow]);
            det *= -1;  //cambio de signo por intercambio//
        }

        //multiplicar el determinante por el elemento diagonal//
        det *= temp[i][i];

        //eliminacion hacia abajo//
        for (int k = i + 1; k < n; k++) {
            double factor = temp[k][i] / temp[i][i];
            for (int j = i; j < n; j++) {
                temp[k][j] -= factor * temp[i][j];
            }
        }
    }

    return det;
}

//calcular inversa con metodo de gauss-jordan//
bool calcularInversa(const Matriz& matriz, Matriz& inversa) {
    int n = matriz.size();

    //crear matriz aumentada//
    Matriz aumentada(n, vector<double>(2 * n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            aumentada[i][j] = matriz[i][j];
            aumentada[i][j + n] = (i == j) ? 1.0 : 0.0;
        }
    }

    //eliminacion gaussiana con pivoteo parcial//
    for (int i = 0; i < n; i++) {
        //buscar pivote//
        int maxRow = i;
        for (int k = i + 1; k < n; k++) {
            if (abs(aumentada[k][i]) > abs(aumentada[maxRow][i])) {
                maxRow = k;
            }
        }

        //si el pivote es muy pequeño, la matriz es singular//
        if (abs(aumentada[maxRow][i]) < 1e-10) {
            return false;
        }

        //intercambiar filas//
        swap(aumentada[i], aumentada[maxRow]);

        //bormalizar la fila pivote//
        double pivote = aumentada[i][i];
        for (int j = 0; j < 2 * n; j++) {
            aumentada[i][j] /= pivote;
        }

        //eliminar hacia arriba y hacia abajo//
        for (int k = 0; k < n; k++) {
            if (k != i) {
                double factor = aumentada[k][i];
                for (int j = 0; j < 2 * n; j++) {
                    aumentada[k][j] -= factor * aumentada[i][j];
                }
            }
        }
    }

    //extraer la matriz inversa de la parte derecha//
    inversa.resize(n, vector<double>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            inversa[i][j] = aumentada[i][j + n];
        }
    }

    return true;
}

//calculamos la pseudoinversa//
bool calcularPseudoinversa(const Matriz& matriz, Matriz& pseudoinversa) {
    // pseudoinversa de moore-penrose//

    Matriz At = transponer(matriz);
    Matriz AtA = multiplicarMatrices(At, matriz);
    Matriz AtA_inv;


    if (!calcularInversa(AtA, AtA_inv)) {
        return false;
    }

    pseudoinversa = multiplicarMatrices(AtA_inv, At);
    return true;
}

//inciamos la funcion principal //
int main() {
    int filas, columnas;

    cout << "Ej. 5: Inversa y Pseudoinversa de Matriz" << endl;
    cout << "\nIngrese el numero de filas: ";
    cin >> filas;
    cout << "Ingrese el numero de columnas: ";
    cin >> columnas;

    //validar dimensiones//
    if (filas <= 0 || columnas <= 0) {
        cout << "\nERROR: Las dimensiones deben ser mayores a 0" << endl;
        return 1;
    }

    //crear y llenar la matriz//
    Matriz matriz(filas, vector<double>(columnas));

    cout << "\nIngrese los elementos de la matriz (fila por fila):" << endl;
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            cout << "Elemento [" << i << "][" << j << "]: ";
            cin >> matriz[i][j];
        }
    }

    //mostrar la matriz ingresada//
    cout << "\nMatriz Ingresada:" << endl;
    cout << fixed << setprecision(2);  //maximo 2 decimales//
    imprimirMatriz(matriz);

    //matriz cuadrada//
    if (filas == columnas) {
        cout << "\nLa matriz es CUADRADA (" << filas << "x" << columnas << ")" << endl;

        //calcular determinante//
        double det = calcularDeterminante(matriz);
        cout << "Determinante: " << det << endl;

        //verificar si tiene inversa//
        if (abs(det) < 1e-10) {
            cout << "\nResultado:" << endl;
            cout << "La matriz NO tiene inversa porque su determinante es cero." << endl;
            cout << "Razon: La matriz es SINGULAR (filas/columnas linealmente dependientes)" << endl;
        }
        else {
            // Calcular inversa
            Matriz inversa;
            if (calcularInversa(matriz, inversa)) {
                cout << "\n--- Inversa de la Matriz ---" << endl;
                cout << fixed << setprecision(4);  //4 decimales para la inversa//
                imprimirMatriz(inversa);

                //verificación: A * A^(-1) = I//
                cout << "\n--- Verificacion: A * A^(-1) ---" << endl;
                Matriz verificacion = multiplicarMatrices(matriz, inversa);
                imprimirMatriz(verificacion);
                cout << "(Debe ser aproximadamente la matriz identidad)" << endl;
            }
            else {
                cout << "\nERROR: No se pudo calcular la inversa." << endl;
            }
        }
    }
    //matriz no cuadrada
    else {
        cout << "\nLa matriz NO es CUADRADA (" << filas << "x" << columnas << ")" << endl;
        cout << "Se calculara la PSEUDOINVERSA de Moore-Penrose" << endl;
        cout << "Formula: A+ = (A^T * A)^(-1) * A^T" << endl;

        Matriz pseudoinversa;
        if (calcularPseudoinversa(matriz, pseudoinversa)) {
            cout << "\n--- Pseudoinversa de la Matriz ---" << endl;
            imprimirMatriz(pseudoinversa);

            cout << "\nDimensiones de la pseudoinversa: "
                << pseudoinversa.size() << "x" << pseudoinversa[0].size() << endl;
        }
        else {
            cout << "\n--- Resultado ---" << endl;
            cout << "ERROR: No se pudo calcular la pseudoinversa." << endl;
            cout << "Razon: La matriz (A^T * A) es singular (no invertible)" << endl;
            cout << "Esto ocurre cuando la matriz no tiene rango completo de columnas." << endl;
        }
    }

    cout << "\nPresione Enter para salir...";
    cin.ignore();
    cin.get();

    return 0;
}
