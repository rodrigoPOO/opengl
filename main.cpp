#include "GL/freeglut.h"
#include <stdio.h>
#include <stdlib.h>
#include "GL/glx.h"
#include "GL/glut.h"
#include "GL/glu.h"
#include "Bomberman.h"
#include <iostream>
#include <unistd.h>
#include "UtilidadesGeom.h"


#define DIREITA 1
#define ESQUERDA -1
#define ALTTRONCO 3.5
#define LARGTRONCO 3
#define LARGTRONCOSUP 1.25
#define LARGTRONCOINF 1.25
#define TORSO 1

#define ALTPERNA 1
#define ALTCANELA 1
#define PROFUNDIDADE -10
#define TAMARTQUADRIL 0.3
#define LARGCOXA 1
#define ALTCOXA 1.25
#define COR_PE_MAO 1.0, 0.0, 1.0
#define COR_BRACO 0.75, 0.75, 0.75
#define COR_TRONCO 0, 0, 1
#define RAIOMAO 0.75
#define RAIOBRACO 0.35
#define RAIO_OLHO 0.2
#define RAIOCAPACETE 2.5
#define ALTURABRACO 1.5
#define ALTURABRACOINFERIOR 1.5
#define RAIOANEXO 0.25
#define ALTURAANEXO 1
#define COR_CABECA 0.25, 0.55, 0.55
#define COR_CAPACETE 0.85, 0.85, 0.85

//#declare LightGray = color red 0.658824 green 0.658824 blue 0.658824







using namespace std;

int Width;
int Height;
Bomberman bm;
int momento = 0;
int profundidade = -10;
int posX, posY;
int posZ = 5;
UtilidadesGeom ug;


void initLight(){
          GLfloat ambientColor[] = {0.75f, 0.75f, 0.75f, 1.0f}; //Color (0.2, 0.2, 0.2)
	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, ambientColor);
	
	//Add positioned light
	GLfloat lightColor0[] = {0.25f, 0.25f, 0.25f, 1.0f}; //Color (0.5, 0.5, 0.5)
	GLfloat lightPos0[] = {0.0f, 4.0f, 8.0f, 1.0f}; //Positioned at (4, 0, 8)
	glLightfv(GL_LIGHT0, GL_DIFFUSE, lightColor0);
	glLightfv(GL_LIGHT0, GL_POSITION, lightPos0);
	
	//Add directed light
	GLfloat lightColor1[] = {0.5f, 0.2f, 0.2f, 1.0f}; //Color (0.5, 0.2, 0.2)
	//Coming from the direction (-1, 0.5, 0.5)
	GLfloat lightPos1[] = {-1.0f, 0.5f, 0.5f, 0.0f};
	glLightfv(GL_LIGHT1, GL_DIFFUSE, lightColor1);
	glLightfv(GL_LIGHT1, GL_POSITION, lightPos1);
	
    
}



void initGL() // All Setup For OpenGL Goes Here
{
    glShadeModel(GL_SMOOTH);	// Habilita sombreamento suavizado
    // Mistura cores de forma suave me um polÌgono
    
    glClearColor(1, 1, 1, 0.5);   
    
    
    glClearDepth(1); // InicializaÁ„o do Depth Buffer
    
    glEnable(GL_DEPTH_TEST); // Habilita teste de profundidade
    
    glEnable(GL_LIGHTING); //Enable lighting
    glEnable(GL_LIGHT0); //Enable light #0
    glEnable(GL_LIGHT1); //Enable light #1
   
    
    	
    glDepthFunc(GL_LEQUAL); // Define qual teste de profundidade vai ser feito
    
    glEnable(GL_COLOR_MATERIAL);
    
    glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST); // Calculos de perspectiva legaizinhos
}

void redesenhaMundo(void) // … aqui que desenhamos TUDO
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);	// Limpe a tela e o Z-Buffer
    
    glLoadIdentity();	// Resete a visualizacao.
     initLight();
    
    glPushMatrix();
    glTranslatef(0,0,PROFUNDIDADE);
    //
    
    bm.i = momento;
    bm.profundidade = profundidade;
    
    
    
    bm.desenharCorpo(posX,posY,posZ);
   // bm.testeCaminhada();
   // bm.testeBracoNaCaminhada();
    /* Fim do desenho */
    
   glPopMatrix();
    
    
    glutSwapBuffers ( );
}

void redimensionaJanela (int width, int height)
{
    /* Save the new width and height */
    Width = width;
    Height = height;
    
    /* Reset the viewport... */
    glViewport(0, 0, width, height);
    
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    
    if ( height == 0 )
    {
        // Calculate The Aspect Ratio Of The Window
        gluPerspective ( 80, ( float ) width, 1.0, 5000.0 );
    }
    else
    {
        gluPerspective ( 80, ( float ) width / ( float ) height, 1.0, 5000.0 );
    }
    
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity(); // Reset The Modelview Matrix
}

void tecla (unsigned char tecla, int x, int y)
{
    switch ( tecla )
    {
        case 27:		// When Escape Is Pressed...
            exit(0);	// exit the program... normal termination.
            break;
            // Ready For Next Case
            
        case 32:
            //zera a rotacao da camera Space
            posX = 0;
            posY = 0;
            posZ = 5;
            break;
            
        case 97:
            //a) camera do lado
            posX = 5;
            posY = 0;
            posZ = 5;
            break;
            
        case 119:
            //w - camera em cima.
              posY = 5;
            posX = 0;
            posZ = 5;
            break;
            
        case 115:
            //s camera "atrás"
            posX = 0;
            posY = 0;
            posZ = -20;
            break;
           
          
        default:
            cout << tecla << endl;
            break;
    }
}

void teclasDasSetas(int tecla, int x, int y)
{
    cout << momento << endl;
     
     
    switch (tecla)
    {
        case GLUT_KEY_UP:	// Quando a seta para cima È teclada...
            glutFullScreen();	// V· para o modo tela cheia...
            break;
            
        case GLUT_KEY_LEFT:
            bm.tipoMovimento = 0;
            if(profundidade == 0){
                profundidade = -20;
            }else{          
                
                  profundidade++;
                
                
            }   
             if(momento > 5){
                momento = 0;
             }else{
                momento++;
             }
            glutDisplayFunc(redesenhaMundo);
            break;
        case GLUT_KEY_RIGHT:
            bm.tipoMovimento = 1;
            if(profundidade == 0){
                profundidade = -20;
            }else{
                if(momento != 5)
                profundidade++;
                
                
            }   
            if(momento >= 5){
                momento = 0;
             }else{
                momento++;
             }
            glutDisplayFunc(redesenhaMundo);
            break;
            
            
        default:
            cout <<  "Teclaram: " <<  tecla << endl; // ...para ajudar vocÍ a debugar...
            break;
    }
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    
    glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_DEPTH );
    
    glutInitWindowSize(640, 480);
    
    glutCreateWindow ("Bomberman");
    
    initGL();
    
    glutDisplayFunc(redesenhaMundo);
    
    glutReshapeFunc(redimensionaJanela);
    
    glutKeyboardFunc(tecla);
    
    glutSpecialFunc(teclasDasSetas);
    
    glutIdleFunc(redesenhaMundo);
    
    glutMainLoop();
    
    return 0;
}



