OUT = bin/clinica.x
CC = g++
OBJ = main.o paciente.o base_datos.o fichero_pacientes.o contacto.o atributo.o agenda.o aplicacion.o
INC = -Isrc
CXX_FLAGS = -g


clinica.x : $(OBJ)
	$(CC) -o clinica.x $(OBJ) $(CXX_FLAGS)

main.o :  main.cpp atributo.h
	$(CC) -c -o main.o main.cpp $(CXX_FLAGS)

aplicacion.o : aplicacion.cpp agenda.h fichero_pacientes.h paciente.h
	$(CC) -c -o aplicacion.o aplicacion.cpp $(CXX_FLAGS)

paciente.o : paciente.cpp paciente.h contacto.h atributo.h
	$(CC) -c -o paciente.o paciente.cpp $(CXX_FLAGS)

agenda.o : agenda.cpp agenda.h contacto.h base_datos.h
	$(CC) -c -o agenda.o agenda.cpp $(CXX_FLAGS)

base_datos.o : base_datos.cpp base_datos.h contacto.h
	$(CC) -c -o base_datos.o base_datos.cpp $(CXX_FLAGS)

fichero_pacientes.o : fichero_pacientes.cpp fichero_pacientes.h base_datos.h atributo.h
	$(CC) -c -o fichero_pacientes.o fichero_pacientes.cpp $(CXX_FLAGS)

contacto.o : contacto.cpp contacto.h atributo.h
	$(CC) -c -o contacto.o contacto.cpp $(CXX_FLAGS)

atributo.o :  atributo.cpp atributo.h
	$(CC) -c -o atributo.o atributo.cpp $(CXX_FLAGS)

clean :
	rm *.o