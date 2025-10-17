#include <iostream> 
using namespace std; //para usar nombres cortos como 'cout' en lugar de 'std::cout'//

int main() {
	double num1, num2; // declaramos dos variables para guardar los numeros, usando 'double' para decimales//

	cout << "Ejericio 1: Operaciones Basicas" << endl;
	cout << "Ingrese el primer numero:";
	cin >> num1; //pedimos y leemos el primer numero//

	cout << "Ingrese el segundo numero:";
	cin >> num2; //pedimos y leemos el segundo numero//

	cout << "\nResultados:" << endl;

	//realizamos y mostramos la suma//
	cout << "Suma:" << num1 << "+" << num2 << "=" << (num1 + num2) << endl;
	//realizamos y mostramos la resta//
	cout << "Resta:" << num1 << "-" << num2 << "=" << (num1 - num2) << endl;
	//realizamos y mostramos la multiplicacion//
	cout << "Multiplicacion:" << num1 << "*" << num2 << "=" << (num1 * num2) << endl;

	//verificamos si el segundo numero es cero para evitar división por cero//
	if (num2 == 0) {
		cout << "Division: Error no se puede dividir por cero." << endl;
	}
	else {
		//si no es cero, realizamos y mostramos la division//
		cout << "Division:" << num1 << "/" << num2 << "=" << (num1 / num2) << endl;
	}

	cout << "\nPresione Enter para salir..." << endl;
	cin.ignore();
	cin.get();
	return 0;
}