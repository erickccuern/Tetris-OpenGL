

	#include <GL/glut.h>
	#include <GL/gl.h>

	void render(){

		//	Esta função reseta o buffer de cor do frame através da flag GL_COLOR_BUFFER_BIT. Quando 
		//se cria e exibe frames em sequência pode acontecer de informações do frames mais recente serem 
		//escritas no novo frame. Para resolver isso, essa função limpa o buffer de cor do frame, setando-o  
		//para preto(default) e deixando o fundo do frame preto. 
		// 	O que aparece no frame não é o que está armazenado no buffer frame. Quando se desenha algo no
		//buffer do frame é necessário chamar outra função para que a informação do buffef seja exibida. Qualquer
		//mudança no buffer do frame só será exibido com a determinada função.
		//	A cor default para a função clear pode ser mudada.	
			
		glClear(GL_COLOR_BUFFER_BIT);

		//	Restaura a matriz de píxeis do frame passado para as configurações padrões. Assim, ao que se exibe 
		//uma nova tela, as mudanças na matriz do frame passado são apagadas para que a matriz do frame novo possa ser
		//manipulada do zero.
			
		glLoadIdentity();

		//	Exibe o que está armazenado no buffer do frame.

		glFlush();
		

	}

	void setCorDefault(){

		//	Seta a cor padrão usada pela função glClear(). Essa função tem 4 argumentos do tipo double
		//que correspondem à intensidade do Vermelho, do Verde , do Azul e de um componente Alfa, usado quando
		//a flag de inicialização da glutInitDisplay() for GLUT_RGBA.
		// A intensidade varia de 0.0 a 1.0.
		
		glClearColor(0.3333,0.899999,0.4,0.0);

	}

	int main(int argc, char **argv){

		glutInit(&argc, argv);

		//	Esta função inicializa o modo de exibição da janela e recebe constantes inteiras
		//existentes na API GLUT. Essas constantes especificam quais buffers serão usados e qual
		//o sistemas de cores da janela na implementação abaixo.
		//	Essa função pode receber vários argumentos.	

		glutInitDisplayMode(GLUT_RGBA);
	
		//	Se a função acima tiver mais um buffer especificado, a render não vai funcionar.
		//Isso pode ocorrer porque os outros buffers também afetam a exibição do frame e mesmo que
		//o buffer de cor seja resetado, os demais ainda podem sobrescrever o buffer de cor.	
		
		glutInitWindowPosition(100,100);
		glutInitWindowSize(5000,5000);
		glutCreateWindow("Hello world!");
		
		//	Esta função é um callback da API. Algumas operações necessitam de um callback  
		//para serem executadas. No caso da glutInitDisplayMode() o seu callback e a função a-
		//baixo. O parâmetro desta função é um ponteiro para uma função que retorna void e não  
		//tem argumentos: void (* ptr) (void).
		//	Sempre que uma janela for exibida ou sofrer alguma alteração, é necessaŕio usar 
		//um callback de Dislplay. No caso, são especificados o modo de exibição, a posição e o
		//tamanho iniciais para então criar a janela. Isto são operações de Display, logo, neces-
		//secitam de um callback para Display. Por isso que o mesmo vem após as operações com um
		//Display.

		//setCorDefault();	

		glutDisplayFunc(render);

		// O código acima cria uma janela com um tamanho, modo de exibição e posição iniciais.
		//Porém, ao compilar, as funções serão executadas e o programa fechará. Para impedir que
		//o programa feche quando executar a última função, usa-se um loop. Enquanto este loop existir
		//o programa continuará em execução.
		
		glutMainLoop();
 

	return 0;	

	}
