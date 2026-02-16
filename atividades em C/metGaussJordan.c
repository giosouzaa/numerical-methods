/*
---------------------------------------------------------------------------
Compilação:     gcc metGaussJordan.c -lm -o gj
Execução:       ./gj
---------------------------------------------------------------------------
Equações transcendentes
O Método de Gauss Jordan

Algoritmo: Cálculo do valor numérico de um polinômio e de sua derivada
 
Material de Apoio: Livro - Cálculo Numérico, Ruggiero
 
 
*/

#include <stdio.h>            //input-output
#include <stdlib.h>           //funções envolvendo alocação de memória, controle de processos, conversões e outras.
#include <unistd.h>           // (read, write, close, etc.). 
#include <math.h>         // funções matemáticas básicas
#include <time.h>         //para manipulação de datas e horários
// ------------------------------------------------------------------------------------------
/* global user's parameters */

double **a;
double *x;
double *b;
double n;
double **A;
double *B;
double m;
 
// ------------------------------------------------------------------------------------------
/* functions    */

 
// ------------------------------------------------------------------------------------------
 
//===========================================================================================
// main
int main (int i,int j,int k,int t)
{
	
	printf("\nInsira o número de equações:");
	scanf("%lf",&n);

	A=(double**)calloc(n+1,sizeof(double));
	B=(double*)calloc(n,sizeof(double));
	a=(double**)calloc(n+1,sizeof(double));
	b=(double *)calloc(n,sizeof(double));

	for(i=0;i<n;i++)
		{a[i]=(double *)calloc(n+1,sizeof(double));
		 A[i]=(double *)calloc(n+1,sizeof(double));}
	
	printf("\nValores da coluna das soluções:\n");
	
	for(i=0;i<n;i++)
		{scanf("%lf",&b[i]);}

	for(i=0;i<n;i++)
		{printf("\nCoeficientes da equação %d:\n",i+1);
		 for(j=0;j<n;j++)
			{scanf("%lf",&a[i][j]);}}
	for(i=0;i<n;i++)
		{for(j=n;j<=n;j++)
		{a[i][j]=b[i];}}

	printf("\n");	

	for(i=0;i<n;i++)
		{printf("\nCoeficientes da equação %d:\n",i+1);
		 for(j=0;j<n;j++)
			{if(j<n-1)
				{printf("%.2f",a[i][j]);
				printf("\t+\t");}
			 else
				{printf("%.2f\t=\t%.2f\n",a[i][j],b[i]);}
			}}

	/*Inicialização*/
	

	for(k=0;k<n;k++)
 		{A[k][k]=1;
 
 		for(j=k+1;j<=n;j++)
			{A[k][j]=a[k][j]/a[k][k];}
 		for(i=0;i<n;i++)
			{if(i!=k)
			{m=a[i][k]/A[k][k];
			{for(j=k;j<=n;j++)
				{A[i][j]=a[i][j]-m*A[k][j];}
			for(i=0;i<n;i++)
				{for(j=n;j<=n;j++)
					{A[i][j]=a[i][j]-m*A[k][j];}}}}}}

	printf("\n");	

	for(i=0;i<n;i++)
		{for(j=0;j<=n;j++)
			{printf("%.0lf\t",A[i][j]);}
		printf("\n");}	
}

//===========================================================================================

