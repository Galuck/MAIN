#include <stdio.h>
#include <stdlib.h>

typedef struct vertice
{
    int visitado;
    int lista_adj[1000];//lista de adjacencia para cada vertice
    int tam_lista_adj;
    int in;
    int lower;
}vertice;

int count=0;//contador para iniciar o in e lower

int menor(int a, int b) ;
void dfs2(vertice * vertices, int qtd_vertices, int raiz, int pai);

int qtd_pontes=0;

int main()
{
    //p2
    int qtd_casos_teste; 

    int qtd_vertices, qtd_arestas;
    int i=0;
    int a=0;//vertice 'a'
    int b=0;//vertice 'b'
    vertice * vertices;

    //p2
    printf("\nDigite a quantidade de casos de teste:\n");
    scanf("%i", &qtd_casos_teste);

    int j=0;
    for(j=1; j<=qtd_casos_teste;j++){
        //cada vez q rodar é um caso novo

        qtd_pontes=0;//para zerar a qtd de pontes para cada caso novo

        printf("\nDigite a quantidade de vertices e arestas, respectivamente:\n");
        scanf("%d %d",&qtd_vertices, &qtd_arestas);

        vertices = (vertice*)calloc(qtd_vertices+1,sizeof(vertice));//alocando os vertices com qtd vertices

        for(i=0;i<qtd_arestas;i++)//adicionando as listas de adjacencias
        {
            scanf("%d %d",&a,&b);
            vertices[a].lista_adj[vertices[a].tam_lista_adj] = b;//adiciona na lista
            vertices[a].tam_lista_adj++;

            vertices[b].lista_adj[vertices[b].tam_lista_adj] = a;
            vertices[b].tam_lista_adj++;
        }

        dfs2(vertices,qtd_vertices,1,1);//aqui vai procurar as pontes e já vai printar direto
        // raiz e pai, vai precisar colocar a raiz de cada exercício

        free(vertices);//libera o espaço em memória dos vértices para cada caso

    }

    return 0;
}

void dfs2(vertice * vertices, int qtd_vertices, int raiz, int pai)
{
    int i;
    int filho;

    vertices[raiz].visitado = 1;// aqui vai marcar a raiz como visitada

    count++;//como é uma função recurssiva, vai ir atualizando esse valor de count

    vertices[raiz].in = count;// count é global, então vai ir atualizando o in e lower toda hora
    vertices[raiz].lower = count;


    //printf("\nValor atual de count: %i\n", count);//printando o count só pra testar     (acho que tem que zerar)
    //printf("\nValor atual de in: %i\n", vertices[raiz].in);
    //printf("\nValor atual de lower: %i\n", vertices[raiz].lower);


    for(i=0;i<vertices[raiz].tam_lista_adj;i++)//vai percorrer a lista de adjacencia da raiz
    {
        //aqui tá toda a lógica da Bridge, percorrida por DFS

        filho = vertices[raiz].lista_adj[i];//filho vai ser o vértice 'i' da lista de adjacencia da raiz

        if (filho == pai)//se o elemento é o pai, não faz nada
        {
            continue;//continua o for?/passa para o próximo
        }
        else
        {
            if (vertices[filho].visitado == 1)//se o elemento é o filho e já foi visitado, é uma back edge
            {
                //back edge (aresta que já foi visitada e que não é o pai)
                vertices[raiz].lower = menor(vertices[raiz].lower,vertices[filho].in);//atualiza o lower da raiz se o 'in' do filho for menor
            }
            else
            {
                //forward edge
                dfs2(vertices,qtd_vertices,filho,raiz);//chama a função recurssivamente, 
                //                                     // Os dois primeiros ficam iguais, mas agora o 'filho' vira a nova raiz, e a 'raiz' vira o novo pai


                //só chega aqui depois de ""retornar"" as funções recurssivas, uma por uma, quase que numa pilha 

                if (vertices[filho].lower > vertices[raiz].in)//verifica se é a ponte
                {
                    qtd_pontes++;
                    printf("\n Ponte entre %d e %d \n", raiz, filho);
                }

                vertices[raiz].lower = menor(vertices[raiz].lower, vertices[filho].lower);//atualiza o lower da raiz se o 'lower' do filho for menor
            }
        }
    }

}

int menor(int a, int b) { return a<b ? a : b;}//retorna o menor valor
