#include <stdio.h>
#include <stdlib.h>

typedef struct aux {
    int chave;
    struct aux *prox;
} ELEMENTO;

typedef struct {
    ELEMENTO *inicio;
} LISTA;

/* funcoes
- inicializar lista
- retornar quantidade de elementos
- exibir elementos
- buscar elemento
- criar elemento (alocar espaço)
- inserir elemento
- excluir elemento
- reinicializar lista 
*/

// inicializar lista
void inicializarLista (LISTA *l) {
    l->inicio = NULL;
}

// retornar quantidade de elementos
int tamanhoLista (LISTA *l) {

    if (l->inicio == NULL)
        printf ("Lista vazia.\n");

    ELEMENTO *posicao = l->inicio;
    int tamanho = 0;

    while (posicao != NULL) {
        tamanho++;
        posicao = posicao->prox;
    }

    return tamanho;
}

// exibir elementos
void exibirLista (LISTA *l) {

    if (l->inicio == NULL)
        printf ("Lista vazia.\n");

    ELEMENTO *posicao = l->inicio;

    while (posicao != NULL) {
        printf ("%d\n", posicao->chave);
        posicao = posicao->prox;
    }
}

// buscar elemento
ELEMENTO* buscarElemento (LISTA *l, int x) {

    ELEMENTO *posicao = l->inicio;

    while (posicao != NULL && posicao->chave != x) {
        posicao = posicao->prox;
    }

    if (posicao == NULL) 
        return NULL;

    else
        return posicao;
    
}

// criar elemento
ELEMENTO* criarElemento (int x) {
    ELEMENTO *novo = (ELEMENTO*) malloc (sizeof (ELEMENTO));
    novo->chave = x;
    return novo;
}

// inserir elemento
void inserirElemento (LISTA *l, ELEMENTO *e) {

    ELEMENTO *anterior = NULL;
    ELEMENTO *posicao = l->inicio;

    while (posicao != NULL && posicao->chave < e->chave) {
        anterior = posicao;
        posicao = posicao->prox;
    }

    e->prox = posicao;

    if (anterior == NULL)
        l->inicio = e;

    else
        anterior->prox = e; 

    return 1;
}

// excluir elemento
int* excluirElemento (LISTA *l, int x) {

    ELEMENTO *anterior = NULL;
    ELEMENTO *posicao = l->inicio;

    while (posicao != NULL && posicao->chave != x) {
        anterior = posicao;
        posicao = posicao->prox;
    } 

    if (posicao == NULL)
        return NULL;

    else {
        if (anterior == NULL)
            l->inicio = posicao->prox;

        else
            anterior->prox = posicao->prox;

        free(posicao);

        return 1;
    }
}

// reinicializar lista
void reinicializarLista (LISTA *l) {

    ELEMENTO *posicao = l->inicio;
    ELEMENTO *apagar;

    while (posicao != NULL) {
        apagar = posicao;
        posicao = posicao->prox;
        free(apagar);
    }
    
    l->inicio = NULL;
}

int main () {
    LISTA l;
    inicializarLista (&l);
    inserirElemento (&l, criarElemento(20));
    inserirElemento (&l, criarElemento(10));
    inserirElemento (&l, criarElemento(30));
    inserirElemento (&l, criarElemento(40));
    printf ("tamanho da lista = %d\n", tamanhoLista (&l));
    printf ("LISTA \n");
    exibirLista (&l);
    printf ("\n\n");
    ELEMENTO *buscar = buscarElemento (&l, 20);
    printf ("elemento buscado = %d\n\n\n", buscar->chave);
    excluirElemento (&l, 20);
    printf ("tamanho da lista atualizada = %d\n", tamanhoLista (&l));
    printf ("LISTA ATUALIZADA \n");
    exibirLista (&l);
    return 0;
}