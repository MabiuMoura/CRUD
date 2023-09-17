#ifndef FUNCTIONS_H
#define FUNCTIONS_H

typedef struct funcionario DATA;
struct funcionario
{
  char nome[30];
  int idade;
  int id;
};

void inputData();
void removeusers(int id);
void pesquisausers(int id);
void listarTodos();
void atualizausers(int id);
void cabecalho();

#endif
