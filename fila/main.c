#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct no {
	char nome[50];
	struct no *proximo;	
}No;

void add(No **lista, char nome[50]){
	No *aux,*novo = (No*) malloc(sizeof(No));
	strcpy(novo->nome, nome);
	novo->proximo = NULL;
	
	if(*lista == NULL){
		*lista = novo;
	}else{
			aux = *lista;
		while(aux->proximo){
			aux = aux->proximo;
	}
		aux->proximo = novo;
	}
}

No remover(No **lista){
	if(*lista != NULL){
		No *temp = *lista;
		
		
		*lista = temp->proximo;
		printf("Removido: %s",temp->nome);
		return *temp;
			
	}else{
		printf("A fila esta vazia");
	}
}

void listar(No **lista){
	No *aux = (No*) malloc(sizeof(No));
	
	aux = *lista;
	while(aux != NULL){
		printf("Nome: %s\n",aux->nome);
		aux = aux->proximo;
	}
}

int main() {
	
	No *lista = NULL;
	
	add(&lista, "Roger");
	add(&lista, "Cesar");
	add(&lista, "Joao");
	add(&lista, "Pedro");
	add(&lista, "Paulo");
	add(&lista, "Alex");

	listar(&lista);
	
	printf("\n---------------------------------------\n");
	
	remover(&lista);
	remover(&lista);
	remover(&lista);
	remover(&lista);
		
	printf("\n---------------------------------------\n");
	
	listar(&lista);

	return 0;
}
