#include<stdio.h>
#include<stdlib.h>
#include<locale.h>

int op;
float num1, num2, soma, sub, mult, divisao; 
char resposta;

int main ()
{
	do 
	{
		setlocale(LC_ALL, "portuguese");
		printf("+-------------------------------------+\n");
		printf("|            Calculadora em C         |\n");
		printf("+-------------------------------------+\n");
		printf("|   1 - Soma          | 2- subtração  |\n");
		printf("+-------------------------------------+\n");
		printf("|   3 - Multiplicação | 4 - Divisão   |\n");
		printf("+=====================================+\n");
		printf("escolha a operação desejada:\n");
		scanf("%d", &op);
		printf("digite o primeiro número : \n");
		scanf("%f", &num1);
		printf("digite o segundo número : \n");
		scanf("%f", &num2);
		printf("\n");	

		switch(op)
		{
			case 1: 
				soma = num1 + num2;
				printf("A SOMA DOS NÚMEROS É : %.2f \n ", soma);
				break;
			case 2:
				sub = num1 - num2;
				printf("A SUBTRAÇÃO DOS NÚMEROS É : %.2f\n ", sub);
				break;    
			case 3:
				mult = num1 * num2;
				printf("A MULTIPLICAÇÃO DOS NÚMEROS É : %.2f\n ", mult);
				break;
			case 4:
				if (num2 == 0)
				{
					printf("NÃO É POSSÍVEL DIVIDIR O NÚMERO POR 0 \n ");   
					break;
				}
				else
				{
					divisao = num1 / num2;
					printf("A DIVISÃO DOS NÚMEROS É : %.2f \n", divisao);
					break;
				}
			default:
				printf("operação inválida ou inexistente. \n");
				break;
		}

		printf("Deseja realizar outra operação? (s/n): ");
		scanf(" %c", &resposta);
	} while (resposta == 's' || resposta == 'S');
	
	return 0;
}
