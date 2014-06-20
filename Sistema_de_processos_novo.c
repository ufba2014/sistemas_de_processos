#include <stdio.h>
#include <stdlib.h>

struct cli_Dados // ESTRUTURA DOS DADOS DOS CLIENTES
{
  char nome[30],endereco[30],sup_Merc[30];
  int ident, telefone, id;
  float valor;
  struct cli_Dados *prox; // VAI APONTAR PARA O PROXIMO ELEMENTO DA ESTRUTURA
};

struct cli_Dados *gancho; //gancho funciona como uma transitividade para chamar o proximo item.

void ini_fila() //FUNÇÂO QUE INICIA A FILA
{
  struct cli_Dados *aux; //Ponteiro local do tipo cli_Dados
  aux = (struct cli_Dados*) malloc(sizeof(struct cli_Dados)); //Aloca um espaço na memoria para a variavel aux
  aux->prox = (struct cli_Dados *)0; //Inicia o primeiro elemento da fila como valor nulo
  gancho = aux; // aux é igual a primeiro elemnto da pilha.
}

/// ÍNDICE DE FUNÇÔES DO PROGRAMA

int menu(void);


int main(void) //FUNÇÂO PRINCIPAL
{
  menu();
  system("pause");
  return 0;
}

int menu(void)
{
  int op;

  do
  {
    system("cls");
    puts("\tSISTEMA DE PROCESSOS");
    puts("");
    puts("\t1 - Adicionar processo");
    puts("\t2 - Consultar Processo");
    puts("\t3 - Mostrar primeiro");
    puts("\t4 - Remove Processo");
    puts("\t5 - Dar prioridade");
    puts("\t6 - Sair");
    printf("\nDigite a op%c%co: ",135,198);
    scanf("%i",&op);
    switch(op)
    {
      case 1:
        {

        }
      case 2:
        {

        }
      case 3:
        {

        }
      case 4:
        {

        }
      case 5:
        {

        }
      case 6:
        {
          return (0);
        }
      default:
        {
          printf("\tOp%c%co inv%clida\n",135, 198, 160);
          system("pause");
        }
    }
  }while(1);
}
