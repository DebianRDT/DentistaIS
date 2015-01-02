#include "aplicacion.h"
#include "agenda.h"
#include "fichero_pacientes.h"
#include "paciente.h"
#include "contacto.h"
#include "fechas.h"


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

  do{
    cout<<"CLINICA DENTAL 1.0"<<endl;
    cout<<"(1)\t Gestionar paciente"<<endl;
    cout<<"(2)\t Visualizar pacientes"<<endl;
    cout<<"(3)\t Gestionar backups"<<endl;
    cout<<"(0)\t Salir"<<endl;

    cout<<"Elija una opcion"<<endl;
    cin>>o;

    if(o==0)
      return;

    switch(o){
    case 1: gestionar_paciente();break;
    case 2: visualizar_pacientes();break;
    case 3: gestionar_backups();break;
    }

  }while(o>0 || o<=3);

}

void Aplicacion::gestionar_paciente(){
  int o;

  cout<<"GESTIONAR PACIENTE"<<endl;
  cout<<"---"<<endl;




  do{

    if(!_la_agenda->contactos()->vacia()){
      cout<<"Paciente seleccionado:"<<endl;
      cout<<*(_la_agenda->contactos()->activo())<<endl;
      
    }

    cout<<"(1)\tIr a siguiente"<<endl;
    cout<<"(2)\tBuscar"<<endl;
    cout<<"(3)\tModificar"<<endl;
    cout<<"(4)\tEliminar"<<endl;
    cout<<"(5)\tMarcar favorito"<<endl;

    cout<<"(6)\tAgregar nota"<<endl;
    cout<<"(7)\tAgregar red social"<<endl;
    cout<<"(8)\tAgregar direccion"<<endl;
    cout<<"(9)\tAgregar telefono"<<endl;

    cout<<"(10)\tEliminar atributo multiple"<<endl;
    cout<<"(11)\tNuevo"<<endl;
    cout<<"(0)\tAtras"<<endl;

    cout<<"Escriba una opcion"<<endl;
    cin>>o;

    switch(o){
    case 1: siguiente();break;
    case 2: buscar();break;
    case 3: modificar();break;
    case 4: eliminar(); break;
    case 5: marcar_favorito(); break;

    case 6: agregar_nota(); break;
    case 7: agregar_red_social(); break;
    case 8: agregar_direccion(); break;
    case 9: agregar_telefono(); break;


    case 10: eliminar_atributo_multiple(); break;
    case 11: nuevo(); break;
    case 0: return;
    }

  }while(o>0 || o<=11);
}

void Aplicacion::visualizar_pacientes(){
  int o;
  do{
    cout<<"Visualizar pacientes:"<<endl;
    cout<<"(1) Ver todos."<<endl;
    cout<<"(2) Ver frecuentes."<<endl;
    cout<<"(3) Ver favoritos"<<endl;
    cout<<"(0) Atras"<<endl;

  

    cout<<"Escriba una opcion"<<endl;
    cin>>o;
    
    switch(o){
    case 1: todos();break;
    case 0: return;
    case 2:break; // POR HACER -> VER FRECUENTES
    case 3: favoritos(); break;
    }

  }while(o>0 || o<=3);

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

void Aplicacion::modificar(){
  
  int o;

  cout<<"(1) Nombre"<<endl;
  cout<<"(2) Apellido 1"<<endl;
  cout<<"(3) Apellido 2"<<endl;
  cout<<"(4) Fecha de nacimiento"<<endl;
  cout<<"(5) Sexo"<<endl;
  // ...
  // POR HACER

  cout<<"Elija que modificar:"<<endl;
  cin>>o;


}


/** Muestra detalles del paciente seleccionado
 *
 */
void Aplicacion::buscar(){
  string apellido1,apellido2;
  
  cout<<"Introduzca primer apellido:"<<endl;
  cin>>apellido2;
  cout<<"Introduzca segundo apellido:"<<endl;
  cin>>apellido2;


  if(_la_agenda->contactos()->buscar(apellido1,apellido2)){
    cout<<"ENCONTRADO!"<<endl;
  }
  else{
    cout<<"NO ENCONTRADO"<<endl;
  }
  

  
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


void Aplicacion::agregar_nota(){
  //POR HACER
}

void Aplicacion::agregar_telefono(){
  //POR HACER
}

void Aplicacion::agregar_red_social(){
  //POR HACER
}

void Aplicacion::agregar_direccion(){
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
  Paciente * p= new Paciente();
  string a1, a2, dni, nombre, sexo;
  char favorito;
  string frecuencia;
  Fecha f;
  int month, day, year;

	cout<<"Introduzca nombre"<<endl;
	cin>>nombre;
	p->set_nombre(nombre);
	cout<<"Introduzca primer apellido"<<endl;
  cin>>a1;
  p->set_apellido1(a1);
  cout<<"Introduzca segundo apellido"<<endl;
  cin>>a2;
  p->set_apellido2(a2);
  cout<<"Introduzca DNI"<<endl;
  cin>>dni;
  p->set_dni(dni);
  cout<<"Introduzca frecuencia"<<endl;
  cin>>frecuencia;
  p->set_frecuencia(frecuencia);
  cout<<"¿Es favorito? y/n\n"<<endl;
  cin>>favorito;
  switch (favorito)
  {
    case 'y':
      p->set_favorito();
      break;
    case 'n':
      p->reset_favorito();
      break;
    default:
      cout<<"Introduzca y/n\n"<<endl;
  }
  cout<<"Introduzca sexo"<<endl;
  cin>>sexo;
  p->set_sexo(sexo);

  
  cout<<"Introduzca fecha de nacimiento"<<endl;
  cout<<"Introduzca mes"<<endl;
  cin>>month;
  cout<<"Introduzca dia"<<endl;
  cin>>day;
  cout<<"Introduzca año"<<endl;
  cin>>year;
  f.setFecha(day, month, year);
  

  _la_agenda->contactos()->nuevo(p);

  /* POR HACER
     FALTAN ATRIBUTOS MULTIPLES*/

  //_la_agenda->nuevo(p);
}

void Aplicacion::siguiente(){
  _la_agenda->contactos()->siguiente();
  
}


void Aplicacion::guardar_como(){
  string nombre_fichero;
  cout<<"Escriba nombre del fichero donde almacenar pacientes"<<endl;
  cin>>nombre_fichero;
  _la_agenda->contactos()->guardar_como(nombre_fichero);
}

void Aplicacion::cargar_desde(){
  string nombre_fichero;
  cout<<"Escriba nombre fichero de pacientes"<<endl;
  cin>>nombre_fichero;
  _la_agenda->contactos()->cargar_desde(nombre_fichero);
}

/** Listar todos los contactos ordenador alfabeticamente
 *  por apellidos
 */
void Aplicacion::todos(){
  if(!_la_agenda->contactos()->vacia()){
    do{
      cout<<*(_la_agenda->contactos()->activo())<<endl;
      _la_agenda->contactos()->siguiente();
    }while(!_la_agenda->contactos()->es_primero());
    
  }
  else{
    cout<<"NADA EN LA AGENDA"<<endl;
  }

}


/** Mostrar lista de pacientes favoritos
 */

void Aplicacion::favoritos(){
  if(!_la_agenda->contactos()->vacia()){
    do{
      if(_la_agenda->contactos()->activo()->es_favorito()){
	cout<<*(_la_agenda->contactos()->activo())<<endl;
      }
      _la_agenda->contactos()->siguiente();
    }while(!_la_agenda->contactos()->es_primero());
  }
}
