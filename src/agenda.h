/*
 * agenda.h
 *  Singleton
 *  Created on: 08/12/2014
 *      Author: francisco
 */

#ifndef AGENDA_H_
#define AGENDA_H_

#include <list>
#include "contacto.h"
#include "base_datos.h"

namespace agenda {

class Agenda {
private:
	static Agenda* _la_agenda;
protected:
	Agenda(BaseDatos* bd);
	BaseDatos* _bd;

public:
	static Agenda* la_agenda(BaseDatos* bd);
	virtual ~Agenda();
	

	BaseDatos* contactos(){
	  return _bd;
	}


};

} /* namespace agenda */
#endif /* AGENDA_H_ */
