#include <stdlib.h>
#include <stdio.h>


typedef struct ArvB{
  int nchaves, folha, *chave;
  int vogal, maiuscula;
  struct ArvB **filho;
}TAB;



TAB *Inicializa();
TAB *Cria(int t);
TAB *Libera(TAB *a);
void Imprime(TAB *a, int andar);
TAB *Busca(TAB* x, int ch);
TAB *Divisao(TAB *x, int i, TAB* y, int t);
TAB *Insere_Nao_Completo(TAB *x, int k, int t);
TAB *Insere(TAB *T, int k, int t);
TAB* remover(TAB* arv, int ch, int t);
TAB* retira(TAB* arv, int k, int t);

