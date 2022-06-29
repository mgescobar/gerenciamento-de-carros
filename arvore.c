#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include<string.h>
#include "arvore.h"


/*
################################################################################
#                                LISTA                                         #
################################################################################
*/

bool vazia(Lista* lista){
  return (lista == NULL);
}

Lista* ultimo(Lista* lista){
  Lista* ultimo = lista;
  while (!vazia(ultimo) && !vazia(ultimo->prox))
    ultimo = ultimo->prox;
  return ultimo;
}

Lista* criarLista(){
  return NULL;
}

Lista* inserirInicio(Lista* lista, void* elemento){
  Lista* novo = (Lista*)malloc(sizeof(Lista));
  novo->info = elemento;
  novo->prox = lista;
  return novo;
}

Lista* inserirMeio(Lista* lista, void* elemento){
	if(!vazia(lista)){
		Lista* aux = lista->prox;
		lista->prox = inserirInicio(aux, elemento);
	}
	return vazia(lista) ? inserirInicio(NULL, elemento) : lista;
}

Lista* inserirFim(Lista* lista, void* elemento){
  if(!vazia(lista))
    ultimo(lista)->prox = inserirInicio(NULL, elemento);
  return vazia(lista) ? inserirInicio(NULL, elemento) : lista;
}


Lista* ret(Lista* lista, void* elemento, bool iguais(void*, void*))
{
   Lista* anterior = NULL;
   Lista* temp = lista;
   while(!vazia(temp) && !iguais(temp->info, elemento)){
      anterior = temp;
      temp = temp->prox;
   }
   if (vazia(temp))
      return lista;
   if (anterior == NULL)
      lista = temp->prox;
   else
      anterior->prox = temp->prox;
   free(temp);
   return lista;
}


void imprimirLista(Lista* lista, void imprimirElemento(void*)){
  while(!vazia(lista)){
    	imprimirElemento(lista->info);
    lista = lista->prox;
  }
}

void* buscar(Lista* lista, void* elemento, bool iguais(void*, void*)){
   Lista* temp = lista;
   while(temp != NULL){
      if (iguais(temp->info, elemento))
      	 return temp->info;
      temp = temp->prox;
   }
   return NULL;
}

Lista* liberarLista(Lista* lista){
   while(!vazia(lista)){
      Lista* temp = lista->prox;
      free(lista);
      lista = temp;
   }
   return NULL;
}



/*
################################################################################
#                                ARVORE                                        #
################################################################################
*/

Arvore* criarVazia(){
	return NULL;
}

/*
Arvore* criar(Carro* info, Arvore* dir, Arvore* esq){
	Arvore* a = (Arvore*)malloc(sizeof(Arvore));
	a->info = info;
	a->dir = dir;
	a->esq = esq;
	return a;
}
*/

Arvore* criar(Carro* info){
	Arvore* a = (Arvore*)malloc(sizeof(Arvore));
	a->esq = NULL;
	a->dir = NULL;
	a->info = info;
	a->altura = 0;
	return a;
}

bool inserirPlaca(Arvore* a, Carro* info){
	return(strcmp(info->placa, a->info->placa) < 0);
}
bool inserirMarca(Arvore* a, Carro* info){
	return(strcmp(info->marca, a->info->marca) < 0);
}
bool inserirAno(Arvore* a, Carro* info){
	return (info->ano < a->info->ano);
}

//função ordenando com base no ano 
Arvore* inserir(Arvore* a, Carro* info, bool inserirElemento(Arvore*, Carro*)){
	if(arvoreVazia(a))
		a = criar(info);
	else if (inserirElemento(a, info))
		a->esq = inserir(a->esq, info, inserirElemento);
	else
		a->dir = inserir(a->dir, info, inserirElemento);
	return a;
}

int removerPlaca(Arvore* a, Carro* info){
	return(strcmp(a->info->placa, info->placa));
}
int removerMarca(Arvore* a, Carro* info){
	return(strcmp(a->info->marca, info->marca));
}
int removerAno(Arvore* a, Carro* info){
	if(a->info->ano < info->ano)
		return -1;
	else if(a->info->ano > info->ano)
		return 1;
	return 0;
}

Arvore* remover(Arvore* a, Carro* info, int removerElemento(Arvore*, Carro*)){
	if(arvoreVazia(a))
		return NULL;
	else if(removerElemento(a, info) > 0)
		a->esq = remover(a->esq, info, removerElemento);
	else if(removerElemento(a, info) < 0)
		a->dir = remover(a->dir, info, removerElemento);
	else{
		if(casoRemover1(a)){
			free(a);
			a = NULL;
		}
		else if(casoRemover2(a)){
			Arvore* t = a;
			a = a->dir;
			free(t);
		}
		else if(casoRemover3(a)){
			Arvore* t = a;
			a = a->esq;
			free(t);
		}
		else{
			Arvore* f = a->esq;
			while(f->dir != NULL)
				f = f->dir;
			a->info = f->info;
			f->info = info;
			a->esq = remover(a->esq, info, removerElemento);
		}
	}
	return a;
}

bool casoRemover1(Arvore* a){
	return (a->esq == NULL && a->dir == NULL);
}
bool casoRemover2(Arvore* a){
	return (a->esq == NULL);
}
bool casoRemover3(Arvore* a){
	return (a->dir == NULL);
}



bool arvoreVazia(Arvore* a){
   	return a == NULL;
}


void imprimir(Arvore* a){
   	printf("<");
	if (!arvoreVazia(a)){
	  imprimirCarro(a->info);
	  imprimir(a->esq);
	  imprimir(a->dir);
	}
	printf(">");   
}

void imprimirPreOrdem(Arvore* a){
	if (!arvoreVazia(a)){
	  imprimirCarro(a->info);
	  imprimirPreOrdem(a->esq);
	  imprimirPreOrdem(a->dir);
	}
}

void imprimirPosOrdem(Arvore* a){
	if (!arvoreVazia(a)){
	  imprimirPosOrdem(a->esq);
	  imprimirPosOrdem(a->dir);
	  imprimirCarro(a->info);
	}
}

void imprimirOrdemSimetrica(Arvore* a){
	if (!arvoreVazia(a)){
	  imprimirOrdemSimetrica(a->esq);
	  imprimirCarro(a->info);
	  imprimirOrdemSimetrica(a->dir);
	}
}


Arvore* liberar(Arvore* a){
	if (!arvoreVazia(a)){
	  liberar(a->esq);
	  liberar(a->dir);
	  free(a);
	}        
	return NULL;
}

bool pertence(Arvore* a, Carro* carro){
	if (arvoreVazia(a))
	return false;
	return ((a->info == carro) || pertence(a->esq, carro) || pertence(a->dir, carro));
}

int max(int a, int b){
	if (a > b)        
	return a;
	return b;
}

void printInfo(Arvore* a){
    printf("Percurso em Pre-Ordem\n");
    imprimirPreOrdem(a);
    printf("\n");
    printf("Percurso em Ordem Simetrica\n");
    imprimirOrdemSimetrica(a);
    printf("\n");
    printf("Percurso em Pos-Ordem\n");
    imprimirPosOrdem(a);
    printf("\n");
    printf("Altura da arvore: %d\n", altura(a));     
}

int fator(Arvore* a){
	if(arvoreVazia(a))
		return 0;
	return(altura(a->esq) - altura(a->dir));
}

int altura(Arvore* a){
	if(arvoreVazia(a))
		return -1;
	else 
		return a->altura;
}

void ajustarAltura(Arvore* a){
	if(!arvoreVazia(a))
		a->altura = 1 + max(altura(a->esq), altura(a->dir));
}



Carro* buscarPlaca(Arvore* a, char placa[255]){
	while(!arvoreVazia(a)){
		if(strcmp(a->info->placa, placa) == 0){
			return a->info;
		}
		else if(strcmp(a->info->placa, placa) < 0){
			a = a->dir;
		}
		else if(strcmp(a->info->placa, placa) > 0){
			a = a->esq;
		}
	}
	return NULL;
}

/*
################################################################################
#                                CARROS                                        #
################################################################################
*/

Carro* criarCarroPlaca(char placa[255]){
  Carro* c = (Carro*) malloc(sizeof(Carro));
  strcpy(c->placa, placa);
  return c;
}

Carro* criarCarro(char placa[255], char marca[255], int ano){
  Carro* c = criarCarroPlaca(placa);
  strcpy(c->marca, marca);
  c->ano = ano;
  return c;
}

Lista* addCarro(Lista* carros, char placa[255]){
	int ano;
	char  marca[255];

	printf("Marca: ");
	scanf(" %[^\n]s", marca);
	printf("Ano [YYYY]: ");
	scanf("%d", &ano);
	printf("\n");

	int placa1, placa2;

	Lista* lista = carros;
	if(vazia(carros) || strcmp((lista->info->placa), placa) > 0){
   		return inserirInicio(carros, criarCarro(placa, marca, ano)); 
	}
   	while(!vazia(lista->prox)){
	   		if(strcmp((lista->info->placa), placa) < 0 && strcmp((lista->prox->info->placa), placa) > 0){
	   			lista = inserirMeio(lista, criarCarro(placa, marca, ano));
	   			return carros;
	   		}
   		else{
   			lista = lista->prox;
   		}
   	}
   	return inserirFim(carros, criarCarro(placa, marca, ano)); 
}


bool verIguais(void* carro1, void* carro2){
  return (strcmp(((Carro*) carro1)->placa, ((Carro*) carro2)->placa) == 0);
}

Carro* buscarCarro(Lista* carros, char placa[255]){
   return (Carro*) buscar(carros, criarCarroPlaca(placa), &verIguais);
}

void imprimirCarro(void* carro){
	Carro* c = (Carro*) carro;
	printf("Placa do carro: ");
	puts(c->placa);
	printf("Marca do carro: ");
	puts(c->marca);
	printf("Ano do carro: ");
	printf("%d\n", c->ano);
	printf("-----------------\n");
}