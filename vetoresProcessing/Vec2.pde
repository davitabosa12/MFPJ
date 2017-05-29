class Vec2 {

  //fields
  private Point init;
  private Point end;
  private float r;
  private float theta;
  private Color c;
  //constructor
  public Vec2(Point init, Point end, Color c) {
    this.init = init;
    this.end = end;
    this.c = c;
    calculus();
  }
  

  private void calculus() { //Calcula a magnitude e angulo do vetor

    float deltaX, deltaY;
    deltaX = end.getX() - init.getX();

    deltaY = end.getY() - init.getY();
    deltaX = abs(deltaX);
    deltaY = abs(deltaY);
    //println(deltaX + " "+ deltaY);
    r = sqrt( deltaX * deltaX + deltaY * deltaY);

    theta = myAtan2(init,end);
  }

  public Point getInit() {
    return init;
  }
  public Point getEnd() {
    return end;
  }

  public float getRadius() {
    return r;
  }

  public float getAngle() {
    return theta;
  }

  public void setInit(Point p) { //recalcula o ponto final do vetor, dado um novo ponto inicial
    this.init = p;
    end = new Point( init.getX() + r*cos(theta), init.getY() - r*sin(theta));
  }

  public void drawArrow() { //desenha a seta do vetor
    stroke(c.getRed(),c.getGreen(),c.getBlue());
    line(init.getX(), init.getY(), end.getX(), end.getY()); //linha principal
    pushMatrix(); //matriz de transformacao em torno de um ponto
      float ang = atan2(end.getY() - init.getY(), end.getX() - init.getX()); //angulo entre dois pontos
      translate(end.getX(), end.getY()); //T(pos)
      rotate(ang); //R(theta)
      line(0, 0, -10, -10);
      line(0, 0, -10, 10);
    popMatrix(); //T(-pos)
    stroke(0);
  }
  
  private float myAtan2(Point a, Point b){ //modificar a funcao atan2() para funcionar no intervalo [0,2PI)
    float deltaX = abs(b.getX() - a.getX());

    float deltaY = abs(b.getY() - a.getY());
    
    float ang = degrees(atan2(deltaY,deltaX));
    if(b.getX() > a.getX() && b.getY() < a.getY()){
      
    } else if(b.getX() < a.getX() && b.getY() < a.getY()){
      ang = 90 + (90 - ang);
    }else if(b.getX() < a.getX() && b.getY() >= a.getY()){
      ang = 180 + ang;
    }else if(b.getX() > a.getX() && b.getY() > a.getY()){
      ang = 270 + (90 - ang);
    }
    return radians(ang);
  }
}