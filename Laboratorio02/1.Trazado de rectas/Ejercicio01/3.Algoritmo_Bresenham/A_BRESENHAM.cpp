// Algoritmo Bresenham


#include <GL/glut.h>
#include <cmath>

// Configuración inicial de la ventana
void inicio() {
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(-25, 25, -25, 25); // Define una proyección ortográfica 2D
    glClearColor(1.0, 1.0, 1.0, 1.0); // Color de fondo
}

// Función: Algoritmo de Bresenham
void recta_bresenham(int x0, int y0, int x1, int y1) {
    int dx = abs(x1 - x0), dy = abs(y1 - y0);
    int sx = x0 < x1 ? 1 : -1;
    int sy = y0 < y1 ? 1 : -1;
    int err = dx - dy;

    glPointSize(3);
    glBegin(GL_POINTS);
    while (true) {
        glVertex2f(x0, y0);
        if (x0 == x1 && y0 == y1) break;
        int e2 = err * 2;
        if (e2 > -dy) {
            err -= dy;
            x0 += sx;
        }
        if (e2 < dx) {
            err += dx;
            y0 += sy;
        }
    }
    glEnd();
}

void pantalla() {
    glClear(GL_COLOR_BUFFER_BIT);

    // Líneas cuadriculares verdes
    glColor3f(0.0, 1.0, 0.0);
    glBegin(GL_LINES);
    int a = -50;
    for (int i = 0; i <= 100; i++) {
        glVertex2f(-50, a);
        glVertex2f(50, a);

        glVertex2f(a, 50);
        glVertex2f(a, -50);
        a++;
    }
    glEnd();

    // Ejes de las ordenadas
    glColor3f(0.0, 0.0, 1.0); // Color de la figura o línea
    glBegin(GL_LINES);
    glVertex2f(150, 0);
    glVertex2f(-150, 0);
    glVertex2f(0, 150);
    glVertex2f(0, -150);
    glEnd();

    // Dibuja la línea en el primer cuadrante
    glColor3f(1.0, 0.0, 0.0); // Color de la línea roja
    recta_bresenham(2, 3, 14, 23);
    glFlush(); // Asegura que las órdenes de dibujo se ejecuten
}

int main(int argc, char* argv[]) {
    glutInit(&argc, argv);
    glutInitWindowSize(680, 480);
    glutInitWindowPosition(10, 10);
    glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
    glutCreateWindow("Algoritmo Bresenham en el primer cuadrante"); // Crea una ventana con el título especificado
    inicio();
    glutDisplayFunc(pantalla);
    glutMainLoop();
    return EXIT_SUCCESS;
}
