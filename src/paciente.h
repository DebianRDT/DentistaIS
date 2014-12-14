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

    Atributo<std::string> _nombre;
    Atributo<std::string> _dni;
    Atributo<std::string> _fecha_nacimiento;
    Atributo<std::string> _sexo;

    //POR HACER
    //Implementar atributos multiples

    
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

    bool operator ==(Contacto* c);
    bool operator <(Contacto* c);
    



    /* GETTERS Y SETTERS */

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

    const Atributo<int>& get_frecuencia(){
        return _frecuencia;
    }



    void set_nombre(const std::string& nombre){
        _nombre.set_contenido(nombre);
    }

    const Atributo<std::string>& get_nombre(){
        return _nombre;
    }

    void set_dni(const std::string& dni){
        _dni.set_contenido(dni);
    }
    const Atributo<std::string>& get_dni(){
        return _dni;
    }

    void set_sexo(const std::string& sexo){
        _sexo.set_contenido(sexo);
    }
    const Atributo<std::string>& get_sexo(){
        return _sexo;
    }

    void set_fecha_nacimiento(const std::string& fecha_nacimiento){
        _fecha_nacimiento.set_contenido(fecha_nacimiento);
    }

    const Atributo<std::string>& get_fecha_nacimiento(){
        return _fecha_nacimiento;
    }



  };

}


#endif
