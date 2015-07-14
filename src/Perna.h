/* 
 * File:   Perna.h
 * Author: rr
 *
 * Created on 2 de Julho de 2015, 20:26
 */

#ifndef PERNA_H
#define	PERNA_H
#include "UtilidadesGeom.h"
#include <vector>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <math.h>

using namespace std;


class Perna {
    
    vector< vector<float> > angulosP;
    vector< vector<float> > angulosJ;
    vector< vector<float> > angulosV;
    
    
    
public:
    Perna();   
    
    virtual ~Perna();
    void setAngulosCaminhada();
    void setAngulosCorrida();
    void desenhaPerna(int momento, int lado);
    void desenhaCoxa();
    void desenhaPe();
    void desenhaJoelho(int lado);
    void desenhaCanela();
    float calculaDeslocamentoHorizontal(int momento);
    
    
private:
    UtilidadesGeom ug;

};

#endif	/* PERNA_H */

