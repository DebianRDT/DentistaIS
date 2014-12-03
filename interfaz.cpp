/*
 * interfaz.cpp
 *
 */

#include <iostream>
#include "interfaz.h"
#include "clinica/paciente.h"
#include "clinica/agenda.h"

using namespace clinica;

Interfaz* Interfaz::_app = 0;


/** Devuelve la instancia unica
 *
 */
Interfaz* Interfaz::App(){
	if(_app==0){
		_app = new Interfaz();
	}
	return _app;
}

Interfaz::Interfaz(){
	_la_agenda = Agenda::LaAgenda();


	std::cout<<"CLINICA DENTAL"<<std::endl;
	_menu_contextual();

}



Interfaz::~Interfaz(){}


void Interfaz::_menu_contextual(){
	int o;


	do{
		std::cout<<"(1)\tGestionar paciente"<<std::endl;
		std::cout<<"(2)\tVisualizar pacientes"<<std::endl;
		std::cout<<"(3)\tGestionar backups"<<std::endl;
		std::cout<<"(0)\tSalir"<<std::endl;

		std::cout<<"Introduzca una opcion"<<std::endl;
		std::cin>>o;
	}while(o>3 || o<0);



	switch(o){
		case 0:return;
		case 1:_menu_gestionar_paciente();break;
		case 2:_menu_visualizar_pacientes();break;
		case 3:_menu_gestionar_pacientes();break;
	}

	_menu_contextual();
}

void Interfaz::_menu_gestionar_paciente(){
	int o;


	do{
		std::cout<<"(1)\tAgregar nuevo"<<std::endl;
		std::cout<<"(2)\tEliminar"<<std::endl;
		std::cout<<"(3)\tModificar"<<std::endl;
		std::cout<<"(4)\tSeleccionar"<<std::endl;
		std::cout<<"(0)\tSalir"<<std::endl;

		std::cout<<"Introduzca una opcion"<<std::endl;
		std::cin>>o;
	}while(o>4 || o<0);



	switch(o){
		case 0:return;
		case 1:_menu_gestionar_paciente();break;
		case 2:_menu_visualizar_pacientes();break;
		case 3:_menu_gestionar_pacientes();break;
		case 4:_menu_seleccionar_paciente();break;
	}

	_menu_contextual();
}

void Interfaz::_menu_visualizar_pacientes(){

}

void Interfaz::_menu_gestionar_pacientes(){

}

void Interfaz::_menu_seleccionar_paciente(){
	std::string apellidos;

	std::cout<<"Introduzca apellidos del paciente a seleccionar"<<std::endl;
	std::cin>>apellidos;

	//...

}
