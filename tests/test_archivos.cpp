#include <gtest/gtest.h>
#include "../src/empleado.h"
#include "../src/jerarquiaDeEmpleados.h"
#include "../src/pago.h"
#include "../src/reporteFinal.h"
#include <iostream>
#include <string>

using namespace std;

namespace{

    TEST(Test_Leer_Archivos, DevolverSalarioPorNomina){

        ReporteFinal *rF = new ReporteFinal();
        float resultado = rF->SalarioBruto(1);
        float esperada = 4600.98;

        delete rF;

        EXPECT_FLOAT_EQ(esperada, resultado);
    }
    TEST(Test_Leer_Archivos, DevolverSalarioPorHoras){

        ReporteFinal *rF = new ReporteFinal();
        float resultado = rF->SalarioPorHoras(460);
        float esperada = 2927.7;

        delete rF;

        EXPECT_FLOAT_EQ(esperada, resultado);
    }    
        TEST(Test_Leer_Archivos, DevolverEmpleado) {

        ReporteFinal *rF = new ReporteFinal();
        Empleado *empleado = new Empleado(2, "Carmen", "Zaoui", "carmen_zaoui@biz.com", 1, 3);

        stringstream s;
        s << empleado;
        string stringEmpleado = s.str();
        string esperada = "12,Carmen,Zaoui,carmen_zaoui@biz.com,1,3";

        delete rF;
        delete empleado;

        EXPECT_EQ(esperada, stringEmpleado);
    }

}