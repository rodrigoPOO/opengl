/* 
 * File:   Braco.cpp
 * Author: rr
 * 
 * Created on 2 de Julho de 2015, 20:26
 */

#include "Braco.h"
#include "GL/freeglut.h"
#include <stdio.h>
#include <stdlib.h>
#include "GL/glx.h"
#include "GL/glut.h"
#include "GL/glu.h"
#include <iostream>
#include <vector>

#define COR_PE_MAO 1.0, 0.0, 1.0
#define COR_BRACO 0.75, 0.75, 0.75
#define COR_TRONCO 0, 0, 1
#define RAIOMAO 0.75
#define RAIOBRACO 0.35
#define ALTURABRACO 1.5
#define ALTURABRACOINFERIOR 1.5


Braco::Braco() {
}

Braco::Braco(const Braco& orig) {
}

Braco::~Braco() {
}

void Braco::setAnguloCaminhda(){
    angulosArticulacao.clear();
    angulosCotovelos.clear();
    //float angulos[2][6] = {{0,15,0,-15,0,15} ,{0,-15,0,15,0,-15}};
    vector<float> angulos1 = {0,15,0,-15,0,15};
    vector<float> angulos2 = {0,-15,0,15,0,-15};
    
    angulosArticulacao.push_back(angulos1);
    angulosArticulacao.push_back(angulos2);
    
    angulosCotovelos.push_back(angulos1);
    angulosCotovelos.push_back(angulos2);
}

void Braco::setAnguloCorrida(){
    angulosArticulacao.clear();
    angulosCotovelos.clear();
     //float angulosArticulacaoBraco[2][6] = {{0,50,0,-35,-10,15} ,{0,-35,0,45,20,-10}};
    
    vector<float> angulosArt1 = {0,50,0,-35,-10,15};
    vector<float> angulosArt2 = {0,-35,0,45,20,-10};
    
    angulosArticulacao.push_back(angulosArt1);
    angulosArticulacao.push_back(angulosArt2);
    
    //float angulosCotovelo[2][6] = {{0, -90, -60, -50,-20 ,0} ,{0, -40, -60, -50, -20, 0}};
    
    vector<float> angulosCot1 = {0, -90, -60, -50,-20 ,0};
    vector<float> angulosCot2 = {0, -40, -60, -50, -20, 0};
    
    
    angulosCotovelos.push_back(angulosCot1);
    angulosCotovelos.push_back(angulosCot2);
    
}

void Braco::desenhaMao(){
   // glPushMatrix();
    glColor3f(COR_PE_MAO);
    
    glScalef(RAIOMAO,RAIOMAO,RAIOMAO);
   this->ug.desenhaEsfera(RAIOMAO);
    //glPopMatrix();
}
void Braco::desenhaBracoSuperior(){
    //desenhar um cilindro normal e rotacionar 45º
    glPushMatrix();
    glColor3f(COR_BRACO);
   // glRotatef(45,-1,0,0);   
    ug.desenhaCilindro(RAIOBRACO,RAIOBRACO,ALTURABRACO);
    glPopMatrix();
    
}

void Braco::desenhaCotovelo(){
   glPushMatrix();
   glColor3f(COR_PE_MAO);
   // glScalef(RAIOBRACO,RAIOBRACO,RAIOBRACO);
   glutSolidSphere(RAIOBRACO,32,32);
   glPopMatrix();
    
}

void Braco::desenhaBracoInferior(){
    glPushMatrix();
    glColor3f(COR_BRACO);
  //  glRotatef(45,-1,0,0);
    
    ug.desenhaCilindro(RAIOBRACO,RAIOBRACO,ALTURABRACOINFERIOR);
   // glTranslated(0,-ALTURABRACO,0);
    
    glPopMatrix();

}

void Braco::desenhaBraco(int momento,int lado,int modo){
        /*Estrutura do braco:
     articulacaoSuperior (esfera)
     *  braco superior ou biceps (cilindro)
     *     cotovelo (esfera)
     *  antebraco (cilindro)
     *  mao (esfera)     
     */
    
    glPushMatrix();    
    /*DESENHA ARTICULACAO SUPERIOR*/
    glColor3f(COR_PE_MAO);     
    glutSolidSphere(RAIOBRACO,32,32);    //fim desenho art sup
    glRotatef(angulosArticulacao[modo][momento],1,0,0);
    
    glTranslatef(0.25*lado, -RAIOBRACO, 0.0);
   
    //glPushMatrix();
    
    desenhaBracoSuperior();
    
    glTranslatef(0.05*lado,-ALTURABRACO,0.0);
    
    desenhaCotovelo();
    glRotatef(angulosCotovelos[modo][momento],1,0,0);
    //glRotatef(angulos[modo][momento],1,0,0);
    glTranslatef(0.0,-RAIOBRACO*1.25,0.0);
    desenhaBracoInferior();
    //glRotatef(60,1,0,0);
    glTranslatef(0.25*lado,-ALTURABRACO*1.25,0.0);
    desenhaMao();
    glPopMatrix();
    //glScalef(LARGCOXA, ALTCOXA, LARGCOXA);
 //   desenhaCilindro(LARGCOXA/2.,LARGCOXA/2.,ALTCOXA);
    
   // glPopMatrix();

    
    

}


