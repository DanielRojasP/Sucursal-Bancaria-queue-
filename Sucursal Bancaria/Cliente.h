#ifndef CLIENTE_H
#define CLIENTE_H
#include <iostream>
#include <ctime>
#include <sstream>
#include <vector>
using namespace std;
class Cliente
{
public:
    Cliente();
    virtual ~Cliente();
    Cliente(string, string, string, string, int, char*);

    string getNumFicha();
    string getCed();
    string getNom();
    string getApellido();
    int getEdad();
    char getFecha();

    void setNumFicha(string);
    void setCed(string);
    void setNom(string);
    void setApellido(string);
    void setEdad(int);
    void setFecha(char*);


    string toString();
    void insertar(Cliente*);
    void mostrar();
    void ordenaClientes();

protected:

private:
    string numFicha;
    string ced;
    string nom;
    string apellido;
    int edad;
    char* fecha;
    Cliente* clientes[1000];
    int cant = 0;
    int tam = 1000;

};

#endif // CLIENTE_H
