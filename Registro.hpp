
#ifndef Registro_hpp
#define Registro_hpp

#include <stdio.h>
#include <string.h>

class Registro {
public:
    char Nom[20];
    int ID;
    Registro* sig;
    Registro(char* nom, int i){
        ID=i;
        strcpy(Nom,nom);
        sig = NULL;
    }
};

#endif /* Registro_hpp */
