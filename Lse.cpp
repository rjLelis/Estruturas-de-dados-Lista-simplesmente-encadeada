#include<iostream>
#include<stdlib.h>
#include<string.h>
using namespace std;

//Estrutura da lse
struct lse_funcionarios {
	int codigo;
	char nome[50];
	float salario;
	struct lse_funcionarios *prox;
} *prim,*ult,*aux;

//Assinaturas das fun��es
void inclusao(int codigo, char nome[], float salario);//Inclus�o de um funcionario
void listagem();//Listagem dos funcionarios
void exclusao(int codigo);//Exclus�o de um funcionaro pelo c�digo
void maiorNome();//Maior nome de todos o funcionarios
void procurar(int codigo);//Procurar um funcionario pelo c�digo
void alterar(int codigo);//Procurar e alterar o nome e o salario de um funcionario
int contador_de_func();//Contar o numero de funcionarios de elementos
float media_salario();//Retorna a m�dia dos salarios dos funcionarios
float maior_salario();//Retorna o maior salario da lista

//PROGRAMA PRINCIPAL
main() {
	int op,cod;
	char nome[50];
	float sal;
	do {
		puts("1 - Inclusao");
		puts("2 - Exclusao");
		puts("3 - Listagem");
		puts("4 - Mostrar o maior nome");
		puts("5 - Procurar um funcionario"); 
		puts("6 - Alterar o dados de um funcionario");
		puts("7 - Numero de funcionarios na lista");
		puts("8 - Media de salarios dos funcionarios");
		puts("9 - Maior salario dos funcionarios");
		puts("0 - Sair");
		cout << ">>> ";
		cin >> op;fflush(stdin);
		switch(op) {
			case 0:
				cout << "O PROGRAMA ESTA FINALIZANDO...\n";
				break;
			case 1: //Fun��o para inclus�o
				cout << "Digite o CODIGO do funcionario: ";
				cin >> cod;fflush(stdin);
				cout << "Digite o NOME do funcionario: ";
				gets(nome);fflush(stdin);
				cout << "Digite o SALARIO do funcionario: ";
				cin >> sal;fflush(stdin);
				inclusao(cod,nome,sal);
				break;
			case 2:// Fun��o para exclus�o passando como par�metro o codigo do funcionario
				cout << "Digite o codigo do funcionario para ser excluido: ";
				cin >> cod;
				exclusao(cod);
				break;
			case 3:// Fun��o de listagem
				listagem();
				break;			
			case 4:// Fun��o para mostrar o maior nome
				maiorNome();
				break;	
			case 5:// Fun��o para procurar um funcionario
				cout << "Digite um CODIGO para procurar um funcionario: ";
				cin >> cod;
				procurar(cod);
				break;
			case 6:// Fun��o para alterar os dados de um funcionario
				cout << "Digite um CODIGO para alterar os dados de um funcionario: ";
				cin >> cod;
				alterar(cod);
				break;
			case 7:// Fun��o para retornar o numero de funcionarios na lista
				cout << "Numero de funcionarios na lista: " << contador_de_func() << "\n";
				break;	
			case 8:// Fun��o para calcular a media dos salarios dos funcionarios
				cout << "Media dos salarios dos funcionarios: " << media_salario() << "\n";
				break;
			case 9:// Fun��o para saber qual o maior salario da lista
				cout << "O maior salario e de: " << maior_salario() << "\n";
				break;
			default:
				puts("Opcao invalida!");
			}
	}while(op != 0);
	cout << "PROGRAMA FINALIZADO";
}

//Listagem
void listagem() {
	aux = prim;//inicializando a varredura
	if(aux != NULL) {//se a lista existir
		puts("---------- FUNCIONARIOS ----------");
		while(aux != NULL){
			cout <<"Codigo: "<< aux->codigo <<"\nNome: " << aux->nome  << "\nSalario: " << aux->salario << "\n";
			cout << "--------------------------------- \n";
			aux = aux->prox;
		}
	} else {//se a lista n�o existir
		cout << "Sem funcionarios cadastrados! \n";
	}
}

//Inclus�o
void inclusao(int codigo, char nome[],float salario) {
	aux = (struct lse_funcionarios *) malloc(sizeof(struct lse_funcionarios));//cria��o de um elemento da lista
	if(prim == NULL) {//se a lista estiver vazia
		prim = aux;	
	} else{//se a lista n�o estiver vazia
		ult->prox = aux;
	}
	ult = aux;//todo elemento recem adicionado � automaticamente o ultimo
	//atribui��o dos elementos
	strcpy(ult->nome,nome);
	ult->codigo = codigo;
	ult->salario = salario;
	ult->prox = NULL;//como n�o existe o proximo depois do ultimo, o proximo passa a ser nulo
	puts("Funcionario incluido!");
}

//Exclus�o
void exclusao(int codigo) {
	struct lse_funcionarios *aux2;//cria��o de um aux2 para... auxiliar
	int achei = 0;//para quebrar o while se achar o item desejado
	aux = prim;//inicializando a busca
	if(aux != NULL){//se a lista existir
		while(aux != NULL and achei == 0) {
			if(aux->codigo == codigo) {
				if(aux == prim) {//se for o primeiro
					if(prim == ult){// se for o primeiro e o ultimo
						prim = ult = NULL;
					} else {//se for s� o primeiro
						prim = prim->prox;
					}
				} else if (aux == ult) {//se for o ultimo
					ult = aux2;
					ult->prox = NULL;
				} else {//se estiver no meio
					aux2->prox = aux->prox;
				}
				achei = 1;
				free(aux);
			} else {//se n�o achou de primeira
				aux2 = aux;
				aux = aux->prox;
			}
		}
			if(achei == 0) {//se n�o achar o funcionario
				cout << "Codigo de funcionario inexistente!\n";
			} else {//se achar o funcionario
				cout << "Funcionario excluido!\n";		
			}
	} else{//se a lista n�o existir
		puts("Sem funcionarios cadastrados!");
	}
}

//Descobrir o maior nome
void maiorNome() {
	int p = 0;//para iniciar a atribui��o
	char maior[200];//para atribuir o maior nome
	aux = prim;//iniciando a busca
	if(aux != NULL){ //se a lista existir
		while(aux != NULL) {
			if(p == 0) {
				strcpy(maior,aux->nome);
				p = 1;
			} else if(strlen(aux->nome) > strlen(maior)){
				strcpy(maior,aux->nome);
			}
			aux = aux->prox;
		}
		cout << "O maior nome e: " << maior << "\n";
	} else{//se a lista n�o existir
		puts("Sem funcionarios cadastrados!");
	}
}

//Procurar
void procurar(int codigo){
	aux = prim;
	while(aux != NULL){
		if(aux->codigo == codigo){
			puts("---------- DADOS DO FUNCIONARIO ----------");	
			cout << "Nome: " << aux->nome << "\nSalario: " << aux->salario << "\n";
			cout << "--------------------------------- \n";
		} else{
			puts("Funcionario inexistente na lista");
		}
		aux = aux->prox;
	}
}

//Alterar
void alterar(int codigo){
	float sal;
	char nome[50];
	aux = prim;
	while(aux != NULL){
		if(aux->codigo == codigo){
			fflush(stdin);
			cout << "Digite um novo NOME para o funcionario: ";
			gets(nome);fflush(stdin);
			cout << "Digite um novo SALARIO para o funcionario: ";
			cin >> sal;fflush(stdin);
			strcpy(aux->nome,nome);
			aux->salario = sal;
			puts("Dados atualizados");
		} else{
			puts("Funcionario inexistente na lista");
		}
		aux = aux->prox;
	}
}

//Contar funcionarios
int contador_de_func(){
	int cont = 0;
	aux = prim;
	while(aux != NULL){
		cont++;
		aux = aux->prox;
	}
	return cont;
}

//Media dos salarios dos funcionarios
float media_salario(){
	int deno = 0;
	float div = 0;
	aux = prim;
	while(aux != NULL){
		div += aux->salario;
		deno++;
		aux = aux->prox;
	}
	return div/deno;
}

//Maior salario
float maior_salario(){
	float maior;
	int p = 1;
	aux = prim;
	while(aux != NULL){
		if(p == 1){
			maior = aux->salario;
			p = 0;
		} else if(aux->salario > maior){
			maior = aux->salario;	
		}
		aux = aux->prox;
	}
	return maior;
}
