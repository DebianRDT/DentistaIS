Revisado por el profesor


Para todos los casos de uso se ordenará el archivo, en caso de ser necesario, por apellidos


#DCU_0_CONT: Contexto del sistema

En el diagrama DCU_0_CONT se pretende mostrar una visión global de la funcionalidad que el sistema debe proporcionar al actor. A continuación, se muestra el diagrama de caso de uso 0, que representa el contexto del sistema:
	
![DCU_0_CONT](https://github.com/DebianRDT/DentistaIS/blob/master/documentacion/diagramas/DCU_0_CONT.png)


#DCU_1_GPA: Gestionar pacientes

En el DCU_1_GPA se muestra la funcionalidad que se ofrece en la sección de gestión de pacientes al administrativo.
	
![DCU_1_GPA](https://github.com/DebianRDT/DentistaIS/blob/master/documentacion/diagramas/DCU_1_GPA.png)
	

#DCU_2_BACKUP: Gestionar backups

En el DCU_2_BACKUP se muestra la funcionalidad que se ofrece en la sección de gestión de backups al administrativo.
	
![DCU_2_BACKUP](https://github.com/DebianRDT/DentistaIS/blob/master/documentacion/diagramas/DCU_2_BACKUP.png)
	

#DCU_3_VPA: Visualizar pacientes

En el DCU_3_VPA se muestra la funcionalidad que se ofrece en la sección de visualizar pacientes al administrativo.
	
![DCU_3_VPA](https://github.com/DebianRDT/DentistaIS/blob/master/documentacion/diagramas/DCU_3_VPA.png)
	

ESPECIFICACIÓN DE CASOS DE USO
==============================

#Caso de uso: Seleccionar paciente

Actor principal: Administrativo

Actores de soporte:

Nivel: Usuario.

Ámbito:

Escenario principal de éxito:
 1. El administrativo *busca un paciente escribiendo su apellido*

 2. El administrativo selecciona un cliente de entre los encontrados
 3. El administrativo elige entre las opciones: 


    1. ver detalle del paciente
    2. *modificar datos del paciente*
    3. eliminar paciente
    4. marcar paciente como favorito.
    
Escenario alternativo:


    1a. No se encuentra ningún paciente que coincida con el apellido introducido y se acaba el caso de uso.



    3.2a. El administrativo asigna un valor imposible para el paciente en la modificación.



#Caso de uso: Modificar paciente

Actor principal: Administrativo

Actores de soporte:

Nivel: Usuario.

Ámbito:

Escenario principal de éxito:
  1. El administrativo elige el atributo que quiere cambiar
  2. Escribe un nuevo valor para ese atributo.

Escenario alternativo:

1.a El atributo elegido es erróneo

  1.a.1 Se vuelve a preguntar qué atributo se desea modificar

  2.a El valor introducido no pertenece al dominio. 

  2.a.1. Se vuelve a pedir el atributo (En este caso volvemos a 2)



#Caso de uso: Visualizar pacientes

Actor principal: Administrativo

Actores de soporte:

Nivel: Usuario.

Ámbito:

Precondiciones: 

Que la agenda tenga datos. 

Escenario principal de éxito:

1. El administrativo elige entre las opciones: 
	1. listar todos ordenados por apellidos
	1. listar todos ordenados por más frecuente
	1. listar favoritos.

Escenario alternativo:


#Caso de uso: Gestionar backups
Actor principal: Administrativo
Actores de soporte:
Nivel: Usuario.
Ámbito:
Escenario principal de éxito:

1. El administrativo elige entre las opciones: Cargar fichero o guardar fichero de pacientes.

1.1. El administrativo elige guardar fichero de pacientes, y se realiza una copia de seguridad de los datos.

1.2. El administrativo intenta restaurar los datos de los pacientes con un fichero externo.

Escenario alternativo:

1.1.a1. Imposibilidad de almacenar el fichero. Termina el caso de uso

1.2.a1. No existe el fichero del que se intenta recuperar información. Termina el caso de uso.

1.2.a2. No se puede acceder al fichero. Termina el caso de uso.


#Caso de uso: Insertar nuevo paciente

Actor principal: Administrativo

Actores de soporte:

Nivel: Usuario.

Ámbito:

Escenario principal de éxito:
1. El administrativo escribe el dni del paciente que va a insertar.
2. El sistema verifica que no existe un cliente con el mismo dni.
3. El administrativo escribe secuencialmente el resto de atributos del nuevo paciente.
4. El sistema los guarda en el disco ordenados por apellido. 

Escenario alternativo:
2a. El administrativo introduce un dni existente.

2a1. Muestra error y vuelve a pedir el cliente.

3a. El administrativo escribe en un atributo datos que no pertenecen al dominio.

3a1. El sistema volverá a solicitar que el administrativo escriba el atributo.
