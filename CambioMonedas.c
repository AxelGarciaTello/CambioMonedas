#include <stdlib.h>
#include <stdio.h>

int *devolverCambio(int cantidad, float monedas[], int tamanio){
  int *cambio,
      i=0;
  cambio=(int *) malloc(sizeof(float)*tamanio);
  for(i=0; i<tamanio; i++){
    while(monedas[i]<=cantidad){
      cantidad-=monedas[i];
      (*(cambio+i))++;
    }
  }
  return cambio;
}

int main(void){
  float monedas[]={10.0f, 5.0f, 2.0f, 1.0f, 0.5f};
  int *cambio,
      i=0;
  cambio=devolverCambio(36, monedas, 5);
  for(i=0; i<5; i++){
    printf("Monedas de %f: %d\n",monedas[i],*(cambio+i));
  }
}
