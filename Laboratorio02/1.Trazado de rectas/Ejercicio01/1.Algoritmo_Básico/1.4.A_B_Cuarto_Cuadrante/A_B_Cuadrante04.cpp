// Algoritmo basico en el cuarto cuadrante

#include<GL/glut.h>
#include <cmath>


void inicio(){
    glMatrixMode(GL_PROJECTION); 
    gluOrtho2D(-25,25,-25,25); // Define una proyección ortográfica 2D
    glClearColor(1.0, 1.0, 1.0, 1.0); // Color de fondo
}

// Función: Algoritmo basico
void recta_simple(int x0, int y0, int x1, int y1) {
    float dx, dy, m, y, b;
    dx = x1 - x0;
    dy = y1 - y0;

    if(dx != 0){
        m = dy/dx;
        b = y0 - m * x0;
        y=y0;
        if(x1>x0){
            for (int x = x0; x <= x1; x++) {
                glPointSize(3);
                glBegin(GL_POINTS);
                glVertex2f(x, round(y));
                glEnd();
                y = m * x + b;
            }       
        }else{
            for (int x = x0; x >= x1; x--) {
                glPointSize(3);
                glBegin(GL_POINTS);
                glVertex2f(x, round(y));
                glEnd();
                y = m * x + b;
            } 
        }
    }

}

void pantalla(){
    glClear(GL_COLOR_BUFFER_BIT);

    // Lineas cuadriculares verdes
    glColor3f(0.0,1.0,0.0);
    glBegin(GL_LINES);
        int a=-50;
        for(int i=0;i<=100;i++){
            glVertex2f(-50,a);
            glVertex2f(50,a);

            glVertex2f(a,50);
            glVertex2f(a,-50);
            a++;
        }
    glEnd();
    
    // Ejes de las ordenadas
    glColor3f(0.0,0.0,1.0); //Color de la figura o línea
    glBegin(GL_LINES);
        glVertex2f(150,0);
        glVertex2f(-150,0);
        glVertex2f(0,150);
        glVertex2f(0,-150);
    glEnd();
    
    // Dibuja la línea en el cuarto cuadrante
    glColor3f(1.0, 0.0, 0.0); // Color de la línea roja
    recta_simple(2,-3, 14, -23);

    glFlush(); // Asegura que las órdenes de dibujo se ejecuten
}


int main(int argc, char *argv[]){
    glutInit(&argc, argv);
    glutInitWindowSize(680,480); 
    glutInitWindowPosition(10,10); 
    glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE); 
    glutCreateWindow("Algoritmo Basico en el cuarto cuadrante"); // Crea una ventana con el título especificado
    inicio(); 
    glutDisplayFunc(pantalla); 
    glutMainLoop();
    return EXIT_SUCCESS;
}