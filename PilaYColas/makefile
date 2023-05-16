# Directorio de archivos fuente
SRCDIR = ./
# "all" es el objetivo por defecto. Sus dependencias se comprueban cuando ejecute la orden "make" en el directorio actual. Puede haber más de una dependencia.
all : ejecutable
#### Reglas secundarias para compilar cada una de las dependencias.
ejecutable : main.o ejercicio.o
	g++ -Wall main.o ejercicio.o -o ejecutable
main.o: $(SRCDIR)main.cpp
	g++ -c $(SRCDIR)main.cpp
ejercicio.o: $(SRCDIR)ejercicio.cpp
	g++ -c $(SRCDIR)ejercicio.cpp
# "limpiar" es un objetivo falso. Sirve para borrar los archivos .o (objeto).
clean:
	rm *.o