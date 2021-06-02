#include <stdio.h>
#include <GL/glut.h>
#include <math.h>

GLfloat nx1=0,nx2=0,nx3=0,nx4=0,nx5=0,nx6=0,nx7=0,nx8=0,ny1=0,ny2=0,ny3=0,ny4=0,ny5=0,ny6=0, ny7=0,dx=0.0, dy=0.0, dx2= 0.0, dy2=0.0, dx3 = 0.0, dy3=0, xi1=0, xm1=0, xf1=0, xi2=0, xm2=0, xf2=0, yi=0, yf1=0, yf2=0, F1=0, F2=0, F3=0, F4=0, F5=0, F6=0, F7=0, F8=0, F9=0, F10=0, F11=0, F12=0, F13=0, F14=0, F15=0, F16=0, F17=0, F18=0, tam1=0, tam2=0;
GLint j=0,k=0;

void Cenario(void);
void Bico(void);
void Corpo(void);
void AsaDireita(void);
void AsaEsquerda(void);
void Nuvem(int i, float theta);
void Fumaca1(int i, float theta);
void Fumaca2(int i, float theta);
void Fumaca3(int i, float theta);

void DesenhaFoguete(void)
{
    glClearColor(0.0,0.7,1.0,1);
    glClear(GL_COLOR_BUFFER_BIT);
    Cenario();
    Bico();
    Corpo();
    AsaEsquerda();
    AsaDireita();

    glFlush();
}

void Cenario(void)
{
    int i;
    float theta;

    glPushMatrix();
        glTranslated(dx,dy,0.0);

        glColor3f(0.0,1.0,0.0); //CHAO
        glBegin(GL_QUADS);
        glVertex2f(-2, -2);
        glVertex2f(-2, -1);
        glVertex2f(2, -1);
        glVertex2f(2, -2);
        glEnd();

        glColor3f(0.5,0.5,0.5); //rocha
        glBegin(GL_TRIANGLE_STRIP);
        glVertex2f(-1.85,-1);
        glVertex2f(-1.75,-0.9);
        glVertex2f(-1.70,-1);
        glVertex2f(-1.65,-0.85);
        glVertex2f(-1.5,-1);
        glEnd();

        // torre de lancamento

        glColor3ub(255, 255, 255); //primeiro pilar (esquerda para direita)
        glBegin(GL_QUADS);
        glColor3ub(255, 255, 255);
        glVertex2f(-1, -1);
        glColor3ub(0, 0, 0);
        glVertex2f(-1, 1);
        glVertex2f(-0.96, 1);
        glVertex2f(-0.96, -1);
        glEnd();

        glColor3ub(255, 255, 255); //segundo pilar
        glBegin(GL_QUADS);
        glColor3ub(255, 255, 255);
        glVertex2f(-0.5, -1);
        glColor3ub(0, 0, 0);
        glVertex2f(-0.5, 1);
        glVertex2f(-0.46, 1);
        glVertex2f(-0.46, -1);
        glEnd();

        glColor3ub(255, 255, 255); //teto torre
        glBegin(GL_QUADS);
        glColor3ub(255, 255, 255);
        glVertex2f(-1, 1);
        glColor3ub(0, 0, 0);
        glVertex2f(-1, 1.05);
        glVertex2f(-0.46, 1.05);
        glVertex2f(-0.46, 1);
        glEnd();

        //partes de dentro (retangulos horizontais)

        glColor3ub(255, 255, 255);
        glBegin(GL_QUADS);
        glColor3ub(255, 255, 255);
        glVertex2f(-1, 0.6);
        glColor3ub(0, 0, 0);
        glVertex2f(-1, 0.65);
        glVertex2f(-0.46, 0.65);
        glVertex2f(-0.46, 0.6);
        glEnd();

        glColor3ub(255, 255, 255);
        glBegin(GL_QUADS);
        glColor3ub(255, 255, 255);
        glVertex2f(-1, 0.2);
        glColor3ub(0, 0, 0);
        glVertex2f(-1, 0.25);
        glVertex2f(-0.46, 0.25);
        glVertex2f(-0.46, 0.2);
        glEnd();

        glColor3ub(255, 255, 255);
        glBegin(GL_QUADS);
        glColor3ub(255, 255, 255);
        glVertex2f(-1, -0.2);
        glColor3ub(0,0,0);
        glVertex2f(-1, -0.15);
        glVertex2f(-0.46, -0.15);
        glVertex2f(-0.46, -0.2);
        glEnd();

        glColor3ub(255, 255, 255);
        glBegin(GL_QUADS);
        glColor3ub(255, 255, 255);
        glVertex2f(-1, -0.6);
        glColor3ub(0,0,0);
        glVertex2f(-1, -0.55);
        glVertex2f(-0.46, -0.55);
        glVertex2f(-0.46, -0.6);
        glEnd();

        //Fim das partes de dentro

        glColor3f(0.2,0.2,0.2);   //chao aonde fica o foguete
        glBegin(GL_QUADS);
        glVertex2f(-0.2, -1);
        glVertex2f(-0.2, -0.92);
        glVertex2f(1.7, -0.92);
        glVertex2f(1.7, -1);
        glEnd();

        glColor3ub(165,42,42); // Suporte do Timer
        glBegin(GL_QUADS);
        glVertex2f(-0.75,1.05);
        glVertex2f(-0.75,1.2);
        glVertex2f(-0.7,1.2);
        glVertex2f(-0.7,1.05);
        glEnd();

        glColor3ub(255, 255, 255);
        glBegin(GL_QUADS);
        glColor3ub(255, 255, 255); // Corpo metalico do Timer
        glVertex2f(-0.45,1.2);
        glColor3ub(85, 85, 85);
        glVertex2f(-0.45,1.6);
        glVertex2f(-1,1.6);
        glVertex2f(-1,1.2);
        glEnd();

        glColor3f(0,0,0); // Monitor do Timer
        glBegin(GL_QUADS);
        glVertex2f(-0.47,1.23);
        glVertex2f(-0.47,1.57);
        glVertex2f(-0.97,1.57);
        glVertex2f(-0.97,1.23);
        glEnd();

        glPopMatrix();

        glPushMatrix();
        glTranslated(dx,dy,0.0);

        glColor3f(1,0,0); //Numeros
        glBegin(GL_LINE_STRIP);
        glVertex2f(nx1,ny1);
        glVertex2f(nx2,ny2);
        glVertex2f(nx3,ny3);
        glVertex2f(nx4,ny4);
        glVertex2f(nx5,ny5);
        glVertex2f(nx6,ny6);
        glEnd();

        glColor3f(1,0,0); //auxiliar numero 3
        glBegin(GL_LINES);
        glVertex2f(nx7,ny7);
        glVertex2f(nx8,ny7);
        glEnd();

        glPopMatrix();
        glPushMatrix();
        glTranslated(dx,dy,0.0);

        Fumaca1(i,theta);
        Fumaca2(i,theta);
        Fumaca3(i,theta);
        glPopMatrix();

    glPushMatrix();
        glTranslated(dx2,dy2,0.0);
        glPushMatrix();
        glColor3f(1,1,0); //Sol
        glBegin(GL_POLYGON);
        for(i=0;i<360;i++)
        {
            theta = i*3.142/180;
            glVertex2f(1.7+0.2*cos(theta),1.7+0.2*sin(theta));
        }
        glEnd();
    glPopMatrix();

    glPushMatrix();
        glTranslated(dx3,dy3,0.0);
        Nuvem(i,theta);
    glPopMatrix();

}

void Fumaca1(int i, float theta)
{
    glColor3f(0.5,0.5,0.5);
    glBegin(GL_POLYGON);
    for(i=0;i<360;i++)
    {
        theta = i*3.142/180;
        glVertex2f(F1+tam1*cos(theta),F2+tam1*sin(theta));
    }
    glEnd();

    glColor3f(0.6,0.6,0.6);
    glBegin(GL_POLYGON);
    for(i=0;i<360;i++)
    {
        theta = i*3.142/180;
        glVertex2f(F3+tam1*cos(theta),F4+tam1*sin(theta));
    }
    glEnd();

    glColor3f(0.7,0.7,0.7);
    glBegin(GL_POLYGON);
    for(i=0;i<360;i++)
    {
        theta = i*3.142/180;
        glVertex2f(F5+tam2*cos(theta),F6+tam2*sin(theta));
    }
    glEnd();
}

void Fumaca2(int i, float theta)
{
    glColor3f(0.5,0.5,0.5);
    glBegin(GL_POLYGON);
    for(i=0;i<360;i++)
    {
        theta = i*3.142/180;
        glVertex2f(F7+tam1*cos(theta),F8+tam1*sin(theta));
    }
    glEnd();

    glColor3f(0.6,0.6,0.6);
    glBegin(GL_POLYGON);
    for(i=0;i<360;i++)
    {
        theta = i*3.142/180;
        glVertex2f(F9+tam2*cos(theta),F10+tam2*sin(theta));
    }
    glEnd();

    glColor3f(0.7,0.7,0.7);
    glBegin(GL_POLYGON);
    for(i=0;i<360;i++)
    {
        theta = i*3.142/180;
        glVertex2f(F11+tam1*cos(theta),F12+tam1*sin(theta));
    }
    glEnd();
}

void Fumaca3(int i, float theta)
{
    glColor3f(0.5,0.5,0.5);
    glBegin(GL_POLYGON);
    for(i=0;i<360;i++)
    {
        theta = i*3.142/180;
        glVertex2f(F13+tam1*cos(theta),F14+tam1*sin(theta));
    }
    glEnd();

    glColor3f(0.6,0.6,0.6);
    glBegin(GL_POLYGON);
    for(i=0;i<360;i++)
    {
        theta = i*3.142/180;
        glVertex2f(F15+tam1*cos(theta),F16+tam1*sin(theta));
    }
    glEnd();

    glColor3f(0.7,0.7,0.7);
    glBegin(GL_POLYGON);
    for(i=0;i<360;i++)
    {
        theta = i*3.142/180;
        glVertex2f(F17+tam2*cos(theta),18+tam2*sin(theta));
    }
    glEnd();
}

void Nuvem(int i, float theta)
{
    glColor3f(1,1,1); //nuvem 1
    glBegin(GL_POLYGON);
    for(i=0;i<360;i++)
    {
        theta = i*3.142/180;
        glVertex2f(-1.7+0.15*cos(theta),1.7+0.15*sin(theta));
    }

    for(i=0;i<360;i++)
    {
        theta = i*3.142/180;
        glVertex2f(-1.5+0.15*cos(theta),1.7+0.15*sin(theta));
    }

    for(i=0;i<360;i++)
    {
        theta = i*3.142/180;
        glVertex2f(-1.3+0.15*cos(theta),1.7+0.15*sin(theta));
    }
    glEnd();

    glColor3f(1,1,1); //nuvem 2
    glBegin(GL_POLYGON);
    for(i=0;i<360;i++)
    {
        theta = i*3.142/180;
        glVertex2f(-0.5+0.15*cos(theta),3.4+0.15*sin(theta));
    }
    for(i=0;i<360;i++)
    {
        theta = i*3.142/180;
        glVertex2f(-0.3+0.15*cos(theta),3.4+0.15*sin(theta));
    }
    for(i=0;i<360;i++)
    {
        theta = i*3.142/180;
        glVertex2f(-0.1+0.15*cos(theta),3.4+0.15*sin(theta));
    }
    glEnd();

    glColor3f(1,1,1); //nuvem 3
    glBegin(GL_POLYGON);
    for(i=0;i<360;i++)
    {
        theta = i*3.142/180;
        glVertex2f(-2.1+0.15*cos(theta),4+0.15*sin(theta));
    }
    for(i=0;i<360;i++)
    {
        theta = i*3.142/180;
        glVertex2f(-1.9+0.15*cos(theta),4+0.15*sin(theta));
    }
    for(i=0;i<360;i++)
    {
        theta = i*3.142/180;
        glVertex2f(-1.7+0.15*cos(theta),4+0.15*sin(theta));
    }
    glEnd();

    glColor3f(1,1,1); //nuvem 4
    glBegin(GL_POLYGON);
    for(i=0;i<360;i++)
    {
        theta = i*3.142/180;
        glVertex2f(0.3+0.15*cos(theta),4.7+0.15*sin(theta));
    }
    for(i=0;i<360;i++)
    {
        theta = i*3.142/180;
        glVertex2f(0.5+0.15*cos(theta),4.7+0.15*sin(theta));
    }
    for(i=0;i<360;i++)
    {
        theta = i*3.142/180;
        glVertex2f(0.7+0.15*cos(theta),4.7+0.15*sin(theta));
    }
    glEnd();

    glColor3f(1,1,1); //nuvem 5
    glBegin(GL_POLYGON);
    for(i=0;i<360;i++)
    {
        theta = i*3.142/180;
        glVertex2f(1.5+0.15*cos(theta),5.8+0.15*sin(theta));
    }
    for(i=0;i<360;i++)
    {
        theta = i*3.142/180;
        glVertex2f(1.7+0.15*cos(theta),5.8+0.15*sin(theta));
    }
    for(i=0;i<360;i++)
    {
        theta = i*3.142/180;
        glVertex2f(1.9+0.15*cos(theta),5.8+0.15*sin(theta));
    }
    glEnd();

     glColor3f(1,1,1); //nuvem 6
    glBegin(GL_POLYGON);
    for(i=0;i<360;i++)
    {
        theta = i*3.142/180;
        glVertex2f(-1.5+0.15*cos(theta),6.2+0.15*sin(theta));
    }
    for(i=0;i<360;i++)
    {
        theta = i*3.142/180;
        glVertex2f(-1.3+0.15*cos(theta),6.2+0.15*sin(theta));
    }
    for(i=0;i<360;i++)
    {
        theta = i*3.142/180;
        glVertex2f(-1.1+0.15*cos(theta),6.2+0.15*sin(theta));
    }
    glEnd();

}

void Bico(void)
{
    glBegin(GL_QUADS); //Bico propriamente dito
    glColor3f(0.4, 0.4, 0.4);
    glVertex2f(0.5, 1.4);
    glVertex2f(0.6, 1.8);
    glVertex2f(0.9, 1.8);
    glVertex2f(1, 1.4);
    glEnd();

}

void Corpo(void)
{
    glColor3ub(255, 255, 255); //corpo propriamente dito - inferior
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 255);
    glVertex2f(0.5, -0.7);
    glColor3ub(80, 80, 80);
    glVertex2f(0.5, 0.6);
    glVertex2f(1, 0.6);
    glVertex2f(1, -0.7);
    glEnd();

    glColor3ub(255, 255, 255); //corpo propriamente dito - superior
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 255);
    glVertex2f(0.5, 0.6);
    glColor3ub(80, 80, 80);
    glVertex2f(0.5, 1.4);
    glVertex2f(1, 1.4);
    glVertex2f(1, 0.6);
    glEnd();

    //Listras coloridas no foguete

    glColor3f(0,0.5,0);
    glBegin(GL_QUADS);
    glVertex2f(0.5, 1.3);
    glVertex2f(0.5, 1.25);
    glVertex2f(1, 1.25);
    glVertex2f(1, 1.3);
    glEnd();

    glColor3f(1.0,1.0,0.0);
    glBegin(GL_QUADS);
    glVertex2f(0.5, 1.2);
    glVertex2f(0.5, 1.15);
    glVertex2f(1, 1.15);
    glVertex2f(1, 1.2);
    glEnd();

    glColor3f(0,0,0.5);
    glBegin(GL_QUADS);
    glVertex2f(0.5, 1.1);
    glVertex2f(0.5, 1.05);
    glVertex2f(1, 1.05);
    glVertex2f(1, 1.1);
    glEnd();

    //fim das listras do Brasil no foguete


    glColor3ub(255, 255, 255); //Propulsor
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 255);
    glVertex2f(0.6, -0.92);
    glColor3ub(40, 40, 40);
    glVertex2f(0.7, -0.7);
    glVertex2f(0.8, -0.7);
    glVertex2f(0.9, -0.92);
    glEnd();


    glColor3f(1,0,0);
    glBegin(GL_POLYGON);
    glVertex2f(xi1,yi);
    glVertex2f(xm1,yf1);
    glVertex2f(xf1,yi);
    glEnd();

    glColor3f(1,1,0);
    glBegin(GL_POLYGON);
    glVertex2f(xi2,yi);
    glVertex2f(xm2,yf2);
    glVertex2f(xf2,yi);
    glEnd();

}

void AsaEsquerda(void)
{

    glColor3f(0.4, 0.4, 0.4);
    glBegin(GL_POLYGON);
    glVertex2f(0.5, 0.3);
    glVertex2f(0.2, -0.4);
    glVertex2f(0.25, -0.7);
    glVertex2f(0.35, -0.45);
    glVertex2f(0.5, -0.4);
    glEnd();

}

void AsaDireita(void)
{
    glColor3f(0.4, 0.4, 0.4);
    glBegin(GL_POLYGON);
    glVertex2f(1, 0.3);
    glVertex2f(1.2, -0.4);
    glVertex2f(1.25, -0.7);
    glVertex2f(1.35, -0.45);
    glVertex2f(1.0, -0.4);
    glEnd();
}

void Teclado(unsigned char tecla, int x, int y)
{
    printf("*** Tratamento de teclas comuns\n");
	printf(">>> Tecla pressionada: %c\n",tecla);

	if (tecla == 27)
		exit(0);
 }

 void Inicializa(void)
{
	// Define a janela de visualização 2D
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-2.0,2.0,-2.0,2.0);//Exibição Bidimensional

}


void Loop(int param)
{

        nx1=0;
        nx2=0;
        nx3=0;
        nx4=0;
        nx5=0;
        nx6=0;
        nx7=0;
        nx8=0;
        ny1=0;
        ny2=0;
        ny3=0;
        ny4=0;
        ny5=0;
        ny6=0;
        ny7=0;
    if(k==0)
    {
        nx1=-0.87; //3
        nx2=-0.57;
        nx3=-0.57;
        nx4=-0.87;
        nx5=-0.87;
        nx6=-0.87;
        nx7=-0.87;
        nx8=-0.57;
        ny1=1.53;
        ny2=1.53;
        ny3=1.27;
        ny4=1.27;
        ny5=1.27;
        ny6=1.27;
        ny7=1.40;
        k++;
        glutPostRedisplay();
        glutTimerFunc(1000, Loop, 1);
    }
    else if(k==1)
    {
        glutSwapBuffers();
        nx1=-0.57; //2
        nx2=-0.87;
        nx3=-0.87;
        nx4=-0.57;
        nx5=-0.57;
        nx6=-0.87;
        ny1=1.27;
        ny2=1.27;
        ny3=1.40;
        ny4=1.40;
        ny5=1.53;
        ny6=1.53;
        k++;
        glutPostRedisplay();
        glutTimerFunc(1000, Loop, 1);
    }
    else if(k==2)
    {
        glutSwapBuffers();
        nx1=-0.57; //1
        nx2=-0.57;
        nx3=-0.87;
        nx4=-0.87;
        nx5=-0.87;
        nx6=-0.87;
        ny1=1.27;
        ny2=1.53;
        ny3=1.40;
        ny4=1.40;
        ny5=1.40;
        ny6=1.40;
        k++;
        glutPostRedisplay();
        glutTimerFunc(1000, Loop, 1);
    }

    else{
        nx1=-0.57; //0
        nx2=-0.87;
        nx3=-0.87;
        nx4=-0.57;
        nx5=-0.57;
        nx6=-0.57;
        ny1=1.27;
        ny2=1.27;
        ny3=1.53;
        ny4=1.53;
        ny5=1.27;
        ny6=1.27;

    if(j<10)
    {

        switch(j) // ANIMACAO DA FUMACA
        {
            case 0:
                tam1 = 0.15;
                tam2 = 0.2;
                F1 = 0.4;
                F2 = -0.8;
                F3 = 0.5;
                F4 = -0.6;
                F5 = 0.6;
                F6 = -1;
                break;

            case 4:
                glutSwapBuffers();
                F7 = 0.8;
                F8 = -0.8;
                F9 = 1.1;
                F10 = -0.6;
                F11 = 1.3;
                F12 = -1;
                break;


            case 9:
                glutSwapBuffers();
                F13 = 0.7;
                F14 = -0.8;
                F15 = 0.7;
                F16 = -0.6;
                F17 = 1.1;
                F18 = -1;
                break;

        }
         //        ANIMACAO DO FOGO
        if(j%2 == 0)
        {
            xi1 = 0.65;
            xm1 = 0.8;
            xf1 = 0.85;
            xi2 = 0.68;
            xm2 = 0.8;
            xf2 = 0.8;
            yi = -0.92;
            yf1 = -1;
            yf2 = -0.96;
        }
        else{
            xi1 = 0.6;
            xm1 = 0.8;
            xf1 = 0.9;
            xi2 = 0.7;
            xm2 = 0.75;
            xf2 = 0.8;
            yi = -0.92;
            yf1 = -1.04;
            yf2 = -1;
        }

        dy  -= 0.05; //Cenario de baixo
        dy2 -= 0.0001; // Sol
        dy3 -= 0.02; // Nuvens
        glutPostRedisplay();
        j++;
        glutTimerFunc(500, Loop, 0);
    }
    else{

        //        ANIMACAO DO FOGO
        if(j%2 == 0)
        {
            xi1 = 0.65;
            xm1 = 0.8;
            xf1 = 0.85;
            xi2 = 0.68;
            xm2 = 0.8;
            xf2 = 0.8;
            yi = -0.92;
            yf1 = -1;
            yf2 = -0.96;
        }
        else{
            xi1 = 0.6;
            xm1 = 0.8;
            xf1 = 0.9;
            xi2 = 0.7;
            xm2 = 0.75;
            xf2 = 0.8;
            yi = -0.92;
            yf1 = -1.04;
            yf2 = -1;
        }

        dy = dy - 0.05; //Cenario de baixo
        dy2 = dy2 - 0.001; // Sol
        dy3 = dy3 - 0.02; // Nuvens
        glutPostRedisplay();
        j++;
        glutTimerFunc(125, Loop, 0);
    }
    }
}

int main(int argc, char** argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowPosition(200,150);
    glutInitWindowSize(600,600);
    glutCreateWindow("Foguete");
    glutDisplayFunc(DesenhaFoguete);
    glutKeyboardFunc(Teclado);
    Inicializa();
    glutTimerFunc(0, Loop, 0);
    glutMainLoop();
}
