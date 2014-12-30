/** Clase Atributo
 *  Representa atributos que pueden componer un contacto.
 */

#ifndef ATRIBUTO_H
#define ATRIBUTO_H

#include <string>
#include <iostream>

namespace agenda{

class Atributo{
private:

  std::string _contenido;
  std::string _titulo;
  
public:
  
  Atributo();
  Atributo(const std::string& contenido, const std::string& titulo);
  virtual ~Atributo();
  
  void set_titulo(const std::string& titulo);
  const std::string& get_titulo() const;
  
  void set_contenido(const std::string& contenido);
  const std::string& get_contenido() const;
  
  friend std::ostream& operator<<(std::ostream& os, const Atributo& a);
	
  bool operator==(const Atributo& a);
  bool operator<(const Atributo& a);
  



};


/** sobrecarga <<
 *  describe como deben imprimirse los atributos
 */


inline std::ostream& operator<<(std::ostream& os, const Atributo& a){
  os<<a._titulo<<"\t"<<a._contenido;
  return os;
}

 

 
}
#endif /*ATRIBUTO_H*/
