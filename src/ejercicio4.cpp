#include <iostream> 
#include <vector>   
#include <cmath> 
using namespace std; // esto evita que tengamos que escribir std:: //

// definimos una estructura para agrupar los dos resultados de las normas
struct Normas {
	double normaL2;          // aqui se guardara el resultado de la norma l2 (euclidiana)//
	double normaLInfinito;   // Aquí se guardará el resultado de la norma l-infinito//
};

// funcion principal para calcular las normas//
Normas calcularNormas(const vector<double>& arreglo) {
	Normas resultado;

	// validacion de seguridad: si el vector esta vacio, devolvemos 0 en ambas normas//
	if (arreglo.empty()) {
		resultado.normaL2 = 0;
		resultado.normaLInfinito = 0;
		return resultado;
	}

	//la l2 es la raiz cuadrada de la suma de los cuadrados de todos los elementos//
	double sumaL2 = 0.0;

	for (double valor : arreglo) {
		sumaL2 += valor * valor;
	}
	resultado.normaL2 = sqrt(sumaL2); // calculamos la raiz cuadrada de la suma final//

	resultado.normaLInfinito = abs(arreglo[0]);

	//recorremos el vector para encontrar el máximo valor absoluto//
	for (double valor : arreglo) {
		double valorAbsoluto = abs(valor); 
		if (valorAbsoluto > resultado.normaLInfinito) {
			resultado.normaLInfinito = valorAbsoluto; 
		}
	}

	return resultado; 
}


int main() {
	int n; //variable para almacenar el tamaño del vector//

	cout << "Ejercicio 4: Normas L2 y L-infinito ===" << endl;
	cout << "Ingrese el tamano del arreglo: ";
	cin >> n; 

	//verificacion de errores: si el tamano es cero o negativo, mostramos error y salimos//
	if (n <= 0) {
		cout << "ERROR: El tamano debe ser mayor a 0" << endl;
		return 1; 
	}

	//creamos el vector 'arreglo' con el tamaño 'n' que el usuario ingreso//
	vector<double> arreglo(n);

	cout << "\nIngrese los " << n << " elementos:" << endl;

	//bucle para pedir al usuario que ingrese cada uno de los 'n' elementos//

	for (int i = 0; i < n; i++) {
		cout << "Elemento [" << i << "]: ";
		cin >> arreglo[i]; 
	}

	//llamamos a la funcion que hace todo el trabajo y guardamos los resultados //
	Normas resultado = calcularNormas(arreglo);

	cout << "\nResultados:" << endl;
	//mostramos la norma l2 (euclidiana) //
	cout << "Norma L2 (euclidiana): " << resultado.normaL2 << endl;
	//mostramos la norma l-infinito//
	cout << "Norma L-infinito: " << resultado.normaLInfinito << endl;

	cout << "\nPresione Enter para salir...";
	cin.ignore();
	cin.get();

	return 0; 
}