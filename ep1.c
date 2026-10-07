#include <stdio.h>

int main() {

    int jogador1, jogador2;

    printf("Jogador 1, escolha (0, 1, 2): ");
    scanf("%d", &jogador1);

    printf("Jogador 2, escolha (0, 1, 2): ");
    scanf("%d", &jogador2);

    if (jogador1 == jogador2) {

        printf("\nO Resultado deu empate\n");
    } else if (
  
      (jogador1 == 0 && jogador2 == 2) || //pedra versus tesoura
      (jogador1 == 1 && jogador2 == 0) || //papel versus pedra
      (jogador1 == 2 && jogador2 == 1) //tesoura versus papel
    ) {
        printf("\nResultado: O Jogador 1 venceu!\n");
    } else {
        printf("\nResultado: O Jogador 2 venceu!\n");
    }

    return 0;
}