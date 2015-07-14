/* 
 * File:   Tronco.h
 * Author: rr
 *
 * Created on 2 de Julho de 2015, 20:34
 */

#ifndef TRONCO_H
#define	TRONCO_H


#include "UtilidadesGeom.h"


class Tronco {
public:
    Tronco();   
    virtual ~Tronco();
    void desenhaTronco();
private:
    UtilidadesGeom ug;

};

#endif	/* TRONCO_H */

