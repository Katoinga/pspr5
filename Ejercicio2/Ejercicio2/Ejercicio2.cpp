#include <iostream>
using namespace std;
struct persona {
	char nombre[15];
	char apellido[15];
	int edad;
};
int main() {
	persona amigo;
	cout << "Escriba el Nombre: " ;
	cin >> amigo.nombre;
	cout << "\nEscriba el Apellido: " ;
	cin >> amigo.apellido;
	cout << "\nEscriba la Edad de la persona: ";
	cin >> amigo.edad;

	cout << endl;
	cout << "Persona que se introdujo: \n\n";
	cout <<amigo.nombre << ", " << amigo.apellido << ", " << amigo.edad;
	cout << endl;
	return 0;
}