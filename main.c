#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

void descriptografia(int vetorcomp[5]) {
  FILE *file = fopen("cript.txt", "r");
  int vetordes[5];
  int chave_des;
  fscanf(file, "%d %d %d %d %d %d", &chave_des, &vetordes[0], &vetordes[1],
         &vetordes[2], &vetordes[3], &vetordes[4]);
  for (int i = 0; i < 5; i++) {
    if(vetorcomp[i] != (vetordes[i] / chave_des)){
      printf("\nLogin Falho!\n");
      exit(0);
    }
  }
  printf("\nVoce está logado!\n");
}

void encriptografia(int vetor[5]) {
  FILE *file = fopen("cript.txt", "w");
  int r = rand() % 10;
  r = r + 1;

  fprintf(file,"%d ", r);
  for (int i = 0; i < 5; i++) {
    fprintf(file,"%d ", r * vetor[i]);
  }

  fclose(file);
}

int main(void) {
  srand(time(NULL));
  int vetor[5];
  int op;
  printf("1 - Registrar\n2 - Login\n");
  scanf("%d", &op);
  if (op == 1) {
    for (int i = 0; i < 5; i++) {
      printf("\nInsira o valor %d: ", i);
      scanf("%d", &vetor[i]);
    }
    encriptografia(vetor);
  }

  else {
    for (int i = 0; i < 5; i++) {
      printf("\nInsira o valor %d: ", i);
      scanf("%d", &vetor[i]);
    }
    descriptografia(vetor);
  }
  return 0;
}