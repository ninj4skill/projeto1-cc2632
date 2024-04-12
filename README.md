# projeto2 de deselvolvimento de algoritmos cc2632
Linguagem = C
Programa para gerenciar uma lista de tarefas, com sua prioridade, categoria e descrição com um limite de 100 tarefas
O usuário pode criar, deletar e listar tarefas de uma categoria
O usuário também possui as opções de carregar e salvar as tarefas em um arquivo binário e também exportar tarefas de um categoria para um arquivo de texto simples
O programa começa apresentando um menu com todas as opções disponíveis para o usuário, e perguntando qual opção ele deseja, sendo essa opção de 1 a 6 
Para sair do programa o usuário deve colocar opção 0
Caso o usuário escolha algo uma opção acima de 6 ele receberá o erro "opção inválida" e voltará para o menu, o mesmo acontece com os outros erros.
As opçãoes consistem de:
1- carregar tarefas = carrega as tarefas armazenadas em um arquivo binário
2 - criar tarefas = cria uma nova tarefa pedindo sua prioridade, categoria e descrição
3 - deletar tarefas = deleta uma tarefas com base na posição dela no array tarefas
4 - listar tarefas = lista as tarefas de uma categoria especifica, caso nenhuma categoria seja pedida ele irá listar todas as tarefas
5 - exportar tarefas = exporta as tarefas de uma categoria especifica para um arquivo texto simples cujo nome está a escolha do usuário
6 - salvar tarefas = salva as tarefas em um arquivo binário