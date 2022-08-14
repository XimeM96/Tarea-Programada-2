#ifndef JERARQUIADEEMPLEADOS_H
#define JERARQUIADEEMPLEADOS_H
#include "empleado.h"
#include <iostream>
#include <map>

using namespace std;

class JerarquiaDeEmpleados{
    
    private:
    Empleado *raiz;   
    map<int, Empleado *> elementos;
    vector <Empleado*> vecEmpleados;
    vector <Pago*> vecPagos;     

    public:

    JerarquiaDeEmpleados();
    ~JerarquiaDeEmpleados();

    void AgregarNodoEmpleado(Empleado*);
    // friend ostream& operator << (ostream &o, const JerarquiaDeEmpleados &JerarquiaDeEmpleados);
    // friend istream& operator >> (istream &i, JerarquiaDeEmpleados &JerarquiaDeEmpleados);    
    


};


#endif