/*
 * base_datos_texto.h
 *
 *  Created on: 4/12/2014
 *      Author: francisco
 */

#ifndef CLINICA_BASE_DATOS_TEXTO_H_
#define CLINICA_BASE_DATOS_TEXTO_H_

#include <string>
#include <list>
#include "base_datos.h"
#include "paciente.h"

namespace clinica {

class BaseDatosTexto: public BaseDatos {
public:
	BaseDatosTexto();
	virtual ~BaseDatosTexto();

	std::list<Paciente*> cargar();
	std::list<Paciente*> cargar_desde(std::string n_fichero);

	bool guardar();
	bool guardar_en(std::string n_fichero);
};

} /* namespace clinica */

#endif /* CLINICA_BASE_DATOS_TEXTO_H_ */
