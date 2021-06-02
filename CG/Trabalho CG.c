#include <stdio.h>
#include <stdlib.h>
#include <GL/glut.h>

FILE *fpin;
int **imagemR, **imagemG, **imagemB, ncol, nlin, grade;

void abrir_arquivos(int argc, char *argv[]);
void ler_cabecalho(void);
void ler_imagem(void);
void fechar_arquivos(void);

void abrir_arquivos(int argc, char *argv[]) {
     if (argc <= 1) {
	    printf("Modo correto de uso: pdi <imagem> <arq_saida>\n");
	  ;//  exit(0);
     }
     if ((fpin=fopen(argv[1],"r"))==NULL) {
	    printf("Nao foi possivel abrir arquivo de imagem %s\n", argv[1]);
	    exit(1);
     }
} // Fim: abrir_arquivos

void ler_imagem(void) {
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
     char controle[4];
     fscanf(fpin,"%s\n",controle);
     fscanf(fpin,"%d %d\n",&ncol,&nlin);
     fscanf(fpin,"%d\n",&grade);
} // Fim: ler_cabecalho

void fechar_arquivos(void) {
  fclose(fpin);
} // Fim: fechar_arquivos

void desenhaOriginal(void) {
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

void desenhaProcessada(void) {
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

void Inicializa(void) {
	// ExibiÃ§Ã£o Bidimensional
	gluOrtho2D(0, ncol, 0, nlin);

}//fim da funcao inicializa

void GerenciaMouse(int button, int state, int x, int y)
{        
    if (button == GLUT_RIGHT_BUTTON)
         if (state == GLUT_DOWN) 
            CriaMenu();
         
    glutPostRedisplay();
}

void CriaMenu() 
{
    int menu;

    menu = glutCreateMenu(MenuCor);
    glutAddMenuEntry("Vermelho",0);
    glutAddMenuEntry("Verde",1);
    glutAddMenuEntry("Azul",2);
 
    glutAttachMenu(GLUT_RIGHT_BUTTON);
}

void MenuCor(int op)
{
   switch(op) {
            case 0:
                     r = 1.0f;
                     g = 0.0f;
                     b = 0.0f;
                     break;
            case 1:
                     r = 0.0f;
                     g = 1.0f;
                     b = 0.0f;
                     break;
            case 2:
                     r = 0.0f;
                     g = 0.0f;
                     b = 1.0f;
                     break;
    }
    glutPostRedisplay();
}
     
int main(int argc, char *argv[]) {
  abrir_arquivos(argc,argv);
  ler_cabecalho();
  ler_imagem();
  fechar_arquivos();

  glutInit(&argc,argv);

  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);

 //----------- Primeira Tela  - Original ----------------

     glutInitWindowPosition(10,35);

     glutInitWindowSize(ncol,nlin);

 	 glutCreateWindow("Foto Original");

     glutDisplayFunc(desenhaOriginal);
	glutMouseFunc(GerenciaMouse);

     // Chama a funÃ§Ã£o responsÃ¡vel por fazer as inicializaÃ§Ãµes
 	Inicializa();

 //FIM Primeira Tela


 //----------- Segunda Tela  - Processada ----------------

     glutInitWindowPosition(ncol+60,35);

 	 glutInitWindowSize(ncol,nlin);

	 glutCreateWindow("Foto Processada");

     glutDisplayFunc(desenhaProcessada);

     // Chama a funÃ§Ã£o responsÃ¡vel por fazer as inicializaÃ§Ãµes
 	Inicializa();


 //FIM  Segunda Tela


	 glutMainLoop();

    return 0;

}
