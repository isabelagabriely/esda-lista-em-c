#include <stdio.h>
#include <string.h>

typedef struct{
    int chave;
    int prox;
} ELEMENTO;

#define MAX 100

typedef struct{
    ELEMENTO A[MAX];
    int posInicio;
    int posDisp;
} LISTA;

/* funcoes
- inicializar lista
- retornar quantidade de elementos
- exibir elementos
- buscar elemento
- criar elemento
- inserir elemento
- excluir elemento
- reinicializar lista 
*/

// inicializar lista
void inicializarLista (LISTA *l) {

    l->posInicio = -1;
    l->posDisp = 0;

    int i;

    for (i=0; i<MAX; i++)
        l->A[i].prox = i+1;

    l->A[MAX-1].prox = -1;
}

// retornar quantidade de elementos
int tamanhoLista (LISTA *l) {

    if (l->posInicio == -1)
        printf ("Lista vazia.\n");

    int posicao = l->posInicio;
    int tamanho = 0;

    while (posicao != -1) {
        tamanho++;
        posicao = l->A[posicao].prox;
    }

    return tamanho;
}

// exibir elementos
void exibirLista (LISTA *l) {

    if (l->posInicio == -1)
        printf ("Lista vazia.\n");

    int posicao = l->posInicio;

    while (posicao != -1) {
        printf ("%d\n", l->A[posicao].chave);
        posicao = l->A[posicao].prox;
    }
}

// buscar elemento
int buscarElemento (LISTA *l, int x) {

    int posicao = l->posInicio;

    while (posicao != -1 && l->A[posicao].chave != x)
        posicao = l->A[posicao].prox;

    if (posicao == -1)
        return -1;

    else
        return posicao;
}

// criar elemento
ELEMENTO criarElemento (int x) {
    ELEMENTO novo;
    novo.chave = x;
    return novo;
}

// inserir elemento
int inserirElemento (LISTA *l, ELEMENTO e) {

    if (l->posDisp == -1)
        return 0;

    int novo = l->posDisp;
    l->posDisp = l->A[novo].prox;
    l->A[novo] = e; 

    int anterior = -1;
    int posicao = l->posInicio;

    while (posicao != -1 && l->A[posicao].chave < e.chave) {
        anterior = posicao;
        posicao = l->A[posicao].prox;
    }

    l->A[novo].prox = posicao;

    if (anterior == -1) 
        l->posInicio = novo;

    else 
        l->A[anterior].prox = novo;

    return 1;
}

// excluir elemento
int excluirElemento (LISTA *l, int x) {

    int anterior = -1;
    int posicao = l->posInicio;

    while (posicao != -1 && l->A[posicao].chave != x) {
        anterior = posicao;
        posicao = l->A[posicao].prox;
    }

    if (posicao == -1)
        return -1;

    else {
        if (anterior == -1)
            l->posInicio = l->A[posicao].prox;

        else 
            l->A[anterior].prox = l->A[posicao].prox;

        l->A[posicao].prox = l->posDisp;
        l->posDisp = posicao;

        return 1;
    }
}

// reinicializar lista
void reinicializarLista (LISTA *l) {

    int i;

    for (i=0; i<MAX; i++) {
        l->A[i].chave = -1;
        l->A[i].prox = i+1;
    }

    l->A[MAX-1].prox= -1;

    l->posInicio = -1;
    l->posDisp = 0;
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
    int pos_buscar = buscarElemento (&l, 20);
    printf ("elemento buscado = %d\n\n\n", l.A[pos_buscar].chave);
    excluirElemento (&l, 20);
    printf ("tamanho da lista atualizada = %d\n", tamanhoLista (&l));
    printf ("LISTA ATUALIZADA \n");
    exibirLista (&l);
    printf ("\n\n");
    reinicializarLista (&l);
    exibirLista (&l);
    return 0;
}