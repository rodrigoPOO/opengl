/* 
 * File:   UtilidadesGLUT.cpp
 * Author: rr
 * 
 * Created on 2 de Julho de 2015, 21:36
 */

#include "UtilidadesGeom.h"
#include "GL/freeglut.h"
#include <stdio.h>
#include <stdlib.h>
#include "GL/glx.h"
#include "GL/glut.h"
#include "GL/glu.h"
#include <iostream>
#include <math.h>

UtilidadesGeom::UtilidadesGeom() {
}


UtilidadesGeom::~UtilidadesGeom() {
}

void UtilidadesGeom::desenhaEsfera(float raio){
    
    glutSolidSphere(raio,32,32);
    
}

void UtilidadesGeom::desenhaCilindro(float raioBase, float raioTopo, float altura){
    GLUquadricObj* quad = gluNewQuadric();
    gluQuadricDrawStyle(quad,GLU_FILL);    
    gluQuadricOrientation(quad,GLU_INSIDE);
    //glTranslatef(0,0,PROFUNDIDADE);
    glRotatef(90, 1, 0, 0); 
    
    gluCylinder(quad, raioBase, raioTopo, altura, 32, 32);     
    
    glColor3f(1, 0.2, 0.2);
}
void UtilidadesGeom::desenhaCilindroRot(float raioBase, float raioTopo, float altura,float angulo){
    GLUquadricObj* quad = gluNewQuadric();
    gluQuadricDrawStyle(quad,GLU_FILL);    
    gluQuadricOrientation(quad,GLU_INSIDE);
    //glTranslatef(0,0,PROFUNDIDADE);
    glRotatef(angulo, 1, 0, 0); 
    gluCylinder(quad, raioBase, raioTopo, altura, 32, 32); 
    
}

void UtilidadesGeom::desenhaPoligono(float p1x,float p1y, float p2x, float p2y, float p3x, float p3y, float p4x, float p4y){
    glBegin(GL_POLYGON);
/* Set the vertices */
    glVertex2d(p1x, p1y);
    glVertex2d(p2x, p2y);
    glVertex2d(p3x, p3y);
    glVertex2d(p4x, p4y);
/* Done making polygon */
    glEnd(); 
}

void UtilidadesGeom::desenhaCirculo(float raio){
    float x,y;
    float radius = 0.5f;
    glBegin(GL_LINES);
        //glColor3f(0.83, 0.55, 0.55);
        

        x = (float)raio * cos(359 * M_PI/180.0f);
        y = (float)raio * sin(359 * M_PI/180.0f);
        for(int j = 0; j < 360; j++)
        {
            glVertex2f(x,y);
            x = (float)raio * cos(j * M_PI/180.0f);
            y = (float)raio * sin(j * M_PI/180.0f);
            glVertex2f(x,y);
        }
    glEnd();
}

void UtilidadesGeom::desenhaChao(float gridX, float gridY){
    glBegin(GL_QUADS);
        glColor3f(0,1,0);
        glNormal3f(0, 1, 0);
        glVertex3f(-gridX / 2, 0, gridX / 2);
        glVertex3f(-gridX / 2, 0, -gridX / 2);
        glVertex3f(gridX / 2, 0, -gridX / 2);
        glVertex3f(gridX / 2, 0, gridX / 2);
        
    glEnd();
}



