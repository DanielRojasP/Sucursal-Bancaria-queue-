#ifndef CLIENTE_H
#define CLIENTE_H
#include <iostream>
#include <sstream>

using namespace std;
class Cliente
{
public:
    Cliente();
    virtual ~Cliente();
    Cliente(string, string, string, string, int, string);

    string getNumFicha();
    string getCed();
    string getNom();
    string getApellido();
    int getEdad();
    string getFecha();

    void setNumFicha(string);
    void setCed(string);
    void setNom(string);
    void setApellido(string);
    void setEdad(int);
    void setFecha(string);


    string toString();


protected:

private:
    string numFicha;
    string ced;
    string nom;
    string apellido;
    int edad;
    string fecha;
};

#endif // CLIENTE_H

