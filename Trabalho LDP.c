#include <stdio.h>
#include <string.h>

// ==== 1 - CADASTRAR =====
void cadastrar(int codigo[], char nome[][15], int *total) {
    // ==== VERIFICA SE O CADASTRO ESTÁ CHEIO =====
    if (*total == 5) {
        printf("\nCadastro cheio!\n");
        return;
    }

    // ==== LÊ O CÓDIGO =====
    printf("\nDigite o codigo: ");
    scanf("%d", &codigo[*total]);
    getchar();

    // ==== LÊ O NOME =====
    printf("Digite o nome: ");
    fgets(nome[*total], 15, stdin);
    nome[*total][strcspn(nome[*total], "\n")] = '\0'; // ==== REMOVE O \n DO FGETS =====

    // ==== ATUALIZA O TOTAL DE REGISTROS =====
    (*total)++;
    printf("\nCadastro realizado com sucesso!\n");
}

// ==== 2 - CONSULTAR =====
void consultar(int codigo[], char nome[][15], int total) {
    int busca, i, achou = 0;

    // ==== SOLICITA CÓDIGO PARA CONSULTA =====
    printf("\nDigite o codigo para consulta: ");
    scanf("%d", &busca);

    // ==== PERCORRE O VETOR PROCURANDO O CÓDIGO =====
    for (i = 0; i < total; i++) {
        if (codigo[i] == busca) {
            // ==== SE O CÓDIGO FOR ENCONTRADO, MOSTRA ELE E O NOME =====
            printf("\nCodigo: %d\nNome: %s\n", codigo[i], nome[i]);
            achou = 1;
            break;
        }
    }

    // ==== INFORMA SE O REGISTRO NÃO FOI ENCONTRADO =====
    if (!achou) {
        printf("\nRegistro nao encontrado!\n");
    }
}

// ==== 3 - LISTAR =====
void listar(int codigo[], char nome[][15], int total) {
    int i;

    // ==== VERIFICA SE NÃO HÁ REGISTROS =====
    if (total == 0) {
        printf("\nNenhum registro cadastrado!\n");
        return;
    }

    // ==== PERCORRE OS REGISTROS CADASTRADOS =====
    printf("\n===== LISTA DE CADASTROS =====\n");
    for (i = 0; i < total; i++) {
        // ==== MOSTRA O CÓDIGO E O NOME DE CADA REGISTRO =====
        printf("Codigo: %d | Nome: %s\n", codigo[i], nome[i]);
    }
}

// ==== 4 - ALTERAR =====
void alterar(int codigo[], char nome[][15], int total) {
    int busca, i, achou = 0;

    // ==== SOLICITA O CÓDIGO QUE SERÁ ALTERADO =====
    printf("\nDigite o codigo que sera alterado: ");
    scanf("%d", &busca);

    // ==== PROCURA O CÓDIGO NO VETOR =====
    for (i = 0; i < total; i++) {
        if (codigo[i] == busca) {
            // ==== LÊ O NOVO CÓDIGO E O NOVO NOME =====
            printf("Digite o novo codigo: ");
            scanf("%d", &codigo[i]);
            getchar();

            printf("Digite o novo nome: ");
            fgets(nome[i], 15, stdin);
            nome[i][strcspn(nome[i], "\n")] = '\0';

            printf("\nRegistro alterado com sucesso!\n");
            achou = 1;
            break;
        }
    }

    // ==== INFORMA SE NÃO FOI ENCONTRADO =====
    if (!achou) {
        printf("\nRegistro nao encontrado!\n");
    }
}

// ==== 5 - EXCLUIR =====
void excluir(int codigo[], char nome[][15], int *total) {
    int busca, i, j, achou = 0;

    // ==== SOLICITA O CÓDIGO QUE SERÁ EXCLUÍDO =====
    printf("\nDigite o codigo que sera excluido: ");
    scanf("%d", &busca);

    // ==== PROCURA O REGISTRO NO VETOR =====
    for (i = 0; i < *total; i++) {
        if (codigo[i] == busca) {
            // ==== DESLOCA OS REGISTROS SEGUINTES UMA POSIÇÃO PARA A ESQUERDA =====
            for (j = i; j < *total - 1; j++) {
                codigo[j] = codigo[j + 1];
                strcpy(nome[j], nome[j + 1]);
            }

            // ==== DIMINUI O TOTAL DE REGISTROS =====
            (*total)--;
            printf("\nRegistro excluido com sucesso!\n");
            achou = 1;
            break;
        }
    }

    // ==== INFORMA SE NÃO FOI ENCONTRADO =====
    if (!achou) {
        printf("\nRegistro nao encontrado!\n");
    }
}

// ==== PROGRAMA PRINCIPAL =====
int main(void) {
    int codigo[5];
    char nome[5][15];
    int total = 0;
    int opcao;

    do {
        printf("\n\n===== MENU =====");
        printf("\n1 - Cadastrar");
        printf("\n2 - Consultar");
        printf("\n3 - Listar");
        printf("\n4 - Alterar");
        printf("\n5 - Excluir");
        printf("\n0 - Sair");
        printf("\nEscolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                cadastrar(codigo, nome, &total);
                break;
            case 2:
                consultar(codigo, nome, total);
                break;
            case 3:
                listar(codigo, nome, total);
                break;
            case 4:
                alterar(codigo, nome, total);
                break;
            case 5:
                excluir(codigo, nome, &total);
                break;
            case 0:
                printf("\nEncerrando...\n");
                break;
            default:
                printf("\nOpcao invalida!\n");
        }
    } while (opcao != 0);

    return 0;
}
