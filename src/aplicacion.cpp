#include "aplicacion.h"
#include "agenda.h"
#include "fichero_pacientes.h"
#include "paciente.h"
#include "contacto.h"


using namespace std;

Aplicacion::Aplicacion(){

  _bd = new agenda::FicheroPacientes();

  _la_agenda = agenda::Agenda::la_agenda(_bd);
  menu_contextual();
}

Aplicacion::~Aplicacion(){
  delete _bd;
}


void Aplicacion::menu_contextual(){
  int o;


  cout<<"CLINICA DENTAL 1.0"<<endl;
  cout<<"(1)\t Gestionar paciente"<<endl;
  cout<<"(2)\t Visualizar pacientes"<<endl;
  cout<<"(3)\t Gestionar backups"<<endl;
  cout<<"(0)\t Salir"<<endl;

  cout<<"Elija una opcion"<<endl;
  cin>>o;

  if(o==0)
    return;

  if(o<1 || o>3)
    menu_contextual();

  switch(o){
  case 1: gestionar_paciente();break;
  case 2: visualizar_pacientes();break;
  case 3: gestionar_backups();break;
  }

}

void Aplicacion::gestionar_paciente(){
  int o;

  cout<<"GESTIONAR PACIENTE"<<endl;

  if(!_la_agenda->get_bd()->vacia()){
    //POR HACER
    //IMPRIMIR PACIENTE
  }

  cout<<"(1)\tVer detalles"<<endl;
  cout<<"(2)\tModificar"<<endl;
  cout<<"(3)\tEliminar"<<endl;
  cout<<"(4)\tMarcar favorito"<<endl;
  cout<<"(5)\tAgregar atributo multiple"<<endl;
  cout<<"(6)\tModificar atributo multiple"<<endl;
  cout<<"(7)\tEliminar atributo multiple"<<endl;
  cout<<"(8)\tNuevo"<<endl;
  cout<<"(0)\tAtras"<<endl;

  cout<<"Escriba una opcion"<<endl;
  cin>>o;

  if(o<0 || o>8)
    gestionar_paciente();

  switch(o){
  case 1: ver_detalles();break;
  case 2: modificar();break;
  case 3: eliminar(); break;
  case 4: marcar_favorito(); break;
  case 5: agregar_atributo_multiple(); break;
  case 6: modificar_atributo_multiple(); break;
  case 7: eliminar_atributo_multiple(); break;
  case 8: nuevo(); break;
  }



  menu_contextual();

}

void Aplicacion::visualizar_pacientes(){
  //POR HACER
}

void Aplicacion::gestionar_backups(){
  int o;

  cout<<"(1)\tGuardar como"<<endl;
  cout<<"(2)\tCargar desde"<<endl;
  cout<<"(0)\tSalir"<<endl;

  cout<<"Escriba una opcion"<<endl;
  cin>>o;

  if(o<0 || o>2)
    gestionar_backups();

  switch(o){
  case 1: guardar_como();break;
  case 2: cargar_desde();break;
  }

  menu_contextual();

}

/** Muestra detalles del paciente seleccionado
 *
 */
void Aplicacion::ver_detalles(){
  
  cout<<*(_la_agenda->get_bd()->activo())<<endl;

}

void Aplicacion::modificar(){
  //POR HACER
}

/** Pide confirmacion para eliminar el paciente y
 *  en caso afirmativo lo elimina ( el paciente activo )
 *  y pone el paciente activo al siguiente
 */
void Aplicacion::eliminar(){
  //POR HACER
}


void Aplicacion::marcar_favorito(){
  //POR HACER
}

void Aplicacion::agregar_atributo_multiple(){
  //POR HACER
}

void Aplicacion::modificar_atributo_multiple(){
  //POR HACER
}

void Aplicacion::eliminar_atributo_multiple(){
  //POR HACER
}


/** Pide datos del nuevo paciente a ingresar
 *  y pide a la agenda que lo inserte si la insercion
 *  tiene exito el paciente activo sera el recien
 *  insertado.
 */
void Aplicacion::nuevo(){
  Paciente* p; //nuevo
  /* POR HACER
     Pedir todos los datos del paciente nuevo. */


  //_la_agenda->nuevo(p);
}


void Aplicacion::guardar_como(){
  string nombre_fichero;
  cout<<"Escriba nombre del fichero donde almacenar pacientes"<<endl;
  cin>>nombre_fichero;
  _la_agenda->get_bd()->guardar_como(nombre_fichero);
}

void Aplicacion::cargar_desde(){
  string nombre_fichero;
  cout<<"Escriba nombre fichero de pacientes"<<endl;
  cin>>nombre_fichero;
  _la_agenda->get_bd()->cargar_desde(nombre_fichero);
}
