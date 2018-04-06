#ifndef Datafile_h
#define Datafile_h

#include <stdio.h>

class Datafile {
public:
    char* direccion;
    Datafile(char* direc);
    FILE* Archivo;
    void abrir();
    void cerrar();
    void escribir(char * data,int pos,int longitud);
    char* leer(int pos,int longitud);
};

#endif /* Datafile_h */
