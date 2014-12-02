/*
 * interfaz.h
 *
 *  Created on: 26/11/2014
 *      Author: francisco
 */

#ifndef INTERFAZ_H_
#define INTERFAZ_H_

#include "clinica/agenda.h"
using namespace clinica;

/**
 * Interfaz: Clase que interactua con el personal administrativo.
 */


class Interfaz{
private:
	Agenda* _la_agenda;
	static Interfaz* _app;
	inline Agenda* _LaAgenda(){
		return _la_agenda;
	}
protected:

	Interfaz();

public:
	static Interfaz* App();

	virtual ~Interfaz();

	void menu_contextual();
	void menu_gestionar_paciente();
	void menu_visualizar_pacientes();
	void menu_gestionar_pacientes();
	void menu_seleccionar_paciente();
};





#endif /* INTERFAZ_H_ */
