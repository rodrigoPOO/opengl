/* 
 * File:   Bomberman.h
 * Author: rr
 *
 * Created on 2 de Julho de 2015, 20:25
 */

#ifndef BOMBERMAN_H
#define	BOMBERMAN_H

#include "Braco.h"
#include "Cabeca.h"
#include "Tronco.h"
#include "Perna.h"
#include "UtilidadesGeom.h"


class Bomberman {
    
    Perna perna;
    Braco braco;
    Cabeca cabeca;
    Tronco tronco;
    UtilidadesGeom ug;
    
    
public:    
    int tipoMovimento = 0;
    int profundidade = -20;
    int i = 0;
    
    Bomberman();
    
    virtual ~Bomberman();
    void desenharCorpo(int posX, int posY, int posZ);
    void testeCaminhada();
    void testeBracoNaCaminhada();
    void setMovimento(int tipo);
    void setZoom(int intensidade);
    void rotacionarCorpoMovimento();
    void posicionarCamera(float posX, float posY, float posZ);
    
private:

};

#endif	/* BOMBERMAN_H */

