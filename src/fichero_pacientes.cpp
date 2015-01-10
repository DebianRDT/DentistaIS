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

  FicheroPacientes::~FicheroPacientes(){
    std::list<Contacto*>::iterator act;
    
    act = _pacientes->begin();
   
    
    while(!_pacientes->empty()){
      delete *act;
      _pacientes->pop_front();
      act = _pacientes->begin();
    }
    
    
  }


  FicheroPacientes::FicheroPacientes(std::list<Contacto*>* pacientes){

    _filename = "default.txt";

    _contactos = pacientes;
    _pacientes = _contactos; //alias de _contactos declarado en clase base
    _activo = _pacientes->begin();

  }




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
    _pacientes->sort(Paciente::cmp_apellidos);
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
          nuevo->set_frecuencia(contenido);
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

	// nombre
        else if(titulo=="NOMBRE"){
          nuevo->set_nombre(contenido);
        }

	// sexo
        else if(titulo=="SEXO"){
          nuevo->set_sexo(contenido);
        }

	// fecha nacimiento
        else if(titulo=="FECHA NACIMIENTO"){
          nuevo->set_fecha_nacimiento(contenido);
        }

	// ATRIBUTOS MULTIPLES

	// nota
        else if(titulo=="NOTA"){
         nuevo->add_nota(contenido);
       }

	// telefono
       else if(titulo=="TELEFONO"){
         nuevo->add_telefono(contenido);
       }

	// direccion
       else if(titulo=="DIRECCION"){
         nuevo->add_direccion(contenido);
       }

	// red social
       else if(titulo=="RED SOCIAL"){
         nuevo->add_nota(contenido);
       }
     }

    }/*end while*/

     fichero.close();
     _pacientes->sort(Paciente::cmp_apellidos); //reordenar, puede que el fichero estubiera desordenado.

     _activo = _pacientes->begin();
   }

  /** Guardar contactos en la lista al final del fichero por defecto
   */
   bool FicheroPacientes::guardar(){

    Paciente* p;
    Atributo* am;
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

      fichero<<"FRECUENCIA:"<<p->get_frecuencia()<<std::endl;
      fichero<<"FAVORITO:"<<p->get_favorito()<<std::endl;

      fichero<<p->get_sexo().get_titulo()<<":"<<p->get_sexo().get_contenido()<<std::endl;
      fichero<<p->get_nombre().get_titulo()<<":"<<p->get_nombre().get_contenido()<<std::endl;
      fichero<<"FECHA NACIMIENTO:"<<p->get_fecha_nacimiento()<<std::endl;


      p->reset_cursor();
      while(!p->es_ultimo()){
        am = p->get_atributo_multiple();
        fichero<<am->get_titulo()<<":"<<am->get_contenido()<<std::endl;
      };


      fichero<<"---"<<std::endl;
    }


    fichero.close();

    return true;
  }

  /** Guardar pacientes en un fichero especificado
   */
  bool FicheroPacientes::guardar_como(const std::string& filename){

    Paciente* p;
    Atributo* am;

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

      fichero<<"FRECUENCIA:"<<p->get_frecuencia()<<std::endl;
      fichero<<"FAVORITO:"<<p->get_favorito()<<std::endl;
      fichero<<"NOMBRE:"<<p->get_nombre()<<std::endl;
      fichero<<"FECHA NACIMIENTO:"<<p->get_fecha_nacimiento()<<std::endl;
      fichero<<"SEXO:"<<p->get_sexo()<<std::endl;

      p->reset_cursor();
      while(!p->es_ultimo()){
        am = p->get_atributo_multiple();
        fichero<<am->get_titulo()<<":"<<am->get_contenido()<<std::endl;
      };

      fichero<<"---"<<std::endl;
    }

    fichero.close();

    return true;
  }

  /**
   * Elimina el paciente activo y pone el cursor al principio
   * de la lista.
   */
  bool FicheroPacientes::eliminar(){

    if(_pacientes->size() == 1){
      delete *_activo;
      _pacientes->pop_back();
      _activo = _pacientes->begin();
      return true;
    }

    if(_pacientes->empty()){
      return false;
    }

    std::list<Contacto*>::iterator it_borrar = _activo;
    delete *_activo;
    _pacientes->erase(it_borrar);
    _activo = _pacientes->begin();

    return true;
  }

  /*Elimina atributo multiple en la posicion indicada*/
  bool FicheroPacientes::eliminar_am(int posicion){
    int i=0;

    //PORHACER posicion debe ser valido
    
    (*_activo)->del_atributo_multiple(posicion);
    return true;
  }

  bool FicheroPacientes::nuevo(Contacto* c){


    _pacientes->push_back(c);
    _pacientes->sort(Paciente::cmp_apellidos);

  }

  Contacto* FicheroPacientes::activo(){
    return *_activo;
  }

  /** Pone _activo al siguiente contacto, si es el ultimo
   *  _activo pasara a apuntar al primer contacto de la lista
   */
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

  /** Devuelve true si el paciente _activo es el primero de la lista
   */
  bool FicheroPacientes::es_primero(){
    return _activo == _pacientes->begin();
  }


  bool FicheroPacientes::buscar(const std::string& a1, const std::string& a2){
    Paciente* act; //paciente actual
    Paciente b; //paciente buscado
    b.set_apellido1(a1);
    b.set_apellido2(a2);

    std::list<Contacto*>::iterator it = _pacientes->begin();

    while(it!=_pacientes->end()){
      if(b == *it){
	// si lo encuentra, sale del bucle y _activo
	// apunta primer paciente encontrado
	_activo = it;
	return true;
      }
      ++it;
    }

    //si no encuentra el exacto,
    //buscamos coincidencias por primer apellido
    it = _pacientes->begin();
    while(it!=_pacientes->end()){
      act = dynamic_cast<Paciente*>(*it);
      if(b.get_apellido1().get_contenido() == act->get_apellido1().get_contenido()){
	// si lo encuentra, sale del bucle y _activo
	// apunta primer paciente encontrado
	_activo = it;
	return true;
      }
      ++it;
    }

    return false;

  }

  void FicheroPacientes::reordenar_frecuencia(){
    _pacientes->sort(Paciente::cmp_frecuencia);
  }

  void FicheroPacientes::reordenar_apellidos(){
    _pacientes->sort(Paciente::cmp_apellidos);
  }

}
