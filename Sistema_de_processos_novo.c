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

int tam; //VARIAVEL GLOBAL QUE VAI COMEÇAR EM 0 E SERÁ INCREMENTADA CADA VEZ QUE UM ELEMENTO FOR INSERIDO

void ini_fila() //FUN��O QUE INICIA A FILA
{
  struct cli_Dados *aux; //Ponteiro local do tipo cli_Dados
  aux = (struct cli_Dados*) malloc(sizeof(struct cli_Dados)); //Aloca um espa�o na memoria para a variavel aux
  aux->prox = (struct cli_Dados *)0; //Inicia o primeiro elemento da fila como valor nulo
  gancho = aux; // aux � igual a primeiro elemnto da pilha
}

/// �NDICE DE FUN��ES DO PROGRAMA

int menu(void);
void ini_fila();
void insere();
void most_prim(struct cli_Dados *posicao);

int main(void) //FUN��O PRINCIPAL
{
  ini_fila();
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
    puts("\t4 - Mostrar ultimo");
    puts("\t5 - Remover ultimo processo inserido");
    puts("\t6 - Remover processo por ID");
    puts("\t7 - Dar prioridade");
    puts("\t8 - Mostrar todos os processos");
    puts("\t9 - Sair");
    printf("\nDigite a op%c%co: ",135,198);
    scanf("%i",&op);
    switch(op)
    {
      case 1:
        {
          insere();
          menu();
          break;
        }
      case 2:
        {

        }
      case 3:
        {
          most_prim(gancho); //PASSO O ENDEREÇO DE MEMORIA DA ULTIMA ESTRUTURA A SER INSERIDA
          system("pause");
          menu();
          break;
        }
      case 4:
        {

        }
      case 5:
        {

        }
      case 6:
        {

        }
      case 7:
        {

        }
      case 8:
        {

        }
      case 9:
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

void insere() //FUNÇÃO QUE INSERE ELEMENTO NA FILA
{
  struct cli_Dados *aux; //Ponteiro local do tipo cli_Dados
  struct cli_Dados *novo = (struct cli_Dados*) malloc(sizeof(struct cli_Dados)); //Aloca um espaço na memoria pra um novo alemento

  novo->id = ++tam; //Como o id dos processos começara de 1 e tam de 0, cada processo novo terá um id igual ao numero de processos da fila mais um
  //As linhas a seguir se tratam do cadastro do elemento novo a ser inserido, campo por campo, lembrando que nas strings não é nescessario o "&"
  printf("\nNovo processo: ID.%d", novo->id);
  printf("\nNome do Cliente: ");
  scanf("%s", novo->nome);
  printf("\nEndere%co do Cliente: ",135);
  scanf("%s", novo->endereco);
  printf("\nIdentidade do Cliente: ");
  scanf("%d", &novo->ident);
  printf("\nTelefone do Cliente: ");
  scanf("%d", &novo->telefone);
  printf("\nValor do Cheque: ");
  scanf("%f", &novo->valor);
  printf("\nData do Cheque: ");
  scanf("%d", &novo->data);
  printf("\nNome do Supermercado: ");
  scanf("%s", novo->sup_Merc);
  novo->prox=gancho; //novo recebe o valor de memoria da estrutura anterior anterior
  gancho = novo; //gancho agora recebe a valor de memoria da nova insercao

  system("cls");

	printf("\nProcesso Registrado!\n");
	system("pause");
}

void most_prim(struct cli_Dados *posicao) //FFUNÇÂO QUE RECEBE COMO ARGUMENTO O ENDEREÇO DE MEMORIA DO ULTIMO ELEMENTO A SER
{                                         //INSERIDO
  printf("ID do processo: %i\n",posicao->id);
  printf("Nome: %s\n",posicao->nome);
  printf("Endere%co: %s\n",135, posicao->endereco);
  printf("Identidade: %i\n", posicao->ident);
  printf("Telefone: %i\n",posicao->telefone);
  printf("Credor: %s\n", posicao->sup_Merc);
  printf("Valor: R$ %2.f\n", posicao->valor);
  printf("Data do cheque: %i\n", posicao->data);
}
