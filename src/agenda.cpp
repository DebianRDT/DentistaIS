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
  


} /* namespace agenda */
