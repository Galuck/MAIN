package gameLogic;

import java.awt.Canvas;
import java.awt.Color;
import java.awt.Dimension;
import java.awt.Graphics;
import java.awt.event.KeyEvent;
import java.awt.event.KeyListener;
import java.awt.image.BufferStrategy;
import java.util.ArrayList;
import java.util.List;

import javax.swing.JFrame;

public class Game extends Canvas implements Runnable, KeyListener {
	
	//definir tamanho da tela
	public static int WIDTH = 640, HEIGHT = 480;
	
	public static int SCALE =3;
	
	public static Player player; //tem que estar static para ser acesado
	
	public World world;
	
	public List<Inimigo> inimigos = new ArrayList<Inimigo>();
	
	
	public Game() {
		
		this.addKeyListener(this);//adiciona "eventos" de teclado
		
		//cria nova dimensao pra janela
		this.setPreferredSize(new Dimension(WIDTH,HEIGHT));
		
		new Spritesheet();
		
		player = new Player(32,32);
		world = new World();
		
		inimigos.add(new Inimigo (120, 152));
		
		inimigos.add(new Inimigo (39, 300));
		
	}
	
	
	//é assim por estar fazendo do zero
	public void tick() {//Update? lógica do jogo
		player.tick();
		for(int i = 0; i< inimigos.size(); i++) {
			inimigos.get(i).tick();
		}
	}
	
	
	public void render() {
		
		//atualizar em tempo real?
		BufferStrategy bs = this.getBufferStrategy();
		
		if(bs == null) {
			this.createBufferStrategy(3);//3 ou 2
			return; //otimizar a parte gráfica
		}
		
		Graphics g = bs.getDrawGraphics();
		
		g.setColor(Color.black);
		g.fillRect(0, 0, WIDTH*SCALE, HEIGHT*SCALE);
		
	
		///PRECISA LIMPAR O BUFFER
		
		player.render(g);
		
		for(int i = 0; i< inimigos.size(); i++) {
			inimigos.get(i).render(g);
		}
		
		world.render(g);
		
		bs.show(); //mostrar gráficos na janela 
	
	}
	
	//metodo principal
	public static void main (String[] args) {
		Game game = new Game();
		JFrame frame = new JFrame();
		
		frame.add(game);
		frame.setTitle("Mini Zelda");
		
		//empacotar tudo
		frame.pack();
		
		//localizaçao da janela na tela (depois do pack)
		frame.setLocationRelativeTo(null);
		
		//quando a janela fechar, para de rodar
		frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		
		//ver a tela
		frame.setVisible(true);
		
		
		//fazer loop? chamar infinitamente para fazer as ações (Update no Unity)
		new Thread(game).start();
		//o update começa quando cria a Thread e dá start
	}
	
	@Override
	public void run() {
		while(true) {//loop infinito onde tudo acontece (tipo Update)
			
			tick();
			render();
			
			try {//vai tentar fazer isso
				Thread.sleep(1000/60);
			} catch (InterruptedException e) {
				// TODO Auto-generated catch block
				e.printStackTrace(); //erro
			}
		}
		
		
	}


	//key listener implementado
	
	@Override
	public void keyTyped(KeyEvent e) {
		// TODO Auto-generated method stub
		
	}


	@Override
	public void keyPressed(KeyEvent e) {
		// TODO Auto-generated method stub
		if(e.getKeyCode()==KeyEvent.VK_RIGHT) {
			player.right=true;
		}
		else if(e.getKeyCode()==KeyEvent.VK_LEFT) {
			player.left=true;
		}
		else if(e.getKeyCode()==KeyEvent.VK_UP) {
			player.up=true;
			
		}
		else if(e.getKeyCode()==KeyEvent.VK_DOWN) {
			player.down=true;
		}
		
		if(e.getKeyCode()== KeyEvent.VK_Z) {
			player.shoot=true;
		}
	}


	@Override
	public void keyReleased(KeyEvent e) {
		if(e.getKeyCode()==KeyEvent.VK_RIGHT) {
			player.right=false;
		}
		else if(e.getKeyCode()==KeyEvent.VK_LEFT) {
			player.left=false;
		}
		else if(e.getKeyCode()==KeyEvent.VK_UP) {
			player.up=false;
			
		}
		else if(e.getKeyCode()==KeyEvent.VK_DOWN) {
			player.down=false;
		}
	}

	
	
}
