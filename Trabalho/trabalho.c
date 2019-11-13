// Trabalho
// http://www.ic.uff.br/~rosseti/EDA/2019-2/Trabalho_EDA_2019_2.pdf'
//cd Documentos/'ED e Algoritmos'/Trabalho

//Busca de letra por chave de Vogal ou Maiuscula
#include <stdlib.h>
#include <stdio.h>
#include "ARVB.H"

const int t = 2;

TAB *SetVM(TAB *T, int v, int m){
	T->vogal = v;
	T->maiuscula = m;
	return T;
}

TAB *MontaArvb(TAB *T, char c, int v, int m, FILE *alfab){
	while (1){
		T = Insere(T, c, t);
		T = SetVM(T, v, m);
		printf("\n");
		printf("Vogal: %d\n", T->vogal);
		printf("Maiuscula: %d\n", T->maiuscula);

		printf("Caractere %c inserido com sucesso\n", c);
		Imprime(T, 0);
		fscanf(alfab, "%c", &c);
		if (c == 10) fscanf(alfab, "%c", &c); // correcao de bug??
		fscanf(alfab, "%d", &v);
		fscanf(alfab, "%d", &m);
		printf("\n");

		if ((c == 0) || (c == 48)) break; // correcao de bug??
	}

	return T;
}


void main(){
	TAB *Arvb = Inicializa();
	char carac, arq[31];
	int vogal, maiuscula;
	int controle = 1, chave;
	int buscado;

	printf("Digite o nome do arquivo para formar a Arvore\n");
	scanf("%s", arq);
	FILE *alfab = fopen(arq, "rt");
	if (!alfab) exit(1);
	fscanf(alfab, "%c", &carac);
	fscanf(alfab, "%d", &vogal);
	fscanf(alfab, "%d", &maiuscula);

	Arvb = MontaArvb(Arvb, carac, vogal, maiuscula, alfab); // cria a arvore com todos os elementos do arquvivo

	while (controle){ // controle e chamadas de funcoes da Arvore B
		printf("0 - Sair\n8 - Buscar um caracter pelo seu numero na ASCII\n9 - Remover\n");
		scanf("%d", &controle);
		if (controle == 9){ // remocao
			scanf("%d", &chave);
			Arvb = remover(Arvb, chave, t);
			Imprime(Arvb, 0);
		}
		else if(controle == 8){
			printf("Digite caractere que deseja buscar: ");
			scanf("%d", &buscado);
			TAB *buscadoNo = Busca(Arvb, buscado);
			printf("Caracter: %c\nVogal: %d\nMaiusculo: %d\n\n",buscadoNo->chave, buscadoNo->vogal, buscadoNo->maiuscula);
		}
	}
}
