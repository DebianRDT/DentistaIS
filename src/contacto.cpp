#include "contacto.h"
#include <list>
#include <string>


namespace agenda {

  /** Constructor
   */
  Contacto::Contacto() { }

  /** Destructor
   *  Limpia la memoria de la lista de atributos multiples _atributos_multiples
   */
  Contacto::~Contacto() {
    // POR HACER

  }

  bool Contacto::add_atributo_multiple(Atributo<AM>* am){


    _atributos_multiples.push_back(am);
    // POR HACER
    // comprobar que se inserto correctamente

    return true;
  }

  /** Elimina el atributo multiple situado en la posicion introducia
   *  por parametro si esta posicion existe en la lista. En caso negativo
   *  devuelve false
   */
  bool Contacto::del_atributo_multiple(int posicion){
    std::list< Atributo<AM>* >::iterator it = _atributos_multiples.begin();
    for(int i=1;i<posicion;i++){
      if(it!=_atributos_multiples.end())
        it++;
      else
        return false;
    }

    // cuando sale del bucle, el iterador esta en la posicion indicada
    // por posicion
    _atributos_multiples.erase(it);

    return true;
  }

  /** Cambia un atributo multiple situado en la posicion pos por otro
   *  si la posicion indicada no existe devuelve false.
   */
  bool Contacto::mod_atributo_multiple(Atributo<AM>* am, int posicion){
    std::list< Atributo<AM>* >::iterator it = _atributos_multiples.begin();
    for(int i=1;i<posicion;i++){
      if(it!=_atributos_multiples.end())
        it++;
      else
        return false;
    }

    // cuando sale del bucle, el iterador esta en la posicion indicada
    // por posicion
    _atributos_multiples.erase(it);

    _atributos_multiples.push_back(am);

    return true;
  }


  /** Para obtener un atributo multiple en una posicion determinada
   *  en el parametro p. Si la posicion existe, se almacena el atributo
   *  en am y devuelve true. Si no existe la posicion devuelve false.
   */
  bool Contacto::get_atributo_multiple(int posicion,Atributo<AM>* am){
    // POR HACER
    std::list< Atributo<AM>* >::iterator it = _atributos_multiples.begin();
    for(int i=1;i<posicion;i++){
      if(it!=_atributos_multiples.end())
        it++;
      else
        return false;
    }

    // cuando sale del bucle, el iterador esta en la posicion indicada
    // por posicion
    am = (*it);

    return true;
  }
  
} /* namespace agenda */
