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
	char endereco[30];
	char spmerc[30];
	int identidade;
	int tel;
	int valor;
	int data;
	int ID;

}processo;

///Struct em que se baseia a pilha.
typedef struct no
{
    processo *prc;
	struct no *prox;
}No;

///FUNÇÂO PRINCIPAL
int main()
{
    return 0;
}

void menu()
{
    int op;

    while(op>=1 && op<=9)
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
        scanf("%d", &op);
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
                break;
            }
        default:
            {
                printf("Comando invalido, por favor escolha uma opcao.\n\n");
                system("Pause");
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
