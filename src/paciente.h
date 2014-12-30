#ifndef PACIENTE_H
#define PACIENTE_H

#include <sstream>
#include <iostream>
#include "contacto.h"
#include "atributo.h"

#include "fechas.h"

namespace agenda{

  class Paciente:public Contacto{
  private:
    Atributo _apellido1;
    Atributo _apellido2;
    Atributo _frecuencia;
    Atributo _favorito;

    Atributo _nombre;
    Atributo _dni;
    Atributo _fecha_nacimiento;
    Atributo _sexo;

    void _print(std::ostream& o) const;


  public:


    void set_favorito();
    void reset_favorito();
    bool es_favorito();

    Paciente(const std::string& apellido1, const std::string& apellido2);
    Paciente();
    virtual ~Paciente();


    /* obligatorias */

    bool operator ==(Contacto* c);
    bool operator <(Contacto* c);


    /* metodos para gestionar atributos multiples */

    void add_telefono(const std::string& telefono);
    bool get_telefono(int pos, const std::string* t);

    void add_nota(const std::string& nota);
    bool get_nota(int pos, const std::string* nota);

    void add_direccion(const std::string& direccion);
    void add_red_social(const std::string& red_social);


    /* GETTERS Y SETTERS */

    void set_apellido1(const std::string& a1){
        _apellido1.set_contenido(a1);
    }

    const Atributo& get_apellido1(){
      return _apellido1;
    }

    void set_apellido2(const std::string& a2){
      _apellido2.set_contenido(a2);
    }

    const Atributo& get_apellido2(){
      return _apellido2;
    }

    void set_frecuencia(const std::string& frecuencia){
      _frecuencia.set_contenido(frecuencia);
    }


    /** devuelve un entero que indica la frecuencia de accesos
     *  del paciente
     */
    int get_frecuencia(){
      std::istringstream buffer(_frecuencia.get_contenido());
      int frecuencia;
      buffer >> frecuencia;
      return frecuencia;
    }



    void set_nombre(const std::string& nombre){
        _nombre.set_contenido(nombre);
    }

    const Atributo& get_nombre(){
        return _nombre;
    }

    void set_dni(const std::string& dni){
        _dni.set_contenido(dni);
    }
    const Atributo& get_dni(){
        return _dni;
    }

    void set_sexo(const std::string& sexo){
        _sexo.set_contenido(sexo);
    }
    const Atributo& get_sexo(){
        return _sexo;
    }

    inline void set_fecha_nacimiento(const Fecha& f){
      std::string fecha = f.getFecha();
      _fecha_nacimiento.set_contenido(fecha);
    }

    inline const std::string& get_fecha_nacimiento(){
      return _fecha_nacimiento.get_contenido();
    }



  };

}


#endif
