#pragma once
#include <string>
#include <iostream>
using namespace std;

struct tipoDatos
{

	string nombreFich;        // Nombre del fichero
	long tamanyo;            // El tamaño en bytes
	tipoDatos();
	void addData(tipoDatos* fichas, int numeroFichas);
	void MostrarTodo(tipoDatos* fichas, int numeroFichas);
	void MostrarTamano(tipoDatos* fichas, int numeroFichas, int numeroTemporal);
	void MostrarDataFich(tipoDatos* fichas, int numeroFichas, string textoTemporal);

};
