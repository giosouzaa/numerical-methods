/*
---------------------------------------------------------------------------
Compilação:     gcc metBriotRuffini.c -lm -o br
Execução:       ./br
---------------------------------------------------------------------------
Equações polinomiais
O Método de Briot Ruffini

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

double n; /*declaracão de variável para definir o grau do polinômio inserido pelo usuário*/
double c; /*declaracão de variável que armazenará o valor do ponto inserido pelo usuário*/
double *a; /*declaracão de ponteiro para armazenar os valores dos coeficientes do polinômio fornecido pelo usuário*/
double *d; /*declaracão de ponteiro para armazenar os valores dos coeficientes do polinômio gerado pela primeira aplicação do dispositivo*/
double *e; /*declaracão de ponteiro para armazenar os valores dos coeficientes do polinômio gerado pela segunda aplicação do dispositivo*/
 
//===========================================================================================
// main
int main (int k)
{
	printf("\nGrau do polinômio: "); /*Solicitação do grau do polinômio*/
	scanf("%lf", &n); /*valor do polinômio inserido pelo usuário*/

	
	a=(double*)calloc(n,sizeof(double *)); /*alocação dinâmica, transformando o ponteiro num vetor com tamanho do valor do grau inserido pelo usuário*/
	d=(double*)calloc(n,sizeof(double *)); /*alocação dinâmica, transformando o ponteiro num vetor com tamanho do valor do grau inserido pelo usuário*/
	e=(double*)calloc(n,sizeof(double *));/*alocação dinâmica, transformando o ponteiro num vetor com tamanho do valor do grau inserido pelo usuário*/

	printf("\nCoeficientes do polinômio:\n"); //Solicitação dos coeficientes do polinômio 

	for (k=0;k<=n;k++) /* laço de repeticão para a insercão dos coeficientes (vale a pena lembrar que os polinômios sempre têm n+1 coefcientes, sendo n o grau do polinômio) */ 
		{scanf("%lf",&a[k]);}

	for (k=0;k<=n;k++) /*Exibicão dos valores inseridos*/
		{printf("\na[%d]=%.2lf\n",k,a[k]);} 

	printf("\nValor da abscissa: ");  /* Pedido do ponto em que o usuário quer que seja calculado o polinômio */ 
	scanf("%lf", &c);
	
	//algoritmo (Briot-Ruffini) : cálculo de p(c)

	d[0]=a[0]; /* Determinacão de que o primeiro coeficiente se manterá com o mesmo valor (como previsto no dispositivo de Briot-Ruffini) e seja armazenado na primeira casa do vetor d */ 
	
	for (k=1;k<=n;k++)  /* laço de repeticão para o cálculo dos valores do dispositivo de Briot-Ruffini */ 
		{d[k]= c*d[k-1]+a[k];}/* Operacão para o calculo dos valores do dispositivo, sendo d[k], o local em que o valor será armazenado no vetor. C o valor do ponto inserido pelo usuario em que ele quer que calcule o polinomio, d[k-1] o valor anterior, que multiplicado por c e somado com a[k] dá um valor no dispositivo */ 


	printf("\n");

	for (k=0;k<=n;k++) // Exibição dos valores calculados
		{if (k<=n-1) /*condicão para exibição, a exibicão deve ir apenas até o penultimo valor calculado */ 
			{printf("d[%d]=%.2lf\t",k,d[k]);}
		 else  /*condicional, se for o ultimo valor calculado deve ser exibido como valor do polinomio no ponto inserido pelo usuario, na forma "p(c)=" */ 
			{printf("p(c)=%.2lf\n", d[k]);}
		}

	printf("\n\n");
	
	//algoritmo (Briot-Ruffini) : cálculo de p'(c)

	e[0]=d[0]; /* Determinação de que o primeiro coeficiente ainda se manterá com o mesmo valor, como previsto no dispositivo de Briot-Ruffini e seja armazenado na primeira casa do vetor e */ 

	for (k=1;k<=n-1;k++) /* laço de repeticão para o calculo dos valores do dispositivo de Briot-Ruffini, será calculado um valor a menos para esse dispositivo, pois o objetivo é encontrar o valor da derivada primeira do polinomio no ponto inserido pelo usuario*/
		{e[k]=c*e[k-1]+d[k];} /* Operacão para o calculo dos valores do dispositivo, sendo e[k], o local em que o valor será armazenado no vetor. C o valor do ponto inserido pelo usuario em que ele quer que calcule o polinomio, e[k-1] o valor anterior, que multiplicado por c e somado com d[k] dá um valor no dispositivo */ 

	for (k=0;k<=n-1;k++) /*Exibicão dos valores calculados*/
		{if (k<=n-2) /*condicão para exibicão, que deverá ir apenas até o penultimo valor calculado (lembrando que o calculo foi realizado apenas até n-1)*/ 
			{printf("e[%d]=%.2lf\t",k,e[k]);}
		 else /*condicional, se for o ultimo valor calculado deve ser exibido como valor do polinomio no ponto inserido pelo usuario, na forma "p'(c)=" */ 
			{printf("p'(c)=%.2lf\n",e[k]);}
		}

	printf("\n");
}

//===========================================================================================
 

