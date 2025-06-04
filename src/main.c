#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include <threads.h>


int itemQuantMax = 15;
int itemNameSize = 25;
int itemCurrentQuant = 0;

char lista[15][25];
char buffer[500];

char * pBuffer = &buffer[sizeof(buffer)];



void wait(int sec) {

	const time_t startTime = time(NULL);

	while (time(NULL) - startTime < sec){};

}
void limparBuff() {

	int c;
	while ((c = getchar()) != '\n' && c != EOF);

}

void listItem(char list[][25]) {

	for (int i = 0; i < 25; i ++) {

		if (list[i][0] != '\0') {
			printf("%s\n", list[i]);
			wait(1);


		}

	}

	limparBuff();


}

void addItem(char list[][25], int * quant, int quantMax) {

	while (1 == 1) {

		if ( quantMax > *quant) {

			printf("informe o item a ser adicionado na lista\n informe exit para sair\n -> ");
			scanf("%s", buffer);
			if (strcmp(buffer, "EXIT") == 0 || strcmp(buffer, "exit") == 0) {
					limparBuff();
				break;
			}else {
				strcpy(list[*quant], buffer);
				(*quant)++;
			}
		}else {
			printf("a lista esta cheia!");
			break;
		}
	}

}

void removeItem(char * buff, char list[][25]) {

	while (1 == 1) {

		printf("deseja ver os itens da lista atualmente ?\n[Y/N] ->");
		scanf("%s", buff);

		if (*buff == 'Y') {
			listItem(list);
		}

		printf("Informe o item para ser removido\n -> ");
		scanf("%s", buff);


		if (strcmp(buff, "EXIT") == 0 || strcmp(buff, "exit") == 0) {
			limparBuff();
			break;
		}

		for (int i = 0; i < itemQuantMax; i++) {

			if (strcasecmp(list[i], buff) == 0) {
				for (int j = 0; j < itemNameSize; j++) {
					list[i][j] = '\0';
				}

				break;
			}

			printf("Item não encontrado !")	;
		}
	}
}



int main(){




	while (1 == 1) {

		wait(0.5);

		printf("informe a operação a ser realizada\n[A]dicionar\n[R]emover\n[L]istar\n -> ");

		int op = getchar();

		if (op == 'A') {

			addItem(lista, &itemCurrentQuant, itemQuantMax);

		}else if (op == 'R') {

				removeItem(pBuffer, lista);

		}else if (op == 'L') {

				listItem(lista);

		}else {
			system("clear");
		}
	}
	return 0;
}
