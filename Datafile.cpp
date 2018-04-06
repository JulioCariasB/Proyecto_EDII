#ifdef __APPLE__
    #include <sys/uio.h>
#else
    #include <sys/io.h>
#endif
#include <stdio.h>
#include "Datafile.h"
#include <stdlib.h>
#include <cstring>
#include <iostream>

using namespace std;

Datafile::Datafile(char* direc){
    direccion = direc;
    Archivo = fopen(direccion, "rb+");
    if (Archivo==NULL) {
        printf("ERROR AL ABRIR EL ARCHIVO");
    }
}

void Datafile::abrir(){
    Archivo = fopen(direccion, "rb+");
}

void Datafile::cerrar(){
    fclose(Archivo);
}

void Datafile::escribir(char * data,int pos,int longitud)
{
    fseek(Archivo,pos,SEEK_SET);
    fwrite(data, 1,longitud,Archivo);
}

char * Datafile::leer(int pos,int longitud)
{
    char *data=new char[longitud];
    fseek(Archivo, pos, SEEK_SET);
    fread(data,1, longitud,Archivo);
    return data;
}

