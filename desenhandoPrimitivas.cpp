	
	#include <GL/glut.h>
	//#include <GL/gl.h>
	#include <ctime>

	GLfloat eixoYTop = 1.0, eixoYBot =0.9;

	void desenhar(){

		time_t tempoAntes = 0, tempoDepois;	
		tempoAntes = time(NULL);		
		
		glClear(GL_COLOR_BUFFER_BIT);
		glColor3f(1.0,1.0,1.0);
		
		/*
		
			A glBegin(flag de interpretação) é uma função que determina o começo da descrição de vértices, ou pontos
		de uma primitiva ou de um grupo de primitivas dentre as 10 possíveis e como elas serão interpretadas através do 
		argumento. O argumento	passado determina que três vértices seguidos serão tratados como um triângulo. glBegin(flag)
		é acompanhada de glEnd(), encerrando a área de declaração de pontos.

		*/		
	
		glBegin(GL_QUADS);
			
			/*

				A matriz de projeção é um campo 2D onde os models serão visualizados. O plano da matriz começa é definido	
			por um quadrada de 1 por 1, ou seja, a origem do plano é (0,0),canto inferior esquerdo, e o limite do plano é (1,1)
			,canto superior direito. Tendo isto mente, a chamda de glVertex define a presença de vértices de baixo para cima na
			tela de projetão de acordo com seus valores: quanto menor o tamanho das cordenadas, mais perto da parte de baixo da
			tela o vértice estará.
			*/			
			
			glVertex3f(0.45,eixoYTop,0.0); 
			glVertex3f(0.6,eixoYTop,0.0);			
			glVertex3f(0.6,eixoYBot,0.0);			
			glVertex3f(0.45,eixoYBot,0.0);

			if(eixoYBot > 0.0){ 
		
				eixoYTop -=0.05;
				eixoYBot -=0.05;						
			
			}
			
			else {
			
				eixoYTop = 1.0;
				eixoYBot =0.9;
	
			}			
			
		glEnd();
		glFlush();
		
		tempoDepois = time(NULL);
		time_t tempo = tempoDepois - tempoAntes;
		
		while(tempo < 1) {

			tempoDepois = time(NULL);

			tempo = tempoDepois - tempoAntes;
	
		}
		
		glutPostRedisplay();

		
			

	}	

	void iniciar(){

		glClearColor(0.0,0.0,0.0,0.0);
		
		//	Esta função determina qual a pilha de matriz vai armazenar a matriz e as operações feitas com a mesma.
		//A pilha de matriz é um estrutura de memória que guarda um determinado tipo de matriz e seus dados dependendo 
		//do seu tipo. A pilha escolhida fará da tela uma matriz do tipo escolhido.
		//	Os tipos de matrizes do OpenGL são 4x4 e se diferenciam pela sua função:
		//		a)GL_MODELVIEW: é uma matriz para operar os models (obejtos) criados. As operações são Translação
		//		  , Rotação e Escalanamento.
		//		b)GL_PROJECTION: é uma matriz para definir o campo de visualização dos models. É uma área da tela
		// 		  que determina o que pode ser visualizado. Mesmo que desenhados foram do campo de visualização, os
		//		  models não serão vistos.
		//		c)GL_TEXTURE;
		// 		d)GL_COLOR; 
		 		
		glMatrixMode(GL_PROJECTION);
		glLoadIdentity(); // Seta a matriz de projeção para o valor Identidade.
		glOrtho(0.0,1.0,0.0,1.0,-1.0,1.0);
		
	}

	int main(int argc, char** argv){

		glutInit(&argc,argv);
		glutInitDisplayMode(GLUT_RGB);
		glutInitWindowPosition(100,100);
		glutInitWindowSize(500,1000);
		glutCreateWindow("Desenhe");
		iniciar();
		glutDisplayFunc(desenhar);
		
		// Criar um loop e chama os callbacks para sempre!

		glutMainLoop();
	

	return 0;	

	}
