#include "paciente.h"
#include <iostream>

namespace agenda{
  

  /** Define la forma en que se imprime la clase Paciente
   *  Es obligatorio definirla para todas las derivadas de Contacto
   */
  void Paciente::_print(std::ostream& o) const{

    o<<_apellido1<<std::endl<<_apellido2<<std::endl;
  }


  /** Constructor
   */
  Paciente::Paciente(const std::string& apellido1, const std::string& apellido2){

    _apellido1 = Atributo<std::string>(apellido1,"APELLIDO 1");
    _apellido2 = Atributo<std::string>(apellido2,"APELLIDO 2");
    _frecuencia = Atributo<int>(0,"FRECUENCIA"); //inicialmente frecuencia accesos 0
    _favorito = Atributo<bool>(false,"FAVORITO");

    _dni = Atributo<std::string>("","DNI");
    _nombre = Atributo<std::string>("","NOMBRE");
    _sexo = Atributo<std::string>("","SEXO");
    _fecha_nacimiento = Atributo<std::string>("","FECHA NACIMIENTO");
  }

  /** Constructor
   */
  Paciente::Paciente(){

    _apellido1 = Atributo<std::string>("","APELLIDO 1");
    _apellido2 = Atributo<std::string>("","APELLIDO 2");
    _frecuencia = Atributo<int>(0,"FRECUENCIA"); //inicialmente frecuencia accesos 0
    _favorito = Atributo<bool>(false,"FAVORITO");
    _dni = Atributo<std::string>("","DNI");
    _nombre = Atributo<std::string>("","NOMBRE");
    _sexo = Atributo<std::string>("","SEXO");
    _fecha_nacimiento = Atributo<std::string>("","FECHA NACIMIENTO");
  }

  /** Destructor
   */
  Paciente::~Paciente(){
    //POR HACER
    //Liberar memoria de todo lo inicializado con new
  }

  /** Marca el paciente como favorito
   */
  void Paciente::set_favorito(){
    
    _favorito.set_contenido(true);
  }
  
  /** Desmarca el paciente como favorito
   */
  void Paciente::reset_favorito(){

    _favorito.set_contenido(false);
  }
  
  /** Responde si el paciente es favorito o no
   */
  bool Paciente::es_favorito(){
    
    return _favorito.get_contenido();
  }




  /** Sobrecarga de operadores de comparacion
   *  compara los atributos _apellido1 + _apellido2
   *  segun orden alfabetico
   */

  bool Paciente::operator==(Contacto* c){
    Paciente* p = dynamic_cast<Paciente*>(c);

    if(_apellido1 ==  p->_apellido1 && _apellido2 == p->_apellido2)
      return true;
  }
  
  bool Paciente::operator<(Contacto* c){

    Paciente* p = dynamic_cast<Paciente*>(c);

    
    if(_apellido1 == p->_apellido1 && _apellido2 < p->_apellido2){
      return true;
    }
    else if(_apellido1 < p->_apellido1){
      return true;
    }
    


    return false;
  }
  

}
