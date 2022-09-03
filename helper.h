//
// Created by mauri on 03/09/22.
//

#ifndef INC_15_DOSLISTAS_UNION_ORDENARLISTA_HELPER_H
#define INC_15_DOSLISTAS_UNION_ORDENARLISTA_HELPER_H

typedef struct nodo{

    int cod;
    struct nodo * sig;
    struct nodo * ant;

}nodo;

typedef struct lista{

    int cant;
    nodo * pri;
    nodo * ult;

}lista;

lista * newlist(void);

nodo * newnodo(int);

void insertarOrdenado(lista*, int);

lista * unionListas(lista*,lista*);

void imprimir(lista*);

#endif //INC_15_DOSLISTAS_UNION_ORDENARLISTA_HELPER_H
