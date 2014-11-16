Revisado por el profesor


Para todos los casos de uso se ordenará el archivo, en caso de ser necesario, por apellidos


#DCU_0_CONT: Contexto del sistema

En el diagrama DCU_0_CONT se pretende mostrar una visión global de la funcionalidad que el sistema debe proporcionar al actor. A continuación, se muestra el diagrama de caso de uso 0, que representa el contexto del sistema:
	
![DCU_0_CONT](https://github.com/DebianRDT/DentistaIS/blob/master/documentacion/diagramas/DCU_0_CONT.png)

#Caso de uso: Visualizar pacientes

Actor principal: Administrativo

Actores de soporte:

Nivel: Usuario.

Ámbito:

Precondiciones: 

- Que la agenda tenga pacientes registrados. 

Escenario principal de éxito:

1. El administrativo elige entre las opciones: 
	1. listar todos ordenados por apellidos
	1. listar todos ordenados por más frecuente
	1. listar favoritos.

Escenario alternativo:

1.a. Si no hay pacientes registrados, se muestra un mensaje indicándolo y se termina el caso de uso.


#Caso de uso: Gestionar backups

Actor principal: Administrativo

Actores de soporte:

Nivel: Usuario.

Ámbito:

Precondiciones:

Escenario principal de éxito:

1. El administrativo elige entre las opciones: Cargar fichero o guardar fichero de pacientes.

1.1. El administrativo elige guardar fichero de pacientes, y se realiza una copia de seguridad de los datos.

1.2. El administrativo elige cargar registros de pacientes a través de un fichero.

Escenario alternativo:

1.1.a1. Imposibilidad de almacenar el fichero. Termina el caso de uso

1.2.a1. No existe el fichero del que se intenta recuperar información. Termina el caso de uso.

1.2.a2. No se puede acceder al fichero. Termina el caso de uso.


#DCU_1_GPA: Gestionar pacientes

En el DCU_1_GPA se muestra la funcionalidad que se ofrece en la sección de gestión de paciente al administrativo.
	
![DCU_1_GPA](https://github.com/DebianRDT/DentistaIS/blob/master/documentacion/diagramas/DCU_1_GPA.png)
	

#Caso de uso: Seleccionar paciente

Actor principal: Administrativo

Actores de soporte:

Nivel: Usuario.

Ámbito:

Escenario principal de éxito:
 1. El administrativo busca un paciente escribiendo su apellido
 2. El administrativo selecciona un cliente entre los encontrados
 3. Se registra un acceso al paciente seleccionado
 4. El administrativo elige entre las opciones:

    1. ver detalle del paciente
    2. *modificar datos del paciente*
    3. eliminar paciente
    4. marcar paciente como favorito.
    
Escenario alternativo:

    1.a. No se encuentra ningún paciente que coincida con el apellido introducido, se muestra un mensaje que indique que no hay pacientes con ese apellido y se acaba el caso de uso.


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



#Caso de uso: Alta nuevo paciente

Actor principal: Administrativo

Actores de soporte:

Nivel: Usuario.

Ámbito:

Escenario principal de éxito:

1. El administrativo escribe secuencialmente los atributos del nuevo paciente.
2. El sistema los guarda en el disco ordenados por apellido. 

Escenario alternativo:

1.a. El administrativo escribe en un atributo datos que no pertenecen al dominio. El sistema volverá a solicitar que el administrativo escriba el atributo.

2.a. Imposible guardar el registro en el fichero. En ese caso se muestra un mensaje indicando el error y termina el caso de uso.

