/*
 * agenda.cpp
 *
 * Agenda de pacientes mediante un fichero Secuencial sin zona de derrama.
 *
 *  Created on: 26/11/2014
 *      Author: francisco
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


/** Recorre la lista de pacientes y crea otra de candidatos
 *  que son enlaces al elemento de la lista donde esta el paciente
 */
std::list<const Candidato*> Agenda::buscar_paciente(const std::string& apellidos){
	//TODO


}

/**
 * Marca el paciente en la posicion indicada por el entero elegido como
 * pacienten activo.
 */
bool Agenda::seleccionar_paciente(const std::list<Paciente*>& candidatos, int elegido){}

/** Devuelve todos los detalles del paciente
 *
 */
const Paciente& Agenda::ver_detalles(){}

/** Devuelve lista de todos los atributos multiples
 *  del paciente seleccionado.
 */
std::list<AtributoMultiple*> Agenda::obtener_atributos_multiples(){}

/** Devuelve lista de atributos multiples de tipo indicado por parametro
 *
 */

std::list<AtributoMultiple*> Agenda::obtener_atributos_multiples(const TipoAt& tipo){}

/** Sustituye el atributo multiple de la posicion n, por el nuevo
 *
 */
bool Agenda::modificar_atributo(const AtributoMultiple& nuevo, int n){}

/** Elimina el paciente seleccionado
 *
 */
bool Agenda::eliminar_paciente(){}

/** Agrega un nuevo paciente ordenado por apellidos en la lista
 *
 */
bool Agenda::nuevo_paciente(const Paciente& nuevo){}

/** Devuelve lista de pacientes favoritos ordenados por apellidos
 *
 */
std::list<Paciente*> Agenda::get_favoritos(){}

/** Devuelve lista de pacientes con orden especificado por parametro.
 *
 */
std::list<Paciente*> Agenda::get_todos(const Orden& o){}

/** Actualiza el fichero con los datos actuales de la lista de pacientes.
 *
 */
bool Agenda::reordernar_fichero(){}
