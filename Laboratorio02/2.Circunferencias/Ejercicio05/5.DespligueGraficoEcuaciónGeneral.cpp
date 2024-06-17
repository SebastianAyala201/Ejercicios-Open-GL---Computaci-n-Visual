#include <GL/glut.h>
#include <cmath>
#include <iostream>

// Variables globales para almacenar los parámetros de la elipse
int a, b;
int grosor;
int h, k; // Variables para el desplazamiento del centro de la elipse

// Configuración inicial de la ventana
void inicio() {
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(-50, 50, -50, 50); // Define una proyección ortográfica 2D
    glClearColor(1.0, 1.0, 1.0, 1.0); // Color de fondo
}

// Función para pintar un punto con las simetrías de la elipse
void pintar(int x, int y) {
    glBegin(GL_POINTS);
    glVertex2f(x + h, y + k); // Primer cuadrante
    glVertex2f(-x + h, y + k); // Segundo cuadrante
    glVertex2f(-x + h, -y + k); // Tercer cuadrante
    glVertex2f(x + h, -y + k); // Cuarto cuadrante
    glEnd();
}

// Función: Algoritmo del Punto Medio para Elipse
void elipse_punto_medio(int a, int b) {
    int x = 0;
    int y = b;
    float a2 = a * a;
    float b2 = b * b;
    float d1 = b2 - a2 * b + 0.25 * a2;

    // Región 1
    while (a2 * (y - 0.5) > b2 * (x + 1)) {
        pintar(x, y);
        if (d1 < 0) {
            d1 += b2 * (2 * x + 3);
        } else {
            d1 += b2 * (2 * x + 3) + a2 * (-2 * y + 2);
            y--;
        }
        x++;
    }

    // Región 2
    float d2 = b2 * (x + 0.5) * (x + 0.5) + a2 * (y - 1) * (y - 1) - a2 * b2;
    while (y > 0) {
        pintar(x, y);
        if (d2 < 0) {
            d2 += b2 * (2 * x + 2) + a2 * (-2 * y + 3);
            x++;
        } else {
            d2 += a2 * (-2 * y + 3);
        }
        y--;
    }
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

    // Dibuja la elipse con los parámetros dados
    glColor3f(1, 0, 0); // Color de la elipse
    glPointSize(3); // Grosor de los puntos
    elipse_punto_medio(a, b);

    glFlush(); // Asegura que las órdenes de dibujo se ejecuten
}

int main(int argc, char* argv[]) {
    // Solicitar parámetros al usuario
    std::cout << "Ingrese el valor de a: ";
    std::cin >> a;
    std::cout << "Ingrese el valor de b: ";
    std::cin >> b;
    std::cout << "Ingrese el desplazamiento en x del centro de la elipse (h): ";
    std::cin >> h;
    std::cout << "Ingrese el desplazamiento en y del centro de la elipse (k): ";
    std::cin >> k;

    glutInit(&argc, argv);
    glutInitWindowSize(680, 480);
    glutInitWindowPosition(10, 10);
    glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
    glutCreateWindow("Algoritmo del Punto Medio para Elipse con ecuacion general"); // Crea una ventana con el título especificado
    inicio();
    glutDisplayFunc(pantalla);
    glutMainLoop();
    return EXIT_SUCCESS;
}
