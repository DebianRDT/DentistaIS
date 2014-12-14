/** Clase Atributo<T> (Plantilla)
 *  Representa atributos que pueden componer un contacto.
 */

#ifndef ATRIBUTO_H
#define ATRIBUTO_H

#include <string>
#include <iostream>

namespace agenda{

template<class T>
class Atributo{
private:

	T _contenido;
	std::string _titulo;

public:

	Atributo();
	Atributo(T contenido, const std::string& titulo);
	virtual ~Atributo();

	void set_titulo(const std::string& titulo);
	const std::string& get_titulo() const;

	void set_contenido(const T& contenido);
	T get_contenido() const;

	template<class F>
	friend std::ostream& operator<<(std::ostream& os, const Atributo<F>& a);



	bool operator==(const Atributo<T>& a);
	bool operator>(const Atributo<T>& a);
	bool operator<(const Atributo<T>& a);
	bool operator<=(const Atributo<T>& a);
	bool operator>=(const Atributo<T>& a);


};

/** sobrecarga <<
 *  describe como deben imprimirse los atributos
 */
template<class F>
std::ostream& operator<<(std::ostream& os, const Atributo<F>& a){
  os<<a._titulo<<"\t"<<a._contenido;
  return os;
}


/** Constructor
 */
template<class T>
Atributo<T>::Atributo(){}

/** Constructor
 */
template<class T>
Atributo<T>::Atributo(T contenido, const std::string& titulo){
	_contenido = contenido;
	_titulo = titulo;
}


/** Destructor
 */
template<class T>
Atributo<T>::~Atributo(){
  //POR HACER
}


/** Pone el titulo que indiquemos por parametro
 *
 */
template<class T>
void Atributo<T>::set_titulo(const std::string& titulo){
  _titulo = titulo;
}

/** Devuelve el titulo del atributo
 */
template<class T>
const std::string& Atributo<T>::get_titulo() const{
	return _titulo;
}

/** Pone el contenido del atributo que indiquemos por parametro
 */
template<class T>
void Atributo<T>::set_contenido(const T& contenido){
  _contenido = contenido;
}


/** Devuelve el contenido del atributo
 */
template<class T>
T Atributo<T>::get_contenido() const{
  return _contenido;
}


 /** Sobrecargar operadores de comparacion
  *  > < >= <= ==
  */


 template<class T>
 bool Atributo<T>::operator==(const Atributo<T>& a){
   return _contenido == a._contenido;
 }

 template<class T>
 bool Atributo<T>::operator>(const Atributo<T>& a){
   // POR HACER
   return _contenido > a._contenido;
 }

 template<class T>
 bool Atributo<T>::operator<(const Atributo<T>& a){
   // POR HACER
 	return _contenido < a._contenido;
 }

 template<class T>
 bool Atributo<T>::operator<=(const Atributo<T>& a){
   
   return _contenido <= a._contenido;
 }
 
 template<class T>
 bool Atributo<T>::operator>=(const Atributo<T>& a){
   // POR HACER
   return _contenido >= a._contenido;
 }
}
#endif /*ATRIBUTO_H*/
