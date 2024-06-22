//Cardioide hacia la izquierda

#include <GL/glut.h>
#include <cmath>

void inicio() {
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(-250, 250, -250, 250); // Define una proyección ortográfica 2D
    glClearColor(0.0, 0.0, 0.0, 1.0); // Color de fondo negro
}

void pantalla() {
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1,1,1);
    glLineWidth(3);
    glBegin(GL_LINES);
    glVertex2f(-250,0);
    glVertex2f(250,0);
    glVertex2f(0,250);
    glVertex2f(0,-250);
    glEnd();

    glColor3f(1.0, 0.0, 1.0); // Color de la línea turquesa
    glLineWidth(3);
    glBegin(GL_LINE_LOOP); // Usamos GL_LINE_STRIP para conectar todos los puntos
    for (float t = 0; t <= 2* M_PI; t += 0.01) {
        float x = (1 - cos(2*t)) * cos(t) * 100;
        float y = (1 - cos( t)) * sin( t) * 100;
        glVertex2f(x, y);
    }
    glEnd();

    glFlush(); // Asegura que las órdenes de dibujo se ejecuten
}

int main(int argc, char *argv[]) {
    glutInit(&argc, argv);
    glutInitWindowSize(680, 480);
    glutInitWindowPosition(10, 10);
    glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
    glutCreateWindow("Cardioide hacia la izquierda"); // Crea una ventana con el título especificado
    inicio();
    glutDisplayFunc(pantalla);
    glutMainLoop();
    return EXIT_SUCCESS;
}
