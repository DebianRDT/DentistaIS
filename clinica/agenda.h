#ifndef AGENDA_H
#define AGENDA_H

#include "paciente.h"
#include "base_datos.h"

#include <string>
#include <list>


namespace clinica{

typedef struct{
	int i;
} Orden;

typedef struct{
	std::list<Paciente*>::iterator it_paciente;
}Candidato;

/**
 * Clase Agenda
 * Gestiona pacientes en un fichero
 * patron Singleton
 */


class Agenda{
private:
	static Agenda* _la_agenda; //!< instancia unica de agenda

	std::list<Paciente*> _todos; //!< Lista ordenada por apellidos de todos los pacientes
	std::list<Paciente*> _favoritos;
	std::list<Paciente*>::iterator _seleccionado;
	BaseDatos* _bd;

	int _n; //!< Numero de pacientes en la lista

protected:
	Agenda(BaseDatos* bd);


public:
	static Agenda* LaAgenda(BaseDatos* bd);
	virtual ~Agenda();

	bool agregar(Paciente* nuevo);
	bool buscar(const std::string& apellido1, const std::string& apellido2);
	const std::list<Paciente*>& todos(const Orden& o);
	const std::list<Paciente*>& favoritos();

	/* actuan sobre el paciente seleccionado (_seleccionado) */
	bool siguiente();
	bool anterior();
	Paciente* obtener();
	bool eliminar();

};

}

#endif
