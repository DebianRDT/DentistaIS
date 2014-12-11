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
	Agenda(BaseDatos* bd, std::list<Contacto*>* contactos);
	BaseDatos* _bd;
	std::list<Contacto*>* _contactos;
	std::list<Contacto*>::iterator _activo;
public:
	static Agenda* la_agenda(BaseDatos* bd);
	virtual ~Agenda();

	bool vacia();

	std::list<Contacto*>::iterator activo();
	std::list<Contacto*>::iterator siguiente();
	std::list<Contacto*>::iterator anterior();


	const std::list<Contacto*>* contactos();
	bool nuevo(Contacto* c);
	bool eliminar();

};

} /* namespace agenda */
#endif /* AGENDA_H_ */
