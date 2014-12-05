/*
 * paciente.cpp
 *
 *  Created on: 26/11/2014
 *      Author: francisco
 */

#include "paciente.h"
#include <list>
using namespace clinica;

/** Constructor
 *
 */
Paciente::Paciente(){

}

/** Destructor
 *
 */
Paciente::~Paciente(){}

const std::string& Paciente::get_apellido1()const{
	return _apellido1;
}
const std::string& Paciente::get_apellido2()const{
	return _apellido2;
}




/* Devuelve una lista con todos los atributos multiples
 * del paciente.
 */
const std::list<AtributoMultiple*>& Paciente::lista_atributos_multiples(const TipoAt& t){}


/** Cambia el atributo multiple en la posicion n, por el nuevo
 *
 */
bool Paciente::cambiar_atributo(int n, const AtributoMultiple& nuevo){
  
  list<AtributoMultiple>::iterator pos;
  
  bool atributo;
  int i=0;
  for(pos=_atributos_multiples_.begin();pos!=_atributos_multiples_.end();pos++)
  {
     
     if(i==n-1)
      {
        *pos=nuevo;    
        atributo=true;
        
      }
    i++; 
      
  }

}


/** Agrega atributo multiple al final de la lista
 *
 */
bool Paciente::agregar_atributo(const AtributoMultiple& nuevo){}


bool clinica::Paciente::es_favorito() {
	return false;
}

/** Saca de la lista el atributo multiple en la posicion n
 *
 */
bool Paciente::eliminar_atributo(int n){}



/** Un paciente es menor que otro cuando su <apellido1 apellido2> es inferior
 *  albafeticamente.
 */
bool Paciente::operator <(const Paciente &p) const{}


/** Un paciente es mayor que otro cuando su <apellido1 apellido2> es superior
 *  albafeticamente. Igual cuando sus apellidos son iguales.
 */
bool Paciente::operator >=(const Paciente &p) const{}
