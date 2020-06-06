#include <string>
#include <iostream>
#include "Tipo.h"

using namespace std;

tipoDatos::tipoDatos() {
	tamanyo = 0;
}
//añade un nuevo dato
void tipoDatos::addData(tipoDatos* fichas, int numeroFichas) {
	cout << "Introduce el nombre del fichero: ";
	cin >> fichas[numeroFichas].nombreFich;
	cout << "Introduce el tamaño en KB: ";
	cin >> fichas[numeroFichas].tamanyo;
	
}
//recorre el arreglo y muestra todos los datos.
void tipoDatos::MostrarTodo(tipoDatos* fichas, int numeroFichas) {
	for (int i = 0; i < numeroFichas; i++) {
		cout << "Nombre: " << fichas[i].nombreFich
			<< "; Tamaño: " << fichas[i].tamanyo
			<< "Kb" << endl;
	}
}
//Muestra los ficheros a partir de un tamaño especifico
void tipoDatos::MostrarTamano(tipoDatos* fichas, int numeroFichas, int numeroTemporal){
	cout << "¿A partir de que tamaño quieres que te muestre? ";
	cin >> numeroTemporal;
	for (int i = 0; i < numeroFichas; i++)
		if (fichas[i].tamanyo >= numeroTemporal)
			cout << "Nombre: " << fichas[i].nombreFich
			<< "; Tamaño: " << fichas[i].tamanyo
			<< " Kb" << endl;
}
// busca un fichero y si coincide muestra la info del fichero
void tipoDatos::MostrarDataFich(tipoDatos* fichas, int numeroFichas, string textoTemporal) {
	cout << "¿De qué fichero quieres ver todos los datos?";
	cin >> textoTemporal;
	for (int i = 0; i < numeroFichas; i++)
		if (fichas[i].nombreFich == textoTemporal)
			cout << "Nombre: " << fichas[i].nombreFich
			<< "; Tamaño: " << fichas[i].tamanyo
			<< " Kb" << endl;
}

