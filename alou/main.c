#include "arvb.h"

int t;

//https://pt.wikipedia.org/wiki/Frequ%C3%AAncia_de_letras
// To do:
// Input:  
//     - texto que deve ser codificado
//     - caracteres válidos (A...Z e a...z)
//     - frequências desses caracteres (minusculas e maiusculas tem mesma frequencia)

// Output: 
//     - árvores b e de huffman
//     - textos encriptados e decriptados

// Obs:
//     - Deve destinguir informações primarias (letras válidas) e as subordinadas (vogal, consoante, maiuscula, minuscula, frequencia)

// Funções: 
//     - comparação entre os códigos gerados pelas árvores (B e de Huffman);
//     - inserção e remoção de nós das árvores B e de Huffman;
//     - encriptação de um texto nas duas árvores;
//     - decriptação de um código para um texto, dada a aŕvore de criptografia;
//     - busca das informações subordinadas, dada a chave primária;
//     - alteração SOMENTE da frequência das letras;
//     - busca de todas as letras de uma determinada classificação; e
//     - remoção de todas as letras de uma classificação informada. 

//Done: 
//     - fator de ramificação (t) da árvore B 

TAB *MontaArvb(TAB *T, char c, FILE *caracteres){
	while (1){
		T = Insere(T, c, t);
		printf("\n");

		printf("Caractere %c inserido com sucesso\n", c);
		Imprime(T, 0);
		fscanf(caracteres, "%c", &c);
		if (c == 10) fscanf(caracteres, "%c", &c); // correcao de bug??
		printf("\n");

		if ((c == 0) || (c == 48)) break; // correcao de bug??
	}
	return T;
}

int main(int argc, char *argv[]){
    printf("Digite o fator de ramificacao da arvore: ");
    scanf("%d", &t);
	int vogal, maiuscula;

	char carac;
	int controle = 1, chave;

	FILE *caracteres = fopen("char.txt", "rt");
	if (!caracteres) exit(1);
	fscanf(caracteres, "%c", &carac);
	fscanf(alfab, "%d", &vogal);

    TAB *arvore = Inicializa();
    arvore = MontaArvb(arvore, carac, caracteres); // cria a arvore com todos os elementos do arquvivo

    int num = 0, from, to;
    while(num != -1){
        printf("0 - Imprimir arvore\n-9 - Remover um valor da arvore\n-1 - Sair\n");
        scanf("%i", &num);
        if(num == -9){
            scanf("%d", &from);
            arvore = retira(arvore, from, t);
            Imprime(arvore,0);
        }
        else if(num == -1){
            printf("\n");
            Imprime(arvore,0);
            Libera(arvore);
            return 0;
        }
        else if(!num){
            printf("\n");
            Imprime(arvore,0);
        }
        printf("\n"); 
    }
}