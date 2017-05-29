public class Point{

  
  //fields
  private float x;
  private float y;
  
  
  public Point(float x, float y){
    this.x = x;
    this.y = y;
  }
  
  public float getX(){
    return this.x;
  }
  
  public float getY(){
    return this.y;
  }
  
  void setX(float newX){
    this.x = newX;
  }
  void setY(float newY){
    this.y = newY;
  }

}

static class PointUtils{
  public static float dist(Point a, Point b){
    float deltaX = b.getX() - a.getX();
    float deltaY = b.getY() - a.getY();
    
    return sqrt(deltaX * deltaX + deltaY * deltaY);
  }  
}