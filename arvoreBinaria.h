#ifndef _ARVOREBINARIA_H_
#define _ARVOREBINARIA_H_

#include <stdio.h>
#include <stdlib.h>

#define TAM 100

typedef struct tree {
    struct tree *esq;
    char info;
    struct tree *dir;
} tree_t;

tree_t *criaArvoreVazia(void);

tree_t *criaArvore(char c, tree_t *sae, tree_t *sad);

void imprimeArvore(tree_t *tree);

tree_t *destroiArvore(tree_t *tree);

int pertence(tree_t *tree, char c);

#endif
