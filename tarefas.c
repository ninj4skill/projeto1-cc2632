#include <stdio.h>
#include <string.h>
#include "tarefas.h"

ERROS criar(Tarefa tarefas[], int *pos){
    if(*pos >= TOTAL)
        return MAX_TAREFA;

    printf("Entre com a prioridade: ");
    scanf("%d", &tarefas[*pos].prioridade);
    if(tarefas[*pos].prioridade <1 || tarefas[*pos].prioridade > 10)
      printf("Prioridade inválida\n");
    else{
      
      clearBuffer();
      printf("Entre com a categoria: "); 
      fgets(tarefas[*pos].categoria,  TOTALC, stdin); 

      tarefas[*pos].categoria[strcspn(tarefas[*pos].categoria,"\n")] = '\0';
      printf("Entre com a descricao: ");
      fgets(tarefas[*pos].descricao, TOTALD, stdin);
      tarefas[*pos].descricao[strcspn(tarefas[*pos].descricao,"\n")] = '\0';
      
      *pos = *pos + 1;
 
      }
    return OK;
}

ERROS deletar(Tarefa tarefas[], int *pos){
    // teste se existem tarefas
    if(*pos == 0)
        return SEM_TAREFAS;

    // verifica se a tarefa escolhida existe
    int pos_deletar;
    printf("Entre com a posicao da tarefa a ser deletada: ");
    scanf("%d", &pos_deletar);
    pos_deletar--; // garantir posicao certa no array
    if(pos_deletar >= *pos || pos_deletar < 0)
        return NAO_ENCONTRADO;

    for(int i = pos_deletar; i < *pos; i++){
        tarefas[i].prioridade = tarefas[i+1].prioridade;
        strcpy(tarefas[i].categoria, tarefas[i+1].categoria);
        strcpy(tarefas[i].descricao,  tarefas[i+1].descricao);
    }

    *pos = *pos - 1;

    return OK;
}

ERROS listar(Tarefa tarefas[], int *pos){
    if(*pos == 0)
        return SEM_TAREFAS;
    printf("Qual a categoria das tarefas que deseja listar?: ");
    clearBuffer();
    fgets(tarefas[*pos].categoria, TOTALC, stdin); 
    int tarefascategoria = 0;
    tarefas[*pos].categoria[strcspn(tarefas[*pos].categoria,"\n")] = '\0';
    for(int i=0; i<*pos; i++){
        if (strcmp(tarefas[i].categoria, tarefas[*pos].categoria) == 0 || tarefas[*pos].categoria[0] == '\0'){
            printf("Pos: %d\t", i+1);
            printf("Prioridade: %d\t", tarefas[i].prioridade);
            printf("Categoria: %s\t", tarefas[i].categoria);
            printf("Descricao: %s\n", tarefas[i].descricao);
            tarefascategoria++;
        }
    }
    if (tarefascategoria == 0){
        printf("Categoria não encontrada");
        return NAO_ENCONTRADO;
    }

    return OK;
}

ERROS salvar(Tarefa tarefas[], int *pos){
    FILE *f = fopen("tarefas.bin", "wb");
    if(f == NULL)
        return ABRIR;

    int qtd = fwrite(tarefas, TOTAL, sizeof(Tarefa), f);
    if(qtd == 0)
        return ESCREVER;

    qtd = fwrite(pos, 1, sizeof(int), f);
    if(qtd == 0)
        return ESCREVER;

    if(fclose(f))
        return FECHAR;

    return OK;
}

ERROS carregar(Tarefa tarefas[], int *pos){
    FILE *f = fopen("tarefas.bin", "rb");
    if(f == NULL)
        return ABRIR;

    int qtd = fread(tarefas, TOTAL, sizeof(Tarefa), f);
    if(qtd == 0)
        return LER;

    qtd = fread(pos, 1, sizeof(int), f);
    if(qtd == 0)
        return LER;

    if(fclose(f))
        return FECHAR;

    return OK;

}

ERROS exportar(Tarefa tarefas[], int *pos){
    char arquivtext[100];
    printf("Digite o nome do arquivo em que deseja salvar as tarefas: ");
    clearBuffer();
    fgets(arquivtext, 100, stdin); 
    arquivtext[strcspn(arquivtext,"\n")] = '\0';
    printf("Digite a categoria das tarefas que deseja exportar: ");
    fgets(tarefas[*pos].categoria, 100, stdin); 
    clearBuffer();
    tarefas[*pos].categoria[strcspn(tarefas[*pos].categoria,"\n")] = '\0';
    int tarefascategoria = 0;
    FILE *f = fopen(arquivtext, "w");
    if(f == NULL){
        return ABRIR;
    }
    for(int i = 0; i < *pos; i++){
        if(strcmp(tarefas[i].categoria, tarefas[*pos].categoria) == 0){
            fprintf(f, "Pos: %d\t", i+1);
            fprintf(f, "Prioridade: %d\t", tarefas[i].prioridade);
            fprintf(f, "Categoria: %s\t", tarefas[i].categoria);
            fprintf(f, "Descrição: %s\n", tarefas[i].descricao);
            tarefascategoria++;
        }
    }
    if (fclose(f)){
        return FECHAR;
    }
    if (tarefascategoria == 0){
        return NAO_ENCONTRADO;
    }
   
    return OK;

}

void clearBuffer(){
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}
