#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct no {
	int valor;
	char nome[50];
	struct no *proximo;
}No;

No* busca_por_nome(No **lista, char nome[50]){
	No *aux = *lista;
	
	while(aux != NULL){
		if(strcmp(aux->nome, nome) == 0){
			return aux;			
		}else{
			aux = aux->proximo;
		}
	}	
}

void inserir_no_inicio(No **lista, int valor, char nome[50]){
	No *novo = (No*) malloc(sizeof(No));
	novo->valor = valor;
	strcpy(novo->nome, nome);
	novo->proximo = *lista;
	*lista = novo;
}


void inserir_no_fim(No **lista, int valor, char nome[50]){
	No *aux,*novo = (No*) malloc(sizeof(No));
	
	novo->valor = valor;
	novo->proximo = NULL;
	strcpy(novo->nome, nome);
	
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

int main() {
	No *aux,*lista = (No*) malloc(sizeof(No));
	lista = NULL;

	inserir_no_inicio(&lista,90,"Cesar");
	inserir_no_inicio(&lista,90,"Nome");
	inserir_no_fim(&lista,120,"Nome 2");
	inserir_no_fim(&lista,111,"Nome 3");
	inserir_no_fim(&lista,120,"Nome 4");
	
	aux = lista;
	while(aux != NULL){
		printf("nome %s, valor %d\n",aux->nome,aux->valor);
		aux = aux->proximo;
	}
	
	No *query_result = busca_por_nome(&lista, "Cesar");
	
	if(query_result != NULL){
		printf("\nResultado da busca: nome %s, valor %d\n",query_result->nome,query_result->valor);
	}else{
		printf("Usuario não encontrado");
	}
	
	
	return 0;
}
