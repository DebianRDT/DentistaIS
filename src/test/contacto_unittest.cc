#include "../contacto.h"
#include "gtest/gtest.h"


TEST(Contacto, contar_atributo_multiple) {
    Paciente c("Apellido1", "Apellido2");

    EXPECT_EQ(0, c.contar_atributo_multiple());

    c.add_atributo_multiple

}
