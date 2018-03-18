#include <stdio.h>
#include <stdlib.h>

int main() {
	FILE *arq;
	char c;
	arq = fopen("arquivo.txt", "r");
	if (arq == NULL){
		printf("Erro na abertura do arquivo");
		exit(1);
	}
	int i;
	//for (i = 0; i < 5; i++){
	while ((c = fgetc(arq)) != EOF){
		//c = fgetc(arq);
		printf("%c", c);
	}
	printf("\n");
	fclose(arq);
	return 0;
}

