#include <stdio.h>
#include <stdlib.h>
#define N 5

int main() {

    int jogador1, jogador2;
    int rodada = 1;
    int vitoria_jog1 = 0, vitoria_jog2 = 0;
    
    while (rodada <= N) {

    printf("Jogador 1, escolha (0, 1, 2): ");
    scanf("%d", &jogador1);

    jogador2 = rand() % 3;

    printf("jogador 1 jogou %d\n", jogador1);
    printf("jogador 2 jogou %d\n", jogador2);

    if (jogador1 == jogador2) {

        printf("Rodada %d: Empate!\n", rodada);
    
    } else if(
        
        (jogador1 == 0 && jogador2 == 2) || //pedra versus tesoura
        (jogador1 == 1 && jogador2 == 0) || //papel versus pedra
        (jogador1 == 2 && jogador2 == 1) //tesoura versus papel
    ) {
        
        printf("Rodada %d: Jogador 1 vence!\n", rodada);
        vitoria_jog1++;

    } else {

    printf("Rodada %d: Jogador 2 vence!\n", rodada);
    vitoria_jog2++;
    
    }

    rodada++;

}

printf("Total de vitórias do usuário: %d\n", vitoria_jog1);
printf("Total de vitórias do PC: %d\n", vitoria_jog2);

return 0;
}