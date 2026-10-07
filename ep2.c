#include <stdio.h>
#include <math.h>

void calc_info_retangulo(double base, double altura, double *area, double *perimetro, double *diagonal) {

    *area = base * altura;
    *perimetro = 2 * (base + altura);
    *diagonal = sqrt((base * base) + (altura * altura));
}

int main() {

    double base, altura;

    printf("=========Calculadora de Retangulo=========\n\n");

    printf("Digite a Base: ");
    scanf("%lf", &base);

    printf("Digite a Altura: ");
    scanf("%lf", &altura);

    double area, perimetro, diagonal;

    calc_info_retangulo(base, altura, &area, &perimetro, &diagonal);

    printf("\n=========Resultados=========\n");

    printf("Area: %.2f\n", area);
    printf("Perimetro: %.2f\n", perimetro);
    printf("Diagonal: %.2f\n", diagonal);

    printf("============================\n");

    return 0;
}