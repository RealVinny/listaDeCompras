#include <stdio.h>
#include <stdlib.h>
#include <string.h>



#define tamanhoMaxArray  15
#define tamanhoMaxNome  40

int main(){

	char lista[tamanhoMaxArray][tamanhoMaxNome] = {};
	int tamanho = 0;

	void addItem(char shoppingList[][tamanhoMaxNome], int *tamanho, int itemMax, const char *itm){
	
		if(*tamanho < tamanhoMaxArray){
			strncpy(shoppingList[*tamanho], itm, 40);
			shoppingList[*tamanho][39] = '\0';
			(*tamanho)++;
		}else{
			printf("lista esta cheia, nao foi possivel adicionar o item!");
	
		}
	}


	void removeItem(char shoppingList[][tamanhoMaxNome], int *tamanho, int index){
	
		if( index < 0 || index >= *tamanho){
		
		printf("index invalido!");
		return;

		}

		for(int i = index; i < *tamanho - 1; i++){
				strcpy(shoppingList[i], shoppingList[i-1]);
		}

		memset(shoppingList[*tamanho -1], 0, tamanhoMaxNome);

		(*tamanho)--;
	}
	



	addItem(lista, &tamanho, tamanhoMaxArray, "agua");
	printf("%s", lista[0]);
	removeItem(lista, &tamanho, 0);
	printf("%s", lista[0]);

	return 0;
}