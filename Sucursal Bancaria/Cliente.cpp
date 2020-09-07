#include "Cliente.h"

Cliente::Cliente()
{
    numFicha = "";
    ced = "";
    nom = "";
    apellido = "";
    edad = 0;
    fecha = "";
}

Cliente::~Cliente()
{

}

Cliente::Cliente(string num, string ced, string nom, string apellido, int edad, string fecha)
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
void Cliente::setFecha(string fecha) {
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
string Cliente::getFecha() {
    return fecha;
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



