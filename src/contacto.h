/** Clase Contacto (Abstracta) 
 *  Es la interfaz para todos los contactos con 
 *  los que trabajara la agenda.
 *
 */

#ifndef CONTACTO_H_
#define CONTACTO_H_

#include <string>
#include <list>
#include "atributo.h"



namespace agenda {



  enum AM{Telefono,Nota,Direccion,RedSocial};


  class Contacto {
  private:

    //interfaz imprimir las clases derivadas
    virtual void _print(std::ostream&) const = 0;

  protected:
    Contacto();
    std::list< Atributo* > _atributos_multiples;
    std::list<Atributo*>::iterator _cursor;

  public:

    virtual ~Contacto();

    void add_atributo_multiple(Atributo *am);
    void mod_atributo_multiple(Atributo *am);
    void del_atributo_multiple();
    Atributo* get_atributo_multiple();

    
    inline int contar_atributos_multiples() const{
      return _atributos_multiples.size();
    }
    
    
    friend std::ostream& operator<<(std::ostream &out, const Contacto& c){
      c._print(out);
      return out;
    }

    /** sobrecargar operadores >= y < para ordenar contactos por
     *  apellidos
     */
    virtual bool operator ==(Contacto* c) = 0;
    virtual bool operator <(Contacto* c) = 0;
    
    
  };
  
} /* namespace agenda */
#endif /* CONTACTO_H_ */
