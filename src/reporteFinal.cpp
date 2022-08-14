#include "reporteFinal.h"
#include <iostream>

using namespace std;

ReporteFinal::ReporteFinal(){



}

ReporteFinal::ReporteFinal(Empleado* e, Pago* p){
    em = e;
    pa = p;
    jE->AgregarNodoEmpleado(em);
}

ReporteFinal::ReporteFinal(string archivoPersonas, string archivoHoras, string archivoNomina, string archivoSalida){
    this->archivoPersonas = archivoPersonas;
    this->archivoHoras = archivoHoras;
    this->archivoNomina = archivoNomina;
    this->archivoSalida = archivoSalida;
    this->LeerEmpleados();
    this->LeerHoras();
    this->LeerNomina();
}

float ReporteFinal::SalarioBruto(int idEmpleado){

    ifstream ifs("nomina.txt", ifstream::in);

    int id {};
    double pagoBruto {};
    string linea {}; 

    while (getline(ifs, linea)) {
        
        istringstream stream(linea);

        id = 0;
        pagoBruto = 0;

        stream >> id >> pagoBruto;

        if(id == idEmpleado){

            return pagoBruto;
        }
    }

    ifs.close();

    return 0;

}

float ReporteFinal::SalarioPorHoras(int idEmpleado){

    ifstream ifs("horastrabajadas.txt", ifstream::in);

        string linea {}; 
        int id {};
        double montoPorHora {};
        double horasLaboradas {};

        while (std::getline(ifs, linea)) {
            
            std::istringstream stream(linea);

            id = 0;
            montoPorHora = 0;
            horasLaboradas = 0;

            stream >> id >> montoPorHora >> horasLaboradas;

            if(id == idEmpleado){

                return montoPorHora * horasLaboradas;
            }
        }

    ifs.close();

    return 0;

}

string ReporteFinal::reportar(){
    stringstream s;
    string nombreSupervisor;
    float pagoNeto = 0;
    for(int i = 0; i <jE->vecEmpleados.size(); i++){

        for(int j = 0; j< jE->vecEmpleados.size(); j++){
            if(jE->vecEmpleados[j]->getIDEmpleado() == jE->vecEmpleados[i]->getIdSupervisor()){
                nombreSupervisor = jE->vecEmpleados[j]->getNombre() +" " +jE->vecEmpleados[j]->getApellido();
            }
        }
        for(int k = 0; k<jE->vecPagos.size(); k++){
            if(jE->vecPagos[k]->getID() == jE->vecEmpleados[i]->getIDEmpleado()){
                pagoNeto = jE->vecPagos[k]->getPagoNeto();
            }
        }

        s<<jE->vecEmpleados[i]->getIDEmpleado()<<","<<jE->vecEmpleados[i]->getNombre()<<" "
        <<jE->vecEmpleados[i]->getApellido()<<","<<nombreSupervisor<<","<<pagoNeto<<endl;
    }
    return s.str();
}

void ReporteFinal::LeerNomina(){
    ifstream lector;
    string id,pago;

    lector.open(archivoNomina);

    if(!lector){
        cout<<"error ";

    }
    else{
        cout<<"Si se abre" << endl;
    }

    while(!lector.eof()){

        getline(lector,id, ' ');
        getline(lector,pago, '\n');

        int i = stoi(id);
        float f = stof(pago);

        Pago *p = new Pago(i,f);
        jE->vecPagos.push_back(p);
        
    }
    lector.close();
}

void ReporteFinal::LeerHoras(){
    ifstream lector;
    string id,pagoHoras,cantHoras;

    lector.open(archivoHoras);

    if(!lector){
        cout<<"error ";

    }
    else{
        cout<<"Si se abre" << endl;
    }

    while(!lector.eof()){

        getline(lector,id, ' ');
        getline(lector,pagoHoras, ' ');
        getline(lector,cantHoras, '\n');

        int i = stoi(id);
        int c = stoi(cantHoras);
        float f = stof(pagoHoras);
        

        Pago* p = new Pago(i,c,f);
        jE->vecPagos.push_back(p);
        
    }
    lector.close();
}


void ReporteFinal::LeerEmpleados(){
    string rutaDePersonas = archivoPersonas;
    string id {};
    string nombre {};
    string apellido {};
    string email {};
    string tipoDeEmpleado {};
    string idSupervisor {};

    ifstream lector;

    lector.open(rutaDePersonas);

    if(!lector){
        cout<<"error ";

    }
    else{
        cout<<"Si se abre" << endl;
    }

    while(!lector.eof()){

        getline(lector,id, ' ');
        getline(lector,nombre, ' ');
        getline(lector,apellido, ' ');
        getline(lector,email, ' ');
        getline(lector,tipoDeEmpleado, ' ');
        getline(lector,idSupervisor, '\n');

        int i = stoi(id);
        int t = stoi(tipoDeEmpleado);
        int is = stoi(idSupervisor);

        Empleado *empleadoNuevo = new Empleado(i,nombre,apellido,email,t,is);
        jE->vecEmpleados.push_back(empleadoNuevo);
    }

    lector.close();
}

void ReporteFinal::guardar(){
    ofstream salida;
    salida.open(archivoSalida);

    salida<<this->reportar()<<endl;
    salida<<this->resumenReporte();
    salida.close();
}

string ReporteFinal::mostrarEmpleados(){
    stringstream s;
    for(int i = 0; i < jE->vecEmpleados.size(); i++){
        s<<jE->vecEmpleados[i]->toString();
    }
    return s.str();
}

string ReporteFinal::resumenReporte(){
    stringstream s;
    float subtotal = 0;
    float totalImpuestos = 0 ;
    float total = 0;
    for(int i = 0;i < jE->vecPagos.size(); i++){
        subtotal = subtotal + jE->vecPagos[i]->getSalarioBruto();
        totalImpuestos = totalImpuestos + jE->vecPagos[i]->getCantImpuestos();
        total = subtotal + totalImpuestos;
    }

    s<<fixed<<"Resumen de reporte:\n"<<"\nSubtotal: "<<subtotal << "\nTotal de impuestos a retener: " << totalImpuestos
    << "\nTotal: "<<total<<endl;

    return s.str();
}



