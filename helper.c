//
// Created by mauri on 03/09/22.
//

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include "helper.h"

void imprimir(lista * listaTrabajo) {

    int i=0;
    nodo * aux= listaTrabajo->pri;

    if(aux==NULL){
        printf("la lista esta vacia\n");
    }

    for(;aux!=NULL;aux=aux->sig){

        printf("%d:el codigo es: %d\n",i+1, aux->cod);
        i++;

    }
}


lista * newlist(void){

    lista * nueva = (lista *) malloc(sizeof (lista));

    if(nueva==NULL){
        printf("\nNo se ha podido asignar memoria a la nueva lista\n");
        exit(-1);
    }

    nueva->pri=NULL;
    nueva->cant=0;
    nueva->ult=NULL;

    return nueva;
}

nodo * newnodo(int cod){

    nodo * nuevo= (nodo *) malloc(sizeof (nodo));

    if(nuevo==NULL){
        printf("\nNo posee memoria suficiente, para crear un nuevo nodo\n");
        exit(-1);
    }

    nuevo->cod=cod;
    nuevo->sig=NULL;
    nuevo->ant=NULL;

    return nuevo;
}

void insertarOrdenado(lista * listaTrabajo, int numero) {

    nodo * aux= listaTrabajo->pri;

    nodo * nodoActual=newnodo(numero);

    if(aux==NULL){
        listaTrabajo->cant++;
        listaTrabajo->ult=nodoActual;
        listaTrabajo->pri=nodoActual;
    }else{

        if(aux->cod>numero){

            aux->ant=nodoActual;
            nodoActual->sig=aux;
            listaTrabajo->pri=nodoActual;
            listaTrabajo->cant++;
            return;
        }

        for(;aux->sig!=NULL && aux->sig->cod<=numero; aux=aux->sig){}

        if(aux->cod==numero){
            return;
        }
            nodoActual->sig=aux->sig;
            aux->sig=nodoActual;
            nodoActual->ant=aux;
            listaTrabajo->cant++;
    }

}

lista *unionListas(lista * L1, lista * L2) {

    lista * L3=newlist();

    nodo *aux1=L1->pri;

    for(;aux1!=NULL;aux1=aux1->sig){
        insertarOrdenado(L3,aux1->cod);
    }

    nodo *aux2=L2->pri;

    for(;aux2!=NULL;aux2=aux2->sig){
        insertarOrdenado(L3,aux2->cod);
    }

    return L3;
}
