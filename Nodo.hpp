

#ifndef Nodo_hpp
#define Nodo_hpp

#include <stdio.h>
#include "ListaRegistro.hpp"

class Nodo {
public:
    Nodo(char* dat, Nodo *pad=NULL, Nodo *izq=NULL, Nodo *der=NULL){
        memcpy(apellido, dat, 30);
    }
    ListaRegistro* Lista = new ListaRegistro();
    char apellido[30];
    int FE;
    Nodo *izquierdo;
    Nodo *derecho;
    Nodo *padre;
    friend class AVL;
};


#endif /* Nodo_hpp */
