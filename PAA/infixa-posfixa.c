#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include<locale.h>
#include<math.h>

typedef struct stack{
    char *pilha;
    int topo;
    int tam;
    int nItens;
}*Pilha;


Pilha create(int tam){
	Pilha Ptp;
	Ptp = (Pilha)calloc(1,sizeof(Pilha));
	Ptp->pilha = (char*)calloc(tam,sizeof(char));
    if(Ptp != NULL){
    	Ptp->tam = tam;
        Ptp->topo=-1;
        Ptp->nItens=0;
    }
    return Ptp;
}


int isfull(Pilha Ptp){
	if(Ptp->nItens==Ptp->tam)
		return 1;
	else 
		return 0;
	
}

int isempty(Pilha Ptp){
	
	if(Ptp->nItens == 0)
		return 1;
	else
		return 0;
}

char* pop(Pilha Ptp){
	if(isempty(Ptp))
		return NULL;
	char *elem = (char*)calloc(1,sizeof(char)); 
	*elem = Ptp->pilha[Ptp->topo];
   	Ptp->topo--;
   	Ptp->nItens--;
   	return elem;
}

int push(Pilha Ptp,char x){
	if(isfull(Ptp))
		return 0;
	else
	{
	Ptp->topo++;
	Ptp->pilha[Ptp->topo] = x;
	Ptp->nItens++;
	}
	return 1;
}

char top(Pilha Ptp){
	if(isempty(Ptp))
		return '\0';
	return (Ptp->pilha[Ptp->topo]);
}

void mostrarPilha(Pilha Ptp)
{
	int i;
	for(i= Ptp->nItens-1;i>=0;i--)
		printf("\n[%d] = %c", i+1,Ptp->pilha[i]);
}

int pot(int x,int y)
{
	int i;
	for(i = 1;i < y; i++)
	{
		x *= x;
		return x;
	}
}

char* conversao(Pilha Ptp, char str[],int tam)
{
	int i,j=0;
	char *posfixa = (char*)calloc(tam,sizeof(char));
	for(i=0;i<tam;i++){
		switch(str[i]){
			case '(': push(Ptp,'(');
			break;
			
			case '+':
			case '-':
				while(top(Ptp)=='+'||top(Ptp)=='-'||top(Ptp)=='*'||top(Ptp)=='/'||top(Ptp)=='^')
					posfixa[j++]=*pop(Ptp);
				push(Ptp,str[i]);
				
				break;
				
			case '*':
			case '/':
				while(top(Ptp)=='*'||top(Ptp)=='/'||top(Ptp)=='^')
					posfixa[j++]=*pop(Ptp);
				push(Ptp,str[i]);
				
				break;
				
			case '^':
				while(top(Ptp)=='^')
					posfixa[j++]=*pop(Ptp);
				push(Ptp,str[i]);
				
				break;
				
			case ')':
				while(top(Ptp)!= '(')
					posfixa[j++]=*pop(Ptp);
				pop(Ptp);
			
				break;
				
				default: posfixa[j++]=str[i];
		}
	}
	while(!isempty(Ptp))
		posfixa[j++]=*pop(Ptp);
	printf("\nPos-fixa: %s",posfixa);
	return posfixa;
}

char Calc(Pilha Ptp, char *posfixa)
{
	int i, num1, num2,res;
	char result[10];
	for(i=0;i<strlen(posfixa);i++){
		switch(posfixa[i])
		{
			case '+':
				num1=atoi(pop(Ptp));
				num2=atoi(pop(Ptp));
				itoa((num2+num1),result,10);
				push(Ptp,result[0]);
				
			break;
			
			case '-':
				num1=atoi(pop(Ptp));
				num2=atoi(pop(Ptp));
				itoa((num2-num1),result,10);
				push(Ptp,result[0]);
				
			break;
			
			case '*':
				num1=atoi(pop(Ptp));
				num2=atoi(pop(Ptp));
				itoa((num2*num1),result,10);
				push(Ptp,result[0]);
				
				break;
				
			case '/':
				num1=atoi(pop(Ptp));
				num2=atoi(pop(Ptp));
				itoa((num2/num1),result,10);
				push(Ptp,result[0]);
				
				break;
				
			case '^':
				num1=atoi(pop(Ptp));
				num2=atoi(pop(Ptp));
				res=(pow(num2,num1));
				itoa(res,result,10);
				push(Ptp,result[0]);
				
				break;
				
				default: push(Ptp,posfixa[i]);
		}
	}
	return top(Ptp);
}



int main(void){
	system("color 73");
	setlocale(LC_ALL,"portuguese");
	int tam;
	char str[50];
	printf("Digite a expressao matematica desejada:");
	fflush(stdin);
	scanf("%s",str);
	Pilha Ptp = create(50);
	
    system("color 37");

    char *posfixa=conversao(Ptp,str,strlen(str));
    printf("\n\nO resultado é: %c",Calc(Ptp,posfixa));
    
    return 0;

}

