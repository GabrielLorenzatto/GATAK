#include<stdio.h>
#include<locale.h>
#include<math.h>

//Modelo de estimativa de produtividade de Jensen modificado por Berlato.

int main(void){

    setlocale(LC_ALL, "Portuguese");

    float ym = 0, ETr[12], ETo[12], y = 0, relacao[12], soma = 0, expo[12];
    int j, i=0;

    printf("Modelo de estimativa de produtividade de Jensen modificado por Berlato.\n");

    while(ym <= 0){
        printf("Informe o rendimento máximo da série estudada (em kg/ha): ");
        scanf("%f", &ym);
    }

    while(i <= 0){
        printf("Período de tempo em meses: ");
        scanf("%d", &i);
    }

    for(j=0; j<i; j++){
        printf("Evapotranspiração real do mês %d: ", j+1);
        scanf("%f", &ETr[j]);

        printf("Evapotranspiração de referência do mês %d: ", j+1);
        scanf("%f", &ETo[j]);

        while(expo[j] <= 0 && expo[j] > 1){
            printf("Informe o número expoente do mês %d: ", j+1);
            scanf("%f", &expo[j]);
        }

        relacao[j] = ETr[j]/ETo[j];
    }

    for(j=0; j<i; j++){
        soma = pow(relacao[j], expo[j]) + soma;

    }

    soma = soma * ym;

    printf("A expectativa de produção é igual a: %.3f kg/ha", soma);

    getchar();
    scanf("c");
}
