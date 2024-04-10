#include <stdio.h>
#include "tarefas.h"

int main(){
    funcao fs[] = {criar, deletar, listar, salvar, carregar};

    Tarefa tarefas[TOTAL];
    int pos;
    ERROS erro = fs[4](tarefas, &pos);

    if(erro != OK)
        pos = 0;

    int opcao;
    do{
        printf("\nMenu principal\n");
        printf("1 - Criar tarefa\n");
        printf("2 - Deletar tarefa\n");
        printf("3 - Listar tarefas\n");
        printf("0 - Sair\n");
        printf("Escolha uma opcao: ");

        scanf("%d", &opcao);
        opcao--;
        if(opcao > 2)
            printf("Opcao invalida\n");
        else if(opcao >= 0){
            //fs[opcao](tarefas, &pos);
            if (opcao == 0){
                erro = fs[0](tarefas, &pos);
                if (erro == MAX_TAREFA){
                    printf("Maximo de tarefas atingido\n");
                }
            }
            else if(opcao == 1){
                erro = fs[1](tarefas, &pos);
                if (erro == SEM_TAREFAS){
                    printf("Sem tarefas para deletar\n");
                }
                else if (erro == NAO_ENCONTRADO){
                    printf("Tarefa não encontrada na lista\n");
                }
            }
            else if(opcao == 2){
                erro = fs[2](tarefas, &pos);
                if (erro == SEM_TAREFAS){
                    printf("Sem tarefas para listar\n");
                }
            }
            }
        else
            printf("Sair...\n");
            erro == fs[3](tarefas, &pos);
            if (erro == ABRIR || erro == ESCREVER || erro == FECHAR){
                printf("Não foi possivel salvar as tarefas\n");
            
            }

    } while(opcao >= 0);

}
