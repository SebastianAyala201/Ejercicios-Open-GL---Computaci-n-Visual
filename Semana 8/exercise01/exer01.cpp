// Dibujando un cubo abierto

#include<GL/glut.h>

void inicio(){
    glMatrixMode(GL_PROJECTION); 
    gluOrtho2D(-40,100,-40,100); // Define una proyección ortográfica 2D
    glClearColor(1.0, 1.0, 1.0, 1.0); // Color de fondo
}

void pantalla(){
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0,0.0,0.0); //Color de la figura o línea
    glBegin(GL_LINE_LOOP);
    glVertex2f(20,0);
    glVertex2f(20,50);
    glVertex2f(60,50);
    glVertex2f(60,0);
    glEnd();

    glColor3f(1.0,0.0,0.0); //Color de la figura o línea
    glBegin(GL_LINE_LOOP);
    glVertex2f(0,60);
    glVertex2f(0,10);
    glVertex2f(20,0);
    glVertex2f(20,50);
    glEnd();

    glColor3f(1.0,0.0,0.0); //Color de la figura o línea
    glBegin(GL_LINE_LOOP);
    glVertex2f(0,60);
    glVertex2f(40,60);
    glVertex2f(60,50);
    glVertex2f(20,50);
    glEnd();
    glFlush(); // Asegura que las órdenes de dibujo se ejecuten
}

int main(int argc, char *argv[]){
    glutInit(&argc, argv);
    glutInitWindowSize(680,480); 
    glutInitWindowPosition(10,10); 
    glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE); 
    glutCreateWindow("Cubo con la funcion glLines"); // Crea una ventana con el título especificado
    inicio(); 
    glutDisplayFunc(pantalla); 
    glutMainLoop();
    return EXIT_SUCCESS;
}