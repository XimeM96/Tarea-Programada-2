#include "reporteFinal.h"
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;


int main(){

    string rutaPersonas = "personas.txt";
    string rutaNomina = "nomina.txt";
    string rutaHoras = "horastrabajadas.txt";
    string rutaSalida = "reporte.csv";


    ReporteFinal *rF = new ReporteFinal(rutaPersonas,rutaHoras,rutaNomina, rutaSalida);

    cout<<rF->reportar()<<endl;
    cout<<rF->resumenReporte()<<endl;
    rF->guardar();

    delete rF;

    return 0;
}