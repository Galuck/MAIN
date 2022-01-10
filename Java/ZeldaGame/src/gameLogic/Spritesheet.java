package gameLogic;

import java.awt.image.BufferedImage;
import java.io.IOException;

import javax.imageio.ImageIO;

public class Spritesheet {

	public static BufferedImage spritesheet;
	
	public static BufferedImage[] player_front;
	
	public static BufferedImage[] inimigo_front;
	
	public Spritesheet() {
		
		try { //tentar
			
			
			spritesheet=ImageIO.read(getClass().getResource("/spritesheet.png"));
		} catch (IOException e) {//caso dê algo errado
			
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		player_front = new BufferedImage[2];
		inimigo_front = new BufferedImage[2];
	
		player_front[0] = Spritesheet.getSprite(5, 16, 16, 16);
		player_front[1] = Spritesheet.getSprite(22, 16, 16, 16);
		
		//79 246
		inimigo_front[0] = Spritesheet.getSprite(79, 246, 16, 16);
		inimigo_front[1] = Spritesheet.getSprite(96, 246, 16, 16);
		
	}
	
	public static BufferedImage getSprite(int x, int y, int width, int height) {
		
		return spritesheet.getSubimage(x, y, width, height);
		
	}
	
	
	
	
}
