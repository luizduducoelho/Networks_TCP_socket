#include <stdio.h>
#include <stdlib.h>

int main() {
	FILE *arq;
	arq = fopen("arquivo.txt", "r");
	if (arq == NULL){
		printf("Erro na abertura do arquivo");
		exit(1);
	}
	int i, total_lido;
	int tam_buffer = 10;
	int v[tam_buffer];
	total_lido = fread(v, 1, tam_buffer, arq);
	if (total_lido != tam_buffer){
		printf("Erro na leitura do arquivo!");
		exit(1);
	}
	else{
		for (i=0; i<15; i++){
			printf("v[%d] = %d \n", i, v[i]);
		}
	}
	fclose(arq);


	//Write back in file
	FILE *warq;
	warq = fopen("ArqGrav.txt", "w");
	if (warq == NULL){
		printf("Problemas na criacao do arquivo");
		exit(1);	
	}
	int total_gravado;
	total_gravado = fwrite(v, 1, tam_buffer, warq);
	if (total_gravado != tam_buffer){
		printf("Erro na escrita do arquivo");
		exit(1);
	}
	fclose(warq);
	
	return 0;
}
