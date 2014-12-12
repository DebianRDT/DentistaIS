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

	Atributo(){}
	Atributo(T contenido, const std::string& titulo);
	virtual ~Atributo();

	void set_titulo(const std::string& titulo);
	const std::string& get_titulo() const;

	void set_contenido(T contenido);
	T get_contenido();

	template<class F>
	friend std::ostream& operator<<(std::ostream& os, const Atributo<F>& a);


};

template<class F>
std::ostream& operator<<(std::ostream& os, const Atributo<F>& a){
  os<<a._titulo<<"\t"<<a._contenido;
  return os;
}

template<class T>
Atributo<T>::Atributo(T contenido, const std::string& titulo){
	_contenido = contenido;
	_titulo = titulo;
}

template<class T>
Atributo<T>::~Atributo(){}


/**
 *
 */
template<class T>
void Atributo<T>::set_titulo(const std::string& titulo){
  _titulo = titulo;
}

template<class T>
const std::string& Atributo<T>::get_titulo() const{
	return _titulo;
}



template<class T>
void Atributo<T>::set_contenido(T contenido){
  _contenido = contenido;
}

template<class T>
T Atributo<T>::get_contenido(){
  return _contenido;
}


}
#endif /*ATRIBUTO_H*/
