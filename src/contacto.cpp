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
    
    _atributos_multiples.push_front(am);
    _cursor = _atributos_multiples.begin();
    

  }
  


  /** Elimina el atributo multiple apuntado por cursor
   */
  void Contacto::del_atributo_multiple(){

    if(_atributos_multiples.size()==1){
      _atributos_multiples.pop_back();
      _cursor = _atributos_multiples.begin();
      return;
    }

    if(!_atributos_multiples.empty()){
      _atributos_multiples.erase(_cursor);
      _cursor = _atributos_multiples.begin();
    }

  }

  /** Cambia un atributo multiple situado en la posicion apuntada por _cursor
   */
  
  void Contacto::mod_atributo_multiple(Atributo *am){
 
    _atributos_multiples.erase(_cursor);
    _atributos_multiples.push_back(am);

    
  }
  

  /** Devuelve puntero a atributo apuntado por _cursor
   *  y modifica el cursor al siguiente. Si es el ultimo elemento,
   *  el cursor pasara a apuntar al primer elemento de la lista
   */
  Atributo* Contacto::get_atributo_multiple(){
    if(_atributos_multiples.empty())
      return NULL;


    std::list<Atributo*>::iterator prev = _cursor;
    
    ++_cursor;

    return *prev;
  }


  /** Devuelve true si el _cursor apunta al ultimo elemento de la
   *  lista de atributos multiples. False en caso contrario.
   *  Si apunta al ultimo elemento lo cambia para que apunte al primero.
   */
  bool Contacto::es_ultimo(){
    if(_cursor == _atributos_multiples.end()){
      _cursor = _atributos_multiples.begin();

      return true;
    }
    else{
      return false;
    }
  }
  

} /* namespace agenda */
