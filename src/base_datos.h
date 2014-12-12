/*
 * base_datos.h
 *
 *  Created on: 07/12/2014
 *      Author: francisco
 */

#ifndef BASE_DATOS_H_
#define BASE_DATOS_H_

#include <list>
#include "contacto.h"

namespace agenda {

class BaseDatos {


public:
	BaseDatos();
	virtual ~BaseDatos();
	virtual void cargar(std::list<Contacto*>* p) = 0;

	static bool guardar(const std::list<Contacto*> contactos, const std::string& filename);
};

} /* namespace agenda */


#endif /* BASE_DATOS_H_ */
