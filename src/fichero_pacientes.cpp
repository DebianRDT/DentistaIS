#include "fichero_pacientes.h"
#include "atributo.h"
#include "contacto.h"
#include "paciente.h"

#include <list>
#include <cstring>
#include <cstdlib> //atoi
#include <fstream>
#include <iostream>
#include <sstream>

namespace agenda{


  Fichero::Fichero(){
    _filename = "default.txt";
  }

  Fichero::~Fichero(){}

  /**  Devuelve lista de contactos en el
   *   fichero por defecto.
   */
  std::list<Contacto*>* Fichero::cargar(){
    std::list<Contacto*>* pacientes = new std::list<Contacto*>();

    Paciente* nuevo;

    std::string linea;
    char separador = ':';


    std::string titulo;
    std::string contenido;

    //POR HACER: CARGA PACIENTES DESDE EL FICHERO
    //pacientes.push_back(new Paciente());

    std::ifstream fichero;
    fichero.open(_filename.c_str());

    if(!fichero)
      return pacientes;


    while(!fichero.eof()){

      std::getline(fichero,linea);
      std::istringstream split(linea);




      //inicio paciente
      if(linea=="***"){
        nuevo = new Paciente();
      }

      //fin paciente
      else if(linea=="---"){
        pacientes->push_back(nuevo);
      }

      //interpretar atributo
      else{
        std::getline(split,titulo,separador);
        std::getline(split,contenido,separador);

        // frecuencia
        if(titulo=="FRECUENCIA"){
          nuevo->set_frecuencia(atoi(contenido.c_str()));
        }

        // favorito
        else if(titulo=="FAVORITO"){
          if(atoi(contenido.c_str())==0)
            nuevo->reset_favorito();
          else
            nuevo->set_favorito();
        }

        // apellido1
        else if(titulo=="APELLIDO 1"){
          nuevo->set_apellido1(contenido);
        }

        // apellido2
        else if(titulo=="APELLIDO 2"){
          nuevo->set_apellido2(contenido);
        }


      }
    }


    return pacientes;

  }

}
