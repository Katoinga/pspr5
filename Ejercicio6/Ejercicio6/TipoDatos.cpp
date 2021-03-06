#include <string>
#include <iostream>
#include "TipoDatos.h"

using namespace std;

tipoDatos::tipoDatos() {
	tamanyo = 0;
	nombreFich = "";
}
//a�ade un nuevo dato 1.
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

	cout << "Introduce el tama�o en KB: ";
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
		cout << "Nombre: " << fichas[i].nombreFich
			<< "; Tama�o: " << fichas[i].tamanyo
			<< "Kb" << endl;
	}
}
//Muestra los ficheros a partir de un tama�o especifico 3.
void tipoDatos::MostrarTamano(tipoDatos* fichas, int numeroFichas, int numeroTemporal) {
	// flag para ver si hay elementos o no
	int flag = 0;
	cout << "�A partir de que tama�o quieres que te muestre? ";
	cin >> numeroTemporal;
	for (int i = 0; i < numeroFichas; i++)
		if (fichas[i].tamanyo >= numeroTemporal) {
			cout << "Nombre: " << fichas[i].nombreFich
				<< "; Tama�o: " << fichas[i].tamanyo
				<< " Kb" << endl;
			flag = 1;
		}
	if (flag == 0)cout << "No hay existencias";
}
// busca un fichero y si coincide muestra la info del fichero 4.
void tipoDatos::MostrarDataFich(tipoDatos* fichas, int numeroFichas, string textoTemporal) {
	int flag = 0;
	cout << "�De qu� fichero quieres ver todos los datos?";
	cin >> textoTemporal;
	for (int i = 0; i < numeroFichas; i++)
		if (fichas[i].nombreFich == textoTemporal) {
			cout << "Nombre: " << fichas[i].nombreFich
				<< "; Tama�o: " << fichas[i].tamanyo
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
					<< "; Tama�o: " << fichas[i].tamanyo
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


