/* Código de implementação de um deque com cabeça em
Linguagem C utilizando lista encadeada.
Autor: Aldemir Silva */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "deque.h"

#define TAM 40 // Tamanho do deque que será criado.

/* Função que cria um elemento "tipoDados" a partir de
um inteiro e retorna o endereço do elemento. */
tipoDados *criaDado(int num) {
    tipoDados *aux = (tipoDados *) malloc(sizeof(tipoDados));
    aux->dado = num;
    return aux;
}

/* Função que insere um elemento "tipoDados" no início do deque em O(1). */
void push_front(tipoLista *pLista, tipoDados *al) {
    tipoNo *aux;
    aux = (tipoNo *) malloc(sizeof(tipoNo));
    aux->d = al;
    if (!pLista->prim) { // Caso em que a lista está vazia.
        pLista->ultimo = aux;
    }
    aux->prox = pLista->prim;
    pLista->prim = aux;
}

/* Função que insere um elemento "tipoDados" no fim do deque em O(1). */
void push_back(tipoLista *pLista, tipoDados *al) {
    tipoNo *aux;
    aux = (tipoNo *) malloc(sizeof(tipoNo));
    aux->d = al;
    aux->prox = NULL;
    if (!pLista->prim) { // Caso em que a lista está vazia.
        pLista->prim = aux;
    } else { // Caso em que a lista não está vazia.
        pLista->ultimo->prox = aux;
    }
    pLista->ultimo = aux;
}

/* Função que remove o primeiro elemento do deque e o faz em tempo O(1).
Se a lista está vazia a função não faz nada */
void pop_front(tipoLista *plista) {
    tipoNo *aux = plista->prim;
    if (aux) { // Caso em que a lista não está vazia.
        plista->prim = plista->prim->prox;
        free(aux);
    }
}

/* Função que remove o útlimo elemento do deque e o faz em tempo O(n).
Se a lista está vazia a função não faz nada */
void pop_back(tipoLista *plista) {
    tipoNo *aux = plista->prim;
    if (aux == plista->ultimo && aux != NULL) { // Caso em que só há um elemento na lista.
        free(aux);
        plista->prim = NULL;
        plista->ultimo = NULL;
    } else if (aux) { // Caso em que há mais de um elemento na lista.
        while (aux->prox != plista->ultimo) {
            aux = aux->prox;
        }
        free(plista->ultimo);
        plista->ultimo = aux;
        aux->prox = NULL;
    }
}

/* Função que cria um deque e retorna o endereço dele na memória. */
tipoLista *criaLista() {
    tipoLista *plista = (tipoLista *) malloc(sizeof(tipoLista));
    plista->prim = NULL;
    plista->ultimo = NULL;
    return plista;
}

/* Função que exibe os elementos do deque. */
void mostraLista(tipoLista *pLista) {
    tipoNo *aux = pLista->prim;
    while (aux) {
        printf("%d ", aux->d->dado);
        aux = aux->prox;
    }
    printf("\n");
}

/* Função que desaloca da memória os elementos do deque. */
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

// Função que testa se um deque está vazio.
int vazia(tipoLista *plista) {
    return plista->prim == NULL;
}

// Código implementado para testar as funções.
int main(void) {
    /* Uma vez que a semente é constante os números gerados
    serão constantes. Também se pode utilizar srand(time(NULL))
    para variar os números. */
    srand(42);

    int num;

    tipoDados *d;

    // Cria um deque vazio utilizando alocação dinâmica.
    tipoLista *lista = criaLista();

    /* Loop para inserir os números pseudo-aleatórios no deque. */
    for (int i = 0; i < TAM; i++) {
        num = rand() % 1000;
        d = criaDado(num);
        push_back(lista, d);
    }

    // Loop para remover todos os números pelo fim do deque.
    while (lista->prim) {
        mostraLista(lista);
        pop_back(lista);
    }

    /* Loop para inserir os números pseudo-aleatórios no deque. */
    for (int i = 0; i < TAM; i++) {
        num = rand() % 1000;
        d = criaDado(num);
        push_back(lista, d);
    }

    // Loop para remover todos os números pelo início do deque.
    while (lista->prim) {
        mostraLista(lista);
        pop_front(lista);
    }

    printf("%d\n", vazia(lista));

    destroiLista(lista);

    return 0;
}
