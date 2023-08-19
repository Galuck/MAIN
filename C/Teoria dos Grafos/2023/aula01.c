// grafo: é um par de conjuntoso primeiro desses conjuntos são os vértices V, aleatórios e não ordenados
// o segundo conjunto, Arestas A, são pares de vértices. Partes de valores que pertencem ao primeiro conjunto.

//{V,A}
//V={1,2,4,6,5...}
//A={(1,2), (2,4), (4,6)...}

//Qual a diferença de grafos e arvores?
//para que um grafo seja uma árvore, se a quandidade de arestas é igual a quantidade de vértices -1, é uma arvore
//Nao pode existir ciclos

//toda arvore é um grafo VERDADEIRO
//nem todo Grafo é uma arvore FALSO

//Duas formas de representar um grafo:
//Matriz de adjacência
//Lista de adjacência

//     (A)----(B)
//      \      /
//       \    /
//        (C)
//         
//        (D) 
//  2 componente conectado
//*dois vertices A B pertencem a um mesmo componente conectado quando eu consigo ir de A para B e de B para A.
//(nao tem caminho) (numero de ilhas)
//
//
//

//Existe uma classificassão que denomina grafos direcionais e grafos não direcionais
////////////////////////////////
//Grafos NÃO direcionais que representam as duas direções (sem seta)
//Grados direcioais tem seta, mostra o caminho exato de cada seta. (aresta tem direção)
//**Um vértice por si só já pode ser considerado um componente conectado,

//VAI TER QUESTÃO DE QUANTIDADE DE COMPONENTES CONECTADOS


// Matriz de adjacencia tem muito zero, num geral é meio inutil porque é espaço inutil

//Lista de Adjacência
//A: B
//B: C
//C: D
//D: A


//Para fazer uma matriz de adjacencia 
// declarar tamanho da matriz, definir pelo numero de vértices
//tamanho da minha matriz é a quantidade de vertices ao quadrado
//ler vertice por vértice, não pode repetir, para descobrir a quantidade de vértices
//declarar vetor grande
//A tá no vetor? não, coloca ele
//percorre todo o input um por um e checar se esse input já está no vetor (fazer isso dentro de um for)
//declara a matriz com o tamanho do vetor resultante? ou com um tipo de count.

//CADA VÉRTICE É UM INDICE NO VETOR ORIGINAL, ISSO SE CHAMA FAZER UM MAPEAMENTO
//ver cada conexão e ir adicionando elas uma por uma na matriz.


//PARA FAZER CÓDIGO DE LISTA DE ADJACÊNCIAS, APRENDER LISTA LIGADA E FAZER UMA ESTRUTURA COM NEXT/PROXIMO
//FAZER UM VETOR COM ESSAS STRUCTS
//Essas structs não representam ordem de conexão, só o que está ligado nela.











