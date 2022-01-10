package gameLogic;

import java.awt.Graphics;
import java.awt.Rectangle;
import java.util.ArrayList;
import java.util.List;

public class Player extends Rectangle{//rectangle pode manipular vetores e detectar colisão
	
	public int spd = 4;
	public boolean right, up, down, left;
	
	public boolean shoot = false;
	
	public int dir=1;
	
	public int curAnimation=0;
	
	public int curFrames =0, targetFrames=15;
	
	public static List<Bullet> bullets = new ArrayList<>();
	
	
	public Player (int x, int y) {
		super(x,y, 40, 50);
	}

	public void tick() {
		
		boolean moved =false;
		
		if(right && World.isFree(x+spd, y)) {
			x+=spd;
			moved =true;
			dir=1;
		}
	
		else if(left && World.isFree(x-spd, y)) {
			x-=spd;
			moved =true;
			dir=-1;
		}
		if(up && World.isFree(x, y-spd)) {
			y-=spd;
			moved =true;
		}
		else if(down && World.isFree(x, y+spd)) { //por algum motivo, tá invertido 
			y+=spd;
			moved =true;
		}
		if(moved) {	
			curFrames++;
			if(curFrames == targetFrames) {
				curFrames=0;
				curAnimation++;
				if(curAnimation==Spritesheet.player_front.length) {
					curAnimation=0;
				}
			}
		}
		
		if(shoot) {
			shoot=false;
			
			//bullet
			bullets.add(new Bullet(x,y, dir));
		}
		
		for(int i =0; i < bullets.size(); i++) {
			bullets.get(i).tick();
		}
	}
	
	public void render(Graphics g) {
		//g.setColor(Color.blue);
		//g.fillRect(x,y, width, height);
		
		
		g.drawImage(Spritesheet.player_front[curAnimation],x,y,32,32,null);
		
		
		for(int i =0; i < bullets.size(); i++) {
			bullets.get(i).render(g);
		}
	}
}
