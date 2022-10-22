#ifndef LISTAD_H
#define LISTAD_H

typedef struct {
    int dado;
} tipoDados;

typedef struct No {
    tipoDados *d;
    struct No *prox;
} tipoNo;

typedef struct {
    tipoNo *prim, *ultimo;
} tipoLista;

tipoDados *criaDado(int num);

void push_front(tipoLista *pLista, tipoDados *al);

void push_back(tipoLista *pLista, tipoDados *al);

void pop_front(tipoLista *plista);

void pop_back(tipoLista *plista);

tipoLista *criaLista();

void mostraLista(tipoLista *pLista);

void destroiLista(tipoLista *pLista);

int vazia(tipoLista *plista);

#endif
