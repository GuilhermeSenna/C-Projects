#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int resp,tam[4],user;
char Usuario[4][30],Senha[4][30],Placa[4][8];
void consultar_placa(void);

int main(void)
{
    strcpy(Placa[1], "ABC-1234");
    strcpy(Placa[2], "XYZ-4567");
    strcpy(Placa[3], "FGH-1001");
    strcpy(Usuario[1], "Fulano");
    strcpy(Usuario[2], "Beltrano");
    strcpy(Usuario[3], "Ciclano");
    strcpy(Senha[1], "123");  //Senha para Fulano
    strcpy(Senha[2], "teste");  //Senha para Beltrano
    strcpy(Senha[3], "abc"); //Senha para Ciclano
    /*printf("Software para cadastramento de numero de placas de carros e comparacao com um banco de dados. ");
    printf("\nPor favor entre com o tipo de usuario.");
    printf("\n-> 1 para Usuario Geral.\n-> 2 para Usuario Comercial.\n-> 3 para Usuario Judicial.\n-> 4 para Administrador.\n-> 5 para sair.\n-> ");
    scanf("%d",&resp);

    while(resp <1 || resp>5)
    {
        system("cls");
        printf("Software para cadastramento de numero de placas de carros e comparacao com um banco de dados. ");
        printf("\nPor favor entre com o tipo de usuario valido.");
        printf("\n-> 1 para Usuario Geral.\n-> 2 para Usuario Comercial.\n-> 3 para Usuario Judicial.\n-> 4 para Administrador.\n-> 5 para sair.\n-> ");
        scanf("%d",&resp);
    }
    */

    printf("Digite seu Login: ");
    fgets(Usuario[4],30,stdin);
    tam[1] = strlen(Usuario[1]);
    tam[2] = strlen(Usuario[2]);
    tam[3] = strlen(Usuario[3]);
    if((strncmp(Usuario[1],Usuario[4],tam[1]-2)==0) || (strncmp(Usuario[2],Usuario[4],tam[2]-4)==0) || (strncmp(Usuario[3],Usuario[4],tam[3]-3)==0))
    {
        printf("\nDigite sua Senha: ");
        fgets(Senha[4],30,stdin);
    }
    else{
        printf("\nUsuario nao encontrado, faca seu registro.");
        printf("\nDigite um Login: ");
        fgets(Usuario[4],30,stdin);
        printf("\nDigite uma Senha: ");
        fgets(Senha[4],30,stdin);
        printf("\n\nEscolha entre os Usuarios: \nUG(1), \nUC - comprador(2),\nUC - vendedor casual(3),\nUC - vendedor autorizado(4),\nUJ - patente baixa(5),\nUJ - patente alta(6),\nADM(7).\n->");
        scanf("%d",&user);
    }

    system("cls");
    switch(user)
    {
        case 1:   //Usuario Geral
            printf("Deseja:\n-> 1 Para consultar uma placa.");
            printf("\n-> 2 Para notificar uma placa.");
            printf("\n-> 3 Informar erros e bugs.\n->");
            scanf("%d",&user);
            switch(user)
            {
                case 1:
                    consultar_placa();

            }
            break;

        case 2:   //Usuario Comercial - Comprador
            printf("Deseja:\n-> 1 Para consultar uma placa.");
            printf("\n-> 2 Para notificar uma placa.");
            printf("\n-> 3 Informar erros e bugs.");
            printf("\n-> 4 Para enviar uma notificacao de compra.\n->");
            scanf("%d",&user);
            break;

        case 3:   //Usuario Comercial - Vendedor casual
            printf("Deseja:\n-> 1 Para consultar uma placa.");
            printf("\n-> 2 Para notificar uma placa.");
            printf("\n-> 3 Informar erros e bugs.");
            printf("\n-> 4 Para checar as notificacoes.");
            printf("\n-> 5 Para enviar uma notificacao de compra.");
            printf("\n-> 6 Para enviar uma resposta ao comprador.");
            printf("\n-> 7 Para solicitar a troca do dono atual ao adm.\n->");
            scanf("%d",&user);
            break;

        case 4:   //Usuario Comercial - Vendedor autorizado
            printf("Deseja:\n-> 1 Para consultar uma placa.");
            printf("\n-> 2 Para notificar uma placa.");
            printf("\n-> 3 Informar erros e bugs.");
            printf("\n-> 4 Para checar as notificacoes.");
            printf("\n-> 5 Para enviar uma notificacao de compra.");
            printf("\n-> 6 Para enviar uma resposta ao comprador.");
            printf("\n-> 7 Para solicitar a troca do dono atual ao adm.");
            printf("\n-> 8 Para efetuar a troca do dono atual.\n->");
            scanf("%d",&user);
            break;

        case 5:    //Usuario Judicial - patente baixa
            printf("Deseja:\n-> 1 Para consultar uma placa.");
            printf("\n-> 2 Para notificar uma placa.");
            printf("\n-> 3 Informar erros e bugs.");
            printf("\n-> 4 Para checar as notificacoes.");
            printf("\n-> 5 Solicitar a lista das placas.");
            printf("\n-> 6 Para solicitar a modificacao do status para o adm.\n->");
            scanf("%d",&user);
            break;

        case 6:    //Usuario Judicial - patente alta
            printf("Deseja:\n-> 1 Para consultar uma placa.");
            printf("\n-> 2 Para notificar uma placa.");
            printf("\n-> 3 Informar erros e bugs.");
            printf("\n-> 4 Para checar as notificacoes.");
            printf("\n-> 5 Solicitar a lista das placas.");
            printf("\n-> 6 Para solicitar a modificacao do status para o adm.");
            printf("\n-> 7 Para Efetuar a modificacao do status.\n->");
            scanf("%d",&user);
            break;

        case 7:  //administrador
            printf("Deseja:\n-> 1 Para consultar uma placa.");
            printf("\n-> 2 Para checar as notificacoes.");
            printf("\n-> 3 Para verificar a validacao do usuario.");
            printf("\n-> 4 Para notificar as autoridades (UJ).");
            printf("\n-> 5 Para remover usuario.");
            printf("\n-> 6 Para Modificar o status do usuario.");
            printf("\n-> 7 Solicitar a lista das placas.\n->");
            scanf("%d",&user);
            break;

    }
}

void consultar_placa(void)
{
    printf("\nDigite uma placa no modelo ABC-1234");
    scanf("%s",&Placa[4]);
    fgets(Placa[4],8,stdin);
    if(strncmp(Placa[1],Placa[4],8)==0)
    {
        printf("teste");
    }
}
