
#include "ListaRegistro.hpp"

ListaRegistro::ListaRegistro(){
    inicio = NULL;
}

void ListaRegistro::Insertar(char *nom, int i){
    if (inicio==NULL) {
        inicio = new Registro(nom,i);
    } else {
        Registro* temp = inicio;
        while (temp->sig != NULL) {
            temp = temp->sig;
        }
        temp->sig = new Registro(nom,i);
    }
}

void ListaRegistro::ImprimirLista(){
    printf("Listando...\n");
    for(Registro*tmp=inicio; tmp!=NULL; tmp=tmp->sig)
    {
        printf("%s-%d\n", tmp->Nom, tmp->ID);
    }
}
