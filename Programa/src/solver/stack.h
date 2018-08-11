#pragma once


typedef struct stack Stack;

typedef struct node Node;


typedef struct node
{
  int color;
  struct node *siguiente;
};

typedef struct stack
{
  struct node *head;
};


Stack *stack_init();

void push(Stack* stack, int color);

int pop(Stack* stack,int color);

void destroy(Stack *stack);

int **tabla(int n_filas,int n_columnas);

void destroy_tabla(int **tabla,int n_filas,int n_columnas);
