#include "../fechas.h"
#include "gtest/gtest.h"

using namespace agenda;



TEST(Fechas, gestion_fechas) {
    Fecha f(20,10,2010);
    EXPECT_EQ("20/10/2010", f.getFecha());

    f.setFecha(1,1,2011);
    EXPECT_EQ("1/1/2011", f.getFecha());



}
