#include <iostream>
#include "aabb.h"
#include <cmath>
#include<GL/gl.h>
#include<GL/glu.h>
#include <GL/glut.h>
using namespace std;
void displayMe();
void drawCircle(float cx, float cy, float r, int num_segments);
void drawRect(AABB aabb);
void drawRotatedRect(OBB obb);
void displayCircleMode();
void displayAABBMode();
int mouse_x, mouse_y,clicks = 0;
std::vector<Vec2> p;

double theta = 0;
//setando os colisores aqui
Circle c = Circle(Vec2(470,300), 70);
Circle mouseC = Circle(Vec2(mouse_x,mouse_y),30);
OBB o = OBB(Vec2(1,-1),Vec2(1,1),Vec2(300,300),Vec2(70,70));
AABB a = AABB(Vec2(80,200),Vec2(120,300));
AABB mouseAABB = AABB(Vec2(mouse_x - 15,mouse_y - 15), Vec2(mouse_x + 15, mouse_y + 15));
double viewWidth = 600;
double viewHeight = 600;
void mouseMove(int x, int y){
    mouse_x = x; mouse_y = y;
    mouseC.setCenter(Vec2(x,y));
    mouseAABB.setMax(Vec2(mouse_x + 15, mouse_y + 15));
    mouseAABB.setMin(Vec2(mouse_x - 15,mouse_y - 15));
    displayMe();
}

void My_mouse_routine(int b,int button,int x, int y)
{

glClear(GL_COLOR_BUFFER_BIT);
    if(button == GLUT_UP){
    clicks++;
    }

    //displayMe();

}

int main(int argc, char** argv)
{
    p.reserve(30);


    std::cout << o.intercepts(c) << std::endl;
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE);
    glutInitWindowSize(viewWidth, viewHeight);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Collision");
    glutMouseFunc( My_mouse_routine );
    glutPassiveMotionFunc(mouseMove);
    //glutMotionFunc(mouseMove);
    glOrtho( 0.f, viewWidth, viewHeight, 0.f, 0.f, 1.f );//comando magico para usar metafora desktop
    glutDisplayFunc(displayMe);

    glutMainLoop();

    return 0;
}
void displayMe(void){
    Vec2 closeA,closeO,closeC;
    glClear(GL_COLOR_BUFFER_BIT);
    closeA = a.closestAABBPoint(Vec2(mouse_x,mouse_y));
    closeO = o.closestOBBPoint(Vec2(mouse_x,mouse_y));
    closeC = c.closestCirclePoint(Vec2(mouse_x,mouse_y));
    //desenha bolinhas
    glColor3f(0.8f,0.0f,0.0f);
    drawCircle(closeA.getX(),closeA.getY(),2,10);
    drawCircle(closeO.getX(),closeO.getY(),2,10);
    drawCircle(closeC.getX(),closeC.getY(),2,10);
    switch(clicks%2){
        case 0:{
            displayCircleMode();
            break;
        }
        case 1:{
            displayAABBMode();
            break;
        }
    }

}
void displayCircleMode(){
    //Caso esteja se perguntando, sim. Eu podia ter usado bit mask. :<
    if(mouseC.intercepts(a) || mouseC.intercepts(o) || mouseC.intercepts(c))
        glColor3f(0.0f,1.0f,0.0f);
    else
        glColor3f(0.70f,0.70f,0.70f);
    drawCircle(mouseC.getCenter().getX(), mouseC.getCenter().getY(),mouseC.getRadius(),20);
    if(mouseC.intercepts(a))
        glColor3f(0.0f,1.0f,0.0f);
    else
        glColor3f(0.70f,0.70f,0.70f);
    drawRect(a);

    if(mouseC.intercepts(c))
        glColor3f(0.0f,1.0f,0.0f);
    else
        glColor3f(0.70f,0.70f,0.70f);
    drawCircle(c.getCenter().getX(), c.getCenter().getY(),c.getRadius(),20);

    if(mouseC.intercepts(o))
        glColor3f(0.0f,1.0f,0.0f);
    else
        glColor3f(0.70f,0.70f,0.70f);
    drawRotatedRect(o);
}
void displayAABBMode(){
    if(mouseAABB.intercepts(a) || mouseAABB.intercepts(o) || mouseAABB.intercepts(c))
        glColor3f(0.0f,1.0f,0.0f);
      else
        glColor3f(0.70f,0.70f,0.70f);
    drawRect(mouseAABB);
    if(mouseAABB.intercepts(a))
        glColor3f(0.0f,1.0f,0.0f);
    else
        glColor3f(0.70f,0.70f,0.70f);
    drawRect(a);

    if(mouseAABB.intercepts(c))
        glColor3f(0.0f,1.0f,0.0f);
    else
        glColor3f(0.70f,0.70f,0.70f);
    drawCircle(c.getCenter().getX(), c.getCenter().getY(),c.getRadius(),20);

    if(mouseAABB.intercepts(o))
        glColor3f(0.0f,1.0f,0.0f);
    else
        glColor3f(0.70f,0.70f,0.70f);
    drawRotatedRect(o);
}
void drawRect(AABB aabb)
{


    glBegin(GL_POLYGON);

        glVertex3f(aabb.getMin().getX(), aabb.getMin().getY(), 0.0);
        glVertex3f(aabb.getMax().getX(), aabb.getMin().getY(), 0.0);
        glVertex3f(aabb.getMax().getX(), aabb.getMax().getY(), 0.0);
        glVertex3f(aabb.getMin().getX(), aabb.getMax().getY(), 0.0);
    glEnd();
    glFlush();

}
void drawRotatedRect(const OBB obb){

    double theta = obb.getAxisY().angleBetween(Vec2(1,0));


    double centerX = obb.getCenter().getX();
    double centerY = obb.getCenter().getY();
    double distX = obb.gethDist().getX();
    double distY = obb.gethDist().getY();

    glPushMatrix();
    glTranslatef(centerX,centerY,0.0f);
    glRotatef(theta,0.0f,0.0f,1.0f);

    glBegin(GL_POLYGON);

        glVertex3d(-distX, -distY, 0.0);
        glVertex3d(distX, -distY, 0.0);
        glVertex3d(distX, distY, 0.0);
        glVertex3d(-distX, distY, 0.0);
    glEnd();
    glPopMatrix();

    glFlush();



}
void drawCircle(float cx, float cy, float r, int num_segments)
{
    glBegin(GL_TRIANGLE_FAN);
    for(int ii = 0; ii < num_segments; ii++)
    {
        float theta = 2.0f * 3.1415926f * float(ii) / float(num_segments);//get the current angle

        float x = r * cos(theta);//calculate the x component
        float y = r * sin(theta);//calculate the y component


        glVertex2f(x + cx, y + cy);//output vertex

    }
    glEnd();
    glFlush();
}
