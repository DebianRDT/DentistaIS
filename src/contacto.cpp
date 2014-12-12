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

  bool Contacto::add_atributo_multiple(Atributo<int>* am){
    // POR HACER
    // en lugar de recibir Atributo<int>* debe recibir
    // el tipo enum AM{Telefono,Nota,...}

    return true;
  }

  /** Elimina el atributo multiple situado en la posicion introducia
   *  por parametro si esta posicion existe en la lista. En caso negativo
   *  devuelve false
   */
  bool Contacto::del_atributo_multiple(int posicion){
    // POR HACER

    return false;
  }

  /** Cambia un atributo multiple situado en la posicion pos por otro
   *  si la posicion indicada no existe devuelve false.
   */
  bool Contacto::mod_atributo_multiple(Atributo<int>* am, int pos){
    // POR HACER
    return false;
  }


  /** Para obtener un atributo multiple en una posicion determinada
   *  en el parametro p. Si la posicion existe, se almacena el atributo
   *  en am y devuelve true. Si no existe la posicion devuelve false.
   */
  bool Contacto::get_atributo_multiple(int p,Atributo<int>* am){
    // POR HACER


    return false;
  }
  
} /* namespace agenda */
