#pragma once
#include <string>
#include <iostream>
using namespace std;

struct tipoDatos
{

	string nombreFich;        // Nombre del fichero
	long tamanyo;            // El tamaño en bytes
	tipoDatos();
	// 0  no ingreso correcto, 1 ingreso todo correcto
	int addData(tipoDatos* fichas, int numeroFichas, char aux[60], int size);
	void MostrarTodo(tipoDatos* fichas, int numeroFichas);
	void MostrarTamano(tipoDatos* fichas, int numeroFichas, int numeroTemporal);
	void MostrarDataFich(tipoDatos* fichas, int numeroFichas, string textoTemporal);
	void BusquedaParcial(tipoDatos* fichas, int numeroFichas, char nombre2[60]);
};
