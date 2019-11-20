#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef ARVB_H
#define ARVB_H

typedef struct ArvB{
  int nchaves, folha, *chave;
  struct ArvB **filho;
}TAB;

TAB *Cria(int t);

TAB *Libera(TAB *a);

void Imprime(TAB *a, int andar);

TAB *Busca(TAB* x, int ch);

TAB *Inicializa();

TAB *Divisao(TAB *x, int i, TAB* y, int t);

TAB *Insere_Nao_Completo(TAB *x, int k, int t);

TAB *Insere(TAB *T, int k, int t);

TAB* remover(TAB* arv, int ch, int t);

TAB* retira(TAB* arv, int k, int t);

TAB *montaArvB(TAB *arvore, char *arquivo_caracteres, int t);

int ehMaiuscula(TAB *arvore, char valor);

int ehVogal(TAB *arvore, char valor);

void decodifica(TAB *arvore, char codigo[]);

#endif