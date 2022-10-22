/* Código de implementação de uma lista simplesmente encadeada em C.
Autor: Aldemir Silva */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "listas.h"

#define TAM 1000 // Tamanho da lista encadeada que será criada.

/* Função que cria um elemento "tipoDados" a partir de
um inteiro e retorna o endereço do elemento. */
tipoDados *criaDado(int num) {
    tipoDados *aux = (tipoDados *) malloc(sizeof(tipoDados));
    aux->dado = num;
    return aux;
}

/* Função que insere um elemento "tipoDados" no
início de uma lista encadeada. */
void push_front(tipoLista *pLista, tipoDados *al) {
    tipoNo *aux;
    aux = (tipoNo *) malloc(sizeof(tipoNo));
    aux->d = al;
    aux->prox = pLista->prim;
    pLista->prim = aux;
}

/* Função que cria uma lista encadeada
e retorna o endereço dela na memória. */
tipoLista *criaLista() {
    tipoLista *lista = (tipoLista *) malloc(sizeof(tipoLista));
    lista->prim = NULL;
    return lista;
}

/* Função que exibe os elementos de uma lista encadeada. */
void mostraLista(tipoLista *pLista) {
    tipoNo *aux = pLista->prim;
    while (aux) {
        printf("%d ", aux->d->dado);
        aux = aux->prox;
    }
    printf("\n");
}

/* Função que desaloca da memória os elementos
de uma lista encadeada. */
void destroiLista(tipoLista *pLista) {
    tipoNo *anterior, *atual = pLista->prim;
    while (atual) {
        anterior = atual;
        atual = atual->prox;
        free(anterior->d);
        free(anterior);
    }
    free(pLista);
}

int main(void) {
    int num;

    /* Uma vez que a semente é constante os números gerados
    serão constantes. Também se pode utilizar srand(time(NULL)). */
    srand(42);

    tipoDados *d;

    tipoLista *lista = criaLista(); // Cria uma lista encadeada vazia (alocação dinâmica).

    /* Loop criado para inserir os números pseudo-aleatórios na lista encadeada. */
    for (int i = 0; i < TAM; i++) {
        num = rand() % 1000;
        d = criaDado(num);
        push_front(lista, d);
    }

    mostraLista(lista);

    destroiLista(lista);

    return 0;
}
