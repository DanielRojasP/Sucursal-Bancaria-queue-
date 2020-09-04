#include "Cliente.h"
#include <queue>

queue<Cliente*> aMayores; //cola para agregar a la fila del Banco Adultos  Mayores
queue<Cliente*> cRegulares; //cola para agregar a la fila del Banco Clientes Regulares
string numFichaM[10] = { "AM1","AM2", "AM3", "AM4", "AM5", "AM6", "AM7", "AM8", "AM9", "AM10" };
string numFichaR[10] = { "R1","R2","R3","R4","R5","R6","R7","R8","R9","R10" };
Cliente c;

int i = 0;
int j = 0;

void ingreso();
void llamar();
void cola(queue<Cliente*> , queue<Cliente*>);
void menu();


int main() {

	menu();
	return 0;

}


void ingreso() {
	
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

	cout << "\nSu numero de Ficha es: "<<numFicha<<endl;

	char* registro = new char();
	*registro = 's';

	//time_t tAct = time(NULL);
	//registro = asctime(localtime(&tAct));

	Cliente* c = new Cliente(numFicha,ced,nom,apellido,edad,registro);
	if (edad > 64) aMayores.push(c);
	else {
		cRegulares.push(c);
	}
	
}
void llamar() {

	
	if (!aMayores.empty()) {
		cout << aMayores.front()->toString();
		c.insertar(aMayores.front());
		aMayores.pop();
	}
	else if (aMayores.empty() && !cRegulares.empty())
	{
		cout << cRegulares.front()->toString();
		c.insertar(cRegulares.front());
		cRegulares.pop();
	}
	else  {
		cout << "No hay clientes en las colas\n";
	}
}
void cola(queue<Cliente*> M, queue<Cliente*> R) {

	int t1 = M.size();
	int t2 = R.size();
	if(t1 ==0 && t2 ==0) cout << "No hay clientes en las colas\n";

	for (int k = 0; k <t1; k++) {
		cout << M.front()->toString()<<endl;
		M.pop();
	}
	cout << "\n";
	for (int l = 0; l <t2; l++) {
		cout << R.front()->toString()<<endl;
		R.pop();
	}
	
}

void menu() {
	
	bool finalizar = false;
	char opc;

	do {
		cout << "1- Tomar Ficha\n";
		cout << "2- Llamar Cliente\n";
		cout << "3- Mostrar la Cola de Clientes\n";
		cout << "4- Salir\n";
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
				finalizar = true;
				break;
		}
		default:
				cout << "Digite una opcion valida\n";
				break;
		}
	} while (!finalizar);
}