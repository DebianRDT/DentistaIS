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


std::list<const Candidato*> Agenda::buscar_paciente(const std::string& apellidos){}
bool Agenda::seleccionar_paciente(const std::list< std::list<Paciente*>::iterator >& candidatos, int elegido){}

const Paciente& Agenda::get_seleccionado(){}
bool Agenda::eliminar_paciente(){}
bool Agenda::nuevo_paciente(const Paciente& nuevo){}

std::list<Paciente*> Agenda::get_favoritos(){}
std::list<Paciente*> Agenda::get_todos(const Orden& o){}




/** Actualiza el fichero con los datos actuales de la lista de pacientes.
 *
 */
bool Agenda::_reordernar_fichero(){}
