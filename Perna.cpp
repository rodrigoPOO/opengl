/* 
 * File:   Perna.cpp
 * Author: rr
 * 
 * Created on 2 de Julho de 2015, 20:26
 */

#include <iostream>

#include "Perna.h"
#include "GL/freeglut.h"

#include "GL/glx.h"
#include "GL/glut.h"
#include "GL/glu.h"


#define ALTPERNA 1
#define ALTCANELA 1
#define TAMARTQUADRIL 0.3
#define COR_PERNA 0.75, 0.75, 0.75
#define RAIO_PE 0.75
#define LARGCOXA 1
#define ALTCOXA 1.25
#define COR_PE_MAO 1.0, 0.0, 1.0
#define ALTURABRACO 1.5
#define ALTURABRACOINFERIOR 1.5




Perna::Perna() {
}


Perna::~Perna() {
}

void Perna::setAngulosCaminhada(){
   angulosP.clear();
   angulosJ.clear();
   angulosV.clear();
   vector<float> anguloPe1 = {0,  0, 25, -20, 20, 40 ,0};
   vector<float> anguloPe2 = {0,  20, 30, 0, 0, 20, 35, 20};
   angulosP.push_back(anguloPe1);
   angulosP.push_back(anguloPe2);
   
   vector<float> anguloJoelho1 = {0, 0, 40, 25, -10, 0 ,0};
   vector<float> anguloJoelho2 = {0, -10, 5, 0, 10, 40, 25} ;
   angulosJ.push_back(anguloJoelho1);
   angulosJ.push_back(anguloJoelho2);
   
   
   vector<float> anguloVirilha1 = {0, 15, -25, -55, -25, -30 , 0};
   vector<float> anguloVirilha2 = {0, -25, -30, 0, 15, -25,-55};
   angulosV.push_back(anguloVirilha1);
   angulosV.push_back(anguloVirilha2);
   
    
}

void Perna::setAngulosCorrida(){
  
   angulosP.clear();
   angulosJ.clear();
   angulosV.clear();
   vector<float> anguloPe1 = { 0, 0, 0, -5, 10, 0};
   vector<float> anguloPe2 = { 0, 0, -20, 0, 30, 20};
   angulosP.push_back(anguloPe1);
   angulosP.push_back(anguloPe2);
   
   vector<float> anguloJoelho1 = { 0, 0, 40, -35, -25, 0};
   vector<float> anguloJoelho2 = { 0,-15, 50, 30, 50, 25};
   angulosJ.push_back(anguloJoelho1);
   angulosJ.push_back(anguloJoelho2);   
   
   vector<float> anguloVirilha1 = { 0, 45, 10, -45, -25, 0};
   vector<float> anguloVirilha2 = { 0, -35, -20, 25, 15, 5};
   angulosV.push_back(anguloVirilha1);
   angulosV.push_back(anguloVirilha2);
     
}


void Perna::desenhaPerna(int momento,int lado){
    
    glPushMatrix();
    
    //glRotatef(angulosVirilha[lado][momento],1,0,0);
    glRotatef(angulosV[lado][momento],1,0,0);
    desenhaCoxa();
    glTranslatef(0.0,-ALTCOXA*1.25,0.0);
    desenhaJoelho(0);
    glRotatef(angulosJ[lado][momento],1,0,0);
    glTranslatef(0.0,-RAIO_PE*0.5,0.0);
    desenhaCanela();
    glTranslatef(0.0,-ALTCANELA*1.25,0.0);
    glColor3f(COR_PE_MAO);
    glutSolidSphere(RAIO_PE/2.,8,8);    
    glRotatef(angulosP[lado][momento],1,0,0);
    desenhaPe();
    glPopMatrix();
    
 
    
    
}
void Perna::desenhaCoxa(){
    glPushMatrix();
        glColor3f(COR_PE_MAO);    
        glutSolidSphere(RAIO_PE/2.,8,8);    
        glTranslatef(0.0, - ALTCOXA*0.25, 0.0);    
        glColor3f(COR_PERNA);    
        ug.desenhaCilindro(LARGCOXA/2.,LARGCOXA/2.,ALTCOXA);        
    glPopMatrix();
}


void Perna::desenhaCanela(){
    glPushMatrix();
    glColor3f(COR_PERNA);
    ug.desenhaCilindro(LARGCOXA/2.,LARGCOXA/2.,ALTCANELA);
    glPopMatrix();
}

void Perna::desenhaJoelho(int lado){
    glPushMatrix();
    glColor3f(COR_PE_MAO);
    glScalef(TAMARTQUADRIL,TAMARTQUADRIL,TAMARTQUADRIL);
    glutSolidSphere(1.0,8,8);
    glPopMatrix();
    
    
}

void Perna::desenhaPe(){
    glPushMatrix();
    glColor3f(COR_PE_MAO);
    //glRotatef(45,1,1,0);
    //glutSolidSphere(RAIOMAO,32,32);
    ug.desenhaCilindro(RAIO_PE*0.5,RAIO_PE,0.5);
    
    glPopMatrix();
   
    
}

float Perna::calculaDeslocamentoHorizontal(int momento){
    if(momento != 0){
        float alturaPerna = 0.75;
        float anguloV1 = (angulosV[1][momento]*M_PI)/180.0;
        //float anguloJ1 = (angulosJ[1][momento]*M_PI)/180.0;
        float pernaSuperior1 = (ALTCOXA*0.5)*cos(anguloV1);
        
        float phi1 = (angulosV[1][momento] - angulosJ[1][momento])*M_PI/180.0;
        float pernaInferior1 = (ALTCANELA*0.5)*cos(phi1);        
        //calculo para a outra perna.
      
        float anguloV0 = (angulosV[0][momento]*M_PI)/180.0;
        //float anguloJ0 = (angulosJ[0][momento]*M_PI)/180.0;
        float pernaSuperior0 = (ALTCOXA*0.5)*cos(anguloV0);

        float phi0 = (angulosV[0][momento] - angulosJ[0][momento])*M_PI/180.0;
        float pernaInferior0 = (ALTCANELA*0.5)*cos(phi0);
        
        if(phi0 <= phi1){            
            return (alturaPerna - (pernaSuperior0+pernaInferior0));    
        }
        return (alturaPerna - (pernaSuperior1+pernaInferior1));    
    }
    return 0;
}



