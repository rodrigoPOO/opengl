

#ifndef UTILIDADESGEOM_H
#define	UTILIDADESGEOM_H

class UtilidadesGeom {
    
public:
    
    UtilidadesGeom();   
    virtual ~UtilidadesGeom();
    void desenhaEsfera(float raio);
    void desenhaCilindroRot(float raioBase, float raioTopo, float altura,float angulo);
    void desenhaCilindro(float raioBase, float raioTopo, float altura);
    void desenhaPoligono(float p1x,float p1y, float p2x, float p2y, float p3x, float p3y, float p4x, float p4y);
    void desenhaCirculo(float raio);
    void desenhaChao(float gridX, float gridY);
};

#endif	

