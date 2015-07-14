/* 
 * File:   Braco.h
 * Author: rr
 *
 * Created on 2 de Julho de 2015, 20:26
 */

#ifndef BRACO_H
#define	BRACO_H

#include <stdio.h>
#include <vector>
#include <stdlib.h>
#include "UtilidadesGeom.h"

using namespace std;




class Braco {
    //modo 1: caminhada: braços rotacionam de 30 em 30, indo e voltando para a posicao inicial
    float angulos[2][6] = {{0,15,0,-15,0,15} ,{0,-15,0,15,0,-15}};
    float angulosArticulacaoBraco[2][6] = {{0,50,0,-35,-10,15} ,{0,-35,0,45,20,-10}};
    float angulosCotovelo[2][6] = {{0, -90, -60, -50,-20 ,0} ,{0, -40, -60, -50, -20, 0}};
    vector< vector<float> > angulosArticulacao;
    vector< vector<float> > angulosCotovelos;
    //modo 2:
    
    UtilidadesGeom ug;
    
public:
    Braco();
    Braco(const Braco& orig);
    virtual ~Braco();
    void desenhaBraco(int momento,int lado,int modo);
    void desenhaCotovelo();
    void desenhaMao();
    void desenhaBracoInferior();
    void desenhaBracoSuperior();
    void setAnguloCaminhda();
    void setAnguloCorrida();
    
    
private:
    

};

#endif	/* BRACO_H */

