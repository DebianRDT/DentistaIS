/** Clase Fichero
 *
 */


#ifndef FICHERO_PACIENTES_H
#define FICHERO_PACIENTES_H

#include "base_datos.h"
#include "paciente.h"

#include <list>
#include <string>

namespace agenda{
  class FicheroPacientes:public BaseDatos{

  private:
    std::string _filename;

  public:
    FicheroPacientes();
    virtual ~FicheroPacientes();

    void cargar(std::list<Contacto*>* pacientes);


  };
}
#endif /*FICHERO_PACIENTES_H*/
