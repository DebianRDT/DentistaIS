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

	const std::string& str();
	bool es_favorito();

	/* atributos multiples */
	const std::list<AtributoMultiple*>& lista_atributos_multiples(const TipoAt& t);
	bool agregar_atributo(const AtributoMultiple& nuevo);
	bool cambiar_atributo(int n, const AtributoMultiple& nuevo);
	bool eliminar_atributo(int n);

	/* sobrecarga operadores para ordenar por apellidos */
	bool operator <(const Paciente &p) const;
	bool operator >=(const Paciente &p) const;

	/*getters y setters */
	const std::string& get_apellido1() const;
	void set_apellido1(const std::string& apellido1);
	const std::string& get_apellido2() const;
	void set_apellido2(const std::string& apellido2);
	const std::list<AtributoMultiple*>& get_atributos_multiples() const;
	void set_atributos_multiples(const std::list<AtributoMultiple*>& atributos_multiples);
	const std::string& get_dni() const;
	void set_dni(const std::string& dni);
	void set_favorito(bool favorito);
	const std::string& get_fecha_nacimiento() const;
	void set_fecha_nacimiento(const std::string& fecha_nacimiento);
	int get_frecuencia() const;
	void set_frecuencia(int frecuencia);
	const std::string& get_nombre() const;
	void set_nombre(const std::string& nombre);
	Sexo get_sexo() const;
	void set_sexo(Sexo sexo);
};

}




#endif /* CLINICA_PACIENTE_H_ */
