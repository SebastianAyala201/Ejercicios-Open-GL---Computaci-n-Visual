#include <GL/glut.h>
#include <iostream>

// Declaración de funciones
void inicio();
void pantalla();
void LINEA(int x0, int y0, int x1, int y1);
void ingresoDatos();

// Variables globales para los puntos
int px0, py0, px1, py1;

int main(int argc, char *argv[]) {
    ingresoDatos();
    glutInit(&argc, argv);
    glutInitWindowSize(1024, 768);
    glutInitWindowPosition(10, 10);
    glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
    glutCreateWindow("Lineas con el algoritmo de punto medio");
    inicio();
    glutDisplayFunc(pantalla);
    glutMainLoop();
    return EXIT_SUCCESS;
}

void inicio() {
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(-25, 25, -25, 25); // Expande el área de visualización
    glClearColor(1.0, 1.0, 1.0, 1.0); // Color de fondo
}

void pantalla() {
    glClear(GL_COLOR_BUFFER_BIT);

    // Lineas cuadriculares verdes
    glColor3f(0.0, 1.0, 0.0);
    glBegin(GL_LINES);

    // Dibujar líneas horizontales
    for (int x = -100; x <= 100; ++x) {
        glVertex2f(-100, x);
        glVertex2f(100, x);
    }

    // Dibujar líneas verticales
    for (int y = -100; y <= 100; ++y) {
        glVertex2f(y, -100);
        glVertex2f(y, 100);
    }

    glEnd();

    glColor3f(0.0, 0.0, 1.0); // Color de la figura o línea
    glBegin(GL_LINES);
    glVertex2f(150, 0);
    glVertex2f(-150, 0);
    glVertex2f(0, 150);
    glVertex2f(0, -150);
    glEnd();

    // Dibuja la línea utilizando el algoritmo de punto medio
    glColor3f(1.0, 0.0, 0.0); // Color de la línea roja
    glPointSize(5); // Ajusta el tamaño de los puntos
    glBegin(GL_POINTS); // Comienza a dibujar puntos
    LINEA(px0, py0, px1, py1);
    glEnd(); // Termina de dibujar puntos

    glFlush(); // Asegura que las órdenes de dibujo se ejecuten
}

// Algoritmo de punto medio para dibujar una línea
void LINEA(int x0, int y0, int x1, int y1) {
    int dx = abs(x1 - x0);
    int dy = abs(y1 - y0);
    int sx = (x0 < x1) ? 1 : -1;
    int sy = (y0 < y1) ? 1 : -1;
    int err = dx - dy;

    while (true) {
        glVertex2i(x0, y0); // Dibuja el punto

        if (x0 == x1 && y0 == y1) break;
        int e2 = 2 * err;
        if (e2 > -dy) {
            err -= dy;
            x0 += sx;
        }
        if (e2 < dx) {
            err += dx;
            y0 += sy;
        }
    }
}

void ingresoDatos() {
    // Solicita al usuario ingresar los datos de los puntos
    std::cout << "Ingrese las coordenadas del primer punto (x0, y0): ";
    std::cin >> px0 >> py0;
    std::cout << "Ingrese las coordenadas del segundo punto (x1, y1): ";
    std::cin >> px1 >> py1;
}
