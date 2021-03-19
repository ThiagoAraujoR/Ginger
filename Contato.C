
#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>

typedef struct{
	int codigo;
	int ddd;
	int numero;
	char nome[30];
	char email[50];
}Contato;


void InserirContato();
void ListarContato();
void ExcluirContato();
void Menu();

static Contato contato[10];
static int contador_Contato=0;

void Info(Contato cont){
	printf("Código:%d \nNome:%s \nNumero:(%d) %d \nEmail:%s\n",
			cont.codigo,strtok(cont.nome,"\n"),cont.ddd,cont.numero,strtok(cont.email,"\n"));
}
int main() {
	Menu();
	return 0;
}

void Menu(){
	printf("====Olá, eu serei sua agenda====\n");
	printf("Selecione a opção desejada\n");
	printf("1-Inserir Contato\n");
	printf("2-Listar Contatos\n");
	printf("3-Sair\n");
	printf("------------------\n");

	int opcao;
	fflush(stdout);
	scanf("%d",&opcao);
	getchar();

	switch (opcao) {
		case 1:
			InserirContato();
			break;
		case 2:
			ListarContato();
			break;
		case 3:
			printf("Volte Sempre");
			Sleep(2);
			exit(0);
		default:
			printf("Opção inexistente\n");
			Sleep(2);
			Menu();
			break;
	}
}

void InserirContato(){
	printf("Adicionar Contato\n");
	printf("-----------------\n");

	printf("Informe o Nome:");
	fflush(stdout);
	fgets(contato[contador_Contato].nome,30,stdin);

	printf("Informe o Email:");
	fflush(stdout);
	fgets(contato[contador_Contato].email,50,stdin);

	printf("Informe o DDD:");
	fflush(stdout);
	scanf("%d",&contato[contador_Contato].ddd);

	printf("Informe o numero de telefone:");
	fflush(stdout);
	scanf("%d",&contato[contador_Contato].numero);

	printf("O contato %s foi adicionado com sucesso\n",strtok(contato[contador_Contato].nome,"\n"));
	contato[contador_Contato].codigo= (contador_Contato+1);
	contador_Contato++;

	Sleep(2);
	Menu();
}

void ListarContato(){
	if(contador_Contato>0){
		printf("---Lista de Contatos---\n");
		printf("-----------------------\n");
		for(int i=0;i<contador_Contato;i++){
			Info(contato[i]);
			printf("----------\n");
			Sleep(1);
		}
		Sleep(2);
		Menu();
	}else{
		printf("Nenhum contato adicionado");
		Sleep(2);
		Menu();
	}
}
