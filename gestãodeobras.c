#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Definições de estruturas
typedef struct {
    int matricula;
    char nome[100];
    char empresa[100];
    char data_admissao[20];
    char setor_trabalho[100];
    char cargo[100];
    char recebe_epi;
    int numero_conselho;
    float salario_base;
    char possui_gratificacao;
} Funcionario;

typedef struct {
    int codigo_obra;
    char descricao[100];
    char endereco[150];
    char engenheiro_responsavel[100];
    char tipo_obra[50];
    float area_total_terreno;
    float metros_quadrados_construir;
    float custo_previsto_obra;
    float custo_mao_de_obra;
    float custo_mat_prima;
    float custo_real;
} CanteiroObra;

typedef struct {
    int codigo;
    char descricao[100];
    int quantidade;
    float preco_unitario;
} MateriaPrima;

typedef struct {
    int codigo;
    char descricao[100];
    char tipo_equipamento[50];
    char tipo_protecao[50];
    int estoque_minimo;
    int estoque_maximo;
    int estoque_atual;
    float valor_unitario;
    char data_cadastro[20];
} Epi;

// Protótipos das funções
void limpar_tela();
void esperar_usuario();
void menu(Funcionario *funcionarios, CanteiroObra *canteiro_obras, MateriaPrima *materia_primas, Epi *episs);
void cadastrar_funcionario(Funcionario *funcionarios);
void cadastrar_canteiro_obra(CanteiroObra *canteiro_obras);
void cadastrar_materia_prima(MateriaPrima *materia_primas);
void cadastrar_epi(Epi *episs);
void imprimir_funcionarios(Funcionario *funcionarios);
void imprimir_canteiro_obra(CanteiroObra *canteiro_obras);
void imprimir_materia_prima(MateriaPrima *materia_primas);
void imprimir_epi(Epi *episs);
void acompanhar_obra(CanteiroObra *canteiro_obras);

// Funções para salvar e carregar dados
void salvar_funcionarios(Funcionario *funcionarios, int tamanho);
void carregar_funcionarios(Funcionario *funcionarios, int tamanho);
void salvar_canteiro_obras(CanteiroObra *canteiro_obras, int tamanho);
void carregar_canteiro_obras(CanteiroObra *canteiro_obras, int tamanho);
void salvar_materia_primas(MateriaPrima *materia_primas, int tamanho);
void carregar_materia_primas(MateriaPrima *materia_primas, int tamanho);
void salvar_epis(Epi *episs, int tamanho);
void carregar_epis(Epi *episs, int tamanho);

// Função principal
int main() {
    Funcionario funcionarios[10] = {0};
    CanteiroObra canteiro_obras[10] = {0};
    MateriaPrima materia_primas[10] = {0};
    Epi episs[10] = {0};

    carregar_funcionarios(funcionarios, 10);
    carregar_canteiro_obras(canteiro_obras, 10);
    carregar_materia_primas(materia_primas, 10);
    carregar_epis(episs, 10);

    while (1) {
        menu(funcionarios, canteiro_obras, materia_primas, episs);
    }

    return 0;
}

// Funções auxiliares
void limpar_tela() {
    system("clear || cls");
}

void esperar_usuario() {
    printf("\nPressione Enter para continuar...");
    getchar();
    getchar();
}

void menu(Funcionario *funcionarios, CanteiroObra *canteiro_obras, MateriaPrima *materia_primas, Epi *episs) {
    limpar_tela();
    int opcao;

    printf("|===========================================|\n");
    printf("|         Sistema de Gestão de obras        |\n");
    printf("|===========================================|\n");
    printf("|1. Cadastrar Funcionário                   |\n");
    printf("|2. Cadastrar Canteiro de Obra              |\n");
    printf("|3. Cadastrar Matéria Prima                 |\n");
    printf("|4. Cadastrar EPI                           |\n");
    printf("|5. Imprimir Funcionários                   |\n");
    printf("|6. Imprimir Canteiros de Obra              |\n");
    printf("|7. Imprimir Matérias Primas                |\n");
    printf("|8. Imprimir EPIs                           |\n");
    printf("|9. Acompanhar Obra                         |\n");
    printf("|0. Sair                                    |\n");
    printf("|===========================================|\n");
    printf("Escolha uma opção: ");
    scanf("%d", &opcao);

    switch(opcao) {
        case 1:
            cadastrar_funcionario(funcionarios);
            salvar_funcionarios(funcionarios, 10);
            break;
        case 2:
            cadastrar_canteiro_obra(canteiro_obras);
            salvar_canteiro_obras(canteiro_obras, 10);
            break;
        case 3:
            cadastrar_materia_prima(materia_primas);
            salvar_materia_primas(materia_primas, 10);
            break;
        case 4:
            cadastrar_epi(episs);
            salvar_epis(episs, 10);
            break;
        case 5:
            imprimir_funcionarios(funcionarios);
            break;
        case 6:
            imprimir_canteiro_obra(canteiro_obras);
            break;
        case 7:
            imprimir_materia_prima(materia_primas);
            break;
        case 8:
            imprimir_epi(episs);
            break;
        case 9:
            acompanhar_obra(canteiro_obras);
            break;
        case 0:
            salvar_funcionarios(funcionarios, 10);
            salvar_canteiro_obras(canteiro_obras, 10);
            salvar_materia_primas(materia_primas, 10);
            salvar_epis(episs, 10);
            exit(0);
        default:
            printf("Opção inválida!\n");
            esperar_usuario();
    }
}

// Funções de cadastro
void cadastrar_funcionario(Funcionario *funcionarios) {
    limpar_tela();
    static int count = 0;

    if (count < 10) {
        printf("===================================\n");
        printf("         Cadastrar Funcionário     \n");
        printf("===================================\n");
        printf("Matrícula: ");
        scanf("%d", &funcionarios[count].matricula);
        printf("Nome: ");
        scanf(" %[^\n]", funcionarios[count].nome);
        printf("Empresa: ");
        scanf(" %[^\n]", funcionarios[count].empresa);
        printf("Data de Admissão (dd/mm/aaaa): ");
        scanf(" %[^\n]", funcionarios[count].data_admissao);
        printf("Setor de Trabalho: ");
        scanf(" %[^\n]", funcionarios[count].setor_trabalho);
        printf("Cargo: ");
        scanf(" %[^\n]", funcionarios[count].cargo);
        printf("Recebe EPI (S/N): ");
        scanf(" %c", &funcionarios[count].recebe_epi);
        printf("Número do Conselho (se houver): ");
        scanf("%d", &funcionarios[count].numero_conselho);
        printf("Salário Base: ");
        scanf("%f", &funcionarios[count].salario_base);
        printf("Possui Gratificação (S/N): ");
        scanf(" %c", &funcionarios[count].possui_gratificacao);
        count++;
    } else {
        printf("Limite de funcionários cadastrados atingido.\n");
    }

    esperar_usuario();
}

void cadastrar_canteiro_obra(CanteiroObra *canteiro_obras) {
    limpar_tela();
    static int count = 0;

    if (count < 10) {
        printf("===================================\n");
        printf("      Cadastrar Canteiro de Obra   \n");
        printf("===================================\n");
        printf("Código da Obra: ");
        scanf("%d", &canteiro_obras[count].codigo_obra);
        printf("Descrição: ");
        scanf(" %[^\n]", canteiro_obras[count].descricao);
        printf("Endereço: ");
        scanf(" %[^\n]", canteiro_obras[count].endereco);
        printf("Engenheiro Responsável: ");
        scanf(" %[^\n]", canteiro_obras[count].engenheiro_responsavel);
        printf("Tipo de Obra: ");
        scanf(" %[^\n]", canteiro_obras[count].tipo_obra);
        printf("Área Total do Terreno: ");
        scanf("%f", &canteiro_obras[count].area_total_terreno);
        printf("Metros Quadrados a Construir: ");
        scanf("%f", &canteiro_obras[count].metros_quadrados_construir);
        printf("Custo Previsto da Obra: ");
        scanf("%f", &canteiro_obras[count].custo_previsto_obra);
        printf("Custo da Mão de Obra: ");
        scanf("%f", &canteiro_obras[count].custo_mao_de_obra);
        printf("Custo da Matéria Prima: ");
        scanf("%f", &canteiro_obras[count].custo_mat_prima);
        printf("Custo Real: ");
        scanf("%f", &canteiro_obras[count].custo_real);
        count++;
    } else {
        printf("Limite de canteiros de obra cadastrados atingido.\n");
    }

    esperar_usuario();
}

void cadastrar_materia_prima(MateriaPrima *materia_primas) {
    limpar_tela();
    static int count = 0;

    if (count < 10) {
        printf("===================================\n");
        printf("      Cadastrar Matéria Prima      \n");
        printf("===================================\n");
        printf("Código: ");
        scanf("%d", &materia_primas[count].codigo);
        printf("Descrição: ");
        scanf(" %[^\n]", materia_primas[count].descricao);
        printf("Quantidade: ");
        scanf("%d", &materia_primas[count].quantidade);
        printf("Preço Unitário: ");
        scanf("%f", &materia_primas[count].preco_unitario);
        count++;
    } else {
        printf("Limite de matérias primas cadastradas atingido.\n");
    }

    esperar_usuario();
}

void cadastrar_epi(Epi *episs) {
    limpar_tela();
    static int count = 0;

    if (count < 10) {
        printf("===================================\n");
        printf("             Cadastrar EPI         \n");
        printf("===================================\n");
        printf("Código: ");
        scanf("%d", &episs[count].codigo);
        printf("Descrição: ");
        scanf(" %[^\n]", episs[count].descricao);
        printf("Tipo de Equipamento: ");
        scanf(" %[^\n]", episs[count].tipo_equipamento);
        printf("Tipo de Proteção: ");
        scanf(" %[^\n]", episs[count].tipo_protecao);
        printf("Estoque Mínimo: ");
        scanf("%d", &episs[count].estoque_minimo);
        printf("Estoque Máximo: ");
        scanf("%d", &episs[count].estoque_maximo);
        printf("Estoque Atual: ");
        scanf("%d", &episs[count].estoque_atual);
        printf("Valor Unitário: ");
        scanf("%f", &episs[count].valor_unitario);
        printf("Data de Cadastro (dd/mm/aaaa): ");
        scanf(" %[^\n]", episs[count].data_cadastro);
        count++;
    } else {
        printf("Limite de EPIs cadastrados atingido.\n");
    }

    esperar_usuario();
}

// Funções de impressão
void imprimir_funcionarios(Funcionario *funcionarios) {
    limpar_tela();
    printf("===================================\n");
    printf("       Funcionários Cadastrados    \n");
    printf("===================================\n");
    int i;
    for (i = 0; i < 10; i++) {
        if (funcionarios[i].matricula != 0) {
            printf("Matrícula: %d\n", funcionarios[i].matricula);
            printf("Nome: %s\n", funcionarios[i].nome);
            printf("Empresa: %s\n", funcionarios[i].empresa);
            printf("Data de Admissão: %s\n", funcionarios[i].data_admissao);
            printf("Setor de Trabalho: %s\n", funcionarios[i].setor_trabalho);
            printf("Cargo: %s\n", funcionarios[i].cargo);
            printf("Recebe EPI: %c\n", funcionarios[i].recebe_epi);
            printf("Número do Conselho: %d\n", funcionarios[i].numero_conselho);
            printf("Salário Base: %.2f\n", funcionarios[i].salario_base);
            printf("Possui Gratificação: %c\n\n", funcionarios[i].possui_gratificacao);
        }
    }

    esperar_usuario();
}

void imprimir_canteiro_obra(CanteiroObra *canteiro_obras) {
    limpar_tela();
    printf("===================================\n");
    printf("    Canteiros de Obra Cadastrados  \n");
    printf("===================================\n");
    int i;
    for (i = 0; i < 10; i++) {
        if (canteiro_obras[i].codigo_obra != 0) {
            printf("Código da Obra: %d\n", canteiro_obras[i].codigo_obra);
            printf("Descrição: %s\n", canteiro_obras[i].descricao);
            printf("Endereço: %s\n", canteiro_obras[i].endereco);
            printf("Engenheiro Responsável: %s\n", canteiro_obras[i].engenheiro_responsavel);
            printf("Tipo de Obra: %s\n", canteiro_obras[i].tipo_obra);
            printf("Área Total do Terreno: %.2f\n", canteiro_obras[i].area_total_terreno);
            printf("Metros Quadrados a Construir: %.2f\n", canteiro_obras[i].metros_quadrados_construir);
            printf("Custo Previsto da Obra: %.2f\n", canteiro_obras[i].custo_previsto_obra);
            printf("Custo da Mão de Obra: %.2f\n", canteiro_obras[i].custo_mao_de_obra);
            printf("Custo da Matéria Prima: %.2f\n", canteiro_obras[i].custo_mat_prima);
            printf("Custo Real: %.2f\n\n", canteiro_obras[i].custo_real);
        }
    }

    esperar_usuario();
}

void imprimir_materia_prima(MateriaPrima *materia_primas) {
    limpar_tela();
    printf("===================================\n");
    printf("      Matérias Primas Cadastradas  \n");
    printf("===================================\n");
    int i;
    for (i = 0; i < 10; i++) {
        if (materia_primas[i].codigo != 0) {
            printf("Código: %d\n", materia_primas[i].codigo);
            printf("Descrição: %s\n", materia_primas[i].descricao);
            printf("Quantidade: %d\n", materia_primas[i].quantidade);
            printf("Preço Unitário: %.2f\n\n", materia_primas[i].preco_unitario);
        }
    }

    esperar_usuario();
}

void imprimir_epi(Epi *episs) {
    limpar_tela();
    printf("===================================\n");
    printf("             EPIs Cadastrados      \n");
    printf("===================================\n");
    int i;
    for (i = 0; i < 10; i++) {
        if (episs[i].codigo != 0) {
            printf("Código: %d\n", episs[i].codigo);
            printf("Descrição: %s\n", episs[i].descricao);
            printf("Tipo de Equipamento: %s\n", episs[i].tipo_equipamento);
            printf("Tipo de Proteção: %s\n", episs[i].tipo_protecao);
            printf("Estoque Mínimo: %d\n", episs[i].estoque_minimo);
            printf("Estoque Máximo: %d\n", episs[i].estoque_maximo);
            printf("Estoque Atual: %d\n", episs[i].estoque_atual);
            printf("Valor Unitário: %.2f\n", episs[i].valor_unitario);
            printf("Data de Cadastro: %s\n\n", episs[i].data_cadastro);
        }
    }

    esperar_usuario();
}

void acompanhar_obra(CanteiroObra *canteiro_obras) {
    limpar_tela();
    int codigo;
    printf("===================================\n");
    printf("          Acompanhar Obra           \n");
    printf("===================================\n");
    printf("Digite o código da obra: ");
    scanf("%d", &codigo);

    for (int i = 0; i < 10; i++) {
        if (canteiro_obras[i].codigo_obra == codigo) {
            printf("Código da Obra: %d\n", canteiro_obras[i].codigo_obra);
            printf("Descrição: %s\n", canteiro_obras[i].descricao);
            printf("Endereço: %s\n", canteiro_obras[i].endereco);
            printf("Engenheiro Responsável: %s\n", canteiro_obras[i].engenheiro_responsavel);
            printf("Tipo de Obra: %s\n", canteiro_obras[i].tipo_obra);
            printf("Área Total do Terreno: %.2f\n", canteiro_obras[i].area_total_terreno);
            printf("Metros Quadrados a Construir: %.2f\n", canteiro_obras[i].metros_quadrados_construir);
            printf("Custo Previsto da Obra: %.2f\n", canteiro_obras[i].custo_previsto_obra);
            printf("Custo da Mão de Obra: %.2f\n", canteiro_obras[i].custo_mao_de_obra);
            printf("Custo da Matéria Prima: %.2f\n", canteiro_obras[i].custo_mat_prima);
            printf("Custo Real: %.2f\n", canteiro_obras[i].custo_real);
            printf("-----------------------------------\n");
            break;
        }
    }

    esperar_usuario();
}


// Funções para salvar dados em arquivo
void salvar_funcionarios(Funcionario *funcionarios, int tamanho) {
    FILE *file = fopen("funcionarios.txt", "w+");
    if (file == NULL) {
        printf("Erro ao abrir o arquivo para escrita.\n");
        return;
    }
    int i;
    for (i = 0; i < tamanho; i++) {
        if (funcionarios[i].matricula != 0) {
            fprintf(file, "%d\n", funcionarios[i].matricula);
            fprintf(file, "%s\n", funcionarios[i].nome);
            fprintf(file, "%s\n", funcionarios[i].empresa);
            fprintf(file, "%s\n", funcionarios[i].data_admissao);
            fprintf(file, "%s\n", funcionarios[i].setor_trabalho);
            fprintf(file, "%s\n", funcionarios[i].cargo);
            fprintf(file, "%c\n", funcionarios[i].recebe_epi);
            fprintf(file, "%d\n", funcionarios[i].numero_conselho);
            fprintf(file, "%.2f\n", funcionarios[i].salario_base);
            fprintf(file, "%c\n", funcionarios[i].possui_gratificacao);
        }
    }
    fclose(file);
}

void salvar_canteiro_obras(CanteiroObra *canteiro_obras, int tamanho) 
{
    FILE *file = fopen("canteiro_obras.txt", "w+");
    if (file == NULL) {
        printf("Erro ao abrir o arquivo para escrita.\n");
        return;
    }
    int i;
    for (i = 0; i < tamanho; i++) {
        if (canteiro_obras[i].codigo_obra != 0) {
            fprintf(file, "%d\n",canteiro_obras[i].codigo_obra);
            fprintf(file, "%s\n",canteiro_obras[i].descricao);
            fprintf(file, "%s\n",canteiro_obras[i].endereco);
            fprintf(file, "%s\n",canteiro_obras[i].engenheiro_responsavel);
            fprintf(file, "%s\n",canteiro_obras[i].tipo_obra);
            fprintf(file, "%.2f\n",canteiro_obras[i].area_total_terreno);
            fprintf(file, "%.2f\n",canteiro_obras[i].metros_quadrados_construir);
            fprintf(file, "%.2f\n",canteiro_obras[i].custo_previsto_obra);
            fprintf(file, "%.2f\n",canteiro_obras[i].custo_mao_de_obra);
            fprintf(file, "%.2f\n",canteiro_obras[i].custo_mat_prima);
            fprintf(file, "%.2f\n",canteiro_obras[i].custo_real);
        }
    
}fclose(file);
}

void salvar_materia_primas(MateriaPrima *materia_primas, int tamanho) {
    FILE *file = fopen("materia_primas.txt", "w+");
    if (file == NULL) {
        printf("Erro ao abrir o arquivo para escrita.\n");
        return;
    }
    int i;
    for (i = 0; i < tamanho; i++) {
        if (materia_primas[i].codigo != 0) {
            fprintf(file, "%d\n", materia_primas[i].codigo);
            fprintf(file, "%s\n", materia_primas[i].descricao);
            fprintf(file, "%d\n", materia_primas[i].quantidade);
            fprintf(file, "%.2f\n", materia_primas[i].preco_unitario);
        }
    }
    fclose(file);
}

void salvar_epis(Epi *episs, int tamanho) {
    FILE *file = fopen("epis.txt", "w+");
    if (file == NULL) {
        printf("Erro ao abrir o arquivo para escrita.\n");
        return;
    }
     int i;
    for (i = 0; i < tamanho; i++) {
        if (episs[i].codigo != 0) {
            fprintf(file, "%d\n",episs[i].codigo);
            fprintf(file, "%s\n",episs[i].descricao);
            fprintf(file, "%s\n",episs[i].tipo_equipamento);
            fprintf(file, "%s\n",episs[i].tipo_protecao);
            fprintf(file, "%d\n",episs[i].estoque_minimo);
            fprintf(file, "%d\n",episs[i].estoque_maximo);
            fprintf(file, "%d\n",episs[i].estoque_atual);
            fprintf(file, "%d\n",episs[i].valor_unitario);
            fprintf(file, "%s\n",episs[i].data_cadastro);
        }
    
}fclose(file);}

// Funções para carregar dados de arquivo
void carregar_funcionarios(Funcionario *funcionarios, int tamanho) {
    FILE *file = fopen("funcionarios.txt", "r+");
    if (file == NULL) {
        printf("Arquivo de funcionários não encontrado. Criando um novo.\n");
        return;
    }
    int i;
    for (i = 0; i < tamanho; i++) {
        if (fscanf(file, "%d\n", &funcionarios[i].matricula) != 1) break;
        fscanf(file, " %[^\n]", funcionarios[i].nome);
        fscanf(file, " %[^\n]", funcionarios[i].empresa);
        fscanf(file, " %[^\n]", funcionarios[i].data_admissao);
        fscanf(file, " %[^\n]", funcionarios[i].setor_trabalho);
        fscanf(file, " %[^\n]", funcionarios[i].cargo);
        fscanf(file, " %c\n", &funcionarios[i].recebe_epi);
        fscanf(file, "%d\n", &funcionarios[i].numero_conselho);
        fscanf(file, "%f\n", &funcionarios[i].salario_base);
        fscanf(file, " %c\n", &funcionarios[i].possui_gratificacao);
    }
    fclose(file);
}

void carregar_canteiro_obras(CanteiroObra *canteiro_obras, int tamanho) {
    FILE *file = fopen("canteiro_obras.txt", "r+");
    if (file == NULL) {
        printf("Arquivo de canteiro de obras não encontrado. Criando um novo.\n");
        return;
    }
    int i;
    for (i = 0; i < tamanho; i++) {
        if (fscanf(file, "%d\n", &canteiro_obras[i].codigo_obra) != 1) break;
        fscanf(file, " %[^\n]", canteiro_obras[i].descricao);
        fscanf(file, " %[^\n]", canteiro_obras[i].endereco);
        fscanf(file, " %[^\n]", canteiro_obras[i].engenheiro_responsavel);
        fscanf(file, " %[^\n]", canteiro_obras[i].tipo_obra);
        fscanf(file, "%f\n", &canteiro_obras[i].area_total_terreno);
        fscanf(file, "%f\n", &canteiro_obras[i].metros_quadrados_construir);
        fscanf(file, "%f\n", &canteiro_obras[i].custo_previsto_obra);
        fscanf(file, "%f\n", &canteiro_obras[i].custo_mao_de_obra);
        fscanf(file, "%f\n", &canteiro_obras[i].custo_mat_prima);
        fscanf(file, "%f\n", &canteiro_obras[i].custo_real);
    }
    fclose(file);
}

void carregar_materia_primas(MateriaPrima *materia_primas, int tamanho) {
    FILE *file = fopen("materia_primas.txt", "r+");
    if (file == NULL) {
        printf("Arquivo de matéria-prima não encontrado. Criando um novo.\n");
        return;
    }
    int i;
    for (i = 0; i < tamanho; i++) {
        if (fscanf(file, "%d\n", &materia_primas[i].codigo) != 1) break;
        fscanf(file, " %[^\n]", materia_primas[i].codigo);
        fscanf(file, " %[^\n]", materia_primas[i].descricao);
        fscanf(file, " %[^\n]", materia_primas[i].preco_unitario);
        fscanf(file, " %[^\n]", materia_primas[i].quantidade);
    }
    fclose(file);
}

void carregar_epis(Epi *episs, int tamanho) {
    FILE *file = fopen("epis.txt", "r+");
    if (file == NULL) {
        printf("Arquivo de EPIs não encontrado. Criando um novo.\n");
        return;
    }
    int i;
    for (i = 0; i < tamanho; i++) {
        if (fscanf(file, "%d\n", &episs[i].codigo) != 1) break;
        fscanf(file, " %[^\n]", episs[i].codigo);
        fscanf(file, " %[^\n]", episs[i].descricao);
        fscanf(file, " %[^\n]", episs[i].tipo_equipamento);
        fscanf(file, " %[^\n]", episs[i].tipo_protecao);
        fscanf(file, " %[^\n]", episs[i].estoque_minimo);
        fscanf(file, " %d\n", &episs[i].estoque_maximo);
        fscanf(file, "%d\n", &episs[i].estoque_atual);
        fscanf(file, "%f\n", &episs[i].valor_unitario);
        fscanf(file, " %s\n", &episs[i].data_cadastro);
    }
    fclose(file);
}
