#ifndef MODULOS_H_INCLUDED
#define MODULOS_H_INCLUDED

/**Clientes**/
typedef struct
{
    int codigo;
    char nome[50];
    char endereco[100];
    char telefone[15];
} CLIENTE;

void menuCliente();
int verificaCodigo(int codigoDigitado);
void inclui_cliente();
void le_cliente();
void pesquisarDadosCliente();
/**Clientes**/

void menu(int *opcao);

int verifica_Cliente(const char *nome);

#endif 
