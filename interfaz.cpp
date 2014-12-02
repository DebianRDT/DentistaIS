/*
 * interfaz.cpp
 *
 *  Created on: 26/11/2014
 *      Author: francisco
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
	_la_agenda->LaAgenda();


	std::cout<<"CLINICA DENTAL"<<std::endl;
	menu_contextual();

}



Interfaz::~Interfaz(){}

void Interfaz::menu_contextual(){
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
		case 1:menu_gestionar_paciente();break;
		case 2:menu_visualizar_pacientes();break;
		case 3:menu_gestionar_pacientes();break;
	}

	menu_contextual();
}

void Interfaz::menu_gestionar_paciente(){
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
		case 1:menu_gestionar_paciente();break;
		case 2:menu_visualizar_pacientes();break;
		case 3:menu_gestionar_pacientes();break;
		case 4:menu_seleccionar_paciente();break;
	}

	menu_contextual();
}

void Interfaz::menu_visualizar_pacientes(){

}

void Interfaz::menu_gestionar_pacientes(){

}

void Interfaz::menu_seleccionar_paciente(){


	std::string apellidos;


	std::cout<<"Introduzca apellidos del paciente a seleccionar"<<std::endl;
	std::cin>>apellidos;



}
