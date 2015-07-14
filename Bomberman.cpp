/* 
 * File:   Bomberman.cpp
 * Author: rr
 * 
 * Created on 2 de Julho de 2015, 20:25
 */

#include "Bomberman.h"

#include "GL/freeglut.h"
#include <stdio.h>
#include <stdlib.h>
#include "GL/glx.h"
#include "GL/glut.h"
#include "GL/glu.h"
#include <iostream>
#include <unistd.h>
#define ALTTRONCO 3.5
#define LARGTRONCO 3
#define LARGTRONCOSUP 1.25
#define LARGTRONCOINF 1.25
#define PROFUNDIDADE -5
#define ESQUERDA -1
#define DIREITA 1



Bomberman::Bomberman() {
    
}

Bomberman::~Bomberman() {
}

void Bomberman::desenharCorpo(int posX, int posY, int posZ){
   
    glPushMatrix();
        
        if(posY == 5){
            glRotatef(45,1,0,0);
            glTranslatef(0,-5,0);
        }
        glTranslatef(0,-7,0);
        ug.desenhaChao(200,200);
    glPopMatrix();
    posicionarCamera(posX,posY,posZ);
        
    if(tipoMovimento == 0){
       perna.setAngulosCaminhada();
       braco.setAnguloCaminhda();
    }else{
       perna.setAngulosCorrida();
       braco.setAnguloCorrida();
    }
    float desl = 0;
    if(tipoMovimento == 0){
       desl = perna.calculaDeslocamentoHorizontal(i);
    }
    

    glTranslatef(0,5+desl,profundidade);
     //set variaveis de rotacao da cabeça.
     cabeca.momento = i;
     cabeca.profundidade = profundidade;
     cabeca.posC_X = posX;
     cabeca.posC_Y = posY;
     cabeca.posC_Z = posZ;
    cabeca.desenhaCabeca();    
    glTranslatef(0.0,-0.75,0.0);
    
    rotacionarCorpoMovimento();
    tronco.desenhaTronco();
    glTranslatef(-LARGTRONCO*0.50,-0.35,0);
    //glTranslatef(-LARGTRONCO*0.75,-ALTTRONCO*0.15,0);
    braco.desenhaBraco(i,ESQUERDA,0);
    glTranslatef(LARGTRONCO,0.0,0);
    braco.desenhaBraco(i,DIREITA,1);
   
   glTranslatef(-0.6*LARGTRONCOINF,-ALTTRONCO,0.0);
   perna.desenhaPerna(i,0); 
   
   glTranslatef(-LARGTRONCOINF*1.25,0.0,0.0);
   perna.desenhaPerna(i,1);
   
    
    
   
}

void Bomberman::testeCaminhada(){
    glTranslatef(0,5,PROFUNDIDADE);
    cout << "i " << i << endl;
    perna.desenhaPerna(i,0);
    glTranslatef(-LARGTRONCOINF*1.25,0.0,0.0);
    perna.desenhaPerna(i,1);
    
    
    
}

void Bomberman::testeBracoNaCaminhada(){
    glTranslatef(0,5,PROFUNDIDADE);
    braco.desenhaBraco(i,ESQUERDA,0);
    glTranslatef(LARGTRONCO,0.0,0);
    braco.desenhaBraco(i,DIREITA,1);
}

void Bomberman::setMovimento(int tipoMov){
    this->tipoMovimento = tipoMov;
}
/*Responsável por controlar o tronco conforme o movimento e o momento.
 */
void Bomberman::rotacionarCorpoMovimento(){
    float rotConst = i;
    if(tipoMovimento == 0){
        if(i == 2 || i == 5){
            glRotatef(5,1,0,0);
        }
        
    }else{
        if(i == 2){
        
         //glRotatef(7,1,0,0);
        

        }
        if(i == 4){
           glRotatef(7,1,0,0);

        }
    }
    
}

void Bomberman::posicionarCamera(float posX, float posY, float posZ){
     gluLookAt(posX, posY, posZ, //posicao
               0, 0, 0, //lugar onde está sendo olhado
               0, 1, 0); //vup
    
}



