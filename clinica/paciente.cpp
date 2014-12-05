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

void Paciente::set_apellido1(const std::string& apellido1) {
    _apellido1=apellido1;
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
bool Paciente::agregar_atributo(const AtributoMultiple& nuevo){
    bool retorno;
    if(_atributos_multiples.add(AtributoMultiple)) {
        retorno=true;
    }
    else {
        retorno=false;
    }
    return retorno;
}


bool clinica::Paciente::es_favorito() {
	return false;
}

/** Saca de la lista el atributo multiple en la posicion n
 *
 */
bool Paciente::eliminar_atributo(int n){}



/** Un paciente es menor que otro cuando su <apellido1 apellido2> es inferior
 *  albafeticamente.
 */
bool Paciente::operator <(const Paciente &p1, const Paciente &p2) const{
    bool retorno;
    if (p1.get_apellido1()<p2.get_apellido1()) {
        retorno=true;
    }
    else {
        retorno=false;
    }
    return retorno;
}


/** Un paciente es mayor que otro cuando su <apellido1 apellido2> es superior
 *  albafeticamente. Igual cuando sus apellidos son iguales.
 */
bool Paciente::operator >(const Paciente &p1, const Paciente &p2) const{
    bool retorno;
    if (p1.get_apellido1() > p2.get_apellido1()) {
        retorno=true;
    }
    else {
        retorno=false;
    }
    return retorno;
}

bool Paciente::operator ==(const Paciente &p1, const Paciente &p2) const {
    bool retorno;
    if (p1.get_apellido1() == p2.get_apellido1()) {
        if (p1.get_apellido2() == p2.get_apellido2()) {
            if(p1.get_dni() == p2.get_dni()) {
                retorno=true;
            }
            else {
                retorno=false;
            }
        }
        else {
            retorno=false;
        }
    }
    else {
        retorno=false;
    }
    return retorno;
}
