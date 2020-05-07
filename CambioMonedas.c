/*
Instituto Politecnico Nacional
Escuela Superior de Cómputo
Analisis de algoritmos
Grupo: 3CV2
Alumnos: Garcia Tello Axel
		 Rodríguez Acosta Alan
Profesor: Benjamin Luna Benoso
@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
Cambio de monedas

Fecha: 29 de abril de 2020
*/
#include <stdlib.h>
#include <stdio.h>

//Funcón para devolver cambio
int *devolverCambio(float cantidad, float monedas[], int tamanio,
    int *contador){
  int *cambio,
      i=0;
  *contador+=2;
  //Creación del espacio de memoria que necesitamos para almacenas el cambio
  cambio=(int *) malloc(sizeof(float)*tamanio); *contador+=1;
  for(i=0; i<tamanio; i++){ //Recorremos todo el arreglo
    *contador+=1;
    /*
      Mientras la cantidad es divisible entre la moneda, se agrega la moneda al
      cambio y disminiye la cantidad
    */
    while(monedas[i]<=cantidad){
      *contador+=1;
      cantidad-=monedas[i];
      (*(cambio+i))++;
      *contador+=2;
    }
    *contador+=1;
  }
  *contador+=2;
  return cambio;
}

int main(void){
  float monedas[]={10.0f, 5.0f, 2.0f, 1.0f, 0.5f};
  int *cambio,
      i=0,
      contador=0;
  float x=0;
  for(x=18.5f; x<=250; x+=18.5){
    cambio=devolverCambio(x, monedas, 5, &contador);
    printf("Cantidad: %f\tLineas ejecutadas: %d\n", x, contador);
    for(i=0; i<5; i++){
      printf("Monedas de %f: %d\n",monedas[i],*(cambio+i));
    }
    printf("\n\n\n");
    contador=0;
    for(i=0; i<5; i++){
      *(cambio+i)=0;
    }
    free(cambio);
  }
}
