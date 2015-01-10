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



  class Contacto {
  private:

    //interfaz imprimir las clases derivadas
    virtual void _print(std::ostream& o) = 0;
    void _mover_cursor(int p);


  protected:
    Contacto();
    std::list< Atributo* > _atributos_multiples;
    std::list<Atributo*>::iterator _cursor;

  public:

    virtual ~Contacto();


    /*metodos para gestion de atributos multiples*/
    void add_atributo_multiple(Atributo *am);
    void mod_atributo_multiple(Atributo *am);
    void del_atributo_multiple();
    void del_atributo_multiple(int p);
    Atributo* get_atributo_multiple();
    bool es_ultimo();

    
    inline int contar_atributos_multiples() const{
      return _atributos_multiples.size();
    }
    
    /* Pone el cursor al principio de la lista de atributos multiples */
    inline void reset_cursor(){
      _cursor = _atributos_multiples.begin();
    }
    
    friend std::ostream& operator<<(std::ostream &out, Contacto& c){
      c._print(out);
      return out;

    }
    /** sobrecargar operadores >= y < para ordenar contactos por
     *  apellidos
     */
    virtual bool operator ==(Contacto* c) = 0;
    virtual bool operator <(Contacto* c) = 0;

    virtual bool es_favorito() = 0;
    virtual void set_favorito() = 0;
    virtual void reset_favorito() = 0;
    virtual int get_frecuencia() = 0;
    virtual const Atributo& get_apellido1() = 0;
    virtual const Atributo& get_apellido2() = 0;
    
    
  };
  



} /* namespace agenda */
#endif /* CONTACTO_H_ */
