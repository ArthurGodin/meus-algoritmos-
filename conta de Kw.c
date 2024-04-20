#include <stdio.h>
#include <stdlib.h>

float salariomin, quantidade_quilowatts, valor_do_quilowatt, valor_da_conta, valor_conta_desconto;
char escolha;


int main ()
{
    do {

        printf("qual o valor do salário mínimo atual? \n");
        scanf("%f", &salariomin);

        valor_do_quilowatt = (salariomin / 7.0)/100.0;

        printf("qual a quantidade mensal de quilowatts que a residência consome? \n");
        scanf("%f", &quantidade_quilowatts);
        printf("o valor de cada quilowatt é de : %.2f reais \n", valor_do_quilowatt);

        valor_da_conta = valor_do_quilowatt * quantidade_quilowatts; 
        valor_conta_desconto = valor_da_conta - (valor_da_conta * (10.0/100.0));

        printf("o valor da conta de energia é de: %.2f reais \n", valor_da_conta);
        printf("o valor da conta de energia com 10 porcento de desconto é de : %.2f reais \n", valor_conta_desconto);

        printf("Deseja executar novamente? (S/N): ");
        scanf(" %c", &escolha);

    } while (escolha == 'S' || escolha == 's');
}



