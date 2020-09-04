#include "Cliente.h"

Cliente::Cliente()
{
    numFicha = "";
    ced = "";
    nom = "";
    apellido = "";
    edad = 0;
    fecha = new char();

}

Cliente::~Cliente()
{
    //dtor
}

Cliente::Cliente(string num, string ced, string nom, string apellido, int edad, char* fecha)
{
    this->numFicha = num;
    this->ced = ced;
    this->nom = nom;
    this->apellido = apellido;
    this->edad = edad;
    this->fecha = fecha;
}
void Cliente::setNumFicha(string num) {
    this->numFicha = num;
}
void Cliente::setNom(string nom) {
    this->nom = nom;
}
void Cliente::setApellido(string apellido) {
    this->apellido = apellido;
}
void Cliente::setCed(string ced) {
    this->ced = ced;
}
void Cliente::setEdad(int edad) {
    this->edad = edad;
}
void Cliente::setFecha(char* fecha) {
    this->fecha = fecha;
}

string Cliente::getNumFicha() {
    return numFicha;
}
string Cliente::getNom() {
    return nom;
}
string Cliente::getApellido() {
    return apellido;
}
string Cliente::getCed() {
    return ced;
}
int Cliente::getEdad() {
    return edad;
}
char Cliente::getFecha() {
    return *fecha;
}


string Cliente::toString() {
    stringstream s;
    s << "Numero de Ficha: " << getNumFicha() << endl;
    s << "Cedula: " << getCed() << endl;
    s << "Nombre: " << getNom() << endl;
    s << "Apellido: " << getApellido() << endl;
    s << "Edad: " << getEdad() << endl;
    s << "Fecha: " << getFecha() << endl;
    return s.str();
}
void Cliente::insertar(Cliente* c) {
    if (cant < tam) {
        clientes[cant] = c;
        cant++;
    }
}
void Cliente::mostrar() {
    ordenaClientes();
    for (int i = 0; i < tam; i++) {
        cout << clientes[i]->toString();
    }
}
void Cliente::ordenaClientes() {
    int aux = 0;
    int min; //variable para almacenar el valor minimo

    for (int i = 0; i < cant - 1; i++) { //ciclo que recorre todo el vector de NOTAS
        min = i; // suponemos que el primer numero del vector es el minimo

        for (int j = i + 1; j < cant; j++) { // (j = i+1) como como estamos diciendo que la primera pos
                                //es la menor entonces que lo recorra desde la segunda pos.
            if (clientes[j]->getEdad() < clientes[min]->getEdad()) {
                min = j;
                //clientes[min] = clientes[j]; //resuelve cual es el menor elemento del arreglo
            }
        }
        clientes[aux] = clientes[min];
        clientes[min] = clientes[i];
        clientes[i] = clientes[aux];
    }
}
