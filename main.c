#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "functions.h"
#include "functions.c"

int main(void) {
    setlocale(LC_ALL, "Portuguese");
    FILE *userssArquivo = fopen("usuarios.txt", "r");

    if (userssArquivo == NULL) {
        userssArquivo = fopen("usuarios.txt", "w");
        if (userssArquivo == NULL) {
            printf("Erro ao criar o arquivo usuarios.txt\n");
            return 1;
        }
    }

    fclose(userssArquivo);

    int opcao,idParaRemover,idParaPesquisar,idParaAtualizar;
    do {
        cabecalho();
        scanf("%d", &opcao);
        switch (opcao) {
            case 1:
                inputData();
                break;
            case 2:
                printf("Digite o ID do usuário a ser removido: ");
                scanf("%d", &idParaRemover);
                removeusers(idParaRemover);
                break;
            case 3:
                printf("Digite o ID do usuário a ser pesquisado: ");
                scanf("%d", &idParaPesquisar);
                pesquisausers(idParaPesquisar);
                break;
            case 4:
                listarTodos();
                break;
            case 5:
                printf("Digite o ID do usuário a ser atualizado: ");
                scanf("%d", &idParaAtualizar);
                atualizausers(idParaAtualizar);
                break;
            case 6:
                printf("Obrigado pela visita.\n");
                break;
            default:
                printf("Opção inválida.\n");
                break;
        }
    } while (opcao != 6);

    return 0;
}
