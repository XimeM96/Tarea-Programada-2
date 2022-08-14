#include "pago.h"

Pago::Pago(int id, float salarioBruto){
    this->id = id;
    this->salarioBruto = salarioBruto;
    this->esNomina = true;
    this->cantImpuestos = salarioBruto * 0.07;
    this->pagoNominaNeto = salarioBruto - (salarioBruto * 0.07);
    this->pagoNeto = pagoNominaNeto;
}

Pago::Pago(int id, int cantidadDeHorasTrabajadas, float salarioPorHoras){
    this->id = id;
    this->cantidadDeHorasTrabajadas = cantidadDeHorasTrabajadas;
    this->salarioPorHoras = salarioPorHoras;
    this->esNomina = false;
    this->pagoTotalPorHoras = cantidadDeHorasTrabajadas * salarioPorHoras;
    this->pagoNeto = pagoTotalPorHoras;
}

int Pago::getID(){
    return this->id;
}
float Pago::getSalarioBruto(){
    return this->salarioBruto;
}
float Pago::getSalarioPorHoras(){
    return this->salarioPorHoras;
}
int Pago::getCantHoras(){
    return this->cantidadDeHorasTrabajadas;
}
bool Pago::getEsNomina(){
    return this->esNomina;
}
float Pago::getPagoTotalPorHoras(){
    return this->pagoTotalPorHoras;
}
float Pago::getPagoNominaNeto(){
    return this->pagoNominaNeto;
}
float Pago::getPagoNeto(){
    return this->pagoNeto;
}

float Pago::getCantImpuestos(){
    return this->cantImpuestos;
}