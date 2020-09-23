#include <stdio.h>

struct st_contato{
	char nome[100];
	char telefone[12];
	char email[100];
	char instagram[40];
};

struct st_agenda{
	struct st_contato contatos[10];
}agenda;

int main(){
	for (int i=0;i<10;i++){
		printf("Insira o nome: \n");
		fflush(stdout);
		fgets(agenda.contatos[i].nome,100,stdin);

		printf("Insira o telefone com DDD\n");
		fflush(stdout);
		fgets(agenda.contatos[i].telefone,12,stdin);


		printf("Insira o email\n");
		fflush(stdout);
		fgets(agenda.contatos[i].email,100,stdin);

		printf("Insira o instagram:\n");
		fflush(stdout);
		fgets(agenda.contatos[i].instagram,40,stdin);
	}

	printf("=====Agenda de Contatos=====\n");
	for (int i=0;i<10;i++){
		printf("===== Contato%d =====",(i+1));
		printf("Nome:%s \n",strtok(agenda.contatos[i].nome,"\n"));
		printf("Telefone:%s \n",strtok(agenda.contatos[i].telefone,"\n"));
		printf("Email:%s \n",strtok(agenda.contatos[i].email,"\n"));
		printf("Instagram:%s \n",strtok(agenda.contatos[i].instagram,"\n"));
	}
	return 0;
}
