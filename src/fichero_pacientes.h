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

    std::list<Contacto*>::iterator cargar();
    bool guardar();
    bool guardar_como(const std::string& filename);
    void cargar_desde(const std::string& filename);

    bool vacia();
    bool eliminar();
    bool nuevo(Contacto* c);
    Contacto* activo();
    void siguiente();
    void anterior();
    bool buscar(const std::string& a1, const std::string& a2);
    bool es_primero();


  };
}
#endif /*FICHERO_PACIENTES_H*/
