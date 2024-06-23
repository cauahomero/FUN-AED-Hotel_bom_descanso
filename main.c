#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "Modulos.h"
#include "quartos.h"
#include "estadias.h"

int main()
{
    setlocale(LC_ALL,"Portuguese");
    int op;

    printf("Trabalho Interdisciplinar - Victor Sotto e Cauã Homero.\n");
    printf("Hotel Bom Descanso.\n");
    do
    {
        menu(&op);
        switch(op)
        {
        case 1:
            menuCliente();
            break;
        case 2:
            menuQuartos();
            break;
        case 3:
            menuEstadias();
            break;
        case -1:
            printf("Encerrando o programa.\n");
            break;
        default:
            printf("Opção incorreta.\n");
        }
    }while(op!=-1);

    return 0;
}
