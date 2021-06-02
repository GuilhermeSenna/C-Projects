#include <stdio.h>
#include <stdlib.h>
#include <GL/glut.h>
#include <string.h>

FILE *fpin;
char controle[2];
int **imagemX, **imagemR, **imagemG, **imagemB, ncol, nlin, grade;

void abrir_arquivos(int argc, char *argv[]);
void ler_cabecalho(void);
void ler_imagemP1(void);
void ler_imagemP2(void);
void ler_imagemP3(void);
void fechar_arquivos(void);
void GoMenuP1(int valor);
void GoMenuP2(int valor);
void GoMenuP3(int valor);
void desenhaInversaP1(void);
void desenhaBandaRP1(void);
void desenhaBandaGP1(void);
void desenhaBandaBP1(void);
void desenhaInversaP2(void);
void desenhaBandaRP2(void);
void desenhaBandaGP2(void);
void desenhaBandaBP2(void);
void desenhaInversaP3(void);
void desenhaBandaRP3(void);
void desenhaBandaGP3(void);
void desenhaBandaBP3(void);

void abrir_arquivos(int argc, char *argv[]) {
     if (argc  <=1) {
	    printf("Modo correto de uso: pdi <imagem> <arq_saida>\n");
	  ;//  exit(0);
     }
     if ((fpin=fopen(argv[1],"r"))==NULL) {
	    printf("Nao foi possivel abrir arquivo de imagem %s\n", argv[1]);
	    exit(1);
     }
} // Fim: abrir_arquivos

void ler_imagemP1(void)
{
    int cont, col, lin;
  imagemX= (int **)malloc((nlin+1)*sizeof(int *));
  for (cont=0;cont<nlin;cont++) {
    imagemX[cont]=(int *)malloc((ncol+1)*sizeof(int));
    if (imagemX[cont]==NULL) { /* Alocar memoria para a matriz de pixels */
      printf("Falha na alocacao de memoria - 1\n");
      exit(1);
    }
  }
  for (lin=0;lin<nlin;lin++) {
    for (col=0;col<ncol;col++) {
      fscanf(fpin,"%d ",&imagemX[lin][col]);
    }
  }
}

void ler_imagemP2(void)
{
    int cont, col, lin;
  imagemX= (int **)malloc((nlin+1)*sizeof(int *));
  for (cont=0;cont<nlin;cont++) {
    imagemX[cont]=(int *)malloc((ncol+1)*sizeof(int));
    if (imagemX[cont]==NULL) { /* Alocar memoria para a matriz de pixels */
      printf("Falha na alocacao de memoria - 1\n");
      exit(1);
    }
  }
  for (lin=0;lin<nlin;lin++) {
    for (col=0;col<ncol;col++) {
      fscanf(fpin,"%d ",&imagemX[lin][col]);
    }
  }
}

void ler_imagemP3(void) {
  int cont, col, lin;
  imagemR= (int **)malloc((nlin+1)*sizeof(int *));
  imagemG= (int **)malloc((nlin+1)*sizeof(int *));
  imagemB= (int **)malloc((nlin+1)*sizeof(int *));
  for (cont=0;cont<nlin;cont++) {
    imagemR[cont]=(int *)malloc((ncol+1)*sizeof(int));
    if (imagemR[cont]==NULL) { /* Alocar memoria para a matriz de pixels */
      printf("Falha na alocacao de memoria - 1\n");
      exit(1);
    }
    imagemG[cont]=(int *)malloc((ncol+1)*sizeof(int));
    if (imagemG[cont]==NULL) { /* Alocar memoria para a matriz de pixels */
      printf("Falha na alocacao de memoria - 1\n");
      exit(1);
    }
    imagemB[cont]=(int *)malloc((ncol+1)*sizeof(int));
    if (imagemR[cont]==NULL) { /* Alocar memoria para a matriz de pixels */
      printf("Falha na alocacao de memoria - 1\n");
      exit(1);
    }
  }
  for (lin=0;lin<nlin;lin++) {
    for (col=0;col<ncol;col++) {
      fscanf(fpin,"%d ",&imagemR[lin][col]);
      fscanf(fpin,"%d ",&imagemG[lin][col]);
      fscanf(fpin,"%d ",&imagemB[lin][col]);
    }
  }
} // Fim: ler_imagem

void ler_cabecalho(void) {
     fscanf(fpin,"%s\n",controle);
     fscanf(fpin,"%d %d\n",&ncol,&nlin);
     fscanf(fpin,"%d\n",&grade);
} // Fim: ler_cabecalho

void fechar_arquivos(void) {
  fclose(fpin);
} // Fim: fechar_arquivosc

void GoMenuP1(int valor)
{
    switch (valor)
    {
    case 1:
        desenhaBandaRP1();
        break;
    case 2:
        desenhaBandaGP1();
        break;
    case 3:
        desenhaBandaBP1();
        break;
    case 4:
        desenhaInversaP1();
        break;
    case 5:
        exit(0);
        break;
    }
    glutPostRedisplay();
}

void GoMenuP2(int valor)
{
    switch (valor)
    {
    case 1:
        desenhaBandaRP2();
        break;
    case 2:
        desenhaBandaGP2();
        break;
    case 3:
        desenhaBandaBP2();
        break;
    case 4:
        desenhaInversaP2();
        break;
    case 5:
        exit(0);
        break;
    }
    glutPostRedisplay();
}

void GoMenuP3(int valor)
{
    switch (valor)
    {
    case 1:
        desenhaBandaRP3();
        break;
    case 2:
        desenhaBandaGP3();
        break;
    case 3:
        desenhaBandaBP3();
        break;
    case 4:
        desenhaInversaP3();
        break;
    case 5:
        exit(0);
        break;
    }
    glutPostRedisplay();
}

void desenhaOriginalP1(void) {
     int col, lin, l, c;
     int X;
     glClearColor(0.0,1.0,1.0,0); //Especifica um cor para o fundo
     glClear(GL_COLOR_BUFFER_BIT);
     glBegin(GL_POINTS);
         for (lin=nlin-1, l=0;lin>=0;lin--,l++) {
             for (col=0, c=0;col<ncol;col++, c++) {
                 X=imagemX[l][c];
                 glColor3ub(X,X,X);
                 glVertex2i(col,lin);
            }
       }
     glEnd();
     glFlush();
}

void desenhaOriginalP2(void) {
     int col, lin, l, c;
     int X;
     glClearColor(0.0,1.0,1.0,0); //Especifica um cor para o fundo
     glClear(GL_COLOR_BUFFER_BIT);
     glBegin(GL_POINTS);
         for (lin=nlin-1, l=0;lin>=0;lin--,l++) {
             for (col=0, c=0;col<ncol;col++, c++) {
                 X=imagemX[l][c];
                 glColor3ub(X,X,X);
                 glVertex2i(col,lin);
            }
       }
     glEnd();
     glFlush();
}

void desenhaOriginalP3(void) {
     int col, lin, l, c;
     int R, G, B;
     glClearColor(0.0,1.0,1.0,0); //Especifica um cor para o fundo
     glClear(GL_COLOR_BUFFER_BIT);
     glBegin(GL_POINTS);
         for (lin=nlin-1, l=0;lin>=0;lin--,l++) {
             for (col=0, c=0;col<ncol;col++, c++) {
                 R=imagemR[l][c];
                 G=imagemG[l][c];
                 B=imagemB[l][c];
                 glColor3ub(R,G,B);
                 glVertex2i(col,lin);
            }
       }
     glEnd();
     glFlush();
}

void desenhaProcessadaP3(void) {
     int col, lin, l, c, cor;
     glClearColor(0.0,1.0,1.0,0); //Especifica um cor para o fundo
     glClear(GL_COLOR_BUFFER_BIT);
     glBegin(GL_POINTS);
         for (lin=nlin-1, l=0;lin>=0;lin--,l++) {
             for (col=0, c=0;col<ncol;col++, c++) {
                 cor=(imagemR[l][c]+imagemG[l][c]+imagemB[l][c])/3;
                 glColor3ub(cor,cor,cor);
                 glVertex2i(col,lin);
            }
       }
     glEnd();
     glFlush();
}

void desenhaInversaP1(void)
{

}

void desenhaBandaRP1(void)
{

}

void desenhaBandaGP1(void)
{

}

void desenhaBandaBP1(void)
{

}

void desenhaInversaP2(void)
{
    int col,lin, l, c, cor, corinversa;
    glClearColor(0.0,1.0,1.0,0); //especifica uma cor para o fundo
    glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_POINTS);
    for(lin=nlin-1, l=0;lin>=0;lin--,l++) {
        for (col=0, c=0;col<ncol;col++, c++){
            cor = (imagemX[l][c]);
            corinversa = 255-cor;
            glColor3ub(corinversa,corinversa,corinversa);
            glVertex2i(col,lin);
        }
    }
	glutDisplayFunc(desenhaInversaP2);
    glEnd();
    glFlush;
}

void desenhaBandaRP2(void)
{
    int col, lin, l, c, cor;
        glClearColor(0.0,1.0,1.0,0); //Especifica um cor para o fundo
        glClear(GL_COLOR_BUFFER_BIT);
        glBegin(GL_POINTS);
         for (lin=nlin-1, l=0;lin>=0;lin--,l++)
         {
             for (col=0, c=0;col<ncol;col++, c++)
             {
                 cor=(imagemX[l][c]);
                 glColor3ub(cor,0,0);
                 glVertex2i(col,lin);
             }
         }
	glutDisplayFunc(desenhaBandaRP2);
     glEnd();
     glFlush();
}

void desenhaBandaGP2(void)
{
    int col, lin, l, c, cor;
        glClearColor(0.0,1.0,1.0,0); //Especifica um cor para o fundo
        glClear(GL_COLOR_BUFFER_BIT);
        glBegin(GL_POINTS);
         for (lin=nlin-1, l=0;lin>=0;lin--,l++)
         {
             for (col=0, c=0;col<ncol;col++, c++)
             {
                 cor=(imagemX[l][c]);
                 glColor3ub(0,cor,0);
                 glVertex2i(col,lin);
             }
         }
	glutDisplayFunc(desenhaBandaGP2);
     glEnd();
     glFlush();
}

void desenhaBandaBP2(void)
{
    int col, lin, l, c, cor;
        glClearColor(0.0,1.0,1.0,0); //Especifica um cor para o fundo
        glClear(GL_COLOR_BUFFER_BIT);
        glBegin(GL_POINTS);
         for (lin=nlin-1, l=0;lin>=0;lin--,l++)
         {
             for (col=0, c=0;col<ncol;col++, c++)
             {
                 cor=(imagemX[l][c]);
                 glColor3ub(0,0,cor);
                 glVertex2i(col,lin);
             }
         }
	glutDisplayFunc(desenhaBandaBP2);
     glEnd();
     glFlush();
}

void desenhaBandaRP3(void)
{
    int col, lin, l, c, cor;
        glClearColor(0.0,1.0,1.0,0); //Especifica um cor para o fundo
        glClear(GL_COLOR_BUFFER_BIT);
        glBegin(GL_POINTS);
         for (lin=nlin-1, l=0;lin>=0;lin--,l++)
         {
             for (col=0, c=0;col<ncol;col++, c++)
             {
                 cor=(imagemR[l][c]);
                 glColor3ub(cor,0,0);
                 glVertex2i(col,lin);
             }
         }
	glutDisplayFunc(desenhaBandaRP3);
     glEnd();
     glFlush();
}

void desenhaBandaGP3(void)
{
    int col, lin, l, c, cor;
        glClearColor(0.0,1.0,1.0,0); //Especifica um cor para o fundo
        glClear(GL_COLOR_BUFFER_BIT);
        glBegin(GL_POINTS);
         for (lin=nlin-1, l=0;lin>=0;lin--,l++)
         {
             for (col=0, c=0;col<ncol;col++, c++)
             {
                 cor=(imagemG[l][c]);
                 glColor3ub(0,cor,0);
                 glVertex2i(col,lin);
             }
         }
	glutDisplayFunc(desenhaBandaGP3);
     glEnd();
     glFlush();
}

void desenhaBandaBP3(void)
{
    int col, lin, l, c, cor;
        glClearColor(0.0,1.0,1.0,0); //Especifica um cor para o fundo
        glClear(GL_COLOR_BUFFER_BIT);
        glBegin(GL_POINTS);
         for (lin=nlin-1, l=0;lin>=0;lin--,l++)
         {
             for (col=0, c=0;col<ncol;col++, c++)
             {
                 cor=(imagemB[l][c]);
                 glColor3ub(0,0,cor);
                 glVertex2i(col,lin);
             }
         }
	glutDisplayFunc(desenhaBandaBP3);
     glEnd();
     glFlush();
}

void desenhaInversaP3(void)
{
    int col,lin, l, c, cor, corinversa;
    glClearColor(0.0,1.0,1.0,0); //especifica uma cor para o fundo
    glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_POINTS);
    for(lin=nlin-1, l=0;lin>=0;lin--,l++) {
        for (col=0, c=0;col<ncol;col++, c++){
            cor = (imagemR[l][c]+imagemG[l][c]+imagemB[l][c])/3;
            corinversa = 255-cor;
            glColor3ub(corinversa,corinversa,corinversa);
            glVertex2i(col,lin);
        }
    }
	glutDisplayFunc(desenhaInversaP3);
    glEnd();
    glFlush;
}

void Inicializa(void) {
	// Exibição Bidimensional
	gluOrtho2D(0, ncol, 0, nlin);

}//fim da funcao inicializa

int main(int argc, char *argv[]) {
  int subl;
  abrir_arquivos(argc,argv);
  ler_cabecalho();

  if((strcmp(controle, "P1")) == 0)
    ler_imagemP1();
  else if((strcmp(controle, "P2")) == 0)
    ler_imagemP2();
  else if((strcmp(controle, "P3")) == 0)
    ler_imagemP3();

  fechar_arquivos();

  glutInit(&argc,argv);

  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);

 //----------- Primeira Tela  - Original ----------------

     glutInitWindowPosition(10,35);
     glutInitWindowSize(ncol,nlin);
     glutCreateWindow("Foto Original");

    if((strcmp(controle, "P1")) == 0)
     {
        subl = glutCreateMenu(GoMenuP1);
        glutDisplayFunc(desenhaOriginalP1);
     }
     else if((strcmp(controle, "P2")) == 0)
     {
        subl = glutCreateMenu(GoMenuP2);
        glutDisplayFunc(desenhaOriginalP2);
     }
     else if((strcmp(controle, "P3")) == 0)
     {
        subl = glutCreateMenu(GoMenuP3);
        glutDisplayFunc(desenhaOriginalP3);
     }
     // Chama a função responsável por fazer as inicializações
 	Inicializa();

 //FIM Primeira Tela



 //----------- Segunda Tela  - Processada ----------------

    glutInitWindowPosition(ncol+60,35);
    glutInitWindowSize(ncol,nlin);
    glutCreateWindow("Foto Processada");

    if((strcmp(controle, "P1")) == 0)
        glutDisplayFunc(desenhaOriginalP1);
    else if((strcmp(controle, "P2")) == 0)
        glutDisplayFunc(desenhaOriginalP2);
    else if((strcmp(controle, "P3")) == 0)
        glutDisplayFunc(desenhaOriginalP3);

    glutAddMenuEntry("Vermelho",1);
    glutAddMenuEntry("Verde",2);
    glutAddMenuEntry("Azul",3);
    glutAddMenuEntry("Invertida",4);

    if((strcmp(controle, "P1")) == 0)
        glutCreateMenu(GoMenuP1);
    else if((strcmp(controle, "P2")) == 0)
        glutCreateMenu(GoMenuP2);
    else if((strcmp(controle, "P3")) == 0)
        glutCreateMenu(GoMenuP3);

    glutAddSubMenu("Cores",subl);
    glutAddMenuEntry("Sair",5);
    glutAttachMenu(GLUT_RIGHT_BUTTON);


     // Chama a função responsável por fazer as inicializações
 	Inicializa();



 //FIM  Segunda Tela


	 glutMainLoop();

    return 0;

}
