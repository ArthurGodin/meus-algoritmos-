#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

float num1, num2, soma, mult, sub, divisao;
int op;
char resposta;


int main ()
{
do
    {
        // pedir ao usuário o primeiro número
        printf("digite o primeiro numero : \n");
        scanf("%f", &num1);

        // pedir ao usuário o segundo número 
        printf("digite o segundo numero : \n");
        scanf("%f", &num2);

        // mostrar as operações possíveis
        printf("1 - soma\n");
        printf("2 - subtracao\n");
        printf("3 - multiplicacao\n");
        printf("4 - divisao\n");

        // pedir ao usuário a operação desejada
        printf("escolha a operacao desejada : \n");
        scanf("%d", &op);

        // realizar a operação selecionada
        switch (op)
        {
            case 1:
                soma = num1 + num2; 
                printf("a soma dos numeros eh : %.2f\n", soma);
                break;
            case 2:
                sub = num1 - num2; 
                printf("a subtração dos numeros eh : %.2f\n", sub);
                break;
            case 3:
                mult = num1 * num2;
                printf("a multiplicação dos numeros eh : %.2f\n", mult);
                break;
            case 4: 
                if (num2 == 0)
                {
                    printf("nao e possivel dividir por zero\n");
                }
                else
                {
                    divisao = num1 / num2;
                    printf("a divisão dos numeros eh : %.2f\n", divisao);
                }
                break;
            default: 
                printf("operação invalida\n");
                break;  
        }  
    printf("deseja realizar outra operacao? (s/n) : \n");
    scanf("%s", &resposta);
    } while (resposta == 's' || resposta == 'S');
}





