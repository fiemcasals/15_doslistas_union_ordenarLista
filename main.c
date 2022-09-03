#include "helper.h"

int main() {

    lista * lista1=newlist();

    insertarOrdenado(lista1, 5);
    insertarOrdenado(lista1, 2);
    insertarOrdenado(lista1, 6);
    insertarOrdenado(lista1, 3);
    insertarOrdenado(lista1, 8);
    insertarOrdenado(lista1, 9);

    lista * lista2=newlist();

    insertarOrdenado(lista2, 6);
    insertarOrdenado(lista2, 3);
    insertarOrdenado(lista2, 5);
    insertarOrdenado(lista2, 2);
    insertarOrdenado(lista2, 7);
    insertarOrdenado(lista2, 10);

    lista *lista3=unionListas(lista1,lista2);

    imprimir(lista3);


    return 0;
}
