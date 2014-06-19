#include <stdio.h>
#include <stdlib.h>

struct cli_Dados // ESTRUTURA DOS DADOS DOS CLIENTES
{
  char nome[30],endereco[30],sup_Merc[30];
  int ident, telefone, id, data;
  float valor;
  struct cli_Dados *prox; // VAI APONTAR PARA O PROXIMO ELEMENTO DA ESTRUTURA
};

struct cli_Dados *gancho; //gancho funciona como uma transitividade para chamar o proximo item.

void ini_fila() //FUN��O QUE INICIA A FILA
{
  struct cli_Dados *aux; //Ponteiro local do tipo cli_Dados
  aux = (struct cli_Dados*) malloc(sizeof(struct cli_Dados)); //Aloca um espa�o na memoria para a variavel aux
  aux->prox = (struct cli_Dados *)0; //Inicia o primeiro elemento da fila como valor nulo
  gancho = aux; // aux � igual a primeiro elemnto da pilha.
}


int main(void) //FUN��O PRINCIPAL
{
  system("pause");
  return 0;
}
