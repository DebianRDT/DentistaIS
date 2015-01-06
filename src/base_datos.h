#ifndef BASE_DATOS_H_
#define BASE_DATOS_H_

#include <list>
#include <string>
#include "contacto.h"

namespace agenda {

class BaseDatos {


 protected:
  std::list<Contacto*>* _contactos;
  std::list<Contacto*>::iterator _activo;

 public:
  BaseDatos();

  virtual ~BaseDatos();
  virtual std::list<Contacto*>::iterator cargar() = 0;
  virtual std::list<Contacto*>* get() = 0;

  virtual bool guardar()=0;
  virtual bool guardar_como(const std::string& filename)=0;
  virtual void cargar_desde(const std::string& filename)=0;
  

  virtual bool vacia()=0;
  virtual bool eliminar()=0;
  virtual bool nuevo(Contacto* c)=0;
  virtual Contacto* activo()=0;
  virtual void siguiente()=0;
  virtual void anterior()=0;
  virtual bool buscar(const std::string& a1, const std::string& a2)=0;
  virtual bool es_primero()=0;

};

} /* namespace agenda */


#endif /* BASE_DATOS_H_ */
