#ifndef PAGO_H
#define PAGO_H
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

class Pago{
    private:

    int id;
    float salarioBruto {};
    float salarioPorHoras {};
    int cantidadDeHorasTrabajadas {};
    bool esNomina;//bool = verdadero si el pago es de nomina, false si el pago es por horas
    float pagoTotalPorHoras {};
    float pagoNominaNeto {};
    float pagoNeto {};
    float cantImpuestos {};

    public:

    int getID();
    float getSalarioBruto();
    float getSalarioPorHoras();
    int getCantHoras();
    bool getEsNomina();
    float getPagoTotalPorHoras();
    float getPagoNominaNeto();
    float getPagoNeto();
    float getCantImpuestos();
    Pago(int,float); 
    Pago(int, int, float); 
};

#endif