import java.util.Scanner;

public class SIMPLETRON //Classes levam os nome em CamelCase
{

    int acc=0;
    int ip=0;
    int[] memory = new int[100];//aloca as memórias
    int posicaoExecutada=0;
    int posicao;
    int instrucao;



    void read(int position){
        Scanner input = new Scanner(System.in);//System.in = teclado
        String dado = input.nextLine();
        memory[position]= Integer.parseInt(dado);

    }

    void write(int position){

        System.out.println(memory[position]);
    }

    void load(int position){

        acc= memory[position];
    }

    void store(int position){

        memory[position] = acc;
    }

    void add(int position){

        acc= memory[position] + acc;// acc+=memory[position]
    }

    void subtract(int position){
        acc=memory[position] - acc;

    }
    void multiply(int position){

        acc *= memory[position];
    }

    void divide(int position){

        acc /= memory[position];
    }

    void branch(int position){

        posicaoExecutada = position;
    }
    void branchneg(int position){
        if (acc < 0)
            posicaoExecutada = position;
    }
    void branchzero(int position){
        if (acc == 0)
            posicaoExecutada = position;
    }
    void halt (int position){
        System.out.printf("\n%s\n", "The program has ended...");
        System.exit(0);// sai do programa
    }

    /////////////////////////////////////
    public void run(){

        System.out.printf ("\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s %s\n%s %s\n",
                "*** Bem vindo ao Simpletron!                  ***",
                "*** Por favor insira uma instrução por vez    ***",
                "*** em seu programa. Eu vou digitar o número  ***",
                "*** de alocação e o ponto de interrogação (?) ***",
                "***Então você digita a palavra para a alocação***",
                "***Digite o número -9999 para parar e         ***",
                "*** indicar o fim do seu programa.            ***",
                " Loc", " Inst", "****", "*****");


        int dado = 0;
        int memoryPointer = 0;

        Scanner input = new Scanner ( System.in );

        do
        {
            System.out.printf ("%d %s  ", memoryPointer, "?" );
            dado = input.nextInt ();
            if ( dado != -9999 ) {
                memory[memoryPointer] = dado;
                memoryPointer++;    // go to the next memory location
            }

        } while ( dado != -9999 );

        System.out.printf ("\n%s%s", "*** Program loading completed ***\n",
                "*** Program execution begins  ***\n");
///////////////////////////
        int count = 0;/*f
        for (int i = 0; i < memory.length; i++) {
            if (i == 50) {//dividir a memoria do computador em 2
                break;
            }
            int code = memory[i];
        }
        */
        for ( int code : memory )//criar ponto de parada no programa
        {
            if (count == 50) {//dividir a memoria do computador em 2
                break;
            }
            if ( code != 0)
            {
                instrucao = memory [ posicaoExecutada ] / 100;
                posicao = memory [ posicaoExecutada ] % 100;
                instrucoes ( instrucao, posicao );
            }
            count++;
        }
/////////////////////////////
    }	// end method runSimulator


    public void instrucoes(int instrucao, int posicao){
            switch(instrucao) {
                case 10:
                    read(posicao);
                    break;
                case 11:
                    write(posicao);
                    break;
                case 20:
                    load(posicao);
                    break;
                case 21:
                    store(posicao);
                    break;
                case 30:
                    add(posicao);
                    break;
                case 31:
                    subtract(posicao);
                    break;
                case 32:
                    divide(posicao);

                    break;
                case 33:
                    multiply(posicao);
                    break;
                case 40:
                    branch(posicao);
                    break;
                case 41:
                    branchneg(posicao);
                    break;
                case 42:
                    branchzero(posicao);
                    break;
                case 43:
                    halt(posicao);
                    break;
            }
            posicaoExecutada++;


        }

        public static void main (String[] args){
            SIMPLETRON x = new SIMPLETRON(); //criando objeto para fazer funcao funcionar em static
            x.run();
        }

}



