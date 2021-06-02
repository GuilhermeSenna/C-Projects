#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define Quantum = 100;

struct fila
{
	int ID;
	int tempo_de_execucao;
	struct fila* prox;
};
typedef struct fila Fila;
typedef Fila* Filap;



void inserir(Fila **inicio,int id)
{
	Fila* novo_no;
	Fila* aux;
    novo_no = (Fila*)malloc(sizeof(Fila));

     if(*inicio == NULL){
         novo_no->ID = id;
         novo_no->tempo_de_execucao = (rand() % 35)*10;
         while(novo_no->tempo_de_execucao == 0)
            novo_no->tempo_de_execucao = (rand() % 35)*10;
         novo_no->prox = NULL;
         *inicio = novo_no;
     }
     else{
         aux = *inicio;
         while(aux->prox != NULL)
             aux = aux->prox;

         novo_no->ID = id;
         novo_no->tempo_de_execucao = (rand() % 35)*10;
         while(novo_no->tempo_de_execucao == 0)
            novo_no->tempo_de_execucao = (rand() % 35)*10;
         novo_no->prox = NULL;
         aux->prox = novo_no;
     }
}

int esta_vazia(Fila* inicio)
{
    return inicio == NULL;
}

void imprime_filap(Fila* inicio){
     if(esta_vazia(inicio))
         printf("\n\nA fila de processos pendentes esta vazia.\n\n");
     else{
         printf("\nA fila de processos pendentes eh:\n\n");
         while(inicio!= NULL){
             printf("   ID     ||        tempo de execucao\n");
             printf("   %d   \t\t\t%d", inicio->ID, inicio->tempo_de_execucao);
             inicio = inicio->prox;
             printf("\n");
         }
     }
}

void imprime_filaf(Fila* inicio){

     if(inicio == NULL)
         printf("\n\nA fila de processos em andamento esta vazia.\n\n");
     else{
         printf("\nA fila de processos em andamento eh:\n\n");
         while(inicio!= NULL){
             printf("   ID     ||        tempo de execucao\n");
             printf("   %d   \t\t\t%d", inicio->ID, inicio->tempo_de_execucao);
             inicio = inicio->prox;
             printf("\n");
         }
     }
}

/*
int elimina_no(Listap *inicio){

    Listap temporario;
    int y;

    temporario = *inicio;
    y = (*inicio)->info;
    *inicio = (*inicio)->prox;
    free(temporario);

    return y;
}
*/

Fila* numero_processos(Fila* inicioP)
{
    int id,process;
    printf("Digite o numero de processos desejados. (Max funcional = 3). \n->");
	scanf("%d",&process);
	while(process<= 0)
    {
        printf("Digite um numero de processos desejados maior que 0.\n->");
        scanf("%d",&process);
    }

	for(id=0;id<process;id++)
         inserir(&inicioP,id);
    return inicioP;
}

void Tempo_maquina(Fila** iniciop, Fila** iniciof)
{
    Fila* aux;
    Fila* aux2;
    if(*iniciof == NULL) //Nao existir Processos pendentes
         {
            *iniciof = *iniciop;
            *iniciop = (*iniciop)->prox;
            if((*iniciof)->prox != NULL)
                (*iniciof)->prox = NULL;
            if((*iniciof)->tempo_de_execucao<=100)
            {
                (*iniciof)->tempo_de_execucao = 0;
                 printf("\n >>>>>>>>>>>>>. Processo ID %d finalizado! <<<<<<<<<<<<<<<\n",(*iniciof)->ID);
                 if((*iniciof)->prox != NULL)
                 {
                    (*iniciof) == NULL;
                 }
                 else{
                    (*iniciof) = (*iniciof)->prox;
                 }
            }
            else{
                (*iniciof)->tempo_de_execucao -= 100;
                (*iniciof)->prox = NULL;
            }
        }
    else{
            if((*iniciof)->tempo_de_execucao == 0)
            {
                if((*iniciof)->prox != NULL)
                {
                    (*iniciof) = (*iniciof)->prox;
                }
                else
                {
                    (*iniciof) = NULL;
                    return ;
                }
            }
            if((*iniciop)!= NULL)
            {
                if((*iniciop)->prox == NULL)
                {
                    if((*iniciof)->prox == NULL)
                    {
                        (*iniciop)->prox = (*iniciof);
                        (*iniciof) = (*iniciop);
                        (*iniciop) = NULL;
                         if((*iniciof)->tempo_de_execucao>100)
                         {
                            (*iniciof)->tempo_de_execucao -= 100;
                         }
                         else{
                            (*iniciof)->tempo_de_execucao = 0;
                            printf("\n >>>>>>>>>>>>>. Processo ID %d finalizado! <<<<<<<<<<<<<<<\n",(*iniciof)->ID);
                            (*iniciof) = (*iniciof)->prox;
                         }
                    }
                    else{
                        aux = (*iniciof)->prox;
                        aux->prox = (*iniciof);
                        (*iniciof)->prox = NULL;
                        (*iniciof) = aux;
                        while(aux->prox != NULL)
                            aux = aux->prox;
                        aux->prox = (*iniciop);
                        (*iniciop) = NULL;
                        (*iniciof)->tempo_de_execucao -= 100;
                    }
                }
            }
            else{
                if((*iniciof)->prox == NULL)
                {
                    if((*iniciof)->tempo_de_execucao>100)
                        {
                            (*iniciof)->tempo_de_execucao -= 100;
                         }
                         else{
                            (*iniciof)->tempo_de_execucao = 0;
                            printf("\n >>>>>>>>>>>>>. Processo ID %d finalizado! <<<<<<<<<<<<<<<\n",(*iniciof)->ID);
                            (*iniciof) = (*iniciof)->prox;
                        }
                }
                else{
                     if((*iniciof)->tempo_de_execucao>100)
                        {
                            (*iniciof)->tempo_de_execucao -= 100;
                             aux2 = aux = (*iniciof);
                             while(aux->prox != NULL)
                                aux = aux->prox;
                             aux->prox = (*iniciof);
                             (*iniciof)->prox = NULL;
                             (*iniciof) = aux2;
                         }
                         else{
                            (*iniciof)->tempo_de_execucao = 0;
                            printf("\n >>>>>>>>>>>>>. Processo ID %d finalizado! <<<<<<<<<<<<<<<\n",(*iniciof)->ID);
                            (*iniciof) = (*iniciof)->prox;
                         }
                }
            }
    }
}

int main()
{
    int temp=0;
    char resp;
    Fila* inicioP;
    Fila* inicioF;
    inicioP = inicioF = NULL;
    srand(time(NULL));
    inicioP = numero_processos(inicioP);
    while(1)
    {
        printf("----------------------------------------------------------------------");
        printf("\n\n->Tempo passado = %dms\n\n",temp);
        imprime_filap(inicioP);
        imprime_filaf(inicioF);
        if(inicioP == NULL && inicioF == NULL)
        {
            printf("\n\n\n Sem processos restantes. Programa finalizado.\n\n\n");
            break;
        }
        printf("Deseja passar um tempo de maquina? (Quantum = 100)?\n->");
        fflush(stdin);
        resp = getchar();
        if(resp == 's' || resp == 'S')
        {
            Tempo_maquina(&inicioP,&inicioF);
            temp += 100;
        }
        else{
            break;
        }
    }
	return 0;
}
