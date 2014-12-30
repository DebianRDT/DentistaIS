#include "paciente.h"
#include <iostream>

#include "fechas.h"

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

    _atributos_multiples.push_back(tel);

  }

  bool Paciente::get_telefono(int posicion, const std::string* t){
    Atributo* telefono;

    get_atributo_multiple(posicion,telefono);
    if(telefono && telefono->get_titulo() == "TELEFONO"){
      t = &telefono->get_contenido();
      return true;
    }
    
    return false;
  }


  void  Paciente::add_nota(const std::string& nota){
    Atributo* n = new Atributo;
    n->set_contenido(nota);
    n->set_titulo("NOTA");

    _atributos_multiples.push_back(n);


  }
  
  // nota apunta a la nota indicada por pos si existe
  // si no existe apunta a NULL y devuelve false.
  bool Paciente::get_nota(int posicion, const std::string* n){
    Atributo* nota;

    get_atributo_multiple(posicion,nota);
    if(nota && nota->get_titulo() == "NOTA"){
      n = &nota->get_contenido();
      return true;
    }
    
    return false;
  }

  
  void  Paciente::add_direccion(const std::string& direccion){
    Atributo* d = new Atributo;
    d->set_contenido(direccion);
    d->set_titulo("DIRECCION");

    _atributos_multiples.push_back(d);
  }
  
  void  Paciente::add_red_social(const std::string& red_social){
    Atributo* r = new Atributo;
    r->set_contenido(red_social);
    r->set_titulo("RED_SOCIAL");

    _atributos_multiples.push_back(r);
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
