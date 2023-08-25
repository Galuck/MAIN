//componentes fortemente conectados e fracamente conectados só existem em grafos direcionais (com seta)
//Todos os grafos não direcionais são fracamente conectados

//A--->B

//fortemente conectados eu levo em consideração a seta
//fracamente conectados eu não levo em considetação a seta

//2 tipos de busca, assim como em arvore, busca em profundidade e busca em largura

///////////////////DFS (profundidade)
//partindo da raiz do grafo, segue uma direção de busca e pesquisa nessa direção até não poder mais
//exemplo ilustrado no caderno vermelho

//ao fazer uma busca assim, a primeira coisa que tem que fazer é uma lista de adjacencia do grafo. (montar a lista)
//depois, criar um vetor 'visitado' (tamanho deve ser a quantidade de vertices +1, para usar o próprio vertice como indice)
//(não tem problema nenhum o "vertice 0" ser vazio)

//dfs(1); vai percorrer a lista de adjacencia do vertice 1, se o vertice 2 n foi visitado.
//ao chegar no valor 2 (exemplo no caderno), ele nao foi visitado, entao dfs será chamado recursivamente, até acabar
//ao terminar as listas de adjacencia, o dfs vai voltar a recursividade um por um
//só vai chamar a recursividade se o vertice nao foi visitado ainda.

//PS: a raiz pode ser QUALQUER vertice.

//exemplo DFS no github Rambim 2023_2 (contagem_componentes e dfs), e também em 2022_2 dfs








////////////////////BFS (largura)
//
// exemplo ilustrado no caderno vermelho


