#include <iostream>
#include <string>
#include "TipoDatos.h"

using namespace std;


int main()
{
	

	//inicio
	tipoDatos* fichas = new tipoDatos[1000];
	tipoDatos metodos;
	int numeroFichas = 0;  // Número de fichas que ya tenemos
	int opcion;          // La opcion del menu que elija el usuario

	string textoTemporal; // Para pedir datos al usuario
	int numeroTemporal = 0;

	// variable tamaño que nos servira para validar el int
	// size porque es el 'tamanyo' del fichero
	int size = 0;
	// variable nombre que nos servira para validar el nombre
	char nombre[60];
	// variable nombre2 que permite buscar parcialmente
	char nombre2[60];
	// int para validar al momento de borrar un elemento
	int del = 0;

	do
	{
		// Menu principal
		cout << endl;
		cout << "Escoja una opción:" << endl;
		cout << "1.- Añadir datos de un nuevo fichero" << endl;
		cout << "2.- Mostrar los nombres de todos los ficheros" << endl;
		cout << "3.- Mostrar ficheros que sean de mas de un cierto tamaño" << endl;
		cout << "4.- Ver datos de un fichero" << endl;
		cout << "5.- (Busqueda Parcial)Ver datos de un fichero" << endl;
		cout << "6.- Eliminar y reorganizar areglo" << endl;
		cout << "7.- Modificar un elemento por indice" << endl;
		cout << "8.- Salir" << endl;
		cin >> opcion;
		// Hacemos una cosa u otra según la opción escogida
		switch (opcion)
		{
		case 1: // Añadir un dato nuevo
			if (numeroFichas < 1000)   // Si queda hueco
			{
				if (metodos.addData(fichas, numeroFichas, nombre, size) == 1) {
					numeroFichas++;  // Y tenemos una ficha más
				}
			}
			else   // Si no hay hueco para más fichas, avisamos
				cout << "Máximo de fichas alcanzado (1000)!" << endl;
			break;

		case 2: // Mostrar todos
			metodos.MostrarTodo(fichas, numeroFichas);
			break;

		case 3: // Mostrar según el tamaño
			metodos.MostrarTamano(fichas, numeroFichas, numeroTemporal);
			break;

		case 4: // Ver todos los datos (pocos) de un fichero
			metodos.MostrarDataFich(fichas, numeroFichas, textoTemporal);
			break;
		case 5: // Busqueda parcial
			metodos.BusquedaParcial(fichas, numeroFichas, nombre2);
			break;

		case 6:// Eliminar un elemento arreglo
			if (metodos.Eliminar(fichas, numeroFichas, del) == 1) {
				numeroFichas--;
			}
			break;

		case 7:
			metodos.Modificar(fichas,numeroFichas, nombre, del, size);
			break;
		case 8: // Salir: avisamos de que salimos
			cout << "Fin del programa" << endl;
			break;

		default: // Otra opcion: no válida
			cout << "Opción desconocida!" << endl;
			break;
		}
	} while (opcion != 8);  // Si la opcion es 8, terminamos

	return 0;
}