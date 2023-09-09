//SSSP

//  calcular as distancias
//escolher vértice de origem e setar a distância dele como -1, porque quando ler a distância dele pra ele mesmo vai ser 0
//a distância de um ponto vai ser sempre a distância do pai +1 (cada vértice vai ter a sua distância)
//fazer isso tudo ainda com o DFS, mas agora o pai vai ajudar a medir as distâncias

//void dfs(int vertice, int distancia){//SÓ PRA ÁRVORE

//  visitados[vertice]=1            //atualiza o vertice novo como visitado
//  distancias[vertice]=distancia   //atualiza a distância de cada vértice
//  for(lista.filho){//percorrer lista de adjacencias
//      if(filho!visitado){//se o filho não foi visitado
//          dfs(filho,distancia+1);
//      }

//  }

    
//}



//BIPARTIDO

//vertices vão ser classificados em dois tipo  (qualquer coisa, vermelho e azul, sla)
//formando dois conjuntos de vértices(cada um dos vértices pertence a um dos dois conjuntos)

//qualquer aresta de um grafo bipartido TEM que conectar vertices de conjuntos DIFERENTES (conectam azul com vermelho)
//vai definir os conjuntos percorrendo a lista de adjacência e ir alternando as cores a cada vértice (fodase a primeira cor, tanto faz)
//(escolher raiz tbm)
//percorrendo a lista:
//o vértice já foi visitado?-> a cor é igual ou diferente da cor do vértice pai? se for diferente, segue, se igual, grafo n é bipartido

//VAI TER QUESTAO NA PROVA PRA SABER SE É BIPARTIDO OU NÃO

//na chamada da função multiplicar por -1 pra ir alternando entre as cores (azul e vermelho)




//BFS

//percorrer lista de adjacencia inteira antes de ir pro próximo (diferente do BFS que vai pulando de lista em lista)
//enquanto percorre a lista, vai colocando os itens na fila
//incluir todos os não visitados na fila enquanto percorre a lista de adjacência da Raiz


//AQUELE EXERCÍCIO VAI CAIR NA PROVA (FIRESCAPE)

//quantos componentes conectados.
//"sobrou algum vértice que ainda não foi visitado? se sim, chamar dfs dnv e adicionar a qtd de componentes conectados"