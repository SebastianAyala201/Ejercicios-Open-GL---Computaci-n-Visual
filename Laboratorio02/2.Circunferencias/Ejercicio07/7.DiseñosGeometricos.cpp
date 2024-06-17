#include <GL/glut.h>
#include <cmath>
#include <iostream>

void inicio();
void pantalla();
void LINEA (int x0, int y0, int x1, int y1);
void ingresoDatos();
void CIRCLE (int xc, int yc, int r);
void SQUARE(int xc, int yc, int r);
void CORNER_CIRCLES(int xc, int yc, int r);
void LINES(int xc, int yc, int r);

int main(int argc, char *argv[]) {
    glutInit(&argc, argv);
    glutInitWindowSize(1024, 768);
    glutInitWindowPosition(30, 10);
    glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
    glutCreateWindow("Disenios Geometricos");
    inicio();
    glutDisplayFunc(pantalla);
    glutMainLoop();
    return EXIT_SUCCESS;
}

// Configuración inicial de la ventana
void inicio() {
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(-100, 100, -100, 100); // Define una proyección ortográfica 2D
    glClearColor(1.0, 1.0, 1.0, 1.0); // Color de fondo
}

// Función principal de dibujo
void pantalla(){
    int xc = 0, yc = 0, r = 80;

    glClear(GL_COLOR_BUFFER_BIT);

    // Dibujar líneas de cuadrícula verde
    glColor3f(0.0, 1.0, 0.0);
    glBegin(GL_LINES);
    for (int x = -100; x<= 100; ++x) {
        glVertex2f(-100, x);
        glVertex2f(100, x);
    }
    for (int y = -100; y<= 100; ++y) {
        glVertex2f(y, -100);
        glVertex2f(y, 100);
    }
    glEnd();

    // Dibujar ejes azules
    glColor3f(0.0, 0.0, 1.0);
    glBegin(GL_LINES);
    glVertex2f(150, 0);
    glVertex2f(-150, 0);
    glVertex2f(0, 150);
    glVertex2f(0, -150);
    glEnd();

    // Dibujar círculo, cuadrado, círculos en esquinas y líneas
    glColor3f(0.0, 0.0, 0.0); // Color rojo
    glPointSize(2);

    CIRCLE(xc, yc, r);
    SQUARE(xc, yc, r);
    CORNER_CIRCLES(xc, yc, r);
    LINES(xc, yc, r);
    glFlush();
}

// Función para dibujar un círculo usando el algoritmo de punto medio
void CIRCLE(int xc, int yc, int r) {
    int x = 0;
    int y = r;
    int d = 1 - r;

    glBegin(GL_POINTS);
    while (x <= y) {
        // Dibujar puntos en los 8 octantes
        glVertex2i(xc + x, yc + y);
        glVertex2i(xc - x, yc + y);
        glVertex2i(xc + x, yc - y);
        glVertex2i(xc - x, yc - y);
        glVertex2i(xc + y, yc + x);
        glVertex2i(xc - y, yc + x);
        glVertex2i(xc + y, yc - x);
        glVertex2i(xc - y, yc - x);

        if (d < 0) {
            d += 2 * x + 3;
        } else {
            d += 2 * (x - y) + 5;
            y--;
        }
        x++;
    }
    glEnd();
}

// Función para dibujar un cuadrado alrededor del círculo
void SQUARE(int xc, int yc, int r) {
    int halfSide = r / 2;
    int left = xc - halfSide/sqrt(2);
    int right = xc + halfSide/sqrt(2);
    int top = yc + halfSide/sqrt(2);
    int bottom = yc - halfSide/sqrt(2);

    glBegin(GL_POINTS);

    // Dibujar los 4 lados del cuadrado usando el algoritmo de Bresenham
    int x0 = left, y0 = top, x1 = right, y1 = top;
    int dx = abs(x1 - x0);
    int dy = abs(y1 - y0);
    int sx = (x0 < x1) ? 1 : -1;
    int sy = (y0 < y1) ? 1 : -1;
    int err = dx - dy;

    while (true) {
        glVertex2i(x0, y0);

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

    // Lado inferior
    x0 = left, y0 = bottom, x1 = right, y1 = bottom;
    dx = abs(x1 - x0);
    dy = abs(y1 - y0);
    sx = (x0 < x1) ? 1 : -1;
    sy = (y0 < y1) ? 1 : -1;
    err = dx - dy;

    while (true) {
        glVertex2i(x0, y0);

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

    // Lado izquierdo
    x0 = left, y0 = top, x1 = left, y1 = bottom;
    dx = abs(x1 - x0);
    dy = abs(y1 - y0);
    sx = (x0 < x1) ? 1 : -1;
    sy = (y0 < y1) ? 1 : -1;
    err = dx - dy;

    while (true) {
        glVertex2i(x0, y0);

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

    // Lado derecho
    x0 = right, y0 = top, x1 = right, y1 = bottom;
    dx = abs(x1 - x0);
    dy = abs(y1 - y0);
    sx = (x0 < x1) ? 1 : -1;
    sy = (y0 < y1) ? 1 : -1;
    err = dx - dy;

    while (true) {
        glVertex2i(x0, y0);

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

    glEnd();
}

// Función para dibujar círculos en las esquinas del cuadrado
void CORNER_CIRCLES(int xc, int yc, int r) {
    int halfSide =1 +r / sqrt(2);

    int left = xc - halfSide/sqrt(3);
    int right = xc + halfSide/sqrt(3);
    int top = yc + halfSide/sqrt(3);
    int bottom = yc - halfSide/sqrt(3);

    int cornerCircleRadius = r - halfSide/1.21;

    auto drawCircle = [](int xc, int yc, int r) {
        int x = 0;
        int y = r;
        int d = 1 - r;
        glBegin(GL_POINTS);
        while (x <= y) {
            // Dibujar puntos en los 8 octantes
            glVertex2i(xc + x, yc + y);
            glVertex2i(xc - x, yc + y);
            glVertex2i(xc + x, yc - y);
            glVertex2i(xc - x, yc - y);
            glVertex2i(xc + y, yc + x);
            glVertex2i(xc - y, yc + x);
            glVertex2i(xc + y, yc - x);
            glVertex2i(xc - y, yc - x);

            if (d < 0) {
                d += 2 * x + 3;
            } else {
                d += 2 * (x - y) + 5;
                y--;
            }
            x++;
        }
        glEnd();
    };

    // Dibujar los 4 círculos en las esquinas del cuadrado
    drawCircle(left, top, cornerCircleRadius);
    drawCircle(right, top, cornerCircleRadius);
    drawCircle(left, bottom, cornerCircleRadius);
    drawCircle(right, bottom, cornerCircleRadius);
}

// Función para dibujar líneas diagonales desde el centro del círculo a las esquinas del cuadrado
void LINES(int xc, int yc, int r) {
    int halfSide = r / sqrt(2);

    int leftTopX = xc - halfSide;
    int leftTopY = yc + halfSide;
    int rightTopX = xc + halfSide;
    int rightTopY = yc + halfSide;

    auto drawLine = [](int x0, int y0, int x1, int y1) {
        int dx = abs(x1 - x0);
        int dy = abs(y1 - y0);
        int sx = (x0 < x1) ? 1 : -1;
        int sy = (y0 < y1) ? 1 : -1;
        int err = dx - dy;

        glBegin(GL_POINTS);
        while (true) {
            glVertex2i(x0, y0);

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
        glEnd();
    };

    // Dibujar las líneas diagonales
    drawLine(xc, yc, leftTopX, leftTopY);
    drawLine(xc, yc, rightTopX, rightTopY);
}
