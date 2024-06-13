#include <stdio.h>
#include <stdlib.h>

float num1, num2;
char resposta;

int main() {
    
    do
    {
        printf("digite o primeiro número : \n");
        scanf("%f", &num1);
        printf("digite o segundo número : \n");
        scanf("%f", &num2);

        if (num2 > num1)
        {
            float start = num1;
            float end = num2;

            for (float i = start; i <= end; i++) 
            {
                printf("%.2f\n", i);
            }
        }

        if (num1 > num2)
        {            
            float start = num1;
            float end = num2;

            for (float i = start; i >= end; i--)
            {
                printf("%.2f\n", i);
            }       
        }

    printf("deseja realizar outra contagem? (S/N)" );
    scanf("%c", &resposta);
    
    } while (resposta == 's' || resposta == 'S');

}



