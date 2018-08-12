#include "stack.h"
#include <stdlib.h>
#include <stdio.h>

void print_stack(Stack *stack){
	struct node *actual=stack->head;
	while (actual!=NULL){
		actual=actual->siguiente;
	}
	return;
}

Stack *stack_init()
{
  Stack *stack=(Stack *)malloc((sizeof(Stack)));
  stack->head=NULL;
  return stack;
}

void push(Stack* stack, int color)
{ 
  if (stack->head!=NULL){
    struct node *nueva_bola;

    nueva_bola=(struct node*)malloc(sizeof(struct node));
    nueva_bola->color=color;
    nueva_bola->siguiente=stack->head;
    stack->head=nueva_bola;

  }
  else{
    struct node *nueva_bola;
    nueva_bola=(struct node*)malloc(sizeof(struct node));
    nueva_bola->color=color;
    nueva_bola->siguiente=NULL;
    stack->head=nueva_bola;

  }
  return;
}

int pop(Stack* stack,int color)
{
  struct node *previous;
  while (stack->head!=NULL )
  {
    int valor=stack->head->color;
    printf("%d\n",valor);
    previous=stack->head;
    if(valor==color){
      stack->head=stack->head->siguiente;
      print_stack(stack);
      free(previous);
      return valor;
    }
    stack->head=previous->siguiente;
    free(previous);


  }
  printf("vacio\n");

}

void destroy(Stack *stack)
{
  while(stack->head!=NULL){
    struct node *aux=stack->head;
    stack->head=aux->siguiente;
    free(aux);
  }
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
    destroy(tabla[fila][col]);
    free(tabla[fila][col]);
  }
  free(tabla[fila]);
}
}
