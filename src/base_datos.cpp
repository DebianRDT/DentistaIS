/*
 * base_datos.cpp
 *
 *  Created on: 07/12/2014
 *      Author: francisco
 */

#include "base_datos.h"

#include <iostream>
#include <fstream>

namespace agenda {

BaseDatos::BaseDatos() {
	// TODO Auto-generated constructor stub

}

BaseDatos::~BaseDatos() {
	// TODO Auto-generated destructor stub
}


bool BaseDatos::guardar(const std::list<Contacto*> contactos, const std::string& filename){

	if(contactos.empty())
		return false;

	std::ofstream fichero;
	fichero.open(filename.c_str());

	if(!fichero.is_open())
		return false;

	for(std::list<Contacto*>::const_iterator it=contactos.begin();it!=contactos.end();it++){
		fichero<<"[CONTACTO_BEGIN]\n";
		fichero<<(*it)<<"\n";
		fichero<<"[CONTACTO_END]\n";
	}


	return true;
}

} /* namespace agenda */
