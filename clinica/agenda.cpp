/*
 * agenda.cpp
 *
 *
 *
 *
 *
 */

#include "agenda.h"

#include "base_datos.h"

using namespace clinica;

Agenda* Agenda::_la_agenda = 0;

/** Constructor
 *
 */
Agenda::Agenda(BaseDatos* bd){
	_n = _todos.size();
	_seleccionado = _todos.begin();
	_bd = bd;
	_todos = bd->cargar();
}

/** Destructor
 *
 */
Agenda::~Agenda(){}


/** Devuelve la instancia (singleton) de la agenda
 *
 */
Agenda* Agenda::LaAgenda(BaseDatos* bd){


	if(_la_agenda == 0){
		_la_agenda = new Agenda(bd);


	}
	return _la_agenda;
}

/** Busca un paciente a partir de sus apellidos
 *  si lo encuentra pone _seleccionado apuntando a la
 *  primera ocurrencia, y devuelve true, si no encontro nada
 *  devuelve false.
 */
bool Agenda::buscar(const std::string& apellido1,const std::string& apellido2=std::string()){
	//std::size_t found;


	for(std::list<Paciente*>::iterator it=_todos.begin();it!=_todos.end();it++){
		if ( (*it)->get_apellido1().find(apellido1)!=std::string::npos || (*it)->get_apellido2().find(apellido2)!=std::string::npos ){
			_seleccionado = it;
			return true;
		}
	}

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

Paciente* Agenda::obtener(){
	return *_seleccionado;
}

/** Elimina el paciente seleccionado
 *  Si es el primero de la lista, el nuevo paciente seleccionado sera el siguiente
 *  Si es el ultimo de la lista el nuevo paciente seleccionado sera el anterior
 *  Si no es ni el primero ni el ultimo, el nuevo paciente sera el siguiente
 *
 */
bool Agenda::eliminar(){
	std::list<Paciente*>::iterator aux = _seleccionado;

	if(_todos.empty())
		return false;

	if(_seleccionado == _todos.begin()){
		_seleccionado++;
	}
	else if(_seleccionado == _todos.end()){
		_seleccionado--;
	}
	else{
		_seleccionado++;
		_todos.erase(aux);
	}


	return _bd->guardar();
}


/** Inserta el nuevo paciente, ordenado por apellidos
 *
 */
bool Agenda::agregar(Paciente* nuevo){

	std::list<Paciente*>::iterator anterior;
	std::list<Paciente*>::iterator actual;

	if(_todos.empty()){
		_todos.push_back(nuevo);
		return true;
	}

	anterior = _todos.begin();
	actual = _todos.begin()++;

	do{

		if( (*anterior)<nuevo && (*actual)>=nuevo){
			_todos.insert(actual++,nuevo);
		}

		(*actual)->get_apellido1();
		anterior = actual;
		actual++;
	}while(actual!=_todos.end());

	return _bd->guardar();
}


/** Devuelve favoritos de la lista de pacientes.
 *
 */

const std::list<Paciente*>& Agenda::favoritos(){
	for(std::list<Paciente*>::iterator it=_todos.begin();it!=_todos.end();it++){
		if((*it)->es_favorito()){
			_favoritos.push_back(*it);
		}
	}
	return _favoritos;
}

