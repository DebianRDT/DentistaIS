#include "paciente.h"
#include "gtest/gtest.h"


TEST(Paciente, constructor) {
    Paciente p("Apellido1", "Apellido2");

    EXPECT_EQ("Apellido1", p.getApellido1());
    EXPECT_EQ("Apellido2", p.getApellido2());

}

TEST(Paciente, asignar_apellidos) {
    Paciente p("Apellido1", "Apellido2");
    p.setApellido1("LastName1");
    p.setApellido2("LastName2");

    EXPECT_EQ("LastName1", p.getApellido1());
    EXPECT_EQ("LastName2", p.getApellido2());

}
