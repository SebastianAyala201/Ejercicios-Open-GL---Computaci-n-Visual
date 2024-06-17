// Algoritmo DDA en el tercer cuadrante

#include<GL/glut.h>
#include <cmath>


void inicio(){
    glMatrixMode(GL_PROJECTION); 
    gluOrtho2D(-25,25,-25,25); // Define una proyección ortográfica 2D
    glClearColor(1.0, 1.0, 1.0, 1.0); // Color de fondo
}

// Función para dibujar una línea dda en el tercer cuadrante
void recta_dda(int x0, int y0, int x1, int y1) {
    float dx, dy, m;
    dx = x1 - x0;
    dy = y1 - y0;
    m = dy / dx;

    if (fabs(m) < 1) {
        if (x0 > x1) {
            // Intercambiar puntos si x0 es mayor que x1
            std::swap(x0, x1);
            std::swap(y0, y1);
        }
        float y = y0;
        for (int x = x0; x <= x1; x++) {
            glPointSize(3);
            glBegin(GL_POINTS);
            glVertex2f(x, round(y));
            glEnd();
            y += m;
        }
    }  
    else {
        if (y0 > y1) {
            // Intercambiar puntos si y0 es mayor que y1
            std::swap(x0, x1);
            std::swap(y0, y1);
        }
        float x = x0;
        for (int y = y0; y <= y1; y++) {
            glPointSize(3);
            glBegin(GL_POINTS);
            glVertex2f(round(x), y);
            glEnd();
            x += 1/m;
        }
    }
}

void pantalla(){
    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(0.0,1.0,0.0);
    int a=-50;
    glBegin(GL_LINES);
        for(int i=0;i<=100;i++){
            glVertex2f(-50,a);
            glVertex2f(50,a);

            glVertex2f(a,50);
            glVertex2f(a,-50);
            a++;
        }
    glEnd();
    
    glColor3f(0.0,0.0,1.0); //Color de la figura o línea
    glBegin(GL_LINES);
        glVertex2f(150,0);
        glVertex2f(-150,0);
        glVertex2f(0,150);
        glVertex2f(0,-150);
    glEnd();
    
    // Dibuja la línea en el tercer cuadrante
    glColor3f(1.0, 0.0, 0.0); // Color de la línea roja
    recta_dda(-2,-3,-14, -23);

    glFlush(); // Asegura que las órdenes de dibujo se ejecuten
}


int main(int argc, char *argv[]){
    glutInit(&argc, argv);
    glutInitWindowSize(680,480); 
    glutInitWindowPosition(10,10); 
    glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE); 
    glutCreateWindow("Algoritmo DDA en el tercer cuadrante"); // Crea una ventana con el título especificado
    inicio(); 
    glutDisplayFunc(pantalla); 
    glutMainLoop();
    return EXIT_SUCCESS;
}
