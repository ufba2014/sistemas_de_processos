#include <stdio.h>
#include <stdlib.h>

/** Sistema de processos.3 - Estrutura de Dados
  * @authr
  */

int g_tam, g_ID;

///Struct de registro dos processos
typedef struct reg_processo
{
    char pessoa[30];
	char endereco[255];
	char spmerc[30];
	int identidade;
	int tel;
	float valor;
	int data;
	int ID;

}processo;

///Struct em que se baseia a pilha.
typedef struct no
{
    processo *prc;
	struct no *prox;
}No;

///indice de funções
void inicia(No *Pilha);
int teste_vazia(No *Pilha);
int coleta_dados(processo *prc);
int menu();

///FUNÇÂO PRINCIPAL
int main()
{
    int menu();
    return 0;
}

int menu()
{
    int op;

    while(1)
    {
        system("cls");
        printf("\t  =========================\n");
        printf("\t          SISTEMA DE       \n");
        printf("\t          PROCESSOS        \n");
        printf("\t  =========================\n\n");
        printf("\t1. Inserir novo processo;\n");
        printf("\t2. Apagar um processo;\n");
        printf("\t3. Apagar processo qualquer;\n");
        printf("\t4. Exibir Pilha;\n");
        printf("\t5. Tamanho da Pilha;\n");
        printf("\t6. Apagar Pilha;\n");
        printf("\t7. Sair.\n");
        scanf("%i", &op);
        switch(op)
        {
        case 1:
            {
                break;
            }
        case 2:
            {
                break;
            }
        case 3:
            {
                break;
            }
        case 4:
            {
                break;
            }
        case 5:
            {
                break;
            }
        case 6:
            {
                break;
            }
        case 7:
            {
                return 0;
                break;
            }
        default:
            {
                printf("Comando invalido, por favor escolha uma opcao.\n\n");
            }
        }
    }
}

///FUNÇOES DA PILHA
void inicia(No *Pilha)  //Inicia a pilha
{
	Pilha->prox = NULL;
	g_tam=0;
	g_ID=1;
}

int teste_vazia(No *Pilha){ // Testa se a pilha está vazia. Se o primeiro elemento aponta para NULL quer dizer
                            // que a pilha não tem elementos
	if(Pilha->prox == NULL)
		return 1;
	else
		return 0;
}

int coleta_dados(processo *prc)
{
    printf("Digite o Nome do cliente: ");
    scanf("%30[^\n]",prc->pessoa);
    printf("Digite o endere%co do cliente: ",135);
    scanf("%30[^\n]",prc->endereco);
    printf("Digite a identidade do cliente: ");
    scanf("%i",prc->identidade);
    printf("Digite o Supermercado credor: ");
    scanf("%30[^\n]",prc->spmerc);
    printf("Digite o telefone do cliente: ");
    scanf("%i",prc->tel);
    printf("Digite o valor do cheque: ");
    scanf("%2.f",prc->valor);
    printf("Digite a data do cheque: ");
    scanf("%i",prc->data);
}
