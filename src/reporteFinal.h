#ifndef REPORTEFINAL_H
#define REPORTEFINAL_H

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

#include "empleado.h"
#include "pago.h"
#include "jerarquiaDeEmpleados.h"

using namespace std;

class ReporteFinal{

    private:
    Empleado* em;
    Pago* pa;
    JerarquiaDeEmpleados * jE = new JerarquiaDeEmpleados();

    string archivoPersonas;
    string archivoNomina;
    string archivoHoras;
    string archivoSalida;

    public:

    ReporteFinal();
    ReporteFinal(Empleado*, Pago*);
    ReporteFinal(string,string,string,string);
    void LeerNomina();
    void LeerHoras();
    void LeerEmpleados();
    string reportar();
    void guardar();
    string mostrarEmpleados();
    string resumenReporte();
    float SalarioBruto(int idEmpleado);
    float SalarioPorHoras(int idEmpleado);

};

#endif