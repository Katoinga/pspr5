#include <iostream>
using namespace std;
struct persona {
	char nombre[15];
	int dia, mes, anyo;
};
int main() {
	persona data[8];
	//llena el arreglo
	for (int i = 0; i < 8; i++) {
		cout << "Escriba el Nombre " << i + 1 << ":";
		cin >> data[i].nombre;
		cout << "\nEscriba el dia " << i + 1 << ":";
		cin >> data[i].dia;
		cout << "\nEscriba el mes " << i + 1 << ":";
		cin >> data[i].mes;
		cout << "\nEscriba el anyo" << i + 1 << ":";
		cin >> data[i].anyo;
		
		cout << endl;
	}
	//lo  imprime
	cout << "El registro de personas que se introdujeron es: \n\n";
	for (int i = 0; i < 8; i++) {
		cout << "Datos: " << data[i].nombre;
		cout << ", " << data[i].dia;
		cout << "/ " << data[i].mes;
		cout << "/ " << data[i].anyo;
		cout << endl;
	}
	int op = 0;
	cout << "Ingrese un numero de mes: \n";
	cin >> op;
	// mientras no sea 0
	while (op !=0) {
		int no = 0;
		for (int i = 0;i < 8;i++)
		{
			if (op == data[i].mes)
			{
				cout << "Este mes " << data[i].nombre << " cumple aos\n";
			}
			else {
				no++;
			}
			// si llega a 8 es porque ninguna persona cumple años ese mes
			if (no == 8) {
				cout << "Nadie cumple aos este mes";
			}
		}
		cout << "\nIngrese un numero de mes: \n";
		cin >> op;
	}
	return 0;
}