#include "paciente.h"
#include <iostream>
#include <sstream>

#include "fechas.h"

namespace agenda{


  /** Define la forma en que se imprime la clase Paciente
   *  Es obligatorio definirla para todas las derivadas de Contacto
   */
  void Paciente::_print(std::ostream& o){
    if(es_favorito()){
      o<<"[FAVORITO]"<<std::endl;
    }
    o<<_apellido1<<" "<<_apellido2<<", "<<_nombre<<" DNI:"<<_dni<<std::endl;
    o<<_sexo<<". Nacimiento: "<<_fecha_nacimiento<<std::endl;

    o<<"Veces consultado: "<<_frecuencia<<" veces."<<std::endl;

    //imprimo atributos multiples
    o<<"+ INFO ("<<contar_atributos_multiples()<<")"<<std::endl;
    while(!es_ultimo()){
      o<<*get_atributo_multiple()<<std::endl;
    }

    o<<"---"<<std::endl;

  }


  /** Constructor
   */
  Paciente::Paciente(const std::string& apellido1, const std::string& apellido2){



    _apellido1 = Atributo(apellido1,"APELLIDO 1");
    _apellido2 = Atributo(apellido2,"APELLIDO 2");
    _frecuencia = Atributo("0","FRECUENCIA"); //inicialmente frecuencia accesos 0
    _favorito = Atributo("false","FAVORITO");

    _dni = Atributo("","DNI");
    _nombre = Atributo("","NOMBRE");
    _sexo = Atributo("","SEXO");
    _fecha_nacimiento = Atributo("","FECHA NACIMIENTO");
  }

  /** Constructor
   */
  Paciente::Paciente(){

    _apellido1 = Atributo("","APELLIDO 1");
    _apellido2 = Atributo("","APELLIDO 2");
    _frecuencia = Atributo("0","FRECUENCIA"); //inicialmente frecuencia accesos 0
    _favorito = Atributo("false","FAVORITO");
    _dni = Atributo("","DNI");
    _nombre = Atributo("","NOMBRE");
    _sexo = Atributo("","SEXO");
    _fecha_nacimiento = Atributo("","FECHA NACIMIENTO");
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

    _favorito.set_contenido("true");
  }

  /** Desmarca el paciente como favorito
   */
  void Paciente::reset_favorito(){

    _favorito.set_contenido("false");
  }

  /** Responde si el paciente es favorito o no
   */
  bool Paciente::es_favorito(){

    if(_favorito.get_contenido() == "true")
      return true;
    else
      return false;
  }


  /* Metodos para gestion de atributos multiples */

  void Paciente::add_telefono(const std::string& telefono){
    Atributo* tel = new Atributo;
    tel->set_contenido(telefono);
    tel->set_titulo("TELEFONO");

    add_atributo_multiple(tel);

  }

  void  Paciente::add_nota(const std::string& nota){
    Atributo* n = new Atributo;
    n->set_contenido(nota);
    n->set_titulo("NOTA");

    add_atributo_multiple(n);

  }


  void  Paciente::add_direccion(const std::string& direccion){
    Atributo* d = new Atributo;
    d->set_contenido(direccion);
    d->set_titulo("DIRECCION");

    add_atributo_multiple(d);

  }


  void  Paciente::add_red_social(const std::string& red_social){
    Atributo* r = new Atributo;
    r->set_contenido(red_social);
    r->set_titulo("RED SOCIAL");

    add_atributo_multiple(r);

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


  const Paciente& Paciente::operator++(){
      std::ostringstream ss;
      ss<<(get_frecuencia()+1);
      _frecuencia.set_contenido(ss.str());

  }




}
