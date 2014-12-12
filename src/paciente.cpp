#include "paciente.h"
#include <iostream>

namespace agenda{
  Paciente::Paciente(const std::string& apellido1, const std::string& apellido2){

    // inicializo atributos obligatorios (para orden)
    // si no se quieren especificar introducir cadena vacia.


    _apellido1 = Atributo<std::string>(apellido1,"APELLIDO 1");
    _apellido2 = Atributo<std::string>(apellido2,"APELLIDO 2");
    _frecuencia = Atributo<int>(0,"FRECUENCIA"); //inicialmente frecuencia accesos 0
    _favorito = Atributo<bool>(false,"FAVORITO");
    
    // POR HACER
    // inicilizar los demas

  }


  Paciente::Paciente(){
    //_apellido1 = new Atributo<std::string>("","APELLIDO 1");
    _apellido1 = Atributo<std::string>("","APELLIDO 1");
    _apellido2 = Atributo<std::string>("","APELLIDO 2");
    _frecuencia = Atributo<int>(0,"FRECUENCIA"); //inicialmente frecuencia accesos 0
    _favorito = Atributo<bool>(false,"FAVORITO");

    // POR HACER
    // inicializar los demas
  }

  Paciente::~Paciente(){

  }


  void Paciente::set_favorito(){
    _favorito.set_contenido(true);
  }
  
  void Paciente::reset_favorito(){
    _favorito.set_contenido(false);
  }
  
  bool Paciente::es_favorito(){
    return _favorito.get_contenido();
  }

  bool Paciente::operator==(const Contacto& c) const{
    //POR HACER
  }
  
  bool Paciente::operator<(const Contacto& c) const{
    //POR HACER
  }
  
  bool Paciente::operator>=(const Contacto& c) const{
    //POR HACER
  }

}
