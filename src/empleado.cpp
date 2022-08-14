#include "empleado.h"

Empleado::Empleado(int idEmpleado, string nombre,string apellido, string email, int tipoEmpleado, int idSupervisor){
    this->idEmpleado = idEmpleado;
    this->nombre = nombre;
    this->apellido = apellido;
    this->email = email;
    this->tipoEmpleado = tipoEmpleado;
    this->idSupervisor = idSupervisor;
}

Empleado::Empleado(int id, string nombre, int idSupervisor, string nombreSupervisor, float salarioBruto, float salarioNeto)
{
    this->idEmpleado = id;
    this->nombre = nombre;
    this->idSupervisor = idSupervisor;
    this->nombreSupervisor = nombreSupervisor;
    this->salarioBruto = salarioBruto;
    this->salarioNeto = salarioNeto;
}

Empleado::~Empleado(){

        for (Empleado* dependiente : this->dependientes)
    {
        delete dependiente;
    }


}

void Empleado::AgregarDependientes(Empleado *dependiente){

    this->dependientes.push_back(dependiente);

}

string Empleado::toString(){
    stringstream s; 
    s<<this->nombre<<" "<<this->apellido<<endl;
    return s.str();
}


int Empleado::getIDEmpleado(){
    return this->idEmpleado;
}
string Empleado::getNombre(){
    return this->nombre;
}
string Empleado::getApellido(){
    return this->apellido;
}
string Empleado::getEmail(){
    return this->email;
}
int Empleado::getTipoEmpleado(){
    return this->tipoEmpleado;
}
int Empleado::getIdSupervisor(){
    return this->idSupervisor;
}
float Empleado::getSalarioBruto(){
    return this->salarioBruto;
}
float Empleado::getSalarioNeto(){
    return this->salarioNeto;
}

ostream& operator << (std::ostream &o, const Empleado &nodo)
{
    o << nodo.idEmpleado;
    o << ",";
    o << nodo.nombre;
    o << ",";
    o << nodo.nombreSupervisor;
    o << ",";
    o << nodo.salarioNeto;
    o << endl;

    for (Empleado *empleadoDependiente : nodo.dependientes)
    {
        o << *empleadoDependiente;
    }

    return o;
}