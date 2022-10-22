/* Implementação de uma árvore binária sem cabeça em Linguagem C.
Baseado no código de Celes, W em "Introdução a estruturas de dados
com técnicas de programção em C". */

#include "arvoreBinaria.h"

// Função que cria uma árvore vazia.
tree_t *criaArvoreVazia() {
    return NULL;
}

/* Função que recebe um caractere, um ponteiro para sub-árvore esquerda,
um ponteiro para sub-árvore direita e cria uma árvore não vazia retornado o endereço 
da árvore. */
tree_t *criaArvore(char c, tree_t *sae, tree_t *sad) {
    tree_t *tree = (tree_t *) malloc(sizeof(tree_t));
    tree->info = c;
    tree->esq = sae;
    tree->dir = sad;
    return tree;
}

/* Função que recebe um ponteiro para uma árvore como entrada e imprime o conteúdo
da árvore. */
void imprimeArvore(tree_t *tree) {
    printf("<");
    if (!vazia(tree)) {
        printf("%c ", tree->info);
        imprimeArvore(tree->esq);
        imprimeArvore(tree->dir);
    }
    printf(">");
}

/* Função que recebe um ponteiro para
uma árvore e a desaloca da memória. */
tree_t *destroiArvore(tree_t *tree) {
    if (!vazia(tree)) {
        destroiArvore(tree->esq);
        destroiArvore(tree->dir);
        free(tree);
    }
}

/* Função que recebe como entrada um ponteiro para uma árvore na
memória e um caractere e verifica se o caractere pertence à árvore. */
int pertence(tree_t *tree, char c) {
    if (vazia(tree)) {
        return 0;
    }
    else {
        return tree->info == c || pertence(tree->esq, c) || pertence(tree->dir, c);
    }
}

/* Função principal que testa algumas das funcionalidades implementadas. */
int main (void) {
    tree_t *a = criaArvore('a',
                    criaArvore('b',
                    criaArvoreVazia(),
                    criaArvore('d', criaArvoreVazia(), criaArvoreVazia())
                    ),
                criaArvore('c',
                    criaArvore('e', criaArvoreVazia(), criaArvoreVazia()),
                    criaArvore('f', criaArvoreVazia(), criaArvoreVazia())
                    )
                );

    imprimeArvore(a);

    destroiArvore(a);

    return 0;
}