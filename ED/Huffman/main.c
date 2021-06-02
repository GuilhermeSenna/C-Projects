#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAM 1000


/*      ESTRUTURA DO NO     */

typedef struct No
{
    char letra;
    int indice;
    char *simb;
    struct No *prox;
    struct No *ant;
    struct No *esq;
    struct No *dir;
} No;

/*********************************/
/*     PROTOTIPOS DE FUNÇÕES     */
/*********************************/

void frequencia(FILE *texto, No **ini, No **fim, int tam);
int ordenaLista(No **ini, No **fim, No *novo);
No* posAnt(No* ini, int ind);
No* huffman(No **ini, No **fim);
No* menor_daLista(No **raiz);
void gera_codigos(No *raiz);
void inorder(No *raiz);
void imprime_lista(No **ini);
void imprimeCodigo(char letra, char *cod);

int main(void)
{
    No *ini = NULL;
    No *fim = NULL;
    FILE *texto = NULL;

    frequencia(texto,&ini,&fim,256);

    imprime_lista(&ini);

    ini = huffman(&ini,&fim);
    imprime_lista(&ini);
    gera_codigos(ini);

    return 0;
}

/* FREQUENCIA                                                                                                */
/* FUNÇÃO: ARMAZENA EM UMA LISTA ENCADEADA A FREQUENCIA DE CADA LETRA DA STRING                               */
void frequencia(FILE *texto, No **ini, No **fim, int tam)
{
    int j;
    int i = 0;
    int cont = 0;
    int flag = 0;
    char nome[TAM] = {0};
    char *aux = (char *) malloc(tam);
    int freq = 0;
    No *novo = NULL;

    memset(aux,0,tam);

    texto = fopen("texto.txt", "r");

    fgets(nome, TAM, texto);

    fclose(texto);

    aux[cont++] = nome[i];                //ARMAZENA NA PRIMEIRA POSIÇÃO DO VETOR AUX O PRIMEIRO CARACTERE

    for(i=1; nome[i] != '\0'; i++)       //APENAS ARMAZENA NO VETOR AUX OS CARACTERES QUE NÃO FOREM REPETIDOS
    {
        flag = 0;

        for(j=0; j<i; j++)
        {
            if(nome[i] == nome[j])
                flag=1;
        }

        if(flag != 1)
        {
            aux[cont++]=nome[i];
        }
    }

    aux[cont] = '\0';

    printf("\n");
    printf("LISTA DE CARACTERES\n");
    printf("\n");

    int n = 0;

    for(i=0; aux[i]!='\0'; i++)
    {
        for(j=0; nome[j]!='\0'; j++)
            if(aux[i] == nome[j])         //INCREMENTA A FREQUENCIA DA LETRA EM QUESTÃO
                freq++;

        novo = (No*)malloc(sizeof(No));   //ALLOCA UM NO PARA ARMAZENAR OS CARACTERES COM A SUAS FREQUENCIAS
        novo->indice = freq;
        novo->letra = aux[i];
        novo->esq = NULL;
        novo->dir = NULL;

        printf("%d - %d, %c\n", ++n, novo->indice, novo->letra);

        ordenaLista(&*ini, &*fim, novo);   //INSERE O NO ORDENADO NA LISTA

        freq = 0;           //ZERA A FREQUENCIA PARA PROXIMO CARACTERE

    }
    free(aux);
}

int ordenaLista(No **ini, No **fim, No *novo)
{
    if((*ini) == NULL)
    {
        novo->prox = novo->ant = NULL;
        (*ini) = (*fim) = novo;
        return 1;
    }
    else if(novo->indice <= (*ini)->indice)
    {
        (*ini)->ant = novo;
        novo->prox = (*ini);
        novo->ant = NULL;
        (*ini) = novo;
        return 1;
    }
    else if(novo->indice >= (*fim)->indice)
    {
        (*fim)->prox = novo;
        novo->prox = NULL;
        novo->ant = (*fim);
        (*fim) = novo;
        return 1;
    }
    else
    {
        No *p = *ini;
        while(p->prox != NULL)
        {
            if(p->prox != NULL && novo->indice > p->indice)
            {
                if(novo->indice < p->prox->indice)
                {
                    novo->prox = p->prox;
                    p->prox->ant = novo;
                    novo->ant = p;
                    p->prox = novo;
                    return 1;
                }
                else
                {
                    p = p->prox;
                }
            }
            else if(novo->indice == p->indice)
            {
                novo->prox = p->prox;
                p->prox->ant = novo;
                novo->ant = p;
                p->prox = novo;
                return 1;
            }
            else
                break;
        }
    }
    return 1;
}

No* posAnt(No* ini, int ind)
{
    No *p = ini;
    while(p != NULL && p->indice != ind)
    {
        p = p->prox;
    }
    if(p != NULL)
    {
        if(p->prox != NULL)
            p->prox->ant = p->ant;
        p = p->prox;
    }

    return p;
}

void imprime_lista(No **ini)
{
    No *p = *ini;
    int n = 0;

    if(p == NULL)
        return ;

    while(p != NULL)
    {
        printf("\n%d - Letra: %c, Indice: %d", ++n, p->letra, p->indice);
        p = p->prox;
    }
}

No* huffman(No **ini, No **fim)
{
    No *p = *ini;

    while(p->prox != NULL)
    {
        No* tmp1 = p;
        No* tmp2 = tmp1->prox;
        int sum = tmp1->indice + tmp2->indice;

        No *novo = (No *) malloc(sizeof(No));
        novo->letra = 0;
        novo->indice = sum;

        novo->esq = tmp1;
        novo->dir = tmp2;

        ordenaLista(ini,fim,novo);

        *ini = posAnt(*ini,tmp1->indice);
        *ini = posAnt(*ini,tmp2->indice);

        p = *ini;
    }
    return p;
}

void inorder(No *raiz)
{
    if(raiz != NULL)
    {
        inorder(raiz->esq);
        printf("\nLetra: %c, Indice: %d\n", raiz->letra, raiz->indice);
        inorder(raiz->dir);
    }
}

No* menor_daLista(No **raiz)
{
    No *atual = *raiz;

    while(atual->esq != NULL)
        atual = atual->esq;

    return atual;
}

void gera_codigos(No *raiz)
{
    static int n = 0;
    static char map[TAM] = {0};

    if(raiz->esq != NULL)
    {
        map[n++] = '0';
        gera_codigos(raiz->esq);
    }

    if(raiz->dir != NULL)
    {
        map[n++] = '1';
        gera_codigos(raiz->dir);
    }

    if(raiz->esq == NULL && raiz->dir == NULL)
    {
        raiz->simb = (char *) malloc(n + 1);
        memset(raiz->simb,'\0',n+1);
        strcat(raiz->simb,map);
        imprimeCodigo(raiz->letra,raiz->simb);
    }

    n--;
    int i;
    for(i = n; map[i] != '\0'; i++)
    {
        map[i] = '\0';
    }
}

void imprimeCodigo(char letra, char *cod)
{
    printf("\n\n");
    printf("%c = %s", letra, cod);
}
