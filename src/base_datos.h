/*
 * base_datos.h
 *
 *  Created on: 07/12/2014
 *      Author: francisco
 */

#ifndef BASE_DATOS_H_
#define BASE_DATOS_H_

#include <list>
#include <string>
#include "contacto.h"

namespace agenda {

class BaseDatos {
  // TODO
  // definir protected lista de contactos
  // para que todas las derivadas la tengan obligatoriamente.


 protected:
  std::list<Contacto*>* _contactos;

 public:
  BaseDatos();

  virtual ~BaseDatos();
  virtual void cargar() = 0;
  virtual std::list<Contacto*>* get() = 0;

  virtual bool guardar_como(const std::string& filename)=0;
  virtual void cargar_desde(const std::string& filename)=0;
};

} /* namespace agenda */


#endif /* BASE_DATOS_H_ */
