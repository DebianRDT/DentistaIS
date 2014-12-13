#ifndef PACIENTE_H
#define PACIENTE_H

#include <iostream>
#include "contacto.h"
#include "atributo.h"

namespace agenda{

  class Paciente:public Contacto{
  private:
    Atributo<std::string> _apellido1;
    Atributo<std::string> _apellido2;
    Atributo<int> _frecuencia;
    Atributo<bool> _favorito;

    //POR HACER
    //Agregar el resto de atributos individuales

    
    void _print(std::ostream& o) const;


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

    bool operator ==(const Contacto& c) const;
    bool operator <(const Contacto& c) const;
    bool operator >=(const Contacto& c) const;

    /* especificas de paciente */

    void set_apellido1(const std::string& a1){
        _apellido1.set_contenido(a1);
    }

    const Atributo<std::string>& get_apellido1(){
      return _apellido1;
    }

    void set_apellido2(const std::string& a2){
      _apellido2.set_contenido(a2);
    }

    const Atributo<std::string>& get_apellido2(){
      return _apellido2;
    }

    void set_frecuencia(int frecuencia){
        _frecuencia.set_contenido(frecuencia);
    }

    

  };

}


#endif
