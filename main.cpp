//
//  main.cpp
//  NewTree
//
//  Created by Luis Alvarez on 4/2/18.
//  Copyright © 2018 Luis Alvarez. All rights reserved.
//

#include <iostream>
#include "AVL.hpp"

using namespace std;

void Mostrar(char* d, int FE)
{
    cout << d << "(" << FE << "),";
}
int main(int argc, const char * argv[]) {
    AVL *ArbolInt = new AVL();
    //ArbolInt->Insertar("Ramirez");
    //ArbolInt->Insertar("Mena");
    //ArbolInt->IngresarNuevo();
    //ArbolInt->Recorrer("datab.dat");
    return 0;
}
