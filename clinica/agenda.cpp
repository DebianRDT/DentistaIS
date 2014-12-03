/*
 * agenda.cpp
 *
 *
 *
 *
 *
 */

#include "agenda.h"
using namespace clinica;

Agenda* Agenda::_la_agenda = 0;
char Agenda::_n_fichero[10] = "pacientes";

/** Constructor
 *
 */
Agenda::Agenda(){
	_n = _todos.size();
	_seleccionado = _todos.begin();
}

/** Destructor
 *
 */
Agenda::~Agenda(){}


/** Devuelve la instancia (singleton) de la agenda
 *
 */
Agenda* Agenda::LaAgenda(){
	if(_la_agenda == 0){
		_la_agenda = new Agenda();
	}
	return _la_agenda;
}

/** Busca un paciente a partir de sus apellidos
 *  si lo encuentra pone _seleccionado apuntando a la
 *  primera ocurrencia, y devuelve true, si encontro nada
 *  devuelve false.
 */
bool Agenda::buscar_paciente(const std::string& apellidos){}

/** Apunta _seleccionado al siguiente paciente de la lista
 */
bool Agenda::siguiente(){}
bool Agenda::anterior(){}
const Paciente& Agenda::get_seleccionado(){}
bool Agenda::eliminar_seleccionado(){}

bool Agenda::nuevo_paciente(const Paciente& nuevo){}

const std::list<Paciente*>& Agenda::get_favoritos(){}
const std::list<Paciente*>& Agenda::get_todos(const Orden& o){}




/** Actualiza el fichero con los datos actuales de la lista de pacientes.
 *
 */
bool Agenda::_reordernar_fichero(){}
