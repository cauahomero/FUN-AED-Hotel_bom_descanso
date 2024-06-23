#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Modulos.h"
#include "estadias.h"

char arquivoClientes[]="clientes.dat";
void menuCliente()
{
    int op;
    printf("\n1 - Cadastrar cliente.\n");
    printf("2 - Clientes cadastrados.\n");
    printf("3 - Pesquisar dados do cliente pelo c�digo.\n");
    printf("Escolha uma op��o: ");
    scanf("%d",&op);
    printf("\n");
    printf("-------------------------------------------------\n");
    switch(op)
    {
    case 1:
        inclui_cliente();
        break;
    case 2:
        le_cliente();
        break;
    case 3:
        pesquisarDadosCliente();
        break;
    default:
        printf("Op��o incorreta.\n");
    }
}

/**Fun��o para imprimir menu de escolha.**/
void menu(int *opcao)
{
    printf("\n1 - Clientes.\n");
    printf("2 - Quartos.\n");
    printf("3 - Estadias.\n");
    printf("-1 - sair do programa.\n");
    printf("Digite uma op��o: ");
    scanf("%d",opcao);
}

/**Fun��o para registrar clientes**/
void inclui_cliente()
{
    int cod=0,codDigitado;

    FILE *arquivo;
    arquivo=fopen(arquivoClientes,"a+b");
    if(arquivo==NULL)
    {
        printf("Erro na abertura do arquivo clientes.");
        return;
    }

    CLIENTE c;

    printf("\nC�digo do cliente: ");
    scanf("%d",&c.codigo);

    /**Verifica��o se o c�digo existe no arquivo**/
    codDigitado=c.codigo;
    do
    {
        cod=verificaCodigo(codDigitado);
        if(cod==1)
        {
            printf("C�digo j� existente no sistema, digite outro: ");
            scanf("%d",&c.codigo);
            codDigitado=c.codigo;
        }
    }while (cod==1);
    /**Verifica��o se o c�digo existe no arquivo**/

    printf("Nome do cliente: ");
    fflush(stdin);
    fgets(c.nome,sizeof(CLIENTE),stdin);
    printf("Endere�o do cliente: ");
    fflush(stdin);
    fgets(c.endereco,sizeof(CLIENTE),stdin);
    printf("Telefone do cliente: ");
    fflush(stdin);
    fgets(c.telefone,sizeof(CLIENTE),stdin);
    printf("\n-------------------------------------------------\n");

    fwrite(&c,sizeof(CLIENTE),1,arquivo);

    fclose(arquivo);
}

/**Fun��o para ler os clientes**/
void le_cliente()
{
    FILE *arquivo;
    arquivo=fopen(arquivoClientes,"rb");
    if(arquivo==NULL)
    {
        printf("Erro na abertura do arquivo clientes.");
        return;
    }

    CLIENTE c;

    while(fread(&c,sizeof(CLIENTE),1,arquivo)==1)/**Ler o bloco da estrutura**/
    {
        printf("C�digo do cliente: %d\n",c.codigo);
        printf("Nome do cliente: %s",c.nome);
        printf("Endere�o do cliente: %s",c.endereco);
        printf("Telefone do cliente: %s",c.telefone);
        printf("-------------------------------------------------\n");
    }

    fclose(arquivo);
}

/**Fun��o para verificar se c�digo j� existe ou n�o**/
int verificaCodigo(int codigoDigitado)
{
    int verificacao=0,codigoExistente;

    FILE *arquivo;
    arquivo=fopen(arquivoClientes,"rb");
    if(arquivo==NULL)
    {
        printf("Erro de abertura do arquivo clientes");
        return 0;
    }

    CLIENTE c;

    while(fread(&c,sizeof(CLIENTE),1,arquivo)==1)
    {
        codigoExistente=c.codigo;
        if(codigoExistente==codigoDigitado)
        {
            verificacao=1;
            break;
        }
    }

    fclose(arquivo);
    return verificacao;
}

/**Fun��o para verificar se o cliente existe ou não - utilizada na parte da estadia**/
int verifica_Cliente(const char *nome)
{
    int verificacao=0;
    char nomeExistente[100];

    FILE *arquivo;
    arquivo=fopen(arquivoClientes,"rb");
    if(arquivo==NULL)
    {
        printf("Erro de abertura no arquivo dos clientes.");
        return 0;
    }

    CLIENTE c;
    while(fread(&c,sizeof(CLIENTE),1,arquivo)==1)
    {
        strcpy(nomeExistente,c.nome);
        if(strcmp(nomeExistente,nome)==0)
        {
            verificacao=1;
            codigoClienteGlobal=c.codigo;//pegar o código do cliente
            break;
        }
    }

    fclose(arquivo);
    return verificacao;
}

/**Função para pesquisar Cliente.**/
void pesquisarDadosCliente()
{
    int cod,codNoSistema,verificacao;

    FILE *arquivo;
    arquivo=fopen(arquivoClientes,"rb");
    if(arquivo==NULL)
    {
        printf("Erro na abertura do arquivo clientes.");
        return;
    }

    printf("\nDigite o c�digo do Cliente: ");
    scanf("%d",&cod);
    printf("\n");

    do
    {
        verificacao=verificaCodigo(cod);
        if(verificacao==0)
        {
            printf("Cliente n�o encontrado, digite outro: ");
            scanf("%d",&cod);
            printf("\n");
        }
    }while (verificacao==0);

    CLIENTE c;
    while(fread(&c,sizeof(CLIENTE),1,arquivo)==1)
    {
        codNoSistema=c.codigo;
        if(cod==codNoSistema)
        {
            printf("-------------------------------------------------\n");
            printf("C�digo do cliente: %d\n",c.codigo);
            printf("Nome do cliente: %s",c.nome);
            printf("Endere�o do cliente: %s",c.endereco);
            printf("Telefone do cliente: %s",c.telefone);
            printf("-------------------------------------------------\n");
        }
    }

    fclose(arquivo);
}
