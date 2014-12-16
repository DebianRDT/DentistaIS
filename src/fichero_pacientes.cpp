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
    _activo = _pacientes->begin();

    
  }

  FicheroPacientes::FicheroPacientes(std::list<Contacto*>* pacientes){

    _filename = "default.txt";

    _contactos = pacientes;
    _pacientes = _contactos; //alias de _contactos declarado en clase base
    _activo = _pacientes->begin();
    
  }


  FicheroPacientes::~FicheroPacientes(){}

  std::list<Contacto*>* FicheroPacientes::get(){
    return _pacientes;
  }



  /** Carga pacientes desde un fichero que no es el por defecto
   *
   */
  void FicheroPacientes::cargar_desde(const std::string& filename){
    std::string aux = _filename;
    _filename = filename;
    cargar();
    _filename = aux;

    //ordenar lista y guardar en fichero por defecto
    _pacientes->sort();
    _activo = _pacientes->begin();
    guardar();
  }

  /**  Borra el contenido previo de la lista 
   *   carga lista de contactos desde el
   *   fichero por defecto
   *   POR HACER: que devuelva iterador al nuevo primer elemento de la lista
   */
  std::list<Contacto*>::iterator FicheroPacientes::cargar(){
    Paciente* nuevo;
    std::string linea;
    char separador = ':';
    std::string titulo;
    std::string contenido;



    std::ifstream fichero;
    fichero.open(_filename.c_str());

    // si no abre el fichero, terminar
    if(!fichero)
      return _activo;


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
    _activo = _pacientes->begin();
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
      fichero<<p->get_apellido1().get_titulo()<<":"<<p->get_apellido1().get_contenido()<<std::endl;
      fichero<<p->get_apellido2().get_titulo()<<":"<<p->get_apellido2().get_contenido()<<std::endl;
      //fichero<<p->get_apellido2().get_titulo()<<":"<<p->get_apellido2().get_contenido()<<std::endl;
      //POR HACER resto de atributos
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
      fichero<<p->get_apellido1().get_titulo()<<":"<<p->get_apellido1().get_contenido()<<std::endl;
      fichero<<p->get_apellido2().get_titulo()<<":"<<p->get_apellido2().get_contenido()<<std::endl;
      fichero<<"---"<<std::endl;
    }
    
    fichero.close();
    
    return true;
  }


  bool FicheroPacientes::eliminar(){
    //POR HACER
    //Falta comprobar que se pueda eliminar s

    std::list<Contacto*>::iterator it_borrar = _activo;
    std::list<Contacto*>::iterator sig = _activo++;

    _pacientes->erase(it_borrar);

    return true;
  }
  
  bool FicheroPacientes::nuevo(Contacto* c){
    _pacientes->push_back(c);
  }

  Contacto* FicheroPacientes::activo(){
    return *_activo;
  }
  
  void FicheroPacientes::siguiente(){
    std::list<Contacto*>::iterator aux = _pacientes->begin();
    std::list<Contacto*>::iterator ultimo;

    while(aux!=_pacientes->end()) {
      ultimo=aux;
      ++aux;

    }

    if(ultimo != _activo)
      ++_activo;
    else{
      _activo = _pacientes->begin();
    }
   

  }

  void FicheroPacientes::anterior(){

    std::list<Contacto*>::iterator aux = _pacientes->begin();
    std::list<Contacto*>::iterator ultimo;

    
    if(_activo == _pacientes->begin()){

      while(aux!=_pacientes->end()) {
        ultimo=aux;
        ++aux;
      }

      _activo = ultimo;
      
    }
    else{
      _activo--;
    }
    

  }

  bool FicheroPacientes::vacia(){
    return _pacientes->empty();
  }


}
