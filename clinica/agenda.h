#ifndef AGENDA_H
#define AGENDA_H

#include "paciente.h"
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
 * Sólo será necesaria una instancia por lo que usamos
 * patrón Singleton
 */
class Agenda{
private:
	static Agenda* _la_agenda; //!< instancia unica de agenda

	static char _n_fichero[10];
	std::list<Paciente*> _todos; //!< Lista ordenada por apellidos de todos los pacientes
	std::list<Paciente*>::iterator _seleccionado;
	int _n; //!< Numero de pacientes en la lista

protected:
	Agenda();


public:
	static Agenda* LaAgenda();
	virtual ~Agenda();


	std::list<const Candidato*> buscar_paciente(const std::string& apellidos);

	bool seleccionar_paciente(const std::list<Paciente*>& candidatos, int elegido);
	const Paciente& ver_detalles();
	std::list<AtributoMultiple*> obtener_atributos_multiples();
	std::list<AtributoMultiple*> obtener_atributos_multiples(const TipoAt& tipo);
	bool modificar_atributo(const AtributoMultiple& nuevo, int n);
	bool eliminar_paciente();

	bool nuevo_paciente(const Paciente& nuevo);
	std::list<Paciente*> get_favoritos();
	std::list<Paciente*> get_todos(const Orden& o);


	bool reordernar_fichero();


	/* métodos que no están en el diagrama de clases */
	const Paciente& siguiente();
	const Paciente& ir_a(const std::list<Paciente*>::iterator& it);


};

}

#endif
