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
//---------------------------------------------------------------------------------------------------------------------------------------

#include "arvb.h"
int t;

int main(int argc, char *argv[]){

    //Pegando o fator de ramificação da árvore (t)
    printf("Digite o fator de ramificacao da arvore: ");
    scanf("%d", &t);

    //Montando a árvore que contém o alfabeto
    TAB *arvore = Inicializa();
    arvore = montaArvB(arvore , "caracteres.txt", t);

    int num = 0;
    char removido, inserido;
    while(num != -1){
        printf("============================================================\n");
        printf("1 - Imprimir arvore\n2 - Inserir um valor na arvore\n3 - Remover um valor da arvore\n0 - Sair\n");
        scanf("%i", &num);
        printf("============================================================\n");
        if(num == 3){
            printf("Digite uma letra para remove-la da arvore: ");
            scanf(" %c", &removido);
            printf("\n");
            arvore = retira(arvore, removido, t);
            Imprime(arvore,0);
        }
        else if(num == 2){
            printf("Digite o caractere que deseja inserir na arvore: ");
            scanf(" %c", &inserido);
            printf("\n");
            arvore = Insere(arvore, inserido, t);
            Imprime(arvore,0);
        }
        else if(num == 5){
            printf("Digite um caracter para saber se ele é maiusculo ou minuscula: ");
            scanf(" %c", &inserido);
            printf("\n");
            ehMaiuscula(arvore, inserido);
        }
        //Sai do programa
        else if(!num){
            Libera(arvore);
            return 0;
        }
        //Imprime a arvore
        else if(num == 1){
            printf("\n");
            Imprime(arvore,0);
        }
        printf("\n"); 
    }
}