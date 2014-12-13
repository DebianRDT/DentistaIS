/*
 * agenda.cpp
 *
 *  Created on: 08/12/2014
 *      Author: francisco
 */

#include "agenda.h"
#include "base_datos.h"

namespace agenda {

  Agenda* Agenda::_la_agenda = 0;

  Agenda::Agenda(BaseDatos* bd) {
    _bd = bd;
    _bd->cargar();
    _contactos = *(_bd->get());
    
    if(!_contactos.empty()){
      _activo = _contactos.begin();
    }
    else{
      _activo = _contactos.end();
    }
    
  }

  Agenda* Agenda::la_agenda(BaseDatos* bd) {
    if(_la_agenda==0){
      _la_agenda = new Agenda(bd);
    }
    return _la_agenda;
  }
  




  Agenda::~Agenda() {
    // TODO Auto-generated destructor stub
  }
  
  bool Agenda::vacia(){
    //TODO
    return true;
  }
  




  const Contacto* Agenda::activo(){
    return *_activo;
  }
  
  const Contacto* Agenda::siguiente(){
    return *(_activo++);
  }
  
  const Contacto* Agenda::anterior(){
    return *(_activo--);
  }

  const std::list<Contacto*> Agenda::contactos(){
    return _contactos;
  }

  /** Agrega un nuevo contacto a la lista en orden alfabetico de su
   *  primer y segundo apellido
   */
  bool nuevo(Contacto* contacto){

  }

} /* namespace agenda */
