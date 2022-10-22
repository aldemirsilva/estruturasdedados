#ifndef LISTAS_H
#define LISTAS_H

typedef struct {
    int dado;
} tipoDados;

typedef struct No {
    tipoDados *d;
    struct No *prox;
} tipoNo;

typedef struct {
    tipoNo *prim;
} tipoLista;

tipoDados *criaDado(int num);

void push_front(tipoLista *pLista, tipoDados *al);

tipoLista *criaLista();

void mostraLista(tipoLista *pLista);

void destroiLista(tipoLista *pLista);

#endif