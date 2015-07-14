/* 
 * File:   Cabeca.h
 * Author: rr
 *
 * Created on 2 de Julho de 2015, 20:26
 */

#ifndef CABECA_H
#include "UtilidadesGeom.h"

class Cabeca {
    
public:
    float dX, dY, dZ;
    int profundidade = 0;
    
    float anguloRotCabeca;
    int momento = 0;
    int posC_X, posC_Y = 0;
    int posC_Z = -2;
    
    
    Cabeca();
    Cabeca(const Cabeca& orig);
    virtual ~Cabeca();
    void desenhaPescoco();
    void desenhaCabeca();
    void desenhaAnexoCabeca();
    void desenhaRosto();
    void ajustaDeslocamento();
private:
    UtilidadesGeom ug;

};

#endif	/* CABECA_H */

