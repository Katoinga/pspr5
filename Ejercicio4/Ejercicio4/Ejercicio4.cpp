#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
struct persona
{
	string nombre;
	char direccion[40];
	char telefono[9];
	int edad;
};
int main()
{
	persona listaPersona[50];
	int edadBuscar, i, opcion, can = 50,no=0;
	int cantidad = 0;
	char n;
	char nombreS[20];
	// rellenando el arreglo con los datos
	for (int i = 0; i < can; i++) {
		cout << "Escriba el Nombre: " << i + 1 << ":";
		cin.getline(nombreS, 20);
		if (nombreS[0] != '\0' && nombreS[0] != ' '
			&& nombreS[0] != '\t') {
			listaPersona[i].nombre = nombreS;
		}
		else {
			break;

		}
		cout << "\nEscriba la direccion: " << i + 1 << ":";
		cin.getline(listaPersona[i].direccion, 40);
		cout << "\nEscriba el telefono: " << i + 1 << ":";
		cin >> listaPersona[i].telefono;
		cout << "\nEscriba la edad: " << i + 1 << ":";
		cin >> listaPersona[i].edad;
		cantidad++;
		cin.ignore();
		cout << endl;
	}
	// while de menu mientras no sea 4
	do
	{
		cout << "\n\n1. Mostrar todos los nombre\n"
			<<"2. Buscar personas por edad\n"<<
			"3. Buscar personas cuya inicial se indique\n"
			<< "4. Salir\n"<< "\nSeleccione opcion:";
		cin >> opcion;
		switch (opcion)
		{
		case 1:
			for (i = 0; i < cantidad; i++) {
				cout << "\nNombre: " << i + 1 << ":\n";
				cout << listaPersona[i].nombre;
			}
			break;
		case 2:
			cout << "\nIngrese edad a buscar: ";
			cin >> edadBuscar;
			no = 0;
			for (i = 0; i < can; i++)
			{
				if (listaPersona[i].edad == edadBuscar) {
					cout << "\nPersona:" << listaPersona[i].nombre;
				}
				else {
					no++;
				}
				if (no == can) {
					cout << "\nNo hay personas con esa edad";
				}
			}
			break;
		case 3:
			no = 0;
			cout << "\nIngrese la inicial del nombre a buscar: ";
			cin >> n;
			for (i = 0; i < can; i++)
			{
				if (listaPersona[i].nombre[0] == n)
					cout << "\nPersona:" << listaPersona[i].nombre;
				else {
					no++;
				}
				if (no == can) {
					cout << "\nNo hay personas con esa inicial";
				}
			}
			break;
		case 4:
			cout << "\nSaliendo...";
			break;
		default :
			cout << "\nNo se reconoce la operacion ";
		}
		// opcion 4 salir
	} while (opcion != 4);
	return 0;	
}