Padronização Código

1. idioma
O codigo fonte deve ser escrito em inglês.
exemplo:
struct str_dataClient
{
	char name[];
	int number;
};

Nomes e termos regionais sem correspondentes em inglês, ou de pessoas ou localidades, 
devem ser escritos no idioma de contexto do termo.
Atualmente inglês é a linguagem padrão para comunicação internacional.

2. Nomenclatura
A escolha adequada e consistente de nomes é o aspecto mais importante na padronização, 
uma vez que deve permitir a compreensão fácil e sem (ou reduzida) ambiguidade aos humanos dos elementos 
representados no código.

3. Tipos de dados
Variaveis globais................... g_nome_variavel
Estruturas.......................... str_nome_estrutura
ponteiros........................... *pNome_ponteiro

3.1. Abreviações
Não use abreviações a menos que elas sejam bem conhecidas fora do seu projeto.

4. Documentação
no início de todo código fonte utilize o padrão abaixo
Informações: autor, data início, data da última alteração, nome do programa, função do código.
Não acentue os comentários!

/* ***************************************************************
* Autor: nome(s) do(s) autor(es) do codigo
* Inicio: data de inicio da codificacao
* Ultima alteracao: data da ultima alteracao realizada no codigo
* Nome: Nome do programa
* Funcao: descricao do que eh o programa
*************************************************************** */

4.1 sub-rotina/método
Utilize o padrão abaixo, contendo: nome do método, função, parâmetros recebidos, valor retornado.

/* ***************************************************************
* Metodo: nome do metodo
* Funcao: testa os valores para transmissao
* Parametros: descricao dos parametros recebidos
* Retorno: descricao do valor retornado
*************************************************************** */
void testaValor (void)
 {
	 if (valor==10)
		 { //valor eh o tamanho da mensagem recebida
 			//faça algo aqui
 		}//fim do if
 	else
		 {
 			//faça outra coisa aqui
 		}//fim do else
}//fim do metodo testaValor

