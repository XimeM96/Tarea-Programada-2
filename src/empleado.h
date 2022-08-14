#ifndef EMPLEADO_H
#define EMPLEADO_H
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include "pago.h"

using namespace std;

class Empleado{

    private:

    int idEmpleado {};
    string nombre {};
    string apellido {};
    string email {};
    int tipoEmpleado {};
    int idSupervisor {};
    string nombreSupervisor{};
    float salarioBruto {};
    float salarioNeto {};

    vector <Empleado*> dependientes;

    public:

    Empleado();
    Empleado(int,string,int,string,float,float);
    Empleado(int,string,string, string, int, int);
    ~Empleado();

    void AgregarDependientes(Empleado *dependiente);
    string toString();
    int getIDEmpleado();
    string getNombre();
    string getApellido();
    string getEmail();
    int getTipoEmpleado();
    int getIdSupervisor();
    float getSalarioBruto();
    float getSalarioNeto();
    friend ostream& operator << (std::ostream &o, const Empleado &Empleado);



};

#endif