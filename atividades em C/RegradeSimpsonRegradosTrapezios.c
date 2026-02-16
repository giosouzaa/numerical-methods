/*
---------------------------------------------------------------------------
Compilação:     gcc RegradeSimpsoneRegradosTrapézios.c -lm -o rsrt
Execução:       ./rsrt
---------------------------------------------------------------------------
Primeira Regra de Simpson

Algoritmo: Resolução numérica de uma integral
 
Material de Apoio: Livro - Cálculo Numérico, Ruggiero
 
 
*/

#include <stdio.h>            //input-output
#include <stdlib.h>           //funções envolvendo alocação de memória, controle de processos, conversões e outras.
#include <unistd.h>           // (read, write, close, etc.). 
#include <math.h>         // funções matemáticas básicas
#include <time.h>         //para manipulação de datas e horários
// ------------------------------------------------------------------------------------------
/* global user's parameters */

double x;
double A;/*variável para armazenar o valor do extremo inferior de integral*/
double B;/*variável para armazenar o valor do extremo superior de integral*/
double *y;/*variável para realizar alocação dinâmica com a quantidade de intervalos definidos*/
double h;/*variável para armazenar o valor do passo da integral*/ 
double SM=0;/*variavel para armazenar a soma de todos os valores entre os extremos*/
double SE=0;/*variavel para armazenar a soma dos valores extremos de f(x)*/
double SI=0;/*variavel para armazenar a soma dos valores impares entre os extremos de f(x)*/
double SP=0;/*variavel para armazenar a soma dos valores pares entre os extremos de f(x)*/
double IT=0;/*variável para armazenar o valor da integral pela regra dos trapézios*/
double IS=0;/*variável para armazenar o valor da integral pela regra de simpson*/

// ------------------------------------------------------------------------------------------
/* functions    */

double f(double x);
 
// ------------------------------------------------------------------------------------------
//=========================================================================================== 
// main

int main (int argc, char* argv[],int i,int n)
{	

	printf("\nEste programa foi realizado para um trabalho de calculo numerico, baseado no exemplo para a Regra dos Trapezios e para a Primeira Regra de Simpson. A funcao resolvida foi y=1/x.\n\n");

	/*Solicitação do número de subintervalos n*/
	printf("\nInsira o número de subintervalos:\n");
	scanf("%d",&n);

	y=(double *)calloc(n+1,sizeof(int));/*Alocação dinamica da quantidade subintervalos mais 1 , pois começa em 0 e vai até a quantidade de subintervalos definidos. Serve para armazenar os valores de f(x)*/
	
	/*Solicitação dos extremos (A,B)*/
	printf("\nInsira os extremos de integração A e B:\n");
	scanf("%lf%lf",&A,&B);

	/*Cálculo dos valores funcionais*/

	h=(B-A)/n; /*Cálculo do passo que será dado em cada valor, o cálculo é dado pela diferença dos valor superior pelo inferior, divido pelo numero de subintervalos*/
	
	x=A;/* Atribuição à x do valor do extremo inferior */

	for(i=0;i<=n;i++){ /*Laço de repetição para atribuição dos valores de f(x) e armazena-los no vetor y, pode-se observar que toda vez que é atribuido um valor a f(x) é somado um passo ao valor de x */
		y[i] = f(x);
		x = x + h;
	}
	
	for(i=0;i<=n;i++){/*Laço de repetição para os cálculos dos somatórios*/
		if(i==0||i==n){/*Nesse condicional serão somados somente os valores extremos de f(x), ou seja y[0] e y[n]*/
			SE=SE+y[i];}
		if(i%2!=0&&i!=n){/*Condicional para somar todos os y impares diferentes de y[0] e y[n]*/
			SI=SI+y[i];
			SM=SM+y[i];}
		if(i%2==0&&i!=0&&i!=n){/*Condicional para somar todos os y pares diferentes de y[n], se n for impar*/
			SP=SP+y[i];
			SM=SM+y[i];}
	}

	/*Cálculo da integral: Regra de Simpson*/
	IS=(h/3)*(SE+(4*SI)+(2*SP));/* Sendo: h= passo, SE= somatório dos extremos, SI= somatório dos valores impares e SP= somatório dos valores pares*/

	/*Cálculo da integral: Regra dos Trapézios*/
	IT=(h/2)*(SE+(2*SM));/* Sendo: h = passo, SE = somatorio dos extremos e SM= somatório dos valores que ficam entre os extremos*/

	/*Exibição da resolução numérica das integrais*/
	printf("\nValor da integral:\nSegundo a Primeira Regra de Simpson, %lf\nSegundo a Regra dos trapézios, %lf\n\n",IS,IT);

}
//===========================================================================================

double f(double x)/*Variáveis da função f(x)*/{
    return (1/x)/* a função em que serao calculados os pontos*/; 
}
