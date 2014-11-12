Aquí los requisitos que nos valen para hoy:

Especificacion de requisitos:
======================

Requisitos de usuario:
----------------------

RU-1. El actor principal será el administrativo que podrá gestionar la información de los pacientes de la clínica.
RU-2. El administrativo podrá realizar copias de seguridad de todos los pacientes registrados en el sistema.
RU-3. El administrativo no necesita identificarse para acceder al sistema.
RU-4. La interfaz deberá ser de texto
RU-5. El administrativo podrá visualizar información de todos los pacientes ordenados por apellido
RU-6. El administrativo podrá ver información de un paciente a través de su DNI.
RU-7. El adminsitrativo podrá restaurar la información de pacientes a través de copias de seguridad.
RU-8. La información de los pacientes se debe almacenar en ficheros planos.
RU-9. El lenguaje para desarrollar el sistema debe ser C++.
RU-10. El sistema debe ser ejecutable en Linux.


REQUISITOS DEL SISTEMA:

Requisitos de información:

RI-1-PAC. Información relativa a pacientes.
	DNI
	Nombre
	Apellidos
	Emails
	Direcciones postales
	Anotaciones
	Redes sociales
	Favoritos
	Veces consultado
	Fecha de nacimiento
	Sexo
	Teléfonos
	
	
Requisitos funcionales:
RF-1. Registrar nuevo paciente. Se deben registrar sus datos personales.
	RF-1.1. Cada paciente será identificado por su DNI de forma única.
RF-2. Podrá, el administrativo, dar de baja a un paciente a través de su DNI.
RF-3. El administrativo podrá visualizar un paciente a través de su DNI.
RF-4. El administrativo podrá modificar un paciente a través de su DNI.
RF-5. El administrativo podrá visualizar una lista de todos los pacientes ordenados por apellido.
RF-6. El administrativo podrá visualizar lista de pacientes marcados como favoritos ordenados por apellido.
RF-7. El administrativo podrá visualizar lista de pacientes frecuentes ordenados por apellido.
RF-8. El administrativo podrá marcar como favorito un paciente, a través de su DNI.
RF-9. El administrativo podrá guardar datos de todos los pacientes en un fichero.
RF-10. El administrativo podrá restaurar pacientes a partir de un fichero.


Requisitos no funcionales:
RNF-1. Debe ser ejecutable en sistemas operativos Linux.
RNF-2. Debe estar escrito en C++
RNF-3. La interfaz debe ser en modo texto
RNF-4. Los datos de los pacientes deben ser almacenados en ficheros de texto planos
RNF-5. No se requiere ningún tipo de seguridad
RNF-6. Volumen de datos de 200 entradas



























