#include "../paciente.h"
#include "gtest/gtest.h"


TEST(Paciente, constructor) {
    Paciente p("Apellido1", "Apellido2");

    EXPECT_EQ("Apellido1", p.get_apellido1());
    EXPECT_EQ("Apellido2", p.get_apellido2());

}

TEST(Paciente, asignar_apellidos) {
    Paciente p("Apellido1", "Apellido2");
    p.set_apellido1("LastName1");
    p.set_apellido2("LastName2");

    EXPECT_EQ("LastName1", p.get_apellido1());
    EXPECT_EQ("LastName2", p.get_apellido2());

}

TEST(Paciente, asignar_nombre) {
    Paciente p("Apellido1", "Apellido2");

    p.set_nombre("Paco");
    EXPECT_EQ("Paco", p.get_nombre());

    p.set_nombre("Juan");
    EXPECT_EQ("Juan", p.get_nombre());
}

TEST(Paciente, favorito) {
    Paciente p("Apellido1", "Apellido2");

    EXPECT_EQ(false, p.get_favorito());

    p.set_favorito();
    EXPECT_EQ(true, p.get_favorito());

    p.reset_favorito();
    EXPECT_EQ(false, p.get_favorito());
}

TEST(Paciente, asignar_dni) {
    Paciente p("Apellido1", "Apellido2");

    p.set_dni("26268243K");
    EXPECT_EQ("26268243K", p.get_dni());

    p.set_dni("26268243L");
    EXPECT_EQ("26268243L", p.get_dni());
}

TEST(Paciente, frecuencia) {
    Paciente p("Apellido1", "Apellido2");

    EXPECT_EQ(0, p.get_frecuencia());

    p.set_frecuencia(14);
    EXPECT_EQ(14, p.get_frecuencia());
}

TEST(Paciente, sexo) {
    Paciente p("Apellido1", "Apellido2");

    p.set_sexo("Hombre");
    EXPECT_EQ("Hombre", p.get_sexo());

    p.set_sexo("Mujer");
    EXPECT_EQ("Mujer", p.get_sexo());
}

TEST(Paciente, fecha_nacimiento) {
    Paciente p("Apellido1", "Apellido2");

    p.set_fecha_nacimiento(40,10,2010);
    EXPECT_EQ("0/0/0", p.get_fecha_nacimiento);

    p.set_fecha_nacimiento(20, 10, 2010);
    EXPECT_EQ("20/10/2010", p.get_fecha_nacimiento);
}

TEST(Paciente, comparacion_pacientes) {
    Paciente p1("Garrido", "Martinez");
    Paciente p2("Molino", "Ortega");
    Paciente p3("Moya", "Robles");
    Paciente p4("Molino", "Ortega");

    EXPECT_LT(p2, p1);
    EXPECT_LT(p3, p2);
    EXPECT_GT(p1, p3);
    EXPECT_EQ(p4, p1);

}
