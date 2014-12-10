

/*
  * paciente.cpp
  *
  *  
  *      
  */
 
 #include "paciente.h"
 #include <list>
 using namespace clinica;
 
 /** Constructor
  *
  */
 Paciente::Paciente(){
 
 }
 
 /** Destructor
  *
  */
 Paciente::~Paciente(){}
 
const std::string& Paciente::get_apellido1()const{
	return _apellido1;
}

void Paciente::set_apellido1(const std::string& apellido1){
	_apellido1=apellido1;	
}

const std::string& Paciente::get_apellido2()const{
	return _apellido2;
}

void Paciente::set_apellido2(const std::string& apellido2){
	_apellido2=apellido2;
}

const std::string& Paciente::get_dni()const{
    return _dni;
}

void Paciente::set_dni(const std::string& dni){
	_dni=dni;
}

const std::string& Paciente::get_nombre()const{
    return _nombre;
}

void Paciente::set_nombre(const std::string& nombre){
	_nombre=nombre;
}


const std::string& Paciente::get_fecha_nacimiento()const{
    return _fecha_nacimiento;
}

void Paciente::set_fecha_nacimiento( const std::string& fecha_nacimiento){
	_fecha_nacimiento=fecha_nacimiento;
	
}
void Paciente::set_favorito(bool favorito){
	_favorito=favorito;
}

Sexo Paciente::get_sexo(){
	return _sexo;
}

void Paciente::set_sexo(Sexo sexo){
	_sexo=sexo;
}

int Paciente::get_frecuencia()const{
    return _frecuencia;}
}

void Paciente::set_frecuencia( int frecuencia){
	_frecuencia=frecuencia;
}

 /* Devuelve una lista con todos los atributos multiples
  * del paciente.
  */
 const std::list<AtributoMultiple*>& Paciente::lista_atributos_multiples(const TipoAt& t){}
 
 
 /** Cambia el atributo multiple en la posicion n, por el nuevo
  *
  */
 bool Paciente::cambiar_atributo(int n, const AtributoMultiple& nuevo){}
 
 
 /** Agrega atributo multiple al final de la lista
  *
  */
 bool Paciente::agregar_atributo(const AtributoMultiple& nuevo){}
 
 
 bool clinica::Paciente::es_favorito() {
 	return false;
 }
 
 /** Saca de la lista el atributo multiple en la posicion n
  *
  */
 bool Paciente::eliminar_atributo(int n){}
 
 
 
const std::string& Paciente::linea(){
/** Un paciente es menor que otro cuando su <apellido1 apellido2> es inferior
 *  albafeticamente.
 */
bool Paciente::operator <(const Paciente &p) const{}
 
	return "";
}

/** Un paciente es mayor que otro cuando su <apellido1 apellido2> es superior
 *  albafeticamente. Igual cuando sus apellidos son iguales.
 */
bool Paciente::operator >=(const Paciente &p) const{}


/*
 * paciente.cpp
 *
 *  Created on: 26/11/2014
 *      Author: francisco
 */




/** Constructor
 *
 */
Paciente::Paciente(){

}

/** Destructor
 *
 */
Paciente::~Paciente(){}

const std::string& Paciente::get_apellido1()const{
	return _apellido1;
}
const std::string& Paciente::get_apellido2()const{
	return _apellido2;
}




/* Devuelve una lista con todos los atributos multiples
 * del paciente.
 */
const std::list<AtributoMultiple*>& Paciente::lista_atributos_multiples(const TipoAt& t){}


/** Cambia el atributo multiple en la posicion n, por el nuevo
 *
 */
bool Paciente::cambiar_atributo(int n, const AtributoMultiple& nuevo){
  
  list<AtributoMultiple>::iterator pos;
  
  bool atributo;
  int i=0;
  for(pos=_atributos_multiples_.begin();pos!=_atributos_multiples_.end();pos++)
  {
     
     if(i==n-1)
      {
        *pos=nuevo;    
        atributo=true;
        return atributo;
      }

    i++; 
      
  }
  
  atributo=false; 

  return atributo;  
  
}


/** Agrega atributo multiple al final de la lista
 *
 */
bool Paciente::agregar_atributo(const AtributoMultiple& nuevo){}


bool clinica::Paciente::es_favorito() {

  return (_favorito);
}

/** Saca de la lista el atributo multiple en la posicion n
 *
 */
bool Paciente::eliminar_atributo(int n){}



/** Un paciente es menor que otro cuando su <apellido1 apellido2> es inferior
 *  albafeticamente.
 */
bool Paciente::operator <(const Paciente &p) const{}


/** Un paciente es mayor que otro cuando su <apellido1 apellido2> es superior
 *  albafeticamente. Igual cuando sus apellidos son iguales.
 */
bool Paciente::operator >=(const Paciente &p) const{}





const std::string& Paciente::get_apellido1()const{
	return _apellido1;
}
const std::string& Paciente::get_apellido2()const{
	return _apellido2;
}




/* Devuelve una lista con todos los atributos multiples
 * del paciente.
 */
const std::list<AtributoMultiple*>& Paciente::lista_atributos_multiples(const TipoAt& t){}


/** Cambia el atributo multiple en la posicion n, por el nuevo
 *
 */
bool Paciente::cambiar_atributo(int n, const AtributoMultiple& nuevo){




}


/** Agrega atributo multiple al final de la lista
 *
 */
bool Paciente::agregar_atributo(const AtributoMultiple& nuevo){}


bool clinica::Paciente::es_favorito() {
	return false;
}

/** Saca de la lista el atributo multiple en la posicion n
 *
 */
bool Paciente::eliminar_atributo(int n){
	
	bool atributo;
	if(_atributos_multiples.erase(n))	
	{
		atributo=true;
	}	
		
	else
	{ 
		atributo=false;
	}
	return atributo;
}



/** Un paciente es menor que otro cuando su <apellido1 apellido2> es inferior
 *  albafeticamente.
 */
bool Paciente::operator <(const Paciente &p) const{}


/** Un paciente es mayor que otro cuando su <apellido1 apellido2> es superior
 *  albafeticamente. Igual cuando sus apellidos son iguales.
 */
bool Paciente::operator >=(const Paciente &p) const{}
/*
 * paciente.cpp
 *
 *  Created on: 26/11/2014
 *      Author: francisco
 */

#include "paciente.h"
#include <list>
using namespace clinica;

/** Constructor
 *
 */
Paciente::Paciente(){

}

/** Destructor
 *
 */
Paciente::~Paciente(){}

const std::string& Paciente::get_apellido1()const{
	return _apellido1;
}
const std::string& Paciente::get_apellido2()const{
	return _apellido2;
}




/* Devuelve una lista con todos los atributos multiples
 * del paciente.
 */
const std::list<AtributoMultiple*>& Paciente::lista_atributos_multiples(const TipoAt& t){}


/** Cambia el atributo multiple en la posicion n, por el nuevo
 *
 */
bool Paciente::cambiar_atributo(int n, const AtributoMultiple& nuevo){
  
  list<AtributoMultiple>::iterator pos;
  
  bool atributo;
  int i=0;
  for(pos=_atributos_multiples_.begin();pos!=_atributos_multiples_.end();pos++)
  {
     
     if(i==n-1)
      {
        *pos=nuevo;    
        atributo=true;
        return atributo;
      }

    i++; 
      
  }
  
  atributo=false; 

  return atributo;  
  
}


/** Agrega atributo multiple al final de la lista
 *
 */
bool Paciente::agregar_atributo(const AtributoMultiple& nuevo){}


bool clinica::Paciente::es_favorito() {

  return (_favorito);
}

/** Saca de la lista el atributo multiple en la posicion n
 *
 */
bool Paciente::eliminar_atributo(int n){}



/** Un paciente es menor que otro cuando su <apellido1 apellido2> es inferior
 *  albafeticamente.
 */
bool Paciente::operator <(const Paciente &p) const{}


/** Un paciente es mayor que otro cuando su <apellido1 apellido2> es superior
 *  albafeticamente. Igual cuando sus apellidos son iguales.
 */
bool Paciente::operator >=(const Paciente &p) const{}

