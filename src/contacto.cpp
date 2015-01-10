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

    std::list<Atributo*>::iterator it_borrar = _cursor;

    if(_atributos_multiples.size()==1){
      delete *_cursor;
      _atributos_multiples.pop_back();
      _cursor = _atributos_multiples.begin();
      
    }

    else if(!_atributos_multiples.empty()){
      delete * _cursor;
      _atributos_multiples.erase(it_borrar);
      _cursor = _atributos_multiples.begin();
    }

  }

  void Contacto::del_atributo_multiple(int p){
    _mover_cursor(p);
    del_atributo_multiple();
  }

  void Contacto::_mover_cursor(int p){
    //POR HACER validez de p
    _cursor = _atributos_multiples.begin();
    for(int i=0;i<p;i++){
      _cursor++;
    }
  }

  /** Cambia un atributo multiple situado en la posicion apuntada por _cursor
   */
  
  void Contacto::mod_atributo_multiple(Atributo *am){
 
    _atributos_multiples.erase(_cursor);
    _atributos_multiples.push_back(am);

    
  }
  

  /** Devuelve puntero a atributo apuntado por _cursor
   *  y modifica el cursor al siguiente. 
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
