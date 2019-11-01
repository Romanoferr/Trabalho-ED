// Trabalho
// http://www.ic.uff.br/~rosseti/EDA/2019-2/Trabalho_EDA_2019_2.pdf'
//cd Documentos/'ED e Algoritmos'/Trabalho
#include <stdlib.h>
#include <stdio.h>
#include "ARVB.h"

const int t = 3;

TAB *SetVM(TAB *T, int V, int M){
	T->vogal = V;
	T->maiuscula = M;
	return T;
}

int main(){
	TAB *Arvb = Inicializa();
	char carac, arq[31];
	int vogal, maiuscula;

	printf("Digite o nome do arquivo para formar a Arvore\n");
	scanf("%s", arq);
	FILE *alfab = fopen(arq, "rt");
	if (!alfab) exit(1);
	fscanf(alfab, "%c", &carac);
	fscanf(alfab, "%d", &vogal);
	fscanf(alfab, "%d", &maiuscula);


	while (1){
		Arvb = Insere(Arvb, carac, t);
		Arvb = SetVM(Arvb, vogal, maiuscula);
		printf("\n");
		printf("%d", Arvb->vogal);
		printf("%d\n", Arvb->maiuscula);

		printf("Caractere %c inserido com sucesso\n", carac);
		Imprime(Arvb, 0);
		fscanf(alfab, "%c", &carac);
		if (carac == 10) fscanf(alfab, "%c", &carac);
		fscanf(alfab, "%d", &vogal);
		fscanf(alfab, "%d", &maiuscula);
		printf("\n\n\n\n");

		if ((carac == 0) || (carac == 48)) break;
	}
	printf("Press ENTER key to Continue\n");  
	getchar();
	Libera(Arvb);
	return 0; 
}
