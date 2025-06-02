#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>


    

void addItem(char * list[], int *index, const char *element){

    list[*index] = strdup(element);
    (*index)++;
   
 
}

void RemoveItem(char * list[], const char *element){

    for(int i = 0; sizeof(*list) > i; i++){
        
        if(strcasecmp(list[i], element)){
            strcpy(list[i], NULL);
            printf("elemento removido com sucesso");
            break;
        }

    }
}


void ListItems(char *list[]){

    for(int i = 0; sizeof(*list) > i; i++){
        printf("%s", list[i]);
    }
}




int main(){

char * lista[50] = {0};
int quantItens = {0};
int * pQuantItens = &quantItens;
char item[] = "";


printf("oque você deseja fazer?\n");
printf("[A]dicionar, [R]emover, [L]istar\n ->");
    int op = getchar();

    if(op == 'A'){ // Adicionando Itens
    

        while( 1 == 1){

    char entrada[] = {0};



    printf("diga o nome do item para ser adicionado:");
    scanf("%s", entrada);

        if(strcasecmp(entrada, "quit")){
            break;
        }

    addItem(lista, pQuantItens, entrada);

        

    }
    
        }else if(op == 'R'){ // Removendo item

        while( 1 == 1){

    char entrada[] = {0};
    

    printf("diga o nome do item para ser removido:");
    scanf("%s", entrada);

        if(strcasecmp(entrada, "quit")){
            break;
            } 
  
            RemoveItem(lista, entrada);

        

    }

        }else if(op == 'L'){ // Listando Itens


        while( 1 == 1){

    char entrada[] = {0};
    

    printf("diga o nome do item para ser adicionado:");
    scanf("%s", entrada);

        if(strcasecmp(entrada, "quit")){
            break;

        ListItems(lista);



    }

    }
    }

printf("%s", lista[0]);



	return 0;
}
