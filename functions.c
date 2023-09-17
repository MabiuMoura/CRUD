#include <stdio.h>
#include "functions.h"

void inputData()
{
    FILE *file;
    DATA users;
    file = fopen("usuarios.txt", "a");

    if (file == NULL)
    {
        printf("Não foi possível abrir o arquivo.\n");
    }
    else
    {
        int id_counter = 0;
        FILE *id_file = fopen("id_counter.txt", "r");
        if (id_file)
        {
            fscanf(id_file, "%d", &id_counter);
            fclose(id_file);
        }

        char x;
        do
        {
            scanf("%*c");
            printf("Digite o nome: ");
            fscanf(stdin, "%s", users.nome);

            users.id = ++id_counter;

            printf("Digite a idade: ");
            scanf("%d", &users.idade);

            fprintf(file, "%d %s %d\n", users.id, users.nome, users.idade);
            printf("Deseja continuar(s/n)? ");
            scanf(" %c", &x);

        } while (x == 's');

        id_file = fopen("id_counter.txt", "w");
        if (id_file)
        {
            fprintf(id_file, "%d", id_counter);
            fclose(id_file);
        }
        fclose(file);
    }
}

void removeusers(int id)
{
    FILE *file = fopen("usuarios.txt", "r");
    FILE *tempFile = fopen("temp.txt", "w");

    if (file == NULL || tempFile == NULL)
    {
        printf("Erro ao abrir arquivos.\n");
        return;
    }

    DATA users;
    int encontrado = 0;

    while (fscanf(file, "%d %s %d", &users.id, users.nome, &users.idade) != EOF)
    {
        if (users.id != id)
        {
            fprintf(tempFile, "%d %s %d\n", users.id, users.nome, users.idade);
        }
        else
        {
            encontrado = 1;
        }
    }

    fclose(file);
    fclose(tempFile);

    if (encontrado == 1)
    {
        remove("usuarios.txt");
        rename("temp.txt", "usuarios.txt");
        printf("Usuário removido com sucesso.\n");
    }
    else
    {
        printf("Usuário com ID %d não encontrado.\n", id);
    }
    printf("\nPressione Enter para voltar ao menu...\n");
    getchar();
    getchar();
}

void pesquisausers(int id)
{
    FILE *file = fopen("usuarios.txt", "r");

    if (file == NULL)
    {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }

    DATA users;
    int encontrado = 0;

    while (fscanf(file, "%d %s %d", &users.id, users.nome, &users.idade) != EOF)
    {
        if (users.id == id)
        {
            printf("Usuário encontrado:\n");
            printf("ID: %d, Nome: %s, Idade: %d\n", users.id, users.nome, users.idade);
            encontrado = 1;
            break;
        }
    }

    fclose(file);

    if (!encontrado)
    {
        printf("Usuário com ID %d não encontrado.\n", id);
    }
    printf("\nPressione Enter para voltar ao menu...\n");
    getchar();
    getchar();
}

void listarTodos()
{
    FILE *file;
    DATA users;

    file = fopen("usuarios.txt", "r");
    if (file == NULL)
    {
        printf("Não foi possível abrir o arquivo.\n");
    }
    else
    {
        printf("Lista de Funcionários:\n");
        while (fscanf(file, "%d %s %d", &users.id, users.nome, &users.idade) != EOF)
        {
            printf("ID: %d, Nome: %s, Idade: %d\n", users.id, users.nome, users.idade);
        }
        fclose(file);

        printf("\nPressione Enter para voltar ao menu...\n");
        getchar();
        getchar();
    }
}

void atualizausers(int id)
{
    FILE *file = fopen("usuarios.txt", "r");
    FILE *tempFile = fopen("temp.txt", "w");

    if (file == NULL || tempFile == NULL)
    {
        printf("Erro ao abrir arquivos.\n");
        return;
    }

    DATA users;
    int encontrado = 0;

    while (fscanf(file, "%d %s %d", &users.id, users.nome, &users.idade) != EOF)
    {
        if (users.id == id)
        {
            encontrado = 1;

            printf("Usuário encontrado:\n");
            printf("ID: %d, Nome: %s, Idade: %d\n", users.id, users.nome, users.idade);

            printf("Digite o novo nome: ");
            scanf("%s", users.nome);

            printf("Digite a nova idade: ");
            scanf("%d", &users.idade);

            fprintf(tempFile, "%d %s %d\n", users.id, users.nome, users.idade);
            printf("Usuário atualizado com sucesso.\n");
        }
        else
        {
            fprintf(tempFile, "%d %s %d\n", users.id, users.nome, users.idade);
        }
    }

    fclose(file);
    fclose(tempFile);

    if (encontrado)
    {
        remove("usuarios.txt");
        rename("temp.txt", "usuarios.txt");
    }
    else
    {
        printf("Usuário com ID %d não encontrado.\n", id);
    }
    printf("\nPressione Enter para voltar ao menu...\n");
    getchar();
    getchar();
}

void cabecalho()
{
    system("clear");
    printf("-------------------------------\n");
    printf("GERENCIAMENTO DE users\n");
    printf("-------------------------------\n\n");
    printf("1 - Inserir\n");
    printf("2 - Remover\n");
    printf("3 - Pesquisar\n");
    printf("4 - Listar todos\n");
    printf("5 - Atualizar usuario\n");
    printf("6 - Sair\n\n");
    printf("Escolha uma opção: ");
}