/*
 * contacto.h
 *
 *  Created on: 07/12/2014
 *      Author: francisco
 */

#ifndef CONTACTO_H_
#define CONTACTO_H_

#include <string>
#include <list>
#include "atributo.h"



namespace agenda {



enum AM{Telefono,Nota,Direccion,RedSocial};


class Contacto {
private:

	std::list<Atributo<int>*> _atributos_multiples;


protected:
	Contacto();
public:

	virtual ~Contacto();

	bool add_atributo_multiple(Atributo<int>* am);
	bool del_atributo_multiple(int posicion);
	bool mod_atributo_multiple(Atributo<int>* am, int pos);
	const Atributo<int>* get_atributo_multiple(int posicion) const;

	inline int contar_atributos_multiples() const{
		return _atributos_multiples.size();
	}


	virtual std::ostream &operator<<(std::ostream &out) const = 0;

	/** sobrecargar operadores >= y < para ordenar contactos por
	 *  apellidos
	 */
	virtual bool operator ==(const Contacto& c) const = 0;
	virtual bool operator <(const Contacto& c) const = 0;
	virtual bool operator >=(const Contacto& c) const = 0;

};

} /* namespace agenda */
#endif /* CONTACTO_H_ */
