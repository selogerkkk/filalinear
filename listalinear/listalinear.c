#include <stdio.h>

#define TAMANHO 10

int main()
{
  int lista[TAMANHO];
  int num, i, j;

  // Insere os números em ordem na lista
  printf("Insira os %d números em ordem:\n", TAMANHO);
  for (i = 0; i < TAMANHO; i++)
  {
    scanf("%d", &num);
    // Encontra a posição correta para o número atual
    for (j = i - 1; j >= 0 && lista[j] > num; j--)
    {
      lista[j + 1] = lista[j];
    }
    lista[j + 1] = num;
  }

  // Encontra a posição correta para o número inserido
  printf("Insira o %dº número:\n", TAMANHO + 1);
  scanf("%d", &num);
  for (i = TAMANHO - 1; i >= 0 && lista[i] > num; i--)
  {
    lista[i + 1] = lista[i];
  }
  printf("O %dº deveria ser inserido na posição %d.\n", (TAMANHO + 1), i + 1);
  lista[i + 1] = num;

  // Exibe a lista atualizada
  printf("Lista atualizada:\n");
  for (i = 0; i < TAMANHO + 1; i++)
  {
    printf("%d ", lista[i]);
  }
  printf("\n");

  return 0;
}
