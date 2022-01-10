package gameLogic;

import java.awt.Graphics;
import java.awt.Rectangle;
import java.util.ArrayList;
import java.util.List;

public class World {

	//adicionar varios objetos com listas
	
	public static List<Blocks> blocos = new ArrayList<Blocks>();
	
	public World() {
		
		//criar blocos
		for(int xx = 0; xx< 15; xx++) {
			blocos.add(new Blocks(xx*32,0));
		}
		for(int xx = 0; xx< 15; xx++) {
			blocos.add(new Blocks(xx*32,480-32));
		}
		for(int yy = 0; yy< 15; yy++) {
			blocos.add(new Blocks(0,yy*32));
		}
		for(int yy = 0; yy< 15; yy++) {
			blocos.add(new Blocks(640-32,yy*32));
		}
		
		
		blocos.add(new Blocks(160,80));
	}
	
	public static boolean isFree(int x, int y) {
		for(int i = 0; i<blocos.size(); i++ ) {
			Blocks blocoAtual = blocos.get(i);
			if(blocoAtual.intersects(new Rectangle(x,y,32,32))){
				return false;//colidiu
			}
		}
		
		return true;//nao colidiu
	}
	
	
	
	
	public void render(Graphics g) {
		for(int i=0; i < blocos.size(); i++) {
			blocos.get(i).render(g);//renderizar blocos
		}
	}
}
