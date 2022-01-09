package gameLogic;

import java.awt.image.BufferedImage;
import java.io.IOException;

import javax.imageio.ImageIO;

public class Spritesheet {

	public static BufferedImage spritesheet;
	
	public static BufferedImage[] player_front;
	
	public Spritesheet() {
		
		try { //tentar
			
			
			spritesheet=ImageIO.read(getClass().getResource("/spritesheet.png"));
		} catch (IOException e) {//caso dê algo errado
			
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		player_front = new BufferedImage[2];
	
		player_front[0] = Spritesheet.getSprite(0, 11, 16, 16);
		player_front[1] = Spritesheet.getSprite(16, 11, 16, 16);
	}
	
	public static BufferedImage getSprite(int x, int y, int width, int height) {
		
		return spritesheet.getSubimage(x, y, width, height);
		
	}
	
	
	
	
}
