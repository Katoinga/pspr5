#include <iostream>
#include <string>
#include "Tipo.h"

using namespace std;

int main()
{
	int numeroFichas = 0;  // N�mero de fichas que ya tenemos
	int opcion=0;          // La opcion del menu que elija el usuario
	string textoTemporal=""; // Para pedir datos al usuario
	int numeroTemporal=0;
	//se crea el arreglo de fichas y el objeto tipo datos para metodos
	tipoDatos* fichas = new tipoDatos[1000];
	tipoDatos metodos;
	
	do
	{
		// Menu principal
		cout << endl;
		cout << "Escoja una opci�n:" << endl;
		cout << "1.- A�adir datos de un nuevo fichero" << endl;
		cout << "2.- Mostrar los nombres de todos los ficheros" << endl;
		cout << "3.- Mostrar ficheros que sean de mas de un cierto tama�o" << endl;
		cout << "4.- Ver datos de un fichero" << endl;
		cout << "5.- Salir" << endl;

		cin >> opcion;

		// Hacemos una cosa u otra seg�n la opci�n escogida
		switch (opcion)
		{
		case 1: // A�adir un dato nuevo
			if (numeroFichas < 1000)   // Si queda hueco
			{
				metodos.addData( fichas, numeroFichas);
				numeroFichas++;  // Y tenemos una ficha m�s
			}
			else   // Si no hay hueco para m�s fichas, avisamos
				cout << "M�ximo de fichas alcanzado (1000)!" << endl;
			break;

		case 2: // Mostrar todos
			metodos.MostrarTodo(fichas, numeroFichas);
			
			break;

		case 3: // Mostrar seg�n el tama�o
			metodos.MostrarTamano(fichas, numeroFichas, numeroTemporal);
			break;

		case 4: // Ver todos los datos (pocos) de un fichero
			metodos.MostrarDataFich(fichas, numeroFichas, textoTemporal);
			break;

		case 5: // Salir: avisamos de que salimos
			cout << "Fin del programa" << endl;
			break;

		default: // Otra opcion: no v�lida
			cout << "Opci�n desconocida!" << endl;
			break;
		}
	} while (opcion != 5);  // Si la opcion es 5, terminamos

	return 0;
}