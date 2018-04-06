
#ifndef AVL_hpp
#define AVL_hpp

#include <stdio.h>
#include "Nodo.hpp"
#include <iostream>
#include "Datafile.h"
#include "stdlib.h"

using namespace std;

struct Regi {
    int id;
    char name[30];
    char lastname[30];
    char credit_card[25];
    char date[12];
    short int day;
    short int month;
    short int year;
    char payment_type[10];
    double total;
    char business_type[20];
    char business_name[50];
};

class AVL {
private:
    enum {IZQUIERDO, DERECHO};
    
    int contador;
    int altura;
    Datafile* data;
    
public:
    AVL(){
        raiz = NULL;
        actual = NULL;
    }
    ~AVL() {
        Podar(raiz);
    }
    Nodo *raiz;
    Nodo *actual;
    void Insertar(char* dat);
    void Borrar(char* dat);
    bool Buscar(char* dat);
    bool Vacio(Nodo *r) { return r==NULL; }
    bool EsHoja(Nodo *r) { return !r->derecho && !r->izquierdo; }
    const int NumeroNodos();
    const int AlturaArbol();
    int Altura(char* dat);
    void Raiz() { actual = raiz; }
    void InOrden(Nodo* nodo);
    void PreOrden(Nodo* nodo);
    void PostOrden(Nodo* nodo);

    void AgregarRegistro(char* id, int posfile, char* nombre);
    void AgregarRegistroAux(Nodo *n, char* id, int posfile, char* nombre);
    void ImprimirListas();
    void ImprimirListasAux(Nodo* nodo);
    
    void Recorrer(char *name);
    void IngresarNuevo();
    
private:
    void Equilibrar(Nodo *nodo, int, bool);
    void RSI(Nodo* nodo);
    void RSD(Nodo* nodo);
    void RDI(Nodo* nodo);
    void RDD(Nodo* nodo);
    void Podar(Nodo* &);
    void auxContador(Nodo*);
    void auxAltura(Nodo*, int);
};


#endif /* AVL_hpp */
