/*
---------------------------------------------------------------------------
Compilação:     gcc metGaussjacobi.c -lm -o gs
Execução:       ./gs
---------------------------------------------------------------------------
Equações transcendentes
O Método de Gauss Jacobi

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

double *x;
double *e;
double **a;
double E;
double *Xo;
double *X;
double *X1;
double s;
double p;
 
// ------------------------------------------------------------------------------------------
/* functions    */

 
// ------------------------------------------------------------------------------------------
 
//===========================================================================================
// main
int main (int n,int m,int i,int k,int j,int t)
{
	
	
	printf("\nInsira o número de equações:");
	scanf("%d",&n);
	
	X1=(double *)calloc(n,sizeof(double));
	Xo=(double *)calloc(n,sizeof(double));
	X=(double *)calloc(n,sizeof(double));
	x=(double *)calloc(n,sizeof(double));
	e=(double *)calloc(n,sizeof(double));
	a=(double **)calloc(n,sizeof(double *));

	for(i=0;i<n;i++)
		{a[i]=(double *)calloc(n,sizeof(double));}

	printf("\nValores da coluna das soluções:\n");
	
	for(i=0;i<n;i++)
		{scanf("%lf",&x[i]);}

	printf("\nInsira os %d valores para o chute inicial:\n",n);
	
	for(i=0;i<n;i++)
		{scanf("%lf",&Xo[i]);}
	
	for(i=0;i<n;i++)
		{printf("\nCoeficientes da equação %d:\n",i+1);
		 for(j=0;j<n;j++)
			{scanf("%lf",&a[i][j]);}
		}
	printf("\n");
	for(i=0;i<n;i++)
		{
		 for(j=0;j<n+1;j++)
			{if(j<n)
			{printf("%.2lfx(%d)",a[i][j],(j+1));
			 if(j<n-1)
				{printf("\t+\t");}}
			else
			{printf("\t=\t%.2lf\n",x[i]);}
			}
		}

	printf("\nPrecisão:");
	scanf("%lf",&E);

	/*Inicialização*/
	
	m=0;

	do
	{t=0;

	 for(i=1;i<=n;i++)
	 {m=m+1; //onde m é o número de iterações
	 	
	 if(i>1)
	 {for(k=1;k<=n;k++)
		{Xo[k]=X[k];}}
	 else
	 {for(k=1;k<=n;k++)
		{Xo[k]=Xo[k];}}
	 s=0;
	 p=0;

	 if(i<=1)
	 {for(j=i+1;j<=n;j++)
		{p=p+((a[i][j])*Xo[j]);}

	 X[i]=(x[i]-p)/(a[i][i]);}
	 
	 else
	 {for(j=1;j<=i-1;j++)
		{s=s+((a[i][j])*Xo[j]);}
	 for(j=i+1;j<=n;j++)
		{if(i<n)
		 {p=p+((a[i][j])*Xo[j]);}
		 if(i==n&&j==n)
		 {p=p+((a[i][j-1])*Xo[j-1]);}}

	 X[i]=(x[i]-(s+p))/(a[i][i]);}

	 e[i]=fabs(X[i]-Xo[i]);

	 if(e[i]>E)
		{t=t+1;}}
	}while(t>0);	
	 
	printf("\nOs valores aproximados encontrados em %d interações com erro<%.4lf são:\n\n",m,E);

	for(k=1;k<=n;k++)
		{printf("X(%d)=%.2f\n",k,X[k]);}
	
	
	
}

//===========================================================================================
