#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    int id;
    char procesador[21];
    char marca[21];
    float precio;
}Notebook;


float aplicarDescuento(float precio);
int contarCaracteres(char* cadena, char caracter);
void ordenarNotebooks(Notebook* list, int len);

int main()
{
    float precio = 20000;
    char luthiers[70]="Quien amara a maria, amaria a maria";
    int letras;
    Notebook lista[6];

    printf("Precio original: %.2f",precio);
    precio = aplicarDescuento(precio);
    printf("\nCon descuento: %.2f",precio);

    letras = contarCaracteres(luthiers,'a');
    printf("\nCantidad de letras en la frace \n%s: %d",luthiers,letras);


    ordenarNotebooks(lista,6);




    return 0;
}

float aplicarDescuento(float precio)
{
    float precioFinal;
    precioFinal=precio*0.95;
    return precioFinal;
}

int contarCaracteres(char* cadena, char caracter)
{
    int contador = 0, i = 0;
    while(cadena[i]!='\0')
    {
        if(cadena[i]==caracter)
        {
            contador++;
        }
        i++;
    }
    return contador;
}

void ordenarNotebooks(Notebook* list, int len)
{
    int i,j;
    char cadenaAux;
    float flotanteAux;
    for(i=0;i<len;i++)
    {
        for(j=i+1;j<len;j++)
        {
            if (strcmp(list[i].marca,list[j].marca)>0)
            {
                strcpy(&cadenaAux,list[i].marca);
                strcpy(list[i].marca,list[j].marca);
                strcpy(list[j].marca,&cadenaAux);
            }
            if (list[i].precio > list[j].precio)
            {
                flotanteAux=list[i].precio;
                list[i].precio=list[j].precio;
                list[j].precio=flotanteAux;
            }
        }
    }
}

/*Crear una función llamada aplicarDescuento que reciba como parámetro el
  precio de un producto y devuelva el valor del producto con un descuento del
  5%. Realizar la llamada desde el main. *

  Crear una función que se llame contarCaracteres que reciba una cadena de
  caracteres como primer parámetro y un carácter como segundo y devuelva la
  cantidad de veces que ese carácter aparece en la cadena *

  Dada la estructura Notebook(id, procesador, marca, precio) generar
  una función que permita ordenar un array de dicha estructura por marca.
  Ante igualdad de marca deberá ordenarse por precio. Hardcodear datos
  y mostrarlos desde el main.


  */
