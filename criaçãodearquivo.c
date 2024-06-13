#include <stdio.h>
#include <stdlib.h>

    FILE *arquivo;
    char nome_arquivo[100];
    char conteudo[100];

int main() 
{
    printf("Digite o nome do arquivo: ");
    scanf("%s", nome_arquivo);
    arquivo = fopen(nome_arquivo, "w");
    if (arquivo == NULL) {
        printf("Erro ao criar o arquivo.\n");
        return 1;
    }
    printf("Digite o conteúdo do arquivo: ");
    scanf("%s", conteudo);
    fprintf(arquivo, "%s", conteudo);
    fclose(arquivo);
    arquivo = fopen(nome_arquivo, "r");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return 1;
    }
    printf("Conteúdo do arquivo:\n");
    while (fgets(conteudo, sizeof(conteudo), arquivo) != NULL) {
        printf("%s", conteudo);
    }
    fclose(arquivo);
    return 0;
}
