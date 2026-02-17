#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
	char nome[50];
	int idade;
}Pessoa;

typedef struct no{
	Pessoa pessoa;
	struct no *proximo;
}No;

Pessoa* ler_pessoa(){
	Pessoa *p = (Pessoa*) malloc(sizeof(Pessoa));
	
	printf("Nome:\n");
	scanf("%49s", &p->nome);
	printf("Idade:\n");
	scanf("%d", &p->idade);
	
	return p;
}

No* push(No *topo){
	Pessoa *p = ler_pessoa();
	
	No *no = (No*) malloc(sizeof(No));
	
	no->pessoa = *p;
	no->proximo = topo;
	
	free(p);
	return no;
}

No* pop(No **topo){
	No *remove = *topo;
	
	*topo = remove->proximo;
	
	return remove;
}

int main(){
	Pessoa *pessoa = ler_pessoa();
	No *no = (No*) malloc(sizeof(No));
	
	no->pessoa = *pessoa;
	
	no->proximo = NULL;
	
	No *topo = no;
	char entrada[2];
	
	free(pessoa);
	printf("Empilhar: s | Ver: v |Remover: p | Sair: x\n");
	scanf("%s",&entrada);
	
	int breaking = 0;
	
	while(breaking == 0){
		
		if(strcmp(entrada, "s") == 0){
			No *no = push(topo);
		
			topo = no;
			
			printf("Topo: %s\n", topo->pessoa.nome);
			printf("Proximo: %s \n", topo->proximo->pessoa.nome);
		}
		
		if(strcmp(entrada, "p") == 0){
			if(topo == NULL){
				printf("Lista vazia\n");
			}else{
			
				No *no = pop(&topo);
				
				if(no){
					printf("Removido: %s\n",no->pessoa.nome);
					printf("Topo: %s\n",topo->pessoa.nome);
					if(topo){
						printf("Proximo: %s\n", topo->proximo->pessoa.nome);
					}else{
						printf("A pilha so possui um unico valor.\n");
					}
				}else{
					free(no);
					printf("A pilha nao possui valor.\n");
				}
			}
		}
	
		printf("Empilhar: s | Ver: v | Percorrer Pilha: p | Sair: x\n");
		scanf("%s",&entrada);
	}
	
	return 0;
}
