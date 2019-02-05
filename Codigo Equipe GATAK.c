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
        printf("Informe o rendimento m�ximo da s�rie estudada (em kg/ha): ");
        scanf("%f", &ym);
    }

    while(i <= 0){
        printf("Per�odo de tempo em meses: ");
        scanf("%d", &i);
    }

    for(j=0; j<i; j++){
        printf("Evapotranspira��o real do m�s %d: ", j+1);
        scanf("%f", &ETr[j]);

        printf("Evapotranspira��o de refer�ncia do m�s %d: ", j+1);
        scanf("%f", &ETo[j]);

        while(expo[j] <= 0 && expo[j] > 1){
            printf("Informe o n�mero expoente do m�s %d: ", j+1);
            scanf("%f", &expo[j]);
        }

        relacao[j] = ETr[j]/ETo[j];
    }

    for(j=0; j<i; j++){
        soma = pow(relacao[j], expo[j]) + soma;

    }

    soma = soma * ym;

    printf("A expectativa de produ��o � igual a: %.3f kg/ha", soma);

    getchar();
    scanf("c");
}
