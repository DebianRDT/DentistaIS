#include "../aplicacion.h"
#include "../fichero_pacientes.h"
#include "../paciente.h"
#include "gtest/gtest.h"
#include "fstream"
//POSIBLE TEST APLICACION **(HECHO POR JOAQUIN)**
using namespace agenda;

TEST(Aplicacion, Visualizar paciente)
{
	Paciente p("name","lastname1","lastname2","23,02,1995","3","false","33XX","hombre");
    EXPECT_EQ("name", p.busqueda_paciente().get_nombre());
    EXPECT_EQ("lastname1", p.busqueda_paciente().get_apellido1());
    EXPECT_EQ("lastname2", p.busqueda_paciente().get_apellido2());
    EXPECT_EQ("23,02,1995", p.busqueda_paciente().get_fecha_nacimiento());
    EXPECT_EQ(3, p.busqueda_paciente().get_frecuencia());
	EXPECT_EQ("false",p.busqueda_paciente().es_favorito());
	EXPECT_EQ("33XX",p.busqueda_paciente().get_dni());
	EXPECT_EQ("hombre",p.busqueda_paciente().get_fecha_nacimiento());
}


