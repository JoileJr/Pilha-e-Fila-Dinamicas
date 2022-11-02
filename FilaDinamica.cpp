#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <conio.h>

struct t_aluno
{
	int ra,faltas;
	float nota1,nota2;
};

t_aluno recebe_dados() //insercao dos dados
{
	t_aluno a;
	printf ("RA    :");
	scanf ("%d",&a.ra);
	printf ("NOTA1 :");
	scanf ("%f",&a.nota1);
	printf ("NOTA2 :");
	scanf ("%f",&a.nota2);
	printf ("FALTAS:");
	scanf ("%d",&a.faltas);
	return a;
}

typedef struct NO{
	t_aluno dado;
	struct NO *prox;
}NO;

typedef struct FILA{
	NO *ini;
	NO *fim;
}FILA;

void inicializaFila( FILA *f){
	f->ini = NULL;
	f->fim = NULL;
}

void enfileira( t_aluno dado, FILA *f){
	NO *ptr = (NO*) malloc(sizeof(NO));
	if(ptr == NULL){
		printf("Erro de aloca??o.\n");
		return;
	} else {
		ptr->dado = dado;
		ptr->prox = NULL;
		if(f->ini == NULL){
			f->ini = ptr;
		} else {
			f->fim->prox = ptr;
		}
		f->fim = ptr;
		return;
	}
}

t_aluno desenfileira(FILA *f){
	NO *ptr = f->ini;
	t_aluno dado;
	if(ptr != NULL){
		f->ini = ptr->prox;
		ptr->prox = NULL;
		dado = ptr->dado;
		free(ptr);
		if(f->ini == NULL){
			f->fim = NULL;
		}
		return dado;
	} else {
		printf("Fila Vazia. \n");
		return dado;	
	}
}

void imprimeFila(FILA *f){
	NO *ptr = f->ini;
	if( ptr != NULL){
		while( ptr != NULL){
			printf(" RA: %d", ptr->dado.ra);
			printf(" NOTA1: %d", ptr->dado.nota1);
			printf(" NOTA2: %d", ptr->dado.nota2);
			printf(" FALTAS: %d", ptr->dado.faltas);
			printf("\n");
			ptr = ptr->prox;
		}
	} else {
		printf("Fila Vazia. \n");
		return;
	}
}

int main(){
	FILA *f1 = (FILA*) malloc(sizeof(FILA));
	char tecla;
	t_aluno aluno;
	inicializaFila(f1);
	
	while (tecla!='S' && tecla!='s')
	{
	  printf("[I]ncluir [L]istar [D]eletar [S]air\n");
	  tecla=getch(); 
	  if (tecla=='i' || tecla=='I')     
	  {
		aluno=recebe_dados();
		enfileira(aluno, f1);		
	  } 
	  else if (tecla=='l' || tecla=='L')
	  {
	  	imprimeFila(f1);
	  } 
	  else if (tecla=='d' || tecla=='D')
	  {
	  	desenfileira(f1);
	  }
	  else if (tecla=='s' || tecla=='S')
	  {
	   printf("Saindo\n");
	  } 
	  else
	  {
		printf("Opcao invalida\n");
	  }
	}
	return 0;
}
