
#ifndef ListaRegistro_hpp
#define ListaRegistro_hpp

#include <stdio.h>
#include "Registro.hpp"

class ListaRegistro{
public:
    Registro* inicio;
    ListaRegistro();
    void Insertar(char* Nom, int id);
    void ImprimirLista();
};

#endif /* ListaRegistro_hpp */
