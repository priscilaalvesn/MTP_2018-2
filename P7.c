/* P7.c */
/* Priscila Alves Nunes */
/* 11811EBI010 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct{
	float x, y;
}Ponto;

Ponto * gera(int N)
{
	Ponto * p = (Ponto *) calloc(N, sizeof(Ponto));
	int i;
	for(i = 0; i < N; i++)
	{
		p[i].x = cos(i * 2.0 * M_PI / (N - 1));
		p[i].y = sin(i * 2.0 * M_PI / (N - 1));
	}
	return p;
}

void mostrar_pontos(Ponto * p_inicial, Ponto * p_final)
{
	if(p_inicial < p_final)
	{
		printf("(%.3lf, %.3lf)", p_inicial -> x, p_inicial -> y);
		mostrar_pontos(p_inicial + 1, p_final);
	}
}

void gravar_pontos(Ponto * p_inicial, int N) {
    FILE * arquivo;
    arquivo = fopen("pontos.dat", "wb");
    fwrite(p_inicial, N, sizeof(Ponto), arquivo);
    fclose(arquivo);
}


Ponto * ler_pontos(char * nome_arquivo, unsigned int * pN) {
    Ponto * p = (Ponto *) malloc(sizeof(p));
    unsigned int N = 0;
    FILE * arquivo;
    arquivo = fopen(nome_arquivo, "rb");
    while(1) {
        fread(p, 1, sizeof(Ponto), arquivo);
        if(feof(arquivo)) break;
        N++;
    }
    rewind(arquivo);
    p = (Ponto *) realloc(p, N*sizeof(Ponto));
    fread(p, N, sizeof(Ponto), arquivo);
    fclose(arquivo);
    *pN = N;
    return p;
}


int main()
{
    unsigned int N, opcao;
    Ponto * p;
	printf("1. Gerar arquivo com pontos; 2. Recuperar pontos de arquivo: ");
    scanf("%u", &opcao); getchar();
    if(opcao == 2)
	{
        p = ler_pontos("pontos.dat", &N);
        mostrar_pontos(p, p + N);
    }
	else
	{
        printf("Quantos pontos deseja? ");
		scanf("%u", &N); getchar();
        p = gera(N);
        gravar_pontos(p, N);
        printf("Arquivo gravado");
    }
    free(p);
    return 0;
}
