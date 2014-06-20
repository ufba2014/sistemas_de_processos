#include <stdio.h>
#include <stdlib.h>

struct cli_Dados // ESTRUTURA DOS DADOS DOS CLIENTES
{
  char nome[50],endereco[50],sup_Merc[50];
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
void most_todas(struct cli_Dados *posicao);
void most_ult(struct cli_Dados *posicao);
void consulta(struct cli_Dados *posicao);
void remove_ultimo(struct cli_Dados *posicao);

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
if(gancho->prox == (struct cli_Dados*)0)
            {
              printf("N%co existem Procesos\n",198);
            }
          else
          {
            consulta(gancho);
          }
          system("pause");
          break;
        }
      case 3:
        {
          if(gancho->prox == (struct cli_Dados*)0)
            {
              printf("N%co existem Procesos\n",198);
            }
          else
            {
              most_prim(gancho); //PASSO O ENDEREÇO DE MEMORIA DA ULTIMA ESTRUTURA A SER INSERIDA

            }
          system("pause");
          break;
        }
      case 4:
        {
          if(gancho->prox == (struct cli_Dados*)0)
            {
              printf("N%co existem Procesos\n",198);
            }
          else
          {
            most_ult(gancho);
          }
          system("pause");
          break;
        }
      case 5:
        {
          if(gancho->prox == (struct cli_Dados*)0)
            {
              printf("N%co existem Procesos\n",198);
            }
          else
          {
            remove_ultimo(gancho);
          }
          system("pause");
          break;
        }
      case 6:
        {
          break;
        }
      case 7:
        {
          break;
        }
      case 8:
        {
          if(gancho->prox == (struct cli_Dados*)0)
            {
              printf("N%co existem Procesos\n",198);
            }
          else
          {
            most_todas(gancho);
          }
          system("pause");
          break;
        }
      case 9:
        {
          return (0);
          break;
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
  system("cls");
  printf("\nNovo processo: ID.%d", novo->id);
  printf("\nNome do Cliente: ");
  fflush(stdin);
  gets(novo->nome);
  printf("\nEndere%co do Cliente: ",135);
  gets(novo->endereco);
  printf("\nIdentidade do Cliente: ");
  scanf("%d", &novo->ident);
  fflush(stdin);
  printf("\nTelefone do Cliente: ");
  scanf("%d", &novo->telefone);
  fflush(stdin);
  printf("\nValor do Cheque: ");
  scanf("%f", &novo->valor);
  fflush(stdin);
  printf("\nData do Cheque: ");
  scanf("%d", &novo->data);
  fflush(stdin);
  printf("\nNome do Supermercado: ");
  gets(novo->sup_Merc);
  novo->prox=gancho; //novo recebe o valor de memoria da estrutura anterior anterior
  gancho = novo; //gancho agora recebe a valor de memoria da nova insercao

  system("cls");

printf("\nProcesso Registrado!\n");
system("pause");
}

void most_prim(struct cli_Dados *posicao) //FFUNÇÂO QUE RECEBE COMO ARGUMENTO O ENDEREÇO DE MEMORIA DO ULTIMO ELEMENTO A SER
{ //INSERIDO
  system("cls");
  printf("ID do processo: %i\n",posicao->id);
  printf("Nome: %s\n",posicao->nome);
  printf("Endere%co: %s\n",135, posicao->endereco);
  printf("Identidade: %i\n", posicao->ident);
  printf("Telefone: %i\n",posicao->telefone);
  printf("Credor: %s\n", posicao->sup_Merc);
  printf("Valor: R$ %2.f\n", posicao->valor);
  printf("Data do cheque: %i\n", posicao->data);
}

void most_todas(struct cli_Dados *posicao) //FUNÇÃO QUE IRÁ EXIBIR TODOS OS PROCESSOS CONTIDOS NA ESTRUTURA
{//A CONDIÇÃO VAI COMPARAR CADA ELEMENTO DA FILA A NULO, E IRÁ EXIBI-LOS, ATÉ O ELEMENTO BASE QUE É O UNICO NULO
  system("cls");
  while(posicao->prox!= (struct cli_Dados*)0){
  struct cli_Dados *tmp = posicao->prox;//Um ponteiro tmp criado para auxiliar na troca de valores, sempre recebendo o elemento seguinte a ser exibido
  printf("ID do processo: %i\n",posicao->id);
  printf("Nome: %s\n",posicao->nome);
  printf("Endere%co: %s\n",135, posicao->endereco);
  printf("Identidade: %i\n", posicao->ident);
  printf("Telefone: %i\n",posicao->telefone);
  printf("Credor: %s\n", posicao->sup_Merc);
  printf("Valor: R$ %2.f\n", posicao->valor);
  printf("Data do cheque: %i\n\n\n", posicao->data);
  posicao = tmp;
  }
}

void most_ult(struct cli_Dados *posicao) //FUNÇÃO QUE IRÁ EXIBIR O ULTIMO ELEMENTO DA FILA, OU SEJA O PRIMEIRO INSERIDO
{ //A CONDIÇÃO VAI COMPARAR CADA ELEMENTO DA FILA A NULO, ATÉ CHEGAR A BASE, QUE É O UNICO QUE APONTA PARA NULO
  while(posicao->prox!= (struct cli_Dados*)0)
  {
  struct cli_Dados *tmp = posicao->prox;//Um ponteiro tmp criado para auxiliar na troca de valores
    if(tmp->prox==(struct cli_Dados*)0)
    {
      system("cls");
      printf("ID do processo: %i\n",posicao->id);
      printf("Nome: %s\n",posicao->nome);
      printf("Endere%co: %s\n",135, posicao->endereco);
      printf("Identidade: %i\n", posicao->ident);
      printf("Telefone: %i\n",posicao->telefone);
      printf("Credor: %s\n", posicao->sup_Merc);
      printf("Valor: R$ %2.f\n", posicao->valor);
      printf("Data do cheque: %i\n\n\n", posicao->data);
    }
  posicao = tmp;
  }
}

void consulta(struct cli_Dados *posicao)//FUNÇÃO QUE IRA CONSULTAR UM ELEMENTO PEDIDO PELO USUARIO PELO ID E IRA EXIBIR
{
    int i;//Variavel local criada para receber o id do usuario
    printf("\nInforme o ID do processo: ");
    scanf("%d", &i);
    if (i>tam){//Condiçao para alertar ao usuario caso o ID digitado seja maior que o numero de processos na fila
        printf("ID invalido!\n");
    }
      while(posicao->prox!= (struct cli_Dados*)0){//Condição que ira percorrer todos os nós da estrutura
        struct cli_Dados *tmp = posicao->prox;
        if(posicao->id==i){//Condição que a cada nó percorrido irá comparar o id da posição ao id que o usuario solicitou
            system("cls");
            printf("ID do processo: %i\n",posicao->id);//e se encontrar, exibir o processo na tela
            printf("Nome: %s\n",posicao->nome);
            printf("Endere%co: %s\n",135, posicao->endereco);
            printf("Identidade: %i\n", posicao->ident);
            printf("Telefone: %i\n",posicao->telefone);
            printf("Credor: %s\n", posicao->sup_Merc);
            printf("Valor: R$ %2.f\n", posicao->valor);
            printf("Data do cheque: %i\n\n\n", posicao->data);
            }
        posicao = tmp;
        }
}

void remove_ultimo(struct cli_Dados *posicao) //FUNÇAO QUE REMOVE O ULTIMO ELEMENTO INSERIDO E RECEBE O ENDEREÇO DE MEMORIA
{                                             //DE GANCHO
  struct cli_Dados *tmp = posicao->prox;
  free(gancho);//libera o espaço na memoria
  gancho = tmp;//agora gancho retorna uma posição na pilha
}
