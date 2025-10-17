#include <iostream>
#include <string>
#include <cctype>
using namespace std; // esto evita que tengamos que escribir std:: //


//funcion para contar las vocales en la cadena de texto //

int contarVocales(const string& cadena) {
    int contador = 0;

    //for para recorrer cada caracter en la cadena//
    for (char c : cadena) {
        char letra = tolower(c); //convertimos el caracter en miniscula //

        //comprobamos si el caracter es una vocal//
        if (letra == 'a' || letra == 'e' || letra == 'i' ||
            letra == 'o' || letra == 'u') {
            contador++;
        }
    }

    return contador;
}

//empieza la ejecucuion del programa //
int main() {
    string cadena;

    cout << "Ejercicio 3: Contador de Vocales" << endl;
    cout << "Ingrese una cadena de texto: ";

    cin.ignore();
    getline(cin, cadena);

    int numeroVocales = contarVocales(cadena);

    cout << "\nResultados:" << endl;
    cout << "La cadena contiene " << numeroVocales << " vocal(es)" << endl;
    cout << "Longitud total: " << cadena.length() << " caracteres" << endl;

    cout << "\nPresione Enter para salir...";
    cin.get();

    return 0;
}