/*Sistema de processos.3 - Estrutura de Dados
Diferença- A ordenação é chamada logo após a inserção*/

#include <stdio.h>
#include <stdlib.h>

//Struct de registro dos processos
typedef struct reg_processo{
	
	char pessoa[30];
	char endereco[30];
	char spmerc[30];
	int identidade;
	int tel;
	int valor;
	int data;
	int ID;
} processo;

struct no{//Struct em que se baseia a pilha. 
	processo *prc;
	struct no *prox;
};
typedef struct no No;

//Conta os elementos da pilha
int g_tam;
//Variável para ID
int g_ID;

//Declaração das funções	

void menu(No *Pilha);
void inicia(No *Pilha);
int teste_vazia(No *Pilha);
void imprime(No *Pilha);
void limpa(No *Pilha);
void preenche(processo *prc); 
void inserir(No *Pilha);
No *apagar(No *Pilha);
No *retira_qualquer(No *Pilha);

//Funções de ordenação para prioridade do valor dos cheques
No* Ordenacao(No *a, No *b);
void DvdpConq(No *base, No **primeiro, No **ultimo);
void mergeSort(No **primeiro);


int main(){
	
	No *Pilha = (No *) malloc(sizeof(No));
	
	if(Pilha== NULL){
		printf("Sem memoria disponivel para alocar a pilha.\n");
		exit(1);
	} 
	else{
		inicia(Pilha);
		menu(Pilha);	
		free(Pilha);
		return 0;
	}
       	
	system("Pause");
	return 0;
}

void menu(No *Pilha){//Função que tem o menu do program

	int op=0;
	No *aux= NULL;
	
	
	while (op>=0 && op<=9)
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
			printf("\t8. Sair.\n");
			//printf("\t7. Ordena Pilha.\n");
			scanf("%d", &op);
		
			switch(op){
				case 1:
					inserir(Pilha);
					mergeSort(&Pilha);
					break;
		
				case 2:
					aux= apagar(Pilha);
					if(aux != NULL)
					printf("Processo retirado: %s\n\n", aux->prc->pessoa);
					system("Pause");
					break;
				case 3:
					aux= retira_qualquer(Pilha);
					printf("Processo retirado: %s\n\n", aux->prc->pessoa);
					system ("pause");
					break;
				case 4:
					imprime(Pilha);
					system("Pause");
					break;
		
				case 5:
					printf("A pilha possui %d processos. \n", g_tam);
					system("Pause");
					break;
					
				case 6:
					limpa(Pilha);
					system("Pause");
					inicia(Pilha);
					break;
				/*case 7:
					mergeSort(&Pilha);
					system("pause");
					break;*/
					
				case 8:
				 exit(0);
					
				default:
					printf("Comando invalido, por favor escolha uma opcao.\n\n");
					system("Pause");
			}
	}
}

//////////////////////// Funções da Pilha///////////////////////////////////

void inicia(No *Pilha){//Inicia a pilh

	Pilha->prox = NULL;
	g_tam=0;
	g_ID=1;
}
int teste_vazia(No *Pilha){// Testa se a pilha está vazia. Se o primeiro elemento aponta para NULL quer dizer que a pilha não te
						   //elementos	
	if(Pilha->prox == NULL)
		return 1;
	else
		return 0;
}

void imprime(No *Pilha){// Função de impressão da pilh
	
	No *aux= Pilha->prox;
	
	if(teste_vazia(Pilha)){
		printf("Nao existem processos nesta pilha.\n");
	}
	else{
		printf("\nProcessos:\n");
	
		while( aux != NULL){
			printf("\nNome do cliente %s\n", aux->prc->pessoa);		
			printf("Endereco do cliente: %s\n",aux->prc->endereco);			
			printf("Identidade do cliente: %i\n", aux->prc->identidade);		
			printf("Telefone do cliente: %i\n", aux->prc->tel);		
			printf("Valor do cheque: %i\n", aux->prc->valor);		
			printf("Data do cheque: %i\n", aux->prc->data);
			printf("Supermercado que recebeu o cheque:%s\n" ,aux->prc->spmerc);
			printf("ID do processo: %i\n", aux->prc->ID);
			
			aux = aux->prox;
		}
	}	
}
void limpa(No *Pilha){//Libera o espaço alocado da Pilh
	
	No *aux= Pilha->prox;
	No *aux2= NULL;
		
	if(teste_vazia(Pilha)){
		printf("A pilha esta vazia. \n");
	}
	else{
		while( aux != NULL){
			aux2= aux->prox;
			free(aux);
			aux = aux2;
		}
	}	
}

void preenche(processo *prc){//Preenche os dados do process
system ("cls");
	
	printf("Informe o nome do supermercado que recebeu o cheque: \n");
	scanf(" %s",  prc->spmerc  );
	
	printf("Nome do cliente:");
    scanf("%s", prc->pessoa );
		
	printf("Informe o endereco do cliente: \n");
	scanf("%s", prc->endereco );			
	
	printf("Informe a identidade do cliente: \n");
	scanf("%d", &prc->identidade);		
	
	printf("Informe o telefone do cliente: \n");
	scanf("%d", &prc->tel);		
		
	printf("Informe o valor do cheque: \n");
	scanf("%d", &prc->valor);		
	
	printf("Informe a data do cheque: \n");
	scanf("%d", &prc->data);
	
	prc->ID= g_ID;
	}

void inserir(No *Pilha){//Iserção de nós na pilh
	
	No *novo=(No*) malloc(sizeof(No));
	No *aux= NULL;
	processo *prc= (processo *) malloc(sizeof(processo));;
	
	preenche(prc);
	
	if(novo == NULL){
		printf("Sem memoria disponivel!\n");
		exit(1);
	}
	else{
		novo->prc= prc;
		novo->prox = NULL;
	
		if(teste_vazia(Pilha))
			Pilha->prox= novo;//Se a pilha estiver vazia novo será o primeiro nó da pilha
		else{
			
		   aux= Pilha->prox;
	
			while(aux->prox != NULL){
				aux = aux->prox;
			}
					
			aux->prox = novo;
		}
		
		g_tam++;
		g_ID ++;
	}
}
No* Ordenacao(No *a, No *b) {
 
  No *result = NULL;
 
  /* Caso basico */
  if (a == NULL) {
    return b;
  } else if (b==NULL) {
    return a;
  }
  
  /* Escolhe a ou b e repete */
  if (a->prc->valor < b->prc->valor) {
    result = a;
    result->prox = Ordenacao(a->prox, b);
  }
  else {
    result = b;
    result->prox = Ordenacao(a, b->prox);
  }
   	return result;
}

void DvdpConq(No *base, No **primeiro, No **ultimo) {
 No *rapido;
  No *lento;
  
  if (base == NULL || base->prox == NULL) {
    /* tamanho menor que 2 */
    *primeiro = base;
    *ultimo = NULL;
  } else {
    lento = base;
    rapido = base->prox;
 
    /* Avanço 'rapido' é de dois nós,e avanço 'lento' é de um nó */
    while (rapido != NULL) {
      rapido = rapido->prox;
      if (rapido != NULL) {
        lento = lento->prox;
        rapido = rapido->prox;
      }
    }
     /* "lento" é antes do ponto médio na fila, para dividi-lo em dois 
       nesse ponto. */
    *primeiro = base;
    *ultimo = lento->prox;
    lento->prox = NULL;
  }
}

void mergeSort(No **primeiro) {
  No* Temp = *primeiro;
  No* a;
  No* b;
 
  /* Caso basico -- tamanho 0 ou 1 */
  if ((Temp == NULL) || (Temp->prox == NULL)) {
    return;
  }
 
  /* dividir em sub filas 'a' e 'b' */
  DvdpConq(Temp, &a, &b); 
 
  /* recursivamente ordena as sub filas */
  mergeSort(&a);
  mergeSort(&b);
 
  /*resposta= sub filas ordenadas */
  *primeiro = Ordenacao(a, b);
}

No *apagar(No *Pilha){//Apaga um nó da pilha. O ultimo elemento inserido
	
	No *ult=NULL, *pnult=NULL;
	
	if (Pilha->prox == NULL)
	{
		printf("Pilha vazia\n\n");
		return NULL;
	}
	
	else{
		ult = Pilha->prox;
	    pnult = Pilha;

		while(ult->prox != NULL){
			pnult = ult;
			ult = ult->prox;
		}

		pnult->prox = NULL;
		g_tam--;
		return ult;
	}
}

No *retira_qualquer(No *Pilha)
{
	int opt,i;
		
	printf("Que posicao, [de 1 ate %d] voce deseja retirar: ", g_tam);
	scanf("%d", &opt);
	
	if(opt>0 && opt <= g_tam){
		if(opt==1)
			return apagar(Pilha);
		else{
			No *atual = Pilha->prox,
				 *anterior=Pilha; 
				 
			for(i=1 ; i < opt ; i++){
				anterior=atual;
				atual=atual->prox;
			}
			
		anterior->prox=atual->prox;
		g_tam--;
		return atual;
		}
			
	}else{
		printf("Elemento invalido\n\n");
		return NULL;
	}
}
