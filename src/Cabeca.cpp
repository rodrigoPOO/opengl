/* 
 * File:   Cabeca.cpp
 * Author: rr
 * 
 * Created on 2 de Julho de 2015, 20:26
 */

#include "Cabeca.h"
#include "GL/freeglut.h"
#include <stdio.h>
#include <stdlib.h>
#include "GL/glx.h"
#include "GL/glut.h"
#include "GL/glu.h"
#include <iostream>

using namespace std;


#define	CABECA_H
#define RAIOANEXO 0.25
#define RAIO_TOPO 0.55
#define ALTURAANEXO 1
#define COR_CABECA 0.25, 0.55, 0.55
#define COR_CAPACETE 0.85, 0.85, 0.85
#define RAIOBRACO 0.35
#define RAIO_OLHO 0.2
#define RAIOCAPACETE 1.75
#define COR_ROSA 1.0, 0.0, 1.0
#define COR_CINZA 0.75, 0.75, 0.75
#define OLHO_PT0 0, 0
#define OLHO_PT1 0, 1
#define OLHO_PT2 0.25, 1
#define OLHO_PT3 0.25, 0
#define RAIO_CABECA 1.40


Cabeca::Cabeca() {
    dZ = 0;
}


Cabeca::~Cabeca() {
}

void Cabeca::desenhaAnexoCabeca(){
    /*Topo: Esfera
     Ligacao: Cilindro
     */
    //cor rosa
    glPushMatrix();
    glTranslated(0,0.50,-2);
    glColor3f(COR_ROSA);
    glRotatef(-30,1,0,0);
    glutSolidSphere(RAIO_TOPO,32,32);
    
    glTranslatef(0.0,-RAIO_TOPO*0.95,0.0);
    //
    glColor3f(COR_CINZA);
    
    ug.desenhaCilindro(RAIOANEXO,RAIOANEXO,ALTURAANEXO);
    
    glPopMatrix();
    
    
    
}



void Cabeca::desenhaCabeca(){
    /*Anexo: desenhaAnexo
     * Capacete: esfera branca
     * Cabeca: esfera cor de pele  #declare Salmon = color red 0.435294 green 0.258824 blue 0.258824
     * Olhos: circulo
     * Sobrancelha: poligono
     * Pescoço: c
     * 
     */
    glPushMatrix();
    glTranslatef(0,0.5,0);
    desenhaAnexoCabeca();    
    glTranslated(-1,-3,0.0);    
    desenhaRosto();
    ajustaDeslocamento();
    glColor3f(COR_CAPACETE);
    glutSolidSphere(RAIOCAPACETE,32,32);
    glPopMatrix();
    
    glPushMatrix();    
        glColor3f(0, 0, 0);
        glTranslatef(-0.75,-2.0,0);
        ug.desenhaPoligono(OLHO_PT0,OLHO_PT1,OLHO_PT2,OLHO_PT3);
        glTranslatef(1.25,0,0);
        ug.desenhaPoligono(OLHO_PT0,OLHO_PT1,OLHO_PT2,OLHO_PT3);
    glPopMatrix();
    glTranslatef(0.0,-RAIOCAPACETE*1.65,0.0);    
    desenhaPescoco();
}

void Cabeca::desenhaPescoco(){
    glPushMatrix();
     glColor3f(COR_CINZA);
    //glTranslatef(1.0,-3,0);
    ug.desenhaCilindro(0.25,0.25,0.75);
    glPopMatrix();
   
}

void Cabeca::desenhaRosto(){
    glPushMatrix();
    glColor3f(1, 0.65, 0.65);           
    
    ug.desenhaPoligono(0,0,0,2,2,2,2,0);
    
    glPopMatrix();
}

void Cabeca::ajustaDeslocamento(){
    dX = 1;
    dY = 1.5;
    if(posC_Z == -20){
        dX = 1;
        dY = 1;        
    }
    if((posC_X == 5) && posC_Y == 0){
        //decrementar o x;        
        dX = 0.5;
        dY = 1.25;        
        if(profundidade  > -10){
            dX -= 0.25;
        }
    }else{
        if(posC_X == 0 && posC_Y == 5){
            dX = 1;
            dY = 0.5;
            if(profundidade > -10){
                dY -= 0.25;
            }
            //glTranslated(1,0.5,-2); //para x = 0, y = 5, z = 5 deveria ir decrementando o y para a cabeça ficar junto ao corpo
        }
    }
   
    glTranslated(dX,dY,-2); //para x = 5, y = 0, z = 5; deveria ir incrementando o y fator
}





