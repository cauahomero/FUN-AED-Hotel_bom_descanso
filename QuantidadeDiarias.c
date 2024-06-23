#include "QuantidadeDiarias.h"

int eBissexto(int ano)
{
    return(ano%4==00&&(ano%100!=0||ano%400==0));
}

int diasNoMes(int mes,int ano)
{
    int diasNoMes[12]={31,28+eBissexto(ano),31,30,31,30,31,31,30,31,30,31};
    return diasNoMes[mes-1];
}

int diasDesdeIncio(int dia,int mes,int ano)
{
    int dias=dia;
    for(int i=1;i<mes;i++)
    {
        dias=dias+diasNoMes(i,ano);
    }
    return dias;
}

int diferencaEntreDatas(int dia1,int mes1,int ano1,int dia2,int mes2,int ano2)
{
    int dias1 = diasDesdeIncio(dia1,mes1,ano1);
    int dias2 = diasDesdeIncio(dia2,mes2,ano2);

    for(int i=ano1;i<ano2;i++)
    {
        dias2=dias2+(365+eBissexto(i));
    }

    return dias2-dias1;
}
