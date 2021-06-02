#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include<string.h>

typedef struct stack{
    char *pilha;
    int topo;
    int tam;
}Pilha;


void create(Pilha *Ptp){
	printf("Digite o tamanho para a pilha:");
	scanf("%d",&Ptp->tam);
	Ptp->pilha = (char*)malloc(sizeof(char)*Ptp->tam);
    if(Ptp != NULL)
        Ptp->topo = -1;
}


bool isfull(Pilha *Ptp){
	if(Ptp->topo == Ptp->tam-1)
		return true;
	else 
		return false;
	
}

bool isempty(Pilha *Ptp){
	
	if(Ptp->topo == -1)
		return true;
	else
		return false;
}

char pop(Pilha *Ptp){
	if(isempty(Ptp))
		return 0;
	else
	{
	char aux; 
	strcpy(aux, Ptp->pilha[Ptp->topo]);
   	Ptp->topo--;
   	return aux;
	}
}

void push(Pilha *Ptp,char x){
	if(isfull(Ptp))
		return 0;
	else
	{
	Ptp->topo++;
	Ptp->pilha[Ptp->topo] = x;
	}
}

char top(Pilha *Ptp){
	 printf("Topo = %s",Ptp->pilha[Ptp->topo]);
}

void free(Pilha *Ptp){
	free(Ptp->pilha);
	Ptp->pilha == NULL;
}


int main(void){
	int op;
	char x[30];
	Pilha endereco;
	
    system("color 37");
    
    printf("\n\nCriando a pilha.\n\n");

    create(&endereco);

	while( 1 ){

		printf("\n1- empilhar (push)\n");
		printf("2- desempilhar (POP)\n");
		printf("3- Mostrar o topo \n");
		printf("4- sair\n");
		printf("\nopcao? ");
		scanf("%d", &op);

		switch (op){

			case 1:
					printf("Qual o valor a ser colocado?");
					fflush(stdin);
					fgets(x,30,stdin);
					push(&endereco,x);
				break;

			case 2:
					strcpy (x,pop(&endereco);
					printf ( "\n%s DESEMPILHADO!\n", x );
				break;

			case 3:
					top(&endereco);
				break;

			case 4: 
				return 0;

			default: printf( "\nOPCAO INVALIDA! \n" );
		}
	}
	
}

