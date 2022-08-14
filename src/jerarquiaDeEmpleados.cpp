#include "jerarquiaDeEmpleados.h"
#include "empleado.h"
#include <string>
#include <sstream>

using namespace std;

JerarquiaDeEmpleados::JerarquiaDeEmpleados(){

    this->raiz = nullptr;

}

JerarquiaDeEmpleados::~JerarquiaDeEmpleados(){

    if (this->raiz != nullptr)

        delete this->raiz;

}

void JerarquiaDeEmpleados::AgregarNodoEmpleado(Empleado *empleado){
    raiz = empleado;
    this->vecEmpleados.push_back(raiz);
}