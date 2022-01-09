package gameLogic;

import java.awt.Color;
import java.awt.Graphics;
import java.awt.Rectangle;

public class Bullet extends Rectangle{
	
	public int dir =1;
	public int speed =8;
	
	public int frames = 0;//timer
	
	
	
	public Bullet(int x, int y, int dir) {
		super (x+16,y+16,10,10);
		this.dir = dir;
	}

	public void tick() {
		x+=speed*dir;
		frames++;
		if (frames==60) {//60 fps-> 1 seg
			Player.bullets.remove(this);
			return;
		}
	}

	public void render(Graphics g) {
		
		g.setColor(Color.red);
		g.fillOval(x, y, width, height);
		
	}
}
