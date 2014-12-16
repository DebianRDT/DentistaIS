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


  void ver_detalles();
  void modificar();
  void eliminar();
  void marcar_favorito();
  void agregar_atributo_multiple();
  void modificar_atributo_multiple();
  void eliminar_atributo_multiple();
  void nuevo();
  void guardar_como();
  void cargar_desde();
  void siguiente();
};

#endif
