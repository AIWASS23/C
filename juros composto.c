#include <stdio.h>
#include <math.h>

float main() {
    float montante, principal, taxa, meses, parcelas;
    printf("Digite o valor principal em reais: \n");
    scanf("%f", &principal);
    printf("Digite a taxa a ser empregada em decimais: \n");
    scanf("%f", &taxa);
    printf("Digite o numero de meses que seu dinheiro estara aplicado: \n");
    scanf("%f", &meses);

    montante = 1 + taxa;
    montante = powf(montante, meses);
    montante = principal * montante;
    parcelas = montante / meses;
    printf("O montante total: %f \n", montante);
    printf("O valor da parcela por mes sera: %f \n", parcelas);
    return (montante);
}
