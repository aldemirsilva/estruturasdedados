/* Implementação de uma árvore binária de busca sem cabeça baseado
no código apresentado em Deitel, C: como programar. O código apresentado no 
livro não contempla a função para desalocar a árvore da memória. */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAM 30

/* Estrutura autorreferenciada do nó */
struct treeNode {
    struct treeNode *esq; /* ponteiro para subárvore esquerda */
    int data; /* valor do nó */
    struct treeNode *dir; /* ponteiro para subárvore direita */
}; /* fim da estrutura treeNode */

typedef struct treeNode TreeNode; /* sinônimo para struct treeNode */
typedef TreeNode *TreeNodePtr; /* sinônimo para TreeNode* */

/* Função que recebe um ponteiro para uma árvore e um inteiro e
o insere na árvore. */
void insertNode(TreeNodePtr *treePtr, int value) {
    /* Caso a árvore esteja vazia, então aloca memória para a estrutura. */
    if (*treePtr == NULL) {
        *treePtr = (TreeNodePtr) malloc(sizeof(TreeNode));

        /* Verifica se a memória foi alocada, então atribui os dados. */
        if (*treePtr != NULL) {
            (*treePtr)->data = value;
            (*treePtr)->esq = NULL;
            (*treePtr)->dir = NULL;
        }
        else
            printf("%d Não inserido. Não há memória disponível.\n", value);
    }
    else { /* Caso a árvore não esteja vazia. */
        /* Caso em que o dado a ser inserido é menor que o dado no nó atual. */
        if (value < (*treePtr)->data)
            insertNode(&((*treePtr)->esq), value);
        /* Caso em que o dado a ser inserido é maior que o dado no nó atual. */
        else if (value > (*treePtr)->data)
            insertNode(&((*treePtr)->dir), value);
        /* Valor de dado duplicado. */
        else
            printf("dup ");
    }
}

/* Realiza o percurso na árvore na ordem simétrica. */
void inOrder(TreeNodePtr treePtr) {
    /* Se a árvore não está vazia, então realiza o percurso. */
    if (treePtr != NULL) {
        inOrder(treePtr->esq);
        printf("%4d", treePtr->data);
        inOrder(treePtr->dir);
    }
}

/* Realiza o percurso na árvore na pré-ordem. */
void preOrder(TreeNodePtr treePtr) {
    /* Se a árvore não está vazia, então realiza o percurso. */
    if (treePtr != NULL) {
        printf("%4d", treePtr->data);
        preOrder(treePtr->esq);
        preOrder(treePtr->dir);
    }
}

/* Realiza o percurso na árvore na pós-ordem. */
void postOrder(TreeNodePtr treePtr) {
    /* Se a árvore não está vazia, então realiza o percurso. */
    if (treePtr != NULL) {
        postOrder(treePtr->esq);
        postOrder(treePtr->dir);
        printf("%4d", treePtr->data);
    }
}

/* Função que recebe um ponteiro para
uma árvore e a desaloca da memória. */
void destroiArvore(TreeNodePtr tree) {
    if (tree) {
        destroiArvore(tree->esq);
        destroiArvore(tree->dir);
        free(tree);
    }
}

int main(void) {
    int i; /* Contador para loop de 1 até TAM */
    int item; /* Variável para manter valores aleatórios */
    TreeNodePtr rootPtr = NULL; /* Árvore inicialmente vazia */

    srand(time(NULL));
    printf("Os números que estão sendo colocados na árvore são:\n");

    /* Insere valores aleatórios entre 0 e 99 na árvore */
    for (i = 0; i < TAM; i++) {
        item = rand() % 100;
        insertNode(&rootPtr, item);
    }

    printf("\n\nO percurso na pré-ordem é:\n");
    preOrder(rootPtr);

    printf("\n\nO percurso na ordem simétrica é:\n");
    inOrder(rootPtr);

    printf("\n\nO percurso na pós-ordem é:\n");
    postOrder(rootPtr);

    printf("\n");

    destroiArvore(rootPtr);

    return 0;
}