#include "paciente.h"
#include "gtest/gtest.h"


TEST(Paciente, constructor) {
    Paciente p("Apellido1", "Apellido2");

    EXPECT_EQ("Apellido1", p.get_Apellido1());
    EXPECT_EQ("Apellido2", p.get_Apellido2());

}

TEST(Paciente, asignar_apellidos) {
    Paciente p("Apellido1", "Apellido2");
    p.set_Apellido1("LastName1");
    p.set_Apellido2("LastName2");

    EXPECT_EQ("LastName1", p.get_Apellido1());
    EXPECT_EQ("LastName2", p.get_Apellido2());

}

TEST(Paciente, asignar_nombre) {
    Paciente p("Apellido1", "Apellido2");

    p.set_Nombre("Paco");
    EXPECT_EQ("Paco", p.get_Nombre());

    p.set_Nombre("Juan");
    EXPECT_EQ("Juan", p.get_Nombre());
}

TEST(Paciente, favorito) {
    Paciente p("Apellido1", "Apellido2");

    EXPECT_EQ(false, p.get_Favorito());

    p.set_Favorito();
    EXPECT_EQ(true, p.get_Favorito());

    p.reset_Favorito();
    EXPECT_EQ(false, p.get_Favorito());
}

TEST(Paciente, asignar_apellidos)
