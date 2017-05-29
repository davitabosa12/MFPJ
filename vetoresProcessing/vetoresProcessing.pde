/*DAVI BATISTA TABOSA
 *MATEMATICA E FISICA PARA JOGOS
 */

import java.util.ArrayList;
import java.util.Collections;
import java.awt.Color;

Point buttonPos; //posicao do botao
Point mousePos; //posicao do mouse
Vec2 res; //vetor resultante
ArrayList<Vec2> vetores; //array de vetores para serem desenhados na tela


Color rainbow[]; //array de cores



int fsm; //maquina de estados

ArrayList<Point> vecBuffer; //array que armazena vetor temporario, para ser armazenado no array de vetores
int presses = 0; //numero de cliques do mouse
void setup() {
  rainbow = new Color[]{Color.RED, Color.ORANGE, Color.YELLOW, Color.BLACK, Color.GREEN, Color.CYAN,Color.DARK_GRAY};
  vetores = new ArrayList<Vec2>();
  vecBuffer = new ArrayList<Point>();
  size(800, 800);
  buttonPos = new Point(width - 200, height - 200); 
}


int x = 0;

void draw() {
  mousePos = new Point(mouseX,mouseY);
  
  background(255);
  drawButton(buttonPos); //desenha o botao
  switch(fsm) {
  case 0: //MODO DE EDICAO
    {
      if (presses > 0)
      {
        if (vetores.size() >=2) //se tiver mais de 2 vetores na tela
          drawResultante(); //desenhe a resultante

        Vec2 temp = new Vec2(vecBuffer.get(0), new Point(mouseX, mouseY), rainbow[presses%7]); //vetor temporario que sera redesnhado na tela ate que o usuario confirme
        temp.drawArrow(); //desenha vetor temporario
        for (Vec2 vetor : vetores) {
          vetor.drawArrow(); //desenha todos os vetores salvos
        }
      }
    }

  case 1: //MODO ALEATORIO
    {
      if (buttonPressed()) {
        if(!vetores.isEmpty())
          shuffleVectors(); //<>//
      }
      for (Vec2 vetor : vetores) {
        vetor.drawArrow();
      }
      drawResultante();
    }
  }
}

void mousePressed() {
  if(mouseOver()){
    fsm = 1;
  }
  else
    fsm=0;
  
  if (fsm == 0) {
    presses++;
    vecBuffer.add(new Point(mouseX, mouseY));

    if (vecBuffer.size() == 2) {
      vetores.add(new Vec2(vecBuffer.get(0), vecBuffer.get(1), rainbow[presses%7]));
      vecBuffer.remove(0);
    }
  }
}

void keyPressed() {
  if (keyCode == ENTER || keyCode == RETURN)
    fsm = 1;
}

void drawResultante() {
  if (!vetores.isEmpty()) {
    stroke(75,0,130);
    int tam = vetores.size();
    res = new Vec2(vetores.get(0).getInit(), vetores.get(tam-1).getEnd(),new Color(75,0,130));
    res.drawArrow();
    stroke(0);
  }
}

void drawButton(Point pos){
  
  fill(140,60,12);
  
  if(mouseOver()){
    fill(60,150,20);
    if(mousePressed){
      fill(12,60,140);
    }
  }else{
    fill(140,60,12);
  }
  noStroke();
  ellipse(pos.getX(), pos.getY(), 100, 100);
  fill(0);
  textAlign(CENTER);
  text("RANDOM",pos.getX(),pos.getY());
}

boolean buttonPressed(){
  
  return mouseOver() && mousePressed;
}

boolean mouseOver(){
  return (PointUtils.dist(buttonPos,mousePos) < 50);
}

void shuffleVectors(){
    Point first;
        first = vetores.get(0).getInit();
        Collections.shuffle(vetores);
        vetores.get(0).setInit(first);
        for (int i = 1; i < vetores.size(); i++) {
          Vec2 vetor = vetores.get(i);
          vetor.setInit(vetores.get(i-1).getEnd());
        }
}