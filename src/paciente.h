#ifndef PACIENTE_H
#define PACIENTE_H

#include <iostream>
#include "contacto.h"
#include "atributo.h"

namespace agenda{

  class Paciente:public Contacto{
  private:
    Atributo<std::string>* _apellido1;
    Atributo<std::string>* _apellido2;
    Atributo<int>* _frecuencia;
    Atributo<bool>* _favorito;

    //POR HACER
    //Agregar el resto de atributos individuales
    

  public:

    //POR HACER
    // constructor de copia para modificar

    void set_favorito();
    void reset_favorito();
    bool es_favorito();

    Paciente(const std::string& apellido1, const std::string& apellido2);
    Paciente();
    virtual ~Paciente();

    /* obligatorias */
    std::ostream &operator<<(std::ostream &out) const;
    bool operator ==(const Contacto& c) const;
    bool operator <(const Contacto& c) const;
    bool operator >=(const Contacto& c) const;

    /* especificas de paciente */
    


  };

}


#endif
