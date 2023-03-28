#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#define N 2

typedef struct
{
  int topo;
  int dados[N];
} stack;

stack *newStack();
void push(stack *s, int value);
int pop(stack *s);
int topo(stack *s);
int isStackEmpty(stack *s);
int isStackFull(stack *s);

int main()
{
  setlocale(LC_ALL, "Portuguese");
  stack *p;
  p = newStack();
  push(p, 15);
  push(p, 25);

  if (isStackEmpty(p))
  {
    printf("A pilha está vazia\n");
  }
  if (!isStackFull(p))
  {
    printf("A pilha não está cheia\n");
  }
}

stack *newStack()
{
  stack *p = (stack *)malloc(sizeof(stack));
  p->topo = 0;
  return p;
}

void push(stack *s, int value)
{
  if (isStackFull(s))
  {
    printf("A pilha já está cheia!\n");
    return;
  }
  s->dados[s->topo] = value;
  s->topo++;
}

int pop(stack *s)
{
  if (isStackEmpty(s))
  {
    printf("Pilha vazia\n");
    return -1;
  }
  s->topo = s->topo - 1;
  return s->dados[s->topo];
}

int topo(stack *s)
{
  if (isStackEmpty(s))
  {
    printf("Pilha vazia\n");
    return -1;
  }
  return s->dados[s->topo - 1];
}

int isStackFull(stack *s)
{
  return s->topo == N;
}

int isStackEmpty(stack *s)
{
  return s->topo == 0;
}
