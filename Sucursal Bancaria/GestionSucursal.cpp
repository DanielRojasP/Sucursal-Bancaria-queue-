#include "GestionSucursal.h"

GestionSucursal::GestionSucursal()
{
}

void GestionSucursal::insertar(Cliente cl) {
	clientes.push_back(cl);
}
void GestionSucursal::ordenaClientes() {


	Cliente aux;
	int mini; //variable para almacenar el valor minimo

	for (unsigned int i = 0; i < clientes.size() - 1; i++) { //ciclo que recorre todo el vector de NOTAS
		mini = i; // suponemos que el primer numero del vector es el minimo

		for (unsigned int j = i + 1; j < clientes.size(); j++) { // (j = i+1) como como estamos diciendo que la primera pos
								//es la menor entonces que lo recorra desde la segunda pos.
			if (clientes[j].getEdad() < clientes[mini].getEdad()) {
				mini = j;
				//clientes[min] = clientes[j]; //resuelve cual es el menor elemento del arreglo
			}
		}
		aux = clientes[mini];
		clientes[mini] = clientes[i];
		clientes[i] = aux;
	}
	for (unsigned int k = 0; k < clientes.size(); k++) {
		cout << clientes[k].toString() << endl;
	}
}
void GestionSucursal::ingreso() {

	if (i == 10) i = 0;
	if (j == 10) j = 0;

	string numFicha;
	string ced;
	cout << "Numero de Cedula:\n";
	cin >> ced;
	string nom;
	cout << "Nombre:\n";
	cin >> nom;
	string apellido;
	cout << "Apellido\n";
	cin >> apellido;
	int edad;
	cout << "Edad\n";
	cin >> edad;

	if (edad >= 65) {
		numFicha = numFichaM[i];
		i++;
	}
	else
	{
		numFicha = numFichaR[j];
		j++;
	}

	cout << "\nSu numero de Ficha es: " << numFicha << endl;

	//toma la fecha del sistema
	string fecha = "";
	stringstream b;
	time_t tSac = time(NULL);
	//localtime(&tSac);
	struct tm* tmp = localtime(&tSac);
	b << tmp->tm_mday << "/" << tmp->tm_mon + 1 << "/" << tmp->tm_year + 1900 << "\t"
		<< tmp->tm_hour << "h:" << tmp->tm_min << "m:" << tmp->tm_sec << "s" << endl;
	fecha = b.str();



	Cliente cl(numFicha, ced, nom, apellido, edad, fecha);
	if (edad > 64) {
		aMayores.push(cl);
		insertar(cl);
	}
	else {
		cRegulares.push(cl);
		insertar(cl);
	}

}
void GestionSucursal::llamar() {


	if (!aMayores.empty()) {
		cout << aMayores.front().toString();
		//c.insertar(aMayores.front());
		aMayores.pop();
	}
	else if (aMayores.empty() && !cRegulares.empty())
	{
		cout << cRegulares.front().toString();
		//	c.insertar(cRegulares.front());
		cRegulares.pop();
	}
	else {
		cout << "No hay clientes en las colas\n";
	}
}
void GestionSucursal::cola(queue<Cliente> M, queue<Cliente> R) {

	int t1 = M.size();
	int t2 = R.size();
	if (t1 == 0 && t2 == 0) cout << "No hay clientes en las colas\n";

	for (int k = 0; k < t1; k++) {
		cout << M.front().toString() << endl;
		M.pop();
	}
	cout << "\n";
	for (int l = 0; l < t2; l++) {
		cout << R.front().toString() << endl;
		R.pop();
	}

}

void GestionSucursal::menu() {

	bool finalizar = false;
	char opc;

	do {
		cout << "1- Tomar Ficha\n";
		cout << "2- Llamar Cliente\n";
		cout << "3- Mostrar la Cola de Clientes\n";
		cout << "4- Salir y Mostrar la Informacion Ordenada\n";
		cin >> opc;

		switch (opc)
		{
		case '1': {
			system("cls");
			ingreso();
			system("pause");
			system("cls");

			break;
		}
		case '2': {
			system("cls");
			llamar();
			system("pause");
			system("cls");

			break;
		}
		case '3': {
			system("cls");
			cola(aMayores, cRegulares);
			system("pause");
			system("cls");

			break;
		}
		case '4': {
			system("cls");
			ordenaClientes();
			system("pause");
			finalizar = true;
			break;
		}
		default:
			cout << "Digite una opcion valida\n";
			system("pause");
			system("cls");
			break;
		}
	} while (!finalizar);
}
