#ifndef GESTIONSUCURSAL_H
#define GESTIONSUCURSAL_H
#include "Cliente.h"
#include <queue>
#include <vector>
#include <time.h>
#include <ctime>

class GestionSucursal
{
public:
	GestionSucursal();

	void insertar(Cliente);
	void ordenaClientes();
	//void mostrar();


	void ingreso();
	void llamar();
	void cola(queue<Cliente>, queue<Cliente>);
	void menu();

private:
	int i = 0;
	int j = 0;

	queue<Cliente> aMayores; //cola para agregar a la fila del Banco Adultos  Mayores
	queue<Cliente> cRegulares; //cola para agregar a la fila del Banco Clientes Regulares
	string numFichaM[10] = { "AM1","AM2", "AM3", "AM4", "AM5", "AM6", "AM7", "AM8", "AM9", "AM10" };
	string numFichaR[10] = { "R1","R2","R3","R4","R5","R6","R7","R8","R9","R10" };
	vector<Cliente> clientes;
	Cliente c;
};

#endif
