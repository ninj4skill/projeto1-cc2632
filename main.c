#include <stdio.h>
#include "tarefas.h"

int main(){
    funcao fs[] = {criar, deletar, listar, exportar, salvar, carregar};

    Tarefa tarefas[TOTAL];
    int pos;
    ERROS erro;

    int opcao;
    do{
        printf("\nMenu principal\n");
        printf("1 - Carregar tarefa\n");
        printf("2 - Criar tarefa\n");
        printf("3 - Deletar tarefa\n");
        printf("4 - Listar tarefas\n");
        printf("5 - Exportar tarefas\n");
        printf("6 - Salvar tarefas\n");
        printf("0 - Sair\n");
        printf("Escolha uma opcao: ");

        scanf("%d", &opcao);
        opcao--;
        if(opcao > 5)
            printf("Opcao invalida\n");
        else if(opcao >= 0){
            
            if (opcao == 1){
                erro = fs[0](tarefas, &pos);
                if (erro == MAX_TAREFA){
                    printf("Maximo de tarefas atingido\n");
                }
            }
            else if(opcao == 2){
                erro = fs[1](tarefas, &pos);
                if (erro == SEM_TAREFAS){
                    printf("Sem tarefas para deletar\n");
                }
                else if (erro == NAO_ENCONTRADO){
                    printf("Tarefa não encontrada na lista\n");
                }
            }
            else if(opcao == 3){
                erro = fs[2](tarefas, &pos);
                if (erro == SEM_TAREFAS){
                    printf("Sem tarefas para listar\n");
                }
            }
            else if (opcao == 4){
                erro = fs[3](tarefas, &pos);
                if(erro == ABRIR || erro == FECHAR){
                    printf("Não foi possível exportar as tarefas\n");
                }
                else if(erro == NAO_ENCONTRADO){
                    printf("Categoria não encontrada\n");
                }
            }
            else if (opcao == 0){
                erro = fs[5](tarefas, &pos);
                if (erro == ABRIR || erro == FECHAR || erro == LER){
                    printf("Não foi possivel carregar as tarefas\n");
                }
            else if (opcao == 5){
                erro = fs[4](tarefas, &pos);
                if (erro == ABRIR || erro == ESCREVER || erro == FECHAR)
                    printf("Não foi possivel salvar as tarefas\n");
            }
            }
            }
        else
            printf("Sair...\n");
            erro == fs[4](tarefas, &pos);
            if (erro == ABRIR || erro == ESCREVER || erro == FECHAR){
                printf("Não foi possivel salvar as tarefas\n");
            
            }

    } while(opcao >= 0);

}
