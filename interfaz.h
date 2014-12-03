/*
 * interfaz.h
 *
 *
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


	void _menu_contextual();
	void _menu_gestionar_paciente();
	void _menu_visualizar_pacientes();
	void _menu_gestionar_pacientes();
	void _menu_seleccionar_paciente();



protected:

	Interfaz();

public:
	static Interfaz* App();
	virtual ~Interfaz();


};





#endif /* INTERFAZ_H_ */
