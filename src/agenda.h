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

	std::list<Contacto*> _contactos;
	std::list<Contacto*>::const_iterator _activo;
public:
	static Agenda* la_agenda(BaseDatos* bd);
	virtual ~Agenda();

	bool vacia();

	const Contacto* activo();
	const Contacto* siguiente();
	const Contacto* anterior();

	const std::list<Contacto*>::const_iterator& cursor(){
	  return _activo;
	}

	

	const std::list<Contacto*> contactos();
	bool nuevo(Contacto* c);
	bool eliminar();

};

} /* namespace agenda */
#endif /* AGENDA_H_ */
