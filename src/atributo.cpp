#include "atributo.h"
using namespace agenda;




/** Constructor
 */

Atributo::Atributo(){}

/** Constructor
 */

Atributo::Atributo(const std::string& contenido, const std::string& titulo){
  _contenido = contenido;
  _titulo = titulo;
}


/** Destructor
 */

Atributo::~Atributo(){
  //POR HACER
}


/** Pone el titulo que indiquemos por parametro
 *
 */

void Atributo::set_titulo(const std::string& titulo){
  _titulo = titulo;
}

/** Devuelve el titulo del atributo
 */
const std::string& Atributo::get_titulo() const{
  return _titulo;
}

/** Pone el contenido del atributo que indiquemos por parametro
 */

void Atributo::set_contenido(const std::string& contenido){
  _contenido = contenido;
}


/** Devuelve el contenido del atributo
 */
const std::string&  Atributo::get_contenido() const{
  return _contenido;
}


/** Sobrecargar operadores de comparacion
 *  < ==
 */



bool Atributo::operator==(const Atributo& a){
  return _contenido == a._contenido;
}


bool Atributo::operator<(const Atributo& a){
  // POR HACER
  return _contenido < a._contenido;
}
