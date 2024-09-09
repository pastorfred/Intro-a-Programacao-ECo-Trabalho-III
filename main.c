#include <stdio.h>

void rolaEsquerda(char vet[], int tam, int num) {
  int i = 0;
  while (i < num % tam) {
    char a = vet[0];
    int b = 0;
    while (b < tam) {
      vet[b] = vet[b + 1];
      b++;
    }
    vet[tam - 1] = a;
    i++;
  }
}

void advance(char vet[], int tam, int adv) {
  for (int i = 0; i < tam; i++) {
    if ((vet[i] <= 122 && vet[i] >= 97) || (vet[i] <= 90 && vet[i] >= 65)) {
      for (int a = 0; a < adv; a++) {
        vet[i] = vet[i] + 1;
        if (vet[i] > 122) {
          vet[i] = 97;
        }
        if (vet[i] > 90 && vet[i] < 97) {
          vet[i] = 65;
        }
      }
    }
  }
}

void transform(char vet[], int tam, char s1[], char s2[]) {
  int i = 0;
  while (i < tam) {
    int a = 0;
    while (s1[a] != '\0') {
      if (vet[i] == s1[a]) {
        vet[i] = s2[a];
        break;
      }
      a++;
    }
    i++;
  }
}

int main(void) {
  char vet[256];
  printf("Digite uma frase com no máximo 256 carácters: ");
  fgets(vet, 256, stdin);

  int i = 0;
  int tam = 0;
  while (vet[i++] != '\0') {
    tam++;
  }
  tam = tam - 1;

   i = 0;
   while (i < 100) {
     rolaEsquerda(vet, tam, i / 2);
     advance(vet, tam, i / 3);
     transform(vet, tam, "abcdefghijklm", "bamdfhgjcielk");
     i++;
   }

  printf("%s", vet);
}