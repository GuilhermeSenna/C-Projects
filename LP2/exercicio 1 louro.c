#include <stdio.h>
#include <stdlib.h>
#include <math.h>

float* func(float A,float f,float ang); /*fazendo o esboco da funcao*/


int main(void) /*criando a int main*/
{
    int i;
   float A,f,ang, *y; /* A de amplitude,    f de frequencia,     ang de angulo*/
   char resp;

   system("color 72"); /* colocando cor no prompt*/


   do /* aplicando a repeticao para obter as variaveis*/
   {

       /* ---------------------------------------------------AMPLITUDE--------------------------------------*/

       printf ("Por Favor, informe o valor da amplitude.\n\nAMP:");
       scanf("%f",&A);/* obtendo o valor da amplitude*/

        while (A < 0)/*dando opcao de correcao em caso de erro do usuario*/
        {
            printf("\n\nPor favor digite um valor maior que 0.\n\nAMP:");
            scanf("%f,&A");/* reobtendo o valor da amplitude*/
        }

        /* ---------------------------------------------------FREQUENCIA--------------------------------------*/

       printf ("\nPor Favor, informe o valor da frequencia.\n\nFREQ:");
       scanf("%f",&f);/* obtendo o valor do angulo*/

        while (f < 0) /*dando opcao de correcao em caso de erro do usuario*/
        {
            printf("\n\nPor favor digite um valor maior que 0.\n\nFREQ:");
            scanf("%f,&f"); /* reobtendo o valor da frequencia*/
        }

        /* ---------------------------------------------------ANGULO--------------------------------------*/

       printf ("\nPor Favor, informe o angulo.\n\nANG:");
       scanf("%f",&ang); /*obtendo o valor do angulo*/

       while (ang < 0) /*dando opcao de correcao em caso de erro do usuario*/
        {
            printf("\n\nPor favor digite um valor maior que 0.\n\nANG:");
            scanf("%f,&ang"); /* reobtendo o valor do angulo*/
        }

        y = func(A,f,ang); /*chamando a funcao*/

       printf ("Deseja modificar os dados informados? (s para continuar ou qualquer tecla diferente para seguir em frente.) \n -> "); /*dando possibilidade de modificar os valores*/
       fflush(stdin); /*Limpando o Buffer*/
       resp = getchar(); /*obtendo a resposta do usuario*/

     } while (resp == 's' || resp == 'S'); /*aplicando a condicao para continuar ou trocar os valores*/

    for (i=0;i<1000;i++) /* aplicando a repeticao para mostrar os 1000 valores*/
    {


     printf ("O valor %d da amostragem eh =%f\n",i+1,y[i]); /*Mostrando os 1000 valores da amostragem*/
    }

    free(y); /* Esvaziando o valor do ponteiro*/

     return(0); /*Retornando 0 para o int main*/
}

float* func(float A,float f,float ang) /*definindo o que fazer na funcao*/
{

 int i; /* aplicando o indice*/
 float t = 0.001;/*aplicando o tempo */
 float *y = (float*)malloc(1000 * sizeof(float)); /*Usando o HEAP*/

 for (i=0;i<1000;i++, t+= 0.001) /*Aplicando a repeticao*/
 {
     y[i] = A*sin(2*3.14*f*t+ang); /* Aplicando a funcao senoidal*/
 }
 return y; /* retornando o vetor y do sinal senoidal*/
}
