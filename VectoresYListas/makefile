# Directorio de archivos fuente
SRCDIR = ./
# "all" es el objetivo por defecto. Sus dependencias se comprueban cuando ejecute la orden "make" en el directorio actual. Puede haber más de una dependencia.
all : ejecutable
#### Reglas secundarias para compilar cada una de las dependencias.
ejecutable : main.o empresa.o
	g++ -Wall main.o empresa.o -o ejecutable
main.o: $(SRCDIR)main.cpp
	g++ -c $(SRCDIR)main.cpp
empresa.o: $(SRCDIR)empresa.cpp
	g++ -c $(SRCDIR)empresa.cpp
# "limpiar" es un objetivo falso. Sirve para borrar los archivos .o (objeto).
limpiar:
	rm *.o