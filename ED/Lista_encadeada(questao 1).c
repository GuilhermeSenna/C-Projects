#include <stdio.h>
#include <stdlib.h>

struct lista
{
	int info;
	struct lista* prox;
	struct lista* ant;
};
typedef struct lista Lista;
typedef Lista *Listap;

void inserir_no_inicio(Listap *inicio,int x)
{
	Lista *novo_no;
	novo_no = (Listap)malloc(sizeof(Lista));
	novo_no->info=x;
	if(*inicio == NULL)
	{
        novo_no->prox = novo_no->ant = NULL;
        *inicio = novo_no;
	}
	else
	{
		novo_no->ant = NULL;
        novo_no->prox = *inicio;
        (*inicio)->ant = novo_no;
        *inicio = novo_no;
	}
}

void inserir_no_final(Listap *inicio,int x)
{
	Listap novo_no, aux;

     novo_no = (Listap)malloc(sizeof(Lista));

     if(*inicio == NULL){
         novo_no->info = x;
         novo_no->prox = novo_no->ant = NULL;
         *inicio = novo_no;
     }
     else{
         aux = *inicio;
         while(aux->prox != NULL)
             aux = aux->prox;

         novo_no->info = x;
         novo_no->ant = aux;
         novo_no->prox = NULL;
         aux->prox = novo_no;
     }
}

int esta_vazia(Listap l)
{
    return l == NULL;
}

void imprime_lista_ordem_direta(Listap l){

     if(esta_vazia(l))
         printf("\n\nA lista esta vazia.\n\n");
     else{
         printf("\nA lista eh:\n\n");
         while(l!= NULL){
             printf(" %d", l->info);
             l = l->prox;
         }
     }
}

void imprime_lista_ordem_inversa(Listap l){

     if(esta_vazia(l))
         printf("\n\nA lista esta vazia.\n\n");
     else{
         while(l->prox != NULL)
             l = l->prox;

         printf("\nA lista eh:\n\n");
         while(l != NULL){
             printf(" %d", l->info);
             l = l->ant;
         }

     }
}

int busca (Listap *inicio, int x)
{
 Listap aux;
 for (aux=*inicio; aux!=NULL; aux=aux->prox){

 	if (aux->info == x)
 	{
 	printf("\nValor encontrado = %d\n",aux->info);
 	return x;
	}
}
 	printf("\nValor nao encontrado.\n");
}

int retira(Listap *inicio, int x){

    Listap temporario, aux;

     if(*inicio == NULL)
        return 0;

    aux = *inicio;

    if((*inicio)->info == x)
        *inicio = (*inicio)->prox;

    while(aux!= NULL && aux->info != x)
        aux = aux->prox;

    if(aux == NULL)
        return 0;
    else{
        temporario = aux;

        if(aux->ant != NULL)
            aux->ant->prox = aux->prox;

        if(aux->prox != NULL)
            aux->prox->ant = aux->ant;

        free(temporario);
    }

    return 1;
}

char elimina_no(Listap *inicio){

    Listap temporario;
    int y;

    temporario = *inicio;
    y = (*inicio)->info;
    *inicio = (*inicio)->prox;
    free(temporario);

    return y;
}

void criar_vetor(Listap *inicio)
{

    char resp = 's';
    int i,tam=0,*vet;
    vet = malloc(sizeof(int));
    for(i=0;i<tam || (resp == 's' || resp == 'S');i++)
    {
        printf("\nDigite o valor a ser inserido no vetor: ");
        scanf("%d",&vet[i]);
        tam++;
        printf("\nDeseja inserir mais valores? (s/n)");
        fflush(stdin);
        resp = getchar();
    }
    for(i=0;i<tam;i++)
    {
        Listap novo_no, aux;
        novo_no = (Listap)malloc(sizeof(Lista));

        if(*inicio == NULL){
         novo_no->info = vet[i];
         novo_no->prox = novo_no->ant = NULL;
         *inicio = novo_no;
     }
     else{
         aux = *inicio;
         while(aux->prox != NULL)
             aux = aux->prox;

         novo_no->info = vet[i];
         novo_no->ant = aux;
         novo_no->prox = NULL;
         aux->prox = novo_no;
     }
    }
}


int main()
{
	char resp,cont;
	int x,m,n;
	Listap l = NULL;
	do{
	printf("Deseja= \n\n1 ->adicionar no inicio \n2 ->adicionar no final \n3 ->Buscar um elemento na lista \n4 ->remover um elemento da lista \n5 ->imprimir na ordem direta \n6 ->imprimir na ordem inversa \n7 ->gerar vetor(Questao 1).\n\n\n");
		printf("Apos acabar a funcao por favor escolha para continuar.");
		printf("\n\n\nDigite a opcao desejada= ");
		fflush(stdin);
		resp = getchar();

		switch(resp){

			case '1':
				system("cls");
				printf("Digite o valor a ser adicionado=");
				scanf("%d",&x);
				inserir_no_inicio(&l,x);
				break;

			case '2':
				system("cls");
				printf("Digite o valor a ser adicionado=");
				scanf("%d",&x);
				inserir_no_final(&l,x);
				break;

			case '3':
				system("cls");
				printf("Digite o valor a ser buscado:");
				scanf("%d",&x);
				busca(&l,x);
				break;

			case '4':
				system("cls");
				printf("\nDigite o valor a ser retirado: ");
                 scanf("\n%d", &x);
                 if(! retira(&l, x)){
                     printf("\nValor nao encontrado!\n\n");
                 }
                 break;


			case '5':
				system("cls");
				imprime_lista_ordem_direta(l);
				break;

			case '6':
				system("cls");
				imprime_lista_ordem_inversa(l);
				break;

            case '7':
                system("cls");
                criar_vetor(&l);
                break;

			default :
				printf("Opção escolhida nao entendida.");
				break;
		}
		printf("\nDeseja continuar? (s/n) = ");
		fflush(stdin);
		cont = getchar();
		system("cls");
	}while(cont =='s' || cont =='S');
	while(! esta_vazia(l)){
        printf("No %d retirado\n", elimina_no(&l));
    }
	printf("Lista liberada.\n\n\n");
	return 0;
}

