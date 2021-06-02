#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <locale.h>

int *geraArray(int tam);
void imprimeArray(int *vet, int tam);
void BubbleSort (int *vet, int tam);
void InsertSort(int *vet, int tam);
void QuickSort(int *vet, int inicio, int fim);
void SelectionSort(int *vet, int tam);
void GnomeSort(int *vet, int tam);
void MergeSort(int *vet, int tam);
int menu();
void swap(int *A, int *B);
void sort(int *vet, int *aux, int i, int f);
void merge(int *vet, int *aux, int i, int m, int f);
int *geraArray1M(int tam);

int main(void){
setlocale(LC_ALL,"portuguese");
int opcao, tam=0, *vet= NULL, res = 0,i=0,op;
float tempo,soma;
clock_t inicio,fim;

do{
opcao = menu();

switch(opcao){

///////////////////////////////////////////////////////////

case 0:
system("cls");
printf("Digite o ordenado para verificar o tempo:\n\n");
printf("1) BubbleSort:\n");
printf("2) InsertionSort:\n");
printf("3) QuickSort:\n");
printf("4) SelectionSort:\n");
printf("5) GnomeSort:\n");
printf("6) MergeSort:\n");
printf("7) Cancelar o programa:\n");
printf("->");
scanf("%d",&op);

    switch(op){

case 1:
system("CLS");
tempo = 0;
soma = 0;
for(i=0;i<1000;i++)
{
tam = 1000000; //Bubble
vet = geraArray1M(tam);
inicio = clock();
BubbleSort(vet,tam);
fim = clock();
printf("\nTempo gasto: %4.0f ms\n\n",tempo = (1000*(double)(fim-inicio)/(double)(CLOCKS_PER_SEC)));
soma = soma + tempo;
}
printf("\n\n\n O Valor medio de execucao do BubbleSort foi: %f ms\n\n",soma/1000);
system("pause");
break;

case 2:

system("CLS");
tempo = 0;
soma = 0;
for(i=0;i<1000;i++)
{
tam = 1000000; //Insertion
vet = geraArray1M(tam);
inicio = clock();
InsertSort(vet,tam);
fim = clock();
printf("\nTempo gasto: %4.0f ms\n\n",tempo = (1000*(double)(fim-inicio)/(double)(CLOCKS_PER_SEC)));
soma = soma + tempo;
}
printf("\n\n\n O Valor medio de execucao do InsertionSort foi: %f ms\n\n",soma/1000);
system("pause");
break;

case 3:
system("CLS");
tempo = 0;
soma = 0;
for(i=0;i<1000;i++)
{
tam = 1000000; //Quick
vet = geraArray1M(tam);
inicio = clock();
QuickSort(vet, 0, tam-1);
fim = clock();
printf("\nTempo gasto: %4.0f ms\n\n",tempo = (1000*(double)(fim-inicio)/(double)(CLOCKS_PER_SEC)));
soma = soma + tempo;
}
printf("\n\n\n O Valor medio de execucao do QuickSort foi: %f ms\n\n",soma/1000);
system("pause");
break;

case 4:

system("CLS");
tempo = 0;
soma = 0;
for(i=0;i<1000;i++)
{
tam = 1000000; //Selection
vet = geraArray1M(tam);
inicio = clock();
SelectionSort(vet,tam);
fim = clock();
printf("\nTempo gasto: %4.0f ms\n\n",tempo = (1000*(double)(fim-inicio)/(double)(CLOCKS_PER_SEC)));
soma = soma + tempo;
}
printf("\n\n\n O Valor medio de execucao do SelectionSort foi: %f ms\n\n",soma/1000);
system("pause");
break;

case 5:

system("CLS");
tempo = 0;
soma = 0;
for(i=0;i<1000;i++)
{
tam = 1000000; //Gnome
vet = geraArray1M(tam);
inicio = clock();
GnomeSort(vet,tam);
fim = clock();
printf("\nTempo gasto: %4.0f ms\n\n",tempo = (1000*(double)(fim-inicio)/(double)(CLOCKS_PER_SEC)));
soma = soma + tempo;
}
printf("\n\n\n O Valor medio de execucao do GnomeSort foi: %f ms\n\n",soma/1000);
system("pause");
break;

case 6:
system("CLS");
tempo = 0;
soma = 0;
for(i=0;i<1000;i++)
{
tam = 1000000; //Merge
vet = geraArray1M(tam);
inicio = clock();
MergeSort(vet,tam);
fim = clock();
printf("\nTempo gasto: %4.0f ms\n\n",tempo = (1000*(double)(fim-inicio)/(double)(CLOCKS_PER_SEC)));
soma = soma + tempo;
}
printf("\n\n\n O Valor medio de execucao do MergeSort foi: %f ms\n\n",soma/1000);
system("pause");
break;


case 7:
return 0;
break;

}

////////////////////////////////////////////////////////////////////////
case 1:
system("CLS");
srand((unsigned) time(NULL));
printf("Insira o tamanho do vetor: ");
scanf("%d", &tam);
vet = geraArray(tam);
break;

case 2:
imprimeArray(vet, tam);
system("PAUSE");
system("CLS");
break;

case 3:
printf("Ordenando ...\n");
inicio = clock();
BubbleSort(vet, tam);
fim = clock();
printf("Tempo gasto: %4.0f ms\n\n",1000*(double)(fim-inicio)/(double)(CLOCKS_PER_SEC));
break;

case 4:
printf("Ordenando ...\n");
inicio = clock();
InsertSort(vet, tam);
fim = clock();
printf("Tempo gasto: %4.0f ms\n\n",1000*(double)(fim-inicio)/(double)(CLOCKS_PER_SEC));
break;

case 5:
printf("Ordenando ...\n");
inicio = clock();
QuickSort(vet, 0, tam-1);
fim = clock();
printf("Tempo gasto: %4.0f ms\n\n",1000*(double)(fim-inicio)/(double)(CLOCKS_PER_SEC));
break;

case 6:
printf("Ordenando ...\n");
inicio = clock();
SelectionSort(vet, tam);
fim = clock();
printf("Tempo gasto: %4.0f ms\n\n",1000*(double)(fim-inicio)/(double)(CLOCKS_PER_SEC));
break;

case 7:
printf("Ordenando ...\n");
inicio = clock();
GnomeSort(vet, tam);
fim = clock();
printf("Tempo gasto: %4.0f ms\n\n",1000*(double)(fim-inicio)/(double)(CLOCKS_PER_SEC));
break;

case 8:
printf("Ordenando ...\n");
inicio = clock();
MergeSort(vet, tam);
fim = clock();
printf("Tempo gasto: %4.0f ms\n\n",1000*(double)(fim-inicio)/(double)(CLOCKS_PER_SEC));
break;

free(vet);
return 0;
}


}while(opcao != 9);
return 0;
}

int menu(){

int opcao=0;

do{
printf("O que você gostaria de fazer?\n\n");
printf("0 - vetor de 1.000.000 (1 milhao) + loop 1000 vezes + valor medio.\n");
printf("1 - Gerar um vetor aleatoriamente\n");
printf("2 - Imprimir Vetor\n");
printf("3 - Ordenar - Bubble Sort\n");
printf("4 - Ordenar - Insertion Sort\n");
printf("5 - Ordenar - Quick Sort\n");
printf("6 - Ordenar - Selection Sort\n");
printf("7 - Ordenar - Gnome Sort\n");
printf("8 - Ordenar - Merge Sort\n");
printf("9 - Fechar programa\n");
printf("-> ");
scanf("%d",&opcao);
if (opcao<0 || opcao> 9)
printf("\nOpcao invalida! Insira novamente\n\n");
} while(opcao<0 || opcao>9);
return opcao;
}

int *geraArray(int tam)
{
    int i, *array;
	array = (int*)malloc(sizeof(int)*tam);
	srand(time(NULL));
	for(i=0;i<tam;i++){
		array[i] = i + 1;
	}
	for(i=0;i<tam;i++)
	{
		swap(&array[i], &array[rand()%tam]);
	}
	return array;
}


void imprimeArray(int *vet, int tam)
{
    int i;
    for (i=0; i < tam; i++)
    {
        if (i % 2 == 0)
        {
            printf ("\n");
        }
        printf ("array[%4d]= %4d | ", i, vet[i]);
    }
    printf("\n\n\n\n\n");
}


void BubbleSort (int *vet, int tam)
{
    int i, j, aux;
    for (j=tam; j>0; j--)
    {
        for(i=0; i<j; i++)
            if (vet[i] > vet[i+1])
            {
                aux = vet[i];
                vet[i] = vet[i+1];
                vet[i+1] = aux;
            }
    }
}


void InsertSort(int *vet, int tam)
{
    int i, j, aux;
    for (i = 1; i < tam; i++)
    {
        j = i;
        while (j > 0 && vet[j - 1] > vet[j])
        {
            aux = vet[j];
            vet[j] = vet[j - 1];
            vet[j - 1] = aux;
            j--;
        }
     }
}


void QuickSort(int *vet, int inicio, int fim)
{

   int pivo, aux, i, j, meio;
   i = inicio;
   j=fim;
   meio = (int) ((i + j) / 2);
   pivo = vet[meio];

   do{
      while (vet[i] < pivo) i = i + 1;
      while (vet[j] > pivo) j = j - 1;

      if(i <= j)
      {
         aux = vet[i];
         vet[i] = vet[j];
         vet[j] = aux;
         i = i + 1;
         j = j - 1;
      }

   }while(j > i);

   if(inicio < j) QuickSort(vet, inicio, j);
   if(i < fim) QuickSort(vet, i, fim);
}

void SelectionSort(int *vet, int tam)
{
    int i, min, j, aux;
    for (i=0; i<tam-1; i++)
    {
        min = i;
        for (j=i+1; j<tam; j++)
        {
            if (vet[j]<vet[min])
                min = j;
        aux = vet[min];
        vet[min] = vet[i];
        vet[i] = aux;
        }
    }
}

void GnomeSort(int *vet, int tam)
{
    int pivo = 0,aux;

    while (pivo < tam)
    {
        if (pivo == 0)
            pivo++;
        if (vet[pivo] >= vet[pivo-1])
            pivo++;
        else
        {
            aux = vet[pivo];
            vet[pivo] = vet[pivo-1];
            vet[pivo-1] = aux;
            pivo--;
        }
    }
}

void MergeSort(int *vet, int tam)
{
  int *aux = (int*)malloc(sizeof(int)*tam);
  sort(vet, aux, 0, tam - 1);
  free(aux);
}

void sort(int *vet, int *aux, int i, int f) {
  if (i >= f)
	return ;

  int m = (i + f) / 2;

  sort(vet, aux, i, m);
  sort(vet, aux, m + 1, f);

  if (vet[m] <= vet[m + 1])
  	return ;

  merge(vet, aux, i, m, f);
}

void merge(int *vet, int *aux, int i, int m, int f) {
  int z,iv = i, ic = m + 1; //iv = inicio do vetor, ic = inicio do auxiliar

  for (z = i; z <= f; z++)
  	aux[z] = vet[z];

  z = i;

  while (iv <= m && ic <= f) {
    if (aux[iv] < aux[ic])
		vet[z++] = aux[iv++];
    else
		vet[z++] = aux[ic++];
  }

  while (iv <= m)
  	vet[z++] = aux[iv++];

  while (ic <= f)
  	vet[z++] = aux[ic++];
}


void swap(int *A, int *B){
	int X = *B;

	*B = *A;

	*A = X;
}

int *geraArray1M(int tam)
{
    int i, *array;
	array = (int*)malloc(sizeof(int)*tam);
	srand(time(NULL));
	for(i=0;i<tam;i++){
		array[i] = i + 1;
	}
	for(i=0;i<tam;i++)
	{
		swap(&array[i], &array[rand()%tam]);
	}
	return array;
}
