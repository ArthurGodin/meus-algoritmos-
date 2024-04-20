#include <stdio.h>
#include <stdlib.h>

int num, c, d, u, numnovo;

int main () {

    printf("digite um número de três digitos : ");
    scanf("%d", &num);

    c = num / 100;
    d = (num % 100) / 10; 
    u = num % 10; 

    numnovo = u * 100 + d * 10 + c;

    printf("o novo número é : %d \n", numnovo);

}
