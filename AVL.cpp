#include "AVL.hpp"
#include "stdio.h"
#include "stdlib.h"


void AVL::Podar(Nodo* &nodo)
{
    
    if(nodo) {
        Podar(nodo->izquierdo);
        Podar(nodo->derecho);
        delete nodo;
        nodo = NULL;
    }
}


void AVL::Insertar(char* dat)
{
    Nodo *padre = NULL;
    
    cout << "Insertar: " << dat << endl;
    actual = raiz;
    
    while(!Vacio(actual) && dat != actual->apellido) {
        int cmp = strcmp(dat, actual->apellido);
        padre = actual;
        if(cmp > 0)
            actual = actual->derecho;
        else if(cmp < 0)
            actual = actual->izquierdo;
    }
    
    
    if(!Vacio(actual)) return;
    
    if(Vacio(padre)) raiz = new Nodo(dat);
    
    else if(dat < padre->apellido) {
        padre->izquierdo = new Nodo(dat, padre);
        Equilibrar(padre, IZQUIERDO, true);
    }
    
    else if(dat > padre->apellido) {
        padre->derecho = new Nodo(dat, padre);
        Equilibrar(padre, DERECHO, true);
    }
}


void AVL::Equilibrar(Nodo *nodo, int rama, bool nuevo)
{
    bool salir = false;
    
    
    while(nodo && !salir) {
        if(nuevo)
            if(rama == IZQUIERDO) nodo->FE--;
            else                  nodo->FE++;
            else
                if(rama == IZQUIERDO) nodo->FE++;
                else                  nodo->FE--;
        if(nodo->FE == 0) salir = true;
        
        else if(nodo->FE == -2) {
            if(nodo->izquierdo->FE == 1) RDD(nodo);
            else RSD(nodo);
            salir = true;
        }
        else if(nodo->FE == 2) {
            if(nodo->derecho->FE == -1) RDI(nodo);
            else RSI(nodo);
            salir = true;
        }
        if(nodo->padre)
            if(nodo->padre->derecho == nodo)
                rama = DERECHO;
            else
                rama = IZQUIERDO;
        nodo = nodo->padre;
    }
}

void AVL::RDD(Nodo* nodo)
{
    cout << "RDD" << endl;
    Nodo *Padre = nodo->padre;
    Nodo *P = nodo;
    Nodo *Q = P->izquierdo;
    Nodo *R = Q->derecho;
    Nodo *B = R->izquierdo;
    Nodo *C = R->derecho;
    
    if(Padre)
        if(Padre->derecho == nodo) Padre->derecho = R;
        else Padre->izquierdo = R;
        else raiz = R;
    
    
    Q->derecho = B;
    P->izquierdo = C;
    R->izquierdo = Q;
    R->derecho = P;
    
    R->padre = Padre;
    P->padre = Q->padre = R;
    if(B) B->padre = Q;
    if(C) C->padre = P;
    
    
    switch(R->FE) {
        case -1: Q->FE = 0; P->FE = 1; break;
        case 0:  Q->FE = 0; P->FE = 0; break;
        case 1:  Q->FE = -1; P->FE = 0; break;
    }
    R->FE = 0;
}


void AVL::RDI(Nodo* nodo)
{
    cout << "RDI" << endl;
    Nodo *Padre = nodo->padre;
    Nodo *P = nodo;
    Nodo *Q = P->derecho;
    Nodo *R = Q->izquierdo;
    Nodo *B = R->izquierdo;
    Nodo *C = R->derecho;
    
    if(Padre)
        if(Padre->derecho == nodo) Padre->derecho = R;
        else Padre->izquierdo = R;
        else raiz = R;
    
    
    P->derecho = B;
    Q->izquierdo = C;
    R->izquierdo = P;
    R->derecho = Q;
    
    
    R->padre = Padre;
    P->padre = Q->padre = R;
    if(B) B->padre = P;
    if(C) C->padre = Q;
    
    
    switch(R->FE) {
        case -1: P->FE = 0; Q->FE = 1; break;
        case 0:  P->FE = 0; Q->FE = 0; break;
        case 1:  P->FE = -1; Q->FE = 0; break;
    }
    R->FE = 0;
}


void AVL::RSD(Nodo* nodo)
{
    cout << "RSD" << endl;
    Nodo *Padre = nodo->padre;
    Nodo *P = nodo;
    Nodo *Q = P->izquierdo;
    Nodo *B = Q->derecho;
    
    if(Padre)
        if(Padre->derecho == P) Padre->derecho = Q;
        else Padre->izquierdo = Q;
        else raiz = Q;
    
    
    P->izquierdo = B;
    Q->derecho = P;
    
    
    P->padre = Q;
    if(B) B->padre = P;
    Q->padre = Padre;
    
    
    P->FE = 0;
    Q->FE = 0;
}


void AVL::RSI(Nodo* nodo)
{
    cout << "RSI" << endl;
    Nodo *Padre = nodo->padre;
    Nodo *P = nodo;
    Nodo *Q = P->derecho;
    Nodo *B = Q->izquierdo;
    
    if(Padre)
        if(Padre->derecho == P) Padre->derecho = Q;
        else Padre->izquierdo = Q;
        else raiz = Q;
    
    
    P->derecho = B;
    Q->izquierdo = P;
    
    
    P->padre = Q;
    if(B) B->padre = P;
    Q->padre = Padre;
    
    
    P->FE = 0;
    Q->FE = 0;
}


void AVL::Borrar(char* dat)
{
    Nodo *padre = NULL;
    Nodo *nodo;
    char aux[30];
    
    actual = raiz;
    
    while(!Vacio(actual)) {
        int cmp = strcmp(dat, actual->apellido);
        if(cmp == 0) {
            if(EsHoja(actual)) {
                if(padre)
                    if(padre->derecho == actual) padre->derecho = NULL;
                    else if(padre->izquierdo == actual)
                        padre->izquierdo = NULL;
                delete actual;
                actual = NULL;
                
                if((padre->derecho == actual && padre->FE == 1) ||
                   (padre->izquierdo == actual && padre->FE == -1)) {
                    padre->FE = 0;
                    actual = padre;
                    padre = actual->padre;
                }
                if(padre)
                    if(padre->derecho == actual) Equilibrar(padre, DERECHO, false);
                    else                         Equilibrar(padre, IZQUIERDO, false);
                return;
            }
            else {
                padre = actual;
                
                if(actual->derecho) {
                    nodo = actual->derecho;
                    while(nodo->izquierdo) {
                        padre = nodo;
                        nodo = nodo->izquierdo;
                    }
                }
                else {
                    nodo = actual->izquierdo;
                    while(nodo->derecho) {
                        padre = nodo;
                        nodo = nodo->derecho;
                    }
                }
                
                memcpy(aux, actual->apellido, 30);
                memcpy(actual->apellido, nodo->apellido, 30);
                memcpy(nodo->apellido, aux, 30);
                actual = nodo;
            }
        }
        else {
            padre = actual;
            if(dat > actual->apellido) actual = actual->derecho;
            else if(dat < actual->apellido) actual = actual->izquierdo;
        }
    }
}


void AVL::InOrden(Nodo* nodo)
{
    if(nodo!=NULL){
        InOrden(nodo->izquierdo);
        printf("%s\n", nodo->apellido);
        InOrden(nodo->izquierdo);
    }
}


void AVL::PreOrden(Nodo* nodo)
{
    if(nodo!=NULL){
        printf("%s\n", nodo->apellido);
        PreOrden(nodo->izquierdo);
        PreOrden(nodo->derecho);
    }
}


void AVL::PostOrden(Nodo* nodo)
{
    if(nodo!=NULL){
        PostOrden(nodo->izquierdo);
        PostOrden(nodo->derecho);
        printf("%s\n", nodo->apellido);
    }
}


bool AVL::Buscar(char* dat)
{
    actual = raiz;
    
    while(!Vacio(actual)) {
        int cmp = strcmp(dat, actual->apellido);
        if(cmp == 0)
            return true;
        else if(cmp > 0)
            actual = actual->derecho;
        else if(cmp < 0)
            actual = actual->izquierdo;
    }
    return false;
}


int AVL::Altura(char* dat)
{
    int altura = 0;
    actual = raiz;
    
    while(!Vacio(actual)) {
        int cmp = strcmp(dat, actual->apellido);
        if(cmp==0)
            return altura;
        else {
            altura++;
            if(cmp>0)
                actual = actual->derecho;
            else if(cmp<0)
                actual = actual->izquierdo;
        }
    }
    return -1;
}


const int AVL::NumeroNodos()
{
    contador = 0;
    
    auxContador(raiz);
    return contador;
}

void AVL::auxContador(Nodo *nodo)
{
    contador++;
    if(nodo->izquierdo)
        auxContador(nodo->izquierdo);
    if(nodo->derecho)
        auxContador(nodo->derecho);
}

const int AVL::AlturaArbol()
{
    altura = 0;
    
    auxAltura(raiz, 0);
    return altura;
}


void AVL::auxAltura(Nodo *nodo, int a)
{
    if(nodo->izquierdo)
        auxAltura(nodo->izquierdo, a+1);
    if(nodo->derecho)
        auxAltura(nodo->derecho, a+1);
    
    if(EsHoja(nodo) && a > altura)
        altura = a;
}

void AVL::AgregarRegistro(char* ape, int posfile, char* nombre){
    actual = raiz;
    
    while(!Vacio(actual)) {
        int cmp = strcmp(ape, actual->apellido);
        if(cmp == 0)
            actual->Lista->Insertar(nombre, posfile);
        else if(cmp > 0)
            actual = actual->derecho;
        else if(cmp < 0)
            actual = actual->izquierdo;
    }
}

void AVL::AgregarRegistroAux(Nodo* n ,char* ape, int posfile, char* nombre){
    while(!Vacio(n)) {
        int cmp = strcmp(ape, actual->apellido);
        if(cmp == 0){
            n->Lista->Insertar(nombre, posfile);
            n->Lista->ImprimirLista();
        }
        else if(cmp > 0)
            AgregarRegistroAux(n->derecho, ape, posfile, nombre);
        else if(cmp < 0)
            AgregarRegistroAux(n->izquierdo, ape, posfile, nombre);
    }
}

void AVL::ImprimirListas(){
    cout<<"Listando Registros"<<endl;
    ImprimirListasAux(raiz);
}

void AVL::ImprimirListasAux(Nodo* nodo){
    if (nodo!=NULL) {
        nodo->Lista->ImprimirLista();
        ImprimirListasAux(nodo->izquierdo);
        ImprimirListasAux(nodo->derecho);
    }
}

void AVL::Recorrer(char* name){
    data = new Datafile(name);
    data->abrir();
    int posicion = 0;
    int tamanio = (int)sizeof(Regi);
    Regi* registro;
    while (!feof(data->Archivo)) {
        char* datai = data->leer(posicion*tamanio, tamanio);
        memcpy(registro, datai, tamanio);
        printf("%d %s %s %s %s", registro->id,registro->name, registro->lastname, registro->credit_card, registro->date);
        printf(" %d %d %d %s",registro->day, registro->month, registro->year, registro->payment_type);
        printf(" %f %s %s\n",registro->total, registro->business_type, registro->business_name);
        posicion++;
    }
    data->cerrar();
}

void AVL::IngresarNuevo(){
    Regi registro;
    cout<<"ID: ";
    cin>>registro.id;
    cout<<"Nombre: ";
    cin>>registro.name;
    cout<<"Apellido: ";
    cin>>registro.lastname;
    cout<<"CreditCard: ";
    cin>>registro.credit_card;
    cout<<"Fecha: ";
    cin>>registro.date;
    cout<<"Dia: ";
    cin>>registro.day;
    cout<<"Mes: ";
    cin>>registro.month;
    cout<<"Año: ";
    cin>>registro.year;
    cout<<"Forma de Pago: ";
    cin>>registro.payment_type;
    cout<<"Total: ";
    cin>>registro.total;
    cout<<"Tipo de Negocio: ";
    cin>>registro.business_type;
    cout<<"Nombre del Negocio: ";
    cin>>registro.business_name;
    data = new Datafile((char*)"datab.dat");
    data->abrir();
    fwrite(&registro, sizeof(Regi), 1, data->Archivo);
    data->cerrar();
}
