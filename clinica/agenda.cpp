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
bool Agenda::buscar_paciente(const std::string& apellidos){

	return false;
}

/** Apunta _seleccionado al siguiente paciente de la lista
 */
bool Agenda::siguiente(){

	if(_seleccionado != _todos.end()){
		_seleccionado++;
		return true;
	}
	else{
		return false;
	}


}

bool Agenda::anterior(){
	if(_seleccionado != _todos.begin()){
		_seleccionado--;
		return true;
	}
	else{
		return false;
	}
}

Paciente* Agenda::get_seleccionado(){
	return *_seleccionado;
}

bool Agenda::eliminar_seleccionado(){

	if(_seleccionado == _todos.begin()){}
	else if(_seleccionado == todos.end()){}
	else{
		_seleccionado++;
		_todos.erase(_seleccionado--);

	}
	return false;
}


/** Inserta el nuevo paciente, ordenado por apellidos
 *
 */
bool Agenda::nuevo_paciente(const Paciente& nuevo){

	return false;
}

/** Devuelve favoritos de la lista de pacientes.
 *
 */
const std::list<Paciente*>& Agenda::get_favoritos(){
	for(std::list<Paciente*>::iterator it=_todos.begin();it!=_todos.end();it++){
		if((*it)->es_favorito()){
			_favoritos.push_back(*it);
		}
	}
	return _favoritos;
}


const std::list<Paciente*>& Agenda::get_todos(const Orden& o){
	return _todos;
}




/** Actualiza el fichero con los datos actuales de la lista de pacientes.
 *
 */
bool Agenda::_reordernar_fichero(){

	return false;
}
