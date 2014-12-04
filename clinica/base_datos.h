/*
 * base_datos.h
 *
 */

#ifndef CLINICA_BASE_DATOS_H_
#define CLINICA_BASE_DATOS_H_

#include <list>
#include "paciente.h"

namespace clinica {

class BaseDatos {
public:
	BaseDatos();
	virtual ~BaseDatos();

	/** Redefinir metodos segun tipo de base de datos
	 */

	virtual std::list<Paciente*> cargar()=0;
	virtual std::list<Paciente*> cargar_desde(std::string n_fichero)=0;

	virtual bool guardar()=0;
	virtual bool guardar_en(std::string n_fichero)=0;
};

} /* namespace clinica */

#endif /* CLINICA_BASE_DATOS_H_ */
