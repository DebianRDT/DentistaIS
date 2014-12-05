/*
 * base_datos_texto.cpp
 *
 */

#include "base_datos_texto.h"

namespace clinica {

BaseDatosTexto::BaseDatosTexto() {
	// TODO Auto-generated constructor stub

}

BaseDatosTexto::~BaseDatosTexto() {
	// TODO Auto-generated destructor stub
}

std::list<Paciente*> BaseDatosTexto::cargar() {
}

std::list<Paciente*> BaseDatosTexto::cargar_desde(std::string n_fichero) {
}

bool BaseDatosTexto::guardar() {
    char * nombreFichero="datosAlmacenados.txt";
    ofstream fichero (nombreFichero);

    list<Paciente*>::iterator i;
    for(i=_todos.begin(); i!=_todos.end(); i++) {
        fichero<<(*i).get_dni();
        fichero<<",";
        fichero<<(*i).get_apellido1();
        fichero<<",";
        fichero<<(*i).get_apellido2();
        fichero<<",";
        fichero<<(*i).get_nombre();
        fichero<<",";
        fichero<<(*i).get_fecha_nacimiento();
        fichero<<",";
        fichero<<(*i).get_sexo();
        fichero<<",";
        fichero<<(*i).get_frecuencia;
        list<AtributoMultiple*>::iterator j;
        for(j=_atributos_multiples.begin(); j != _atributos_multiples.end(); j++) {
            fichero<<(*j).tipo;
            fichero<<"(";
            fichero<<(*j).contenido;
            fichero<<")";
        }
        fichero<<endl;
    }
    fichero.close();
}

bool BaseDatosTexto::guardar_en(std::string n_fichero) {
}

} /* namespace clinica */
