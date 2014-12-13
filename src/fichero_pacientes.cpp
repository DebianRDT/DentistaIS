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


  FicheroPacientes::FicheroPacientes(){
    _filename = "default.txt";
    _pacientes = new std::list<Contacto*>;
  }

  FicheroPacientes::FicheroPacientes(std::list<Contacto*>* pacientes){

    _filename = "default.txt";

    _contactos = pacientes;
    _pacientes = _contactos; //alias de _contactos declarado en clase base

    
  }


  FicheroPacientes::~FicheroPacientes(){}

  std::list<Contacto*>* FicheroPacientes::get(){
    return _pacientes;
  }



  /** Carga pacientes desde un fichero que no es el por defecto
   */
  void FicheroPacientes::cargar_desde(const std::string& filename){
    std::string aux = _filename;
    _filename = filename;
    cargar();
    _filename = aux;
  }

  /**  Borra el contenido previo de la lista 
   *   carga lista de contactos desde el
   *   fichero por defecto
   *   POR HACER: que devuelva true/false
   */
  void FicheroPacientes::cargar(){
    Paciente* nuevo;
    std::string linea;
    char separador = ':';
    std::string titulo;
    std::string contenido;


    //vaciar lista de pacientes
    while(!_pacientes->empty()){
      delete _pacientes->front();
      _pacientes->pop_front();
    }


    std::ifstream fichero;
    fichero.open(_filename.c_str());

    // si no abre el fichero, terminar
    if(!fichero)
      return;


    while(!fichero.eof()){

      std::getline(fichero,linea);
      std::istringstream split(linea);

      //inicio paciente
      if(linea=="***"){
        nuevo = new Paciente();
      }

      //fin paciente
      else if(linea=="---"){
        _pacientes->push_back(nuevo);
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

    }/*end while*/

    fichero.close();

  }


  /** Guardar contactos en la lista al final del fichero por defecto
   */
  bool FicheroPacientes::guardar(){

    Paciente* p;

    if(_pacientes->empty())
      return true;
    
    std::ofstream fichero;
    fichero.open(_filename.c_str());
    
    if(!fichero.is_open())
      return false;
    
    for(std::list<Contacto*>::iterator it=_pacientes->begin();it!=_pacientes->end();it++){
      p = static_cast<Paciente*>(*(it)); //cast de Contacto* a Paciente*

      fichero<<"***"<<std::endl;
      fichero<<p<<std::endl;
      fichero<<"---"<<std::endl;
    }
    

    fichero.close();
    
    return true;
}

  /** Guardar pacientes en un fichero especificado
   */
  bool FicheroPacientes::guardar_como(const std::string& filename){

    Paciente* p;

    if(_pacientes->empty())
      return true;
    
    std::ofstream fichero;
    fichero.open(filename.c_str());
    
    if(!fichero.is_open())
      return false;
    
    for(std::list<Contacto*>::iterator it=_pacientes->begin();it!=_pacientes->end();it++){
      p = static_cast<Paciente*>(*(it)); //cast de Contacto* a Paciente*

      fichero<<"***"<<std::endl;
      fichero<<*p<<std::endl;
      fichero<<"---"<<std::endl;
    }
    

    fichero.close();
    
    return true;
    

  }

}
