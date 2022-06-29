/*
################################################################################
#                                INCLUSÕES                                     #
################################################################################
*/

#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include<string.h>
#include "arvore.h"

/*
################################################################################
#                                MAIN                                          #
################################################################################
*/

int main()
{
	int botao;
	char placa[255];

	
	Arvore* aPlaca = criarVazia();
	Arvore* aMarca = criarVazia();
	Arvore* aAno = criarVazia();
	

	Lista* carros = criarLista();
	

	while(1){
		printf("O que deseja fazer??\n 1- Inserir carro \n 2- Excluir carro \n 3- Buscar carro pela placa \n 4- Listar carros pela placa \n 5- Listar carros pela marca \n 6- Listar carros pelo ano \n 0) Sair \n\n ");
		scanf("%d", &botao);
		switch(botao){
			case(1):
				printf("Placa [ABC 1234]: ");
				scanf(" %[^\n]s", placa);
				carros = addCarro(carros, placa);
				aPlaca = inserir(aPlaca, buscarCarro(carros, placa), &inserirPlaca);
				aMarca = inserir(aMarca, buscarCarro(carros, placa), &inserirMarca);
				aAno = inserir(aAno, buscarCarro(carros, placa), &inserirAno);
				break;
			case(2):
				printf("Digite o número da placa: ");
				scanf(" %[^\n]s", placa);
				Carro* temp = buscarPlaca(aPlaca, placa);
				aMarca = remover(aMarca, temp, &removerMarca);
				aAno = remover(aAno, temp, &removerAno);
				aPlaca = remover(aPlaca, temp, &removerPlaca);
				carros = ret(carros, buscarCarro(carros, placa), &verIguais);
				break;
			case(3):
				printf("Digite o número da placa: ");
				scanf(" %[^\n]s", placa);
				imprimirCarro(buscarPlaca(aPlaca, placa));
				break;	
			case(4):
				imprimirLista(carros, &imprimirCarro);
				break;
			case(5):
				imprimirOrdemSimetrica(aMarca);
				break;
			case(6):
				imprimirOrdemSimetrica(aAno);
				break;	
			case(0):
				exit(0);
        break;
			default:
				printf("Essa opção não existe.");
				break;
		}
	}
}
