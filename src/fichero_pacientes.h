/** Clase Fichero
 *
 */


#ifndef FICHERO_PACIENTES_H
#define FICHERO_PACIENTES_H

#include "base_datos.h"
#include "contacto.h"


#include <list>
#include <string>

namespace agenda{
  class FicheroPacientes:public BaseDatos{

  private:
    std::string _filename;
    std::list<Contacto*>* _pacientes;

  public:
    FicheroPacientes();
    FicheroPacientes(std::list<Contacto*>* pacientes);
    
    virtual ~FicheroPacientes();


    std::list<Contacto*>* get();




    void cargar();
    bool guardar();

    bool guardar_como(const std::string& filename);
    void cargar_desde(const std::string& filename);


  };
}
#endif /*FICHERO_PACIENTES_H*/
