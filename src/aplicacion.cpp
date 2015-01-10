#include "aplicacion.h"
#include "agenda.h"
#include "fichero_pacientes.h"
#include "paciente.h"
#include "contacto.h"
#include "fechas.h"
#include <iostream>
#include <string>


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
    default: break;
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
    case 2: todos_frecuencia(); break;
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

   switch (o)
  {
     case 1:
      modificar_nombre();
      break;
     case 2:
      modificar_apellido1();
      break;
     case 3:
      modificar_apellido2();
      break;
     case 4:
      modificar_fecha_nacimiento();
      break;
     case 5:
      modificar_sexo();
      break;
   }
}


/** Muestra detalles del paciente seleccionado
 *
 */
void Aplicacion::buscar(){
  string apellido1,apellido2;
  
  cout<<"Introduzca primer apellido:"<<endl;
  cin>>apellido1;
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
    char confirmacion;
    bool bucle=true;
    Paciente* p = dynamic_cast<Paciente*>(_la_agenda->contactos()->activo());
    while (bucle){


    cout << "¿Realmente desea borrar al paciente " << p->get_nombre() << " " << p->get_apellido1() << " " << p->get_apellido2() << "?" << endl;
    cout << "Si (S) / No (N)";
    cin >> confirmacion;

    switch(confirmacion) {
    case 's': case 'S': if(_la_agenda->contactos()->eliminar()){cout << "ELIMINADO";} else {cout << "NO SE HA PODIDO ELIMINAR";}  break;

    case 'n': case 'N': bucle=false; break;

    default: break;
    }

    }


}


void Aplicacion::marcar_favorito(){
  _la_agenda->contactos()->activo()->set_favorito();
  _la_agenda->contactos()->guardar();
}


void Aplicacion::agregar_nota(){
  string nota;
  string aux;
  cout << "Escriba nueva nota" << endl;
  getline(cin, nota); //NECESARIO LIMPIAR EL BUFFER
  Paciente* p = dynamic_cast<Paciente*>(_la_agenda->contactos()->activo());
  p->add_nota(nota);
  _la_agenda->contactos()->guardar();
}

void Aplicacion::agregar_telefono(){
  string telefono;
  Paciente* p = dynamic_cast<Paciente*>(_la_agenda->contactos()->activo());
  cout << "Escriba el numero de telefono" << endl;
  getline(cin, telefono);//NECESARIO LIMPIAR EL BUFFER

  p->add_telefono(telefono);
  _la_agenda->contactos()->guardar();

}

void Aplicacion::agregar_red_social(){
  string red_social;
  Paciente* p = dynamic_cast<Paciente*>(_la_agenda->contactos()->activo());
  cout << "Escriba la red social del paciente" << endl;
  getline(cin, red_social);//NECESARIO LIMPIAR EL BUFFER
  p->add_red_social(red_social);
  _la_agenda->contactos()->guardar();
}

void Aplicacion::agregar_direccion(){
  string direccion;
  Paciente* p = dynamic_cast<Paciente*>(_la_agenda->contactos()->activo());
  cout << "Escriba la direccion del paciente" << endl;
  getline(cin, direccion);//NECESARIO LIMPIAR EL BUFFER
  p->add_direccion(direccion);
  _la_agenda->contactos()->guardar();
}


void Aplicacion::eliminar_atributo_multiple(){
  int i;
  int o;
  do{
    i=1;
    while(!_la_agenda->contactos()->activo()->es_ultimo()){
    cout<<"("<<i<<")"<<*_la_agenda->contactos()->activo()->get_atributo_multiple()<<std::endl;
    i++;
  }
  cout<<"Introduzca atributo a eliminar"<<endl;
  cin>>o;

  if (o<1 || o>i)
    cout<<"Opcion incorrecta"<<endl;
  }while((o<0 || o>i));


 //POR HACER
 //eliminar atributo segun opcion introducida
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


void Aplicacion::todos_frecuencia(){
  if(!_la_agenda->contactos()->vacia()){

    _la_agenda->contactos()->reordenar_frecuencia();

    do{
      cout<<*(_la_agenda->contactos()->activo())<<endl;
      _la_agenda->contactos()->siguiente();
    }while(!_la_agenda->contactos()->es_primero());
    
    _la_agenda->contactos()->reordenar_apellidos();
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


void Aplicacion::modificar_nombre()
{
  string nombre;
  cout<<"Introduzca nombre nuevo"<<endl;
  cin>>nombre;

  Paciente* p = dynamic_cast<Paciente*>(_la_agenda->contactos()->activo());
  p->set_nombre(nombre);
}

void Aplicacion::modificar_apellido1()
{
  string apellido1;
  cout<<"Introduzca nuevo apellido1"<<endl;
  cin>>apellido1;

  Paciente* p = dynamic_cast<Paciente*>(_la_agenda->contactos()->activo());
  p->set_apellido1(apellido1);
}
void Aplicacion::modificar_apellido2()
{
  string apellido2;
  cout<<"Introduzca nuevo apellido2"<<endl;
  cin>>apellido2;

  Paciente* p = dynamic_cast<Paciente*>(_la_agenda->contactos()->activo());
  p->set_apellido2(apellido2);

}
void Aplicacion::modificar_fecha_nacimiento()
{
  string fechaNacimiento;
  cout<<"Introduzca fecha de nacimiento"<<endl;
  cin>>fechaNacimiento;

  Paciente* p = dynamic_cast<Paciente*>(_la_agenda->contactos()->activo());
  p->set_fecha_nacimiento(fechaNacimiento);


}
void Aplicacion::modificar_sexo()
{
  string sexo;
  cout<<"Introduzca nuevo sexo del paciente"<<endl;
  cin>>sexo;
  Paciente* p = dynamic_cast<Paciente*>(_la_agenda->contactos()->activo());
  p->set_sexo(sexo);



}


