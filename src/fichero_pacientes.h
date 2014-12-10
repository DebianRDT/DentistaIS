#ifndef FICHERO_PACIENTES_H
#define FICHERO_PACIENTES_H

#include "base_datos.h"
#include "paciente.h"

#include <list>
#include <string>

namespace agenda{
  class Fichero:public BaseDatos{

  private:
    std::string _filename;
    
  public:
    Fichero();
    virtual ~Fichero();
    
    const std::list<Contacto*>& cargar();
  

  };
}
#endif /*FICHERO_PACIENTES_H*/
