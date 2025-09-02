#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <limits.h>
#include <ctype.h>
#include <time.h>
#include <stdbool.h>

typedef struct{
    int* p_pi; //sera usado para guardar o endereco do vetor
    int n; //guarda quantos elementos tem no vetor
} VetorInteligente;

VetorInteligente cria(){
    VetorInteligente npi;
    npi.p_pi=NULL;
    npi.n=0;
    return npi;
}


/*VetorInteligente adiciona(VetorInteligente vi, int x){
    VetorInteligente nvi=cria();
    nvi.p_pi=malloc((vi.n+1)*sizeof(int));
    nvi.n=vi.n+1;
    nvi.p_pi[nvi.n-1]=x;
    return nvi;
}*/

VetorInteligente adiciona(VetorInteligente vi, int x) {
	int *nvi = (int*)malloc((vi.n + 1) * sizeof(int));
	for (int w = 0; w < vi.n; w++) {
		nvi[w] = vi.p_pi[w];
}
	nvi[vi.n] = x;
	free(vi.p_pi);
	vi.p_pi = nvi;
	vi.n=vi.n+1;
	return vi;
}

void mostra(VetorInteligente vi){
    for (int e = 0; e < vi.n; e++) {
        printf("%d ", vi.p_pi[e]);
    }
}

void mostrain(VetorInteligente vi){
    for (int e = vi.n-1; e>=0; e--) {
        printf("%d ", vi.p_pi[e]);
    }
}

VetorInteligente destroi(VetorInteligente vi){
    free(vi.p_pi);
    vi.p_pi = NULL;
    vi.n=0;
}

int main(){
    unsigned long long int a;
    VetorInteligente vi=cria();
    printf("Digite um numero natural maior que 0: ");
    scanf("%llu", &a);


        while (a>0){
            vi=adiciona(vi, a%2);
            a=a/2;
        }


    mostrain(vi);
    destroi(vi);
    printf("\n");
    return 0;
}
