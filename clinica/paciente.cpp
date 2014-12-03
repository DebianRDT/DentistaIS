/*
 * paciente.cpp
 *
 *  Created on: 26/11/2014
 *      Author: francisco
 */

#include "paciente.h"
#include <list>
using namespace clinica;

/** Constructor
 *
 */
Paciente::Paciente(){

}

/** Destructor
 *
 */
Paciente::~Paciente(){}

/* Devuelve una lista con todos los atributos multiples
 * del paciente.
 */
const std::list<AtributoMultiple*>& Paciente::lista_atributos_multiples(){}


/** Cambia el atributo multiple en la posicion n, por el nuevo
 *
 */
bool Paciente::cambiar_atributo(int n, const AtributoMultiple& nuevo){}


/** Agrega atributo multiple al final de la lista
 *
 */
bool Paciente::agregar_atributo(const AtributoMultiple& nuevo){}

/** Saca de la lista el atributo multiple en la posicion n
 *
 */
bool Paciente::eliminar_atributo(int n){}



const std::string& Paciente::linea(){

	return "";
}
