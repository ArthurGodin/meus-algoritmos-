#include <stdio.h>
#include <stdlib.h>


struct aluno
{
    float nota;
    float media;
    char nome[50]; 
};

int main() 
{
    float media;
    int i;
    struct aluno notas[4]; 

    
    
    for (i=0; i < 4; i++)
    {
        printf("digite o nome do %d° aluno : ", i+1);
        scanf ("%s", &notas[i].nome);
        printf("digite a %d° nota do %s : ", i+1 , notas[i].nome);
        scanf ("%f", &notas[i].nota); 
    }

media = (notas[0].nota + notas[1].nota + notas[2].nota + notas[3].nota) / 4;
printf("a média dos alunos é %.2f", notas[0].nome, media);


}


