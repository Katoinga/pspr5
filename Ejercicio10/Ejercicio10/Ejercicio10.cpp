#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
struct jugador
{
	char nombre[60];
	int edad;
	int altura;
};
int main()
{
	struct jugador listaJugadores[20];
	int i, opcion, can = 20, no = 0;
	char n;
	// rellenando el arreglo con los datos
	for (int i = 0; i < can; i++) {
		cout << "Escriba el Nombre " << i + 1 << " :";
		cin.getline(listaJugadores[i].nombre, 60);
		cout << "\nEscriba la edad " << i + 1 << " :";
		cin >> listaJugadores[i].edad;
		cout << "\nEscriba la estatura(cm) " << i + 1 << " :";
		cin >> listaJugadores[i].altura;
		cin.ignore();
		cout << endl;
	}
	// while de menu mientras no sea 4
	do
	{
		cout << "\n\n1. Listar los nombres\n"
			<< "2. Listar las alturas\n" <<
			"3. Listar la edades\n"
			<< "4. Salir\n" << "\nSeleccione opcion:";
		cin >> opcion;
		switch (opcion)
		{
		case 1:
			for (i = 0; i < can; i++) {
				cout << "\nNombre " << i + 1 << " :\n";
				cout << listaJugadores[i].nombre;
			}
			break;
		case 2:
			for (i = 0; i < can; i++) {
				cout << "\nAlturas " << i + 1 << " :\n";
				cout << listaJugadores[i].altura<<" cm";
			}
			break;
		case 3:
			for (i = 0; i < can; i++) {
				cout << "\nEdades: " << i + 1 << ":\n";
				cout << listaJugadores[i].edad;
			}
			break;
		case 4:
			cout << "\nSaliendo...";
			break;
		default:
			cout << "\nNo se reconoce la operacion ";
		}
		// opcion 4 salir
	} while (opcion != 4);
	return 0;
}