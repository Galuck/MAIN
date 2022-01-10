package pong;

//imports
import java.awt.Canvas;
import java.awt.Color;
import java.awt.Dimension;
import java.awt.Graphics;
import java.awt.event.KeyEvent;
import java.awt.event.KeyListener;
import java.awt.image.BufferStrategy;
import java.awt.image.BufferedImage;

import javax.swing.JFrame;

public class Game extends Canvas implements Runnable, KeyListener{

	
	/**
	 * 
	 */
	private static final long serialVersionUID = 1L;//só pra tirar o aviso
	public static int WIDTH = 240;
	public static int HEIGHT =120;
	public static int SCALE=3;
	
	
	public BufferedImage layer = new BufferedImage(WIDTH,HEIGHT,BufferedImage.TYPE_INT_RGB);//onde vai ser renderizado
	
	
	public static Enemy enemy;
	public static Player player;
	public static Ball ball;
	
	public Game() {
		this.setPreferredSize(new Dimension(WIDTH*SCALE,HEIGHT*SCALE));
		this.addKeyListener(this);
		
		player =new Player(100, HEIGHT-5);//-10 pq é a altura dele
		enemy = new Enemy(100,0);
		ball = new Ball(100, HEIGHT/2 -1);
		
	}
	public static void main (String[]args) {///////////////////////////////////
		
		Game game = new Game();
		
		
		JFrame frame = new JFrame();
		frame.setResizable(false); // não pode mexer no tamnho da tela
		frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);//não continua rodando apos fechar
		
		
		frame.add(game);
		frame.pack();
		//tem q ser depois de adicionar o game e o pack
		frame.setLocationRelativeTo(null); //centro da tela
		
		
		frame.setVisible(true);
		
		
		new Thread(game).start();
		
		}
	
	
	public void tick() {
		
		player.tick();
		enemy.tick();
		ball.tick();
	}
	
	public void render() {
		BufferStrategy bs = this.getBufferStrategy();
		if(bs==null) {
			this.createBufferStrategy(3);//3 para rodar liso
			return;
		}
		
		Graphics g= layer.getGraphics();		
		g.setColor(Color.black);
		g.fillRect(0, 0, WIDTH, HEIGHT);
		player.render(g);
		enemy.render(g);
		ball.render(g);
		
		g= bs.getDrawGraphics();
		g.drawImage(layer, 0, 0, WIDTH*SCALE, HEIGHT*SCALE,null);
		
		bs.show();
	}
	
	@Override //
	public void run() {
		
		while(true) {
			render();
			tick();	
			
			try {//try e catch pq pode falhar
				Thread.sleep(1000/60);
			} catch (InterruptedException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}//60 fps
		}
		
	}
	@Override
	public void keyTyped(KeyEvent e) {
		
	}
	@Override
	public void keyPressed(KeyEvent e) {
		
		if(e.getKeyCode() == KeyEvent.VK_RIGHT) {
			player.right=true;
		}else if(e.getKeyCode()==KeyEvent.VK_LEFT) {
			player.left=true;
		}
	}
	@Override
	public void keyReleased(KeyEvent e) {
		// TODO Auto-generated method stub
		if(e.getKeyCode() == KeyEvent.VK_RIGHT) {
			player.right=false;
		}else if(e.getKeyCode()==KeyEvent.VK_LEFT) {
			player.left=false;
		}
	}

}
