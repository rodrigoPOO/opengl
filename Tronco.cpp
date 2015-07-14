/* 
 * File:   Tronco.cpp
 * Author: rr
 * 
 * Created on 2 de Julho de 2015, 20:34
 */

#include "Tronco.h"
#include "GL/freeglut.h"
#include <stdio.h>
#include <stdlib.h>
#include "GL/glx.h"
#include "GL/glut.h"
#include "GL/glu.h"
#include <iostream>


#define ALTTRONCO 3.5
#define LARGTRONCO 3
#define LARGTRONCOSUP 1.25
#define LARGTRONCOINF 1.25
#define TORSO 1
#define COR_TRONCO 0, 0, 1


Tronco::Tronco() {
}

Tronco::~Tronco() {
}

void Tronco::desenhaTronco(){
    glPushMatrix();    
    glColor3f(COR_TRONCO);
    ug.desenhaCilindro(LARGTRONCOINF, LARGTRONCOSUP, ALTTRONCO);
    glPopMatrix();
    
    

}

