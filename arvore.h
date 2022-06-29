#include<stdbool.h>

typedef struct carro{
	char placa[255];
	char marca[255];
	int ano;
}Carro;

typedef struct arvore{
	Carro* info;
	struct arvore* dir;
	struct arvore* esq;
	int altura;
}Arvore;

typedef struct lista{
  Carro* info;
  struct lista* prox;
}Lista;

/*Lista*/

bool vazia(Lista* lista);


Lista* ultimo(Lista* lista);

//C
Lista* criarLista(void);

// Cria o inicio da lista após receber a lista e um elemento(inicial).
Lista* inserirInicio(Lista* lista, void* elemento);

// Cria o meio da lista após receber a lista e um elemento.
Lista* inserirMeio(Lista* lista, void* elemento);

// Cria o fim da lista após receber a lista e um elemento(final).
Lista* inserirFim(Lista* lista, void* elemento);

// Esvazia uma lista passada por parâmetro, verificando constantentemente se
// a mesma está vazia ou é igual e passando para uma lista temporária auxiliar.
Lista* ret(Lista* lista, void* elemento, bool iguais(void*, void*));

// Recebe uma lista e realiza a impressão de toda ela.
void imprimirLista(Lista* lista, void imprimirElemento(void*));

// Recebe a lista, o elemento a ser buscado e a função para verificar, e
// realiza buscas percorrendo a lista.
void* buscar(Lista* lista, void* elemento, bool iguais(void*, void*));

// Recebe a lista e esvazia/libera ela da memória com free.
Lista* liberarLista(Lista* lista);

/*Arvore*/

// Função que somente retorna null.
Arvore* criarVazia();

// Preenche o carro criado com informações NULL
Arvore* criar(Carro* info);

// Recebe a placa e realiza a comparação para ordenar o nó a esq ou dir.
bool inserirPlaca(Arvore* a, Carro* info);

// Recebe a marca e realiza a comparação para ordenar o nó a esq ou dir.
bool inserirMarca(Arvore* a, Carro* info);

// Recebe o ano e realiza a comparação para ordenar o nó a esq ou dir.
bool inserirAno(Arvore* a, Carro* info);

// Recebe a arvore e reordena os carros com base no ano.
Arvore* inserir(Arvore* a, Carro* info, bool inserirElemento(Arvore*, Carro*));

// Realiza e retorna a comparação da placa arvore e lista.
int removerPlaca(Arvore* a, Carro* info);

// Realiza e retorna a comparação da marca arvore e lista.
int removerMarca(Arvore* a, Carro* info);

// Realiza e retorna a comparação do ano arvore e lista.
int removerAno(Arvore* a, Carro* info);

// Realiza a remoção da arvore por completo, liberando-a da memoria com free.
Arvore* remover(Arvore* a, Carro* info, int removerElemento(Arvore*, Carro*));

// Retorna caso o nó da esquerda e direita forem NULL.
bool casoRemover1(Arvore* a);

// Retorna caso somente a esquerda for NULL.
bool casoRemover2(Arvore* a);

// Retorna caso somente a direita for NULL.
bool casoRemover3(Arvore* a);

// Verifica a condição da arvore.
bool arvoreVazia(Arvore* a);

// Realiza a impressão de toda a arvore
void imprimir(Arvore* a);

// Realiza a impressão da lista do carro e depois esq e dir.
void imprimirPreOrdem(Arvore* a);

// Realiza a impressão da esq e dir e depois lista do carro.
void imprimirPosOrdem(Arvore* a);

// Realiza a impressão da esq, lista do carro e depois dir.
void imprimirOrdemSimetrica(Arvore* a);

// Libera a memória de toda a arvore com free.
Arvore* liberar(Arvore* a);

// Verifica se a informação (parametro) procede.
bool pertence(Arvore* a, Carro* carro);

// Realiza verificação do maior elemento e retorna o maior.
int max(int a, int b);

// Verifica a altura da arvore
int altura(Arvore* a);

// Imprime 
void printInfo(Arvore* a);

// Percorre a arvore em busca da string, retornando a placa, o lado em que está
// ou NULL quando não encontrada.
Carro* buscarPlaca(Arvore* a, char placa[255]);

// Verifica se a arvore está vazia e ajusta a altura verificando as alturas
// da direita e esquerda e acrescentando 1.
void ajustarAltura(Arvore* a);

/*Carro*/

// Cria e aloca o carro (placa)
Carro* criarCarroPlaca(char placa[255]);

// Auxiliar - Cria e aloca o carro (placa, marca e ano)
Carro* criarCarro(char placa[255], char marca[255], int ano);

// Imprime, chama as funções para criar o carro e armazena na arvore
Lista* addCarro(Lista* carros, char placa[255]);

// Verifica se existem carros iguais
bool verIguais(void* carro1, void* carro2);

// Executa a busca do carro pela placa e verifica a possivel existencia
Carro* buscarCarro(Lista* carros, char placa[255]);

// Imprime o carro
void imprimirCarro(void* carro);