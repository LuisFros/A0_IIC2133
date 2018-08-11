#include "stack.h"
#include <stdlib.h>
#include <stdio.h>


Stack *stack_init()
{
  /* Aqui agrega tu código */
  
  Stack *stack=(Stack *)malloc((sizeof( Stack)));
  stack->head=NULL;
  return stack;
}

void push(Stack* stack, int color)
{
  struct node *nueva_bola;
	nueva_bola=(struct node*)malloc(sizeof(struct node));
  nueva_bola->color=color;
	nueva_bola->siguiente=stack->head;
  stack->head=nueva_bola;
  return;
}

// pop recursive


// int pop(Stack* stack,int color)
// {
//   printf("HO99");
//   int valor=stack->head->color;
//   printf("VALOR:\n");
//   printf("%d\n",valor);
//   stack->head=stack->head->siguiente;
//   printf("HO");
//   if(valor==color){
//     printf("%d\n",valor);
//     // printf("HOO");
//     return valor;
//   }
//   else if (stack->head){
//     printf("%d\n",valor);
//     // printf("HOOO");
//     return pop(stack,color);
//   }
//   else{
//     printf("vacio");
//   }
// }

int pop(Stack* stack,int color)
{
  // printf("COLOR POP: %d\n",color);
  while (stack->head!=NULL )
  {
    int valor=stack->head->color;
    printf("%d\n",valor);
    if(valor==color){
      stack->head=stack->head->siguiente;
      return valor;
    }
    stack->head=stack->head->siguiente;

  }

  printf("vacio\n");

}

void destroy(Stack *stack)
{
  struct node *actual=stack->head;
  while(stack->head!=NULL){
    actual=stack->head;
    stack->head=stack->head->siguiente;
    free(actual);
  }
  free(actual);
}


/* A continuación puedes crear cualquier función adicional que ayude en la
  implementación de tu programa */

int **tabla(int n_filas,int n_columnas)
{
  int **tabla;
  tabla=(int **)malloc(sizeof(int*)*n_filas);
  for (int fila=0;fila<n_filas;fila++)
  {
    tabla[fila]=(int *)malloc(sizeof(int)*n_columnas);
    for (int col=0;col<n_columnas;col++)
    {
		  Stack *stack=stack_init();
      // direccion?
      tabla[fila][col]=stack;
    }
  }
  return tabla;
}

void destroy_tabla(int **tabla,int n_filas,int n_columnas)
{
for (int fila=0;fila<n_filas;fila++){
  for (int col=0;col<n_columnas;col++){
    free(tabla[fila][col]);
  }
  free(tabla[fila]);
}
}
