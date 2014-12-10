#include "fichero_pacientes.h"
#include "contacto.h"
#include "paciente.h"
#include <list>

namespace agenda{


  Fichero::Fichero(){
    _filename = "default.txt";
  }
  
  Fichero::~Fichero(){}
  
  /**  Devuelve lista de contactos en el 
   *   fichero por defecto.
   */
  const std::list<Contacto*>& Fichero::cargar(){
    std::list<Contacto*> pacientes;

    //POR HACER: CARGA PACIENTES DESDE EL FICHERO
    //pacientes.push_back(new Paciente());

    return pacientes;

  }

}
