#include "../fechas.h"
#include "../contacto.h"
#include "../atributo.h"
#include "../paciente.h"

#include "gtest/gtest.h"

using namespace agenda;

TEST(Paciente, constructor) {

    Paciente p("Apellido1", "Apellido2");

    EXPECT_EQ("Apellido1", p.get_apellido1().get_contenido());
    EXPECT_EQ("Apellido2", p.get_apellido2().get_contenido());

}



TEST(Paciente, asignar_apellidos) {
    Paciente p("Apellido1", "Apellido2");
    p.set_apellido1("LastName1");
    p.set_apellido2("LastName2");

    EXPECT_EQ("LastName1", p.get_apellido1().get_contenido());
    EXPECT_EQ("LastName2", p.get_apellido2().get_contenido());

}


TEST(Paciente, asignar_nombre) {
    Paciente p("Apellido1", "Apellido2");

    p.set_nombre("Paco");
    EXPECT_EQ("Paco", p.get_nombre().get_contenido());

    p.set_nombre("Juan");
    EXPECT_EQ("Juan", p.get_nombre().get_contenido());
}


TEST(Paciente, favorito) {
    Paciente p("Apellido1", "Apellido2");

    EXPECT_EQ(false, p.es_favorito());

    p.set_favorito();
    EXPECT_EQ(true, p.es_favorito());

    p.reset_favorito();
    EXPECT_EQ(false, p.es_favorito());
}

TEST(Paciente, asignar_dni) {
    Paciente p("Apellido1", "Apellido2");

    p.set_dni("26268243K");
    EXPECT_EQ("26268243K", p.get_dni().get_contenido());

    p.set_dni("26268243L");
    EXPECT_EQ("26268243L", p.get_dni().get_contenido());
}


TEST(Paciente, frecuencia) {
    Paciente p("Apellido1", "Apellido2");

    EXPECT_EQ(0, p.get_frecuencia());

    p.set_frecuencia("14");
    EXPECT_EQ(14, p.get_frecuencia());
}


TEST(Paciente, sexo) {
    Paciente p("Apellido1", "Apellido2");

    p.set_sexo("Hombre");
    EXPECT_EQ("Hombre", p.get_sexo().get_contenido());

    p.set_sexo("Mujer");
    EXPECT_EQ("Mujer", p.get_sexo().get_contenido());
}



TEST(Paciente, telefono){
  
  Paciente p;
  std::string telefono1;

  p.add_telefono("123456789");
  telefono1 = p.get_atributo_multiple()->get_contenido();

  EXPECT_EQ("123456789", telefono1);
  //EXPECT_EQ("666666666", *telefono2);
  
  
}


TEST(Paciente, nota){

  
  Paciente p;
  std::string nota;

  p.add_nota("hola mundo");  
  nota = p.get_atributo_multiple()->get_contenido();

  EXPECT_EQ("hola mundo", nota);
  
}





TEST(Paciente, fecha_nacimiento) {
    Paciente p("Apellido1", "Apellido2");
    p.set_fecha_nacimiento("1/1/2010");

    EXPECT_EQ("1/1/2010", p.get_fecha_nacimiento());

    //f.setFecha(20,10,2010);
    //p.set_fecha_nacimiento(f.getFecha());
    //EXPECT_EQ("20/10/2010", p.get_fecha_nacimiento());
}



TEST(Paciente, comparacion_pacientes) {
    Paciente* p1 = new Paciente("Garrido", "Martinez");
    Paciente* p2 = new Paciente("Molino", "Ortega");
    Paciente* p3 = new Paciente("Moya", "Robles");
    Paciente* p4 = new Paciente("Molino", "Ortega");

    EXPECT_EQ(true, p1<p2);
    EXPECT_EQ(false, p3<p2);
    EXPECT_EQ(false, p4<p1);



    delete(p1);
    delete(p2);
    delete(p3);
    delete(p4);

}

