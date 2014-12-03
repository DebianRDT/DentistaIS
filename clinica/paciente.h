/*
 * paciente.h
 *
 */

#ifndef CLINICA_PACIENTE_H_
#define CLINICA_PACIENTE_H_

#include <string>
#include <list>

namespace clinica{


enum class TipoAt{Telefono,Direccion,RedSocial,Nota};

typedef struct{
	TipoAt tipo;
	std::string contenido;
} AtributoMultiple;

enum class Sexo {Hombre,Mujer};

class Paciente{
private:
	std::list<AtributoMultiple*> _atributos_multiples;

	std::string _dni;
	std::string _nombre;
	std::string _apellido1;
	std::string _apellido2;
	bool _favorito;
	std::string _fecha_nacimiento;
	Sexo _sexo;
	int _frecuencia;


public:

	Paciente();
	virtual ~Paciente();

	/* falta constructor de copia */


	const std::string& str();
	bool es_favorito();

	/* faltan metodos get y set */

	/* atributos multiples */
	const std::list<AtributoMultiple*>& lista_atributos_multiples(const TipoAt& t);
	bool agregar_atributo(const AtributoMultiple& nuevo);
	bool cambiar_atributo(int n, const AtributoMultiple& nuevo);
	bool eliminar_atributo(int n);
};

}




#endif /* CLINICA_PACIENTE_H_ */
