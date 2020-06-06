#include <string>
#include <iostream>
#include "TipoDatos.h"

using namespace std;
void Bubble_Sort(tipoDatos* arr, int size);
tipoDatos::tipoDatos() {
	tamanyo = 0;
	nombreFich = "";
}
//añade un nuevo dato 1.
int tipoDatos::addData(tipoDatos* fichas, int numeroFichas, char aux[60], int size) {
	cout << "Introduce el nombre del fichero: ";
	cin.getline(aux, 60);
	cin.getline(aux, 60);
	// si no ingresa nada o ingresa espacio o tab
	if (aux[0] != '\0' && aux[0] != ' '
		&& aux[0] != '\t') {
		fichas[numeroFichas].nombreFich = aux;
	}
	else {
		cout << "Error! Introduzca un nombre valido";
		return 0;
	}

	cout << "Introduce el tamaño en KB: ";
	cin >> size;
	// aqui incluyo como permitible a 0 ya que en la
	// incognita solo nos nice numero negativos
	if (size >= 0) {
		fichas[numeroFichas].tamanyo = size;
	}
	else {
		cout << "Error! Introduzca un tamanyo valido";
		return 0;
	}
	cin.ignore();
	return 1;

}
//recorre el arreglo y muestra todos los datos. 2.
void tipoDatos::MostrarTodo(tipoDatos* fichas, int numeroFichas) {
	for (int i = 0; i < numeroFichas; i++) {
		cout << "Indice:" << i << ", Nombre: " << fichas[i].nombreFich
			<< "; Tamaño: " << fichas[i].tamanyo
			<< "Kb" << endl;
	}
	if (numeroFichas == 0) cout << "No hay";
}
//Muestra los ficheros a partir de un tamaño especifico 3.
void tipoDatos::MostrarTamano(tipoDatos* fichas, int numeroFichas, int numeroTemporal) {
	// flag para ver si hay elementos o no
	int flag = 0;
	cout << "¿A partir de que tamaño quieres que te muestre? ";
	cin >> numeroTemporal;
	for (int i = 0; i < numeroFichas; i++)
		if (fichas[i].tamanyo >= numeroTemporal) {
			cout << "Nombre: " << fichas[i].nombreFich
				<< "; Tamaño: " << fichas[i].tamanyo
				<< " Kb" << endl;
			flag = 1;
		}
	if (flag == 0)cout << "No hay existencias";
}
// busca un fichero y si coincide muestra la info del fichero 4.
void tipoDatos::MostrarDataFich(tipoDatos* fichas, int numeroFichas, string textoTemporal) {
	int flag = 0;
	cout << "¿De qué fichero quieres ver todos los datos?";
	cin >> textoTemporal;
	for (int i = 0; i < numeroFichas; i++)
		if (fichas[i].nombreFich == textoTemporal) {
			cout << "Nombre: " << fichas[i].nombreFich
				<< "; Tamaño: " << fichas[i].tamanyo
				<< " Kb" << endl;
			flag = 1;
		}
	if (flag == 0)cout << "No hay existencias";
}
// busqueda parcial 5.
void tipoDatos::BusquedaParcial(tipoDatos* fichas, int numeroFichas, char nombre2[60])
{
	int flag = 0;
	cout << "Introduce el nombre parcial del fichero: ";
	cin.getline(nombre2, 60);
	cin.getline(nombre2, 60);
	// si no ingresa nada o ingresa espacio o tab
	if (nombre2[0] != '\0' && nombre2[0] != ' '
		&& nombre2[0] != '\t') {
		for (int i = 0; i < numeroFichas; i++)
			// busca en fichas[i] la cadena nombre2
			// si la encuentra imprime los datos de la ficha[i]
			if (fichas[i].nombreFich.find(nombre2) != std::string::npos) {
				cout << "Ocurrencia\n";
				cout << "Nombre: " << fichas[i].nombreFich
					<< "; Tamaño: " << fichas[i].tamanyo
					<< " Kb" << endl;
				flag = 1;
			}
	}
	else {
		cout << "Error! Introduzca un nombre parcial valido";
		return;
	}
	if (flag == 0)cout << "No hay";
}

int tipoDatos::Eliminar(tipoDatos* fichas, int numeroFichas, int del)
{
	cout << "Ingrese el indice del elemento a eliminar";
	cout << "\nSi no sabe un indice en la opcion 2 se puede ver:\n";
	cin >> del;
	if (del >= 0 && del < numeroFichas) {
		for (int i = del;i < numeroFichas;i++) {
			fichas[i] = fichas[i + 1];
		}
		return 1;
	}
	// no es necesario borrarlo porque el siguiente elemento 
	// entrara en el ultimo indice y los datos se reemplazaran 
	// y utilizamos el tamano como numeroFichas
	else {
		cout << "Error! Introduzca un entero valido";
		return 0;
	}
}
void tipoDatos::Modificar(tipoDatos* fichas, int numeroFichas, char nombre[60], int del, long sizekb) {
	cout << "Ingrese el indice del elemento a modificar";
	cout << "\nSi no sabe un indice en la opcion 2 se puede ver:\n";
	cin >> del;
	if (del >= 0 && del < numeroFichas) {
		cout << "\n\nPresione enter si no desea modificar";
		cout << "\nPresione otra tecla para empezar a modificar\n";
		cin.getline(nombre, 60);
		cin.getline(nombre, 60);
		// si ingresa otra tecla modifica
		if (nombre[0] != '\0' && nombre[0] != ' '
			&& nombre[0] != '\t') {
			cout << "Introduce el nuevo nombre del fichero: ";
			cin.getline(nombre, 60);
			// si no ingresa nada o ingresa espacio o tab
			if (nombre[0] != '\0' && nombre[0] != ' '
				&& nombre[0] != '\t') {
				fichas[del].nombreFich = nombre;
			}
			else {
				cout << "Error! Introduzca un nombre valido";
				return;
			}

			cout << "Introduce nuevo el tamaño en KB: ";
			cin >> sizekb;
			// aqui incluyo como permitible a 0 ya que en la
			// incognita solo nos nice numero negativos
			if (sizekb >= 0) {
				fichas[del].tamanyo = sizekb;
			}
			else {
				cout << "Error! Introduzca un tamanyo valido";
				return;
			}
			cin.ignore();
		}
		// presiona enter cancela modificacion
		else {
			cout << "\nCancelando modificacion";
			return;
		}
	}
	else {
		cout << "Error! Introduzca un entero valido";
		return;
	}
}
void tipoDatos::Organizar(tipoDatos* fichas, int numeroFichas) {
	cout << "\nOrganizando arreglo....\n";
	Bubble_Sort(fichas, numeroFichas);
	cout << "Organizacion finalizada seleccione la opcion 2 para ver\n";
}

void Bubble_Sort(tipoDatos* arr, int size)
{
	tipoDatos temp;
	int iteration;
	int index;
	for (iteration = 0; iteration < size - 1; iteration++)
	{
		for (index = 0; index < size - iteration - 1; index++)
		{
			if (arr[index].nombreFich.compare(arr[index + 1].nombreFich) > 0) {
				temp = arr[index];
				arr[index] = arr[index + 1];
				arr[index + 1] = temp;
			}
		}
	}
}

