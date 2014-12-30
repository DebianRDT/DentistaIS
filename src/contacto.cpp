#include "contacto.h"
#include <list>
#include <string>


namespace agenda {

  /** Constructor
   */
  Contacto::Contacto() {
    _cursor = _atributos_multiples.begin();
  }

  /** Destructor
   *  Limpia la memoria de la lista de atributos multiples _atributos_multiples
   */
  Contacto::~Contacto() {
    // POR HACER

  }

  void Contacto::add_atributo_multiple(Atributo* am){
    _atributos_multiples.insert(_cursor,am);
    ++_cursor;
  }
  


  /** Elimina el atributo multiple apuntado por cursor
   */
  void Contacto::del_atributo_multiple(){

    if(!_atributos_multiples.empty()){
      _atributos_multiples.erase(_cursor);
      --_cursor;
    }

  }

  /** Cambia un atributo multiple situado en la posicion apuntada por _cursor
   */
  
  void Contacto::mod_atributo_multiple(Atributo *am){
 
    _atributos_multiples.erase(_cursor);
    _atributos_multiples.push_back(am);

    
  }
  


  Atributo* Contacto::get_atributo_multiple(){
    
    return *_cursor;
  }
  

} /* namespace agenda */
