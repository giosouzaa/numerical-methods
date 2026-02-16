/*
---------------------------------------------------------------------------
Compilação:     gcc MetRungeKutta.c -lm -o mrk
Execução:       ./mrk
---------------------------------------------------------------------------
Equações diferenciais: o método de Runge-Kutta de 4a ordem

Algoritmo: Resolução numérica de uma equação diferencial
 
Material de Apoio: Livro - Cálculo Numérico, Ruggiero
 
 
*/

#include <stdio.h>            //input-output
#include <stdlib.h>           //funções envolvendo alocação de memória, controle de processos, conversões e outras.
#include <unistd.h>           // (read, write, close, etc.). 
#include <math.h>         // funções matemáticas básicas
#include <time.h>         //para manipulação de datas e horários

// ------------------------------------------------------------------------------------------
/* global user's parameters */

double X0=0;
double Y0=2;
double h=0.1;
double *k;
double *y;
 
// ------------------------------------------------------------------------------------------
/* functions    */

double f(double X0,double Y0);
 
// ------------------------------------------------------------------------------------------
 
//===========================================================================================
// main
int main (int i,int j)
{
	k=(double*)calloc(4,sizeof(double *));
	y=(double*)calloc(10,sizeof(double *));

	printf("\nEste programa foi realizado para um trabalho de calculo numerico, baseado no exemplo para o metodo de Runge-Kutta de quarta ordem. A funcao resolvida e: y'=x-y+2 com os parametros:\n\ny(0)=2\nm=10\nh=0.1\nmalha [0,1]\n\n");	

	for(i=1;i<=10;i++){
		k[1]=f(X0,Y0);
		for(j=2;j<=3;j++){
			k[j]=f(X0+(h/2),Y0+(h*k[j-1])/2);
		}
	k[4]=f(X0+h,Y0+(h*k[3]));
	y[i]=Y0+((h/6)*(k[1]+2*k[2]+2*k[3]+k[4]));
	printf("\nX[%d]=%.1lf\ty[%d]=%lf\n\n",i,X0,i,y[i]);
	X0=X0+h;
	Y0=y[i];
	}
}

//===========================================================================================
 
double f(double X0,double Y0){
    return (X0-Y0+2); 
}


 
