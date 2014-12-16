#include "../fechas.h"
#include "gtest/gtest.h"


TEST(Fechas, gestion_fechas) {
    Fecha f(20,10,2010);

    EXPECT_EQ(true, f.validar());

    f.setFecha(32,10,2010);
    EXPECT_EQ(false, f.validar());

    f.setFecha(28, 2, 2015);
    EXPECT_EQ(false, f.validar());

    f.setFecha(29,2,2012);
    EXPECT_EQ(true, f.validar());

    f.setFecha(1,1,2011);
    EXPECT_EQ("1/1/2011", f.getFecha());

}
