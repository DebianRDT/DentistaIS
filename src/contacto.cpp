/*
 * contacto.cpp
 *
 *  Created on: 07/12/2014
 *      Author: francisco
 */
#include <list>
#include <string>
#include "contacto.h"

namespace agenda {

  Contacto::Contacto() {

  }

  Contacto::~Contacto() {
    //limpiar la lista de atributos multiples?

  }

  bool Contacto::add_atributo_multiple(Atributo<int>* am){

    return true;
  }

  /** Elimina el atributo multiple situado en la posicion introducia
   *  por parametro si esta posicion existe en la lista. En caso negativo
   *  devuelve false
   */
  bool Contacto::del_atributo_multiple(int posicion){

    return false;
  }

  /** Cambia un atributo multiple situado en la posicion pos por otro
   *  si la posicion indicada no existe devuelve false.
   */
  bool Contacto::mod_atributo_multiple(Atributo<int>* am, int pos){

    return false;
  }

  const Atributo<int>* Contacto::get_atributo_multiple(int posicion) const{

    return NULL;
  }
  
} /* namespace agenda */
