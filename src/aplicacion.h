#ifndef APLICACION_H
#define APLICACION_H

#include "agenda.h"
#include "fichero_pacientes.h"

using namespace agenda;

class Aplicacion{
 private:
  Agenda* _la_agenda;
  FicheroPacientes* _bd;

 public:

  Aplicacion();
  virtual ~Aplicacion();

  void menu_contextual();
  void gestionar_paciente();
  void visualizar_pacientes();
  void gestionar_backups();
  void menu_modificar();


  void buscar();
  void modificar();
  void eliminar();
  void marcar_favorito();

  void agregar_nota();
  void agregar_direccion();
  void agregar_red_social();
  void agregar_telefono();

  void eliminar_atributo_multiple();

  void nuevo();
  void guardar_como();
  void cargar_desde();
  void siguiente();

  void todos();
  void favoritos();

  void modificar_nombre();
  void modificar_apellido1();
  void modificar_apellido2();
  void modificar_fecha_nacimiento();
  void modificar_sexo();

};

#endif
