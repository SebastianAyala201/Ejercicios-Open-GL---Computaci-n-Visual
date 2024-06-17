#include <GL/glut.h>
#include <cmath>
#include <iostream>

// Variables globales para almacenar los parámetros de la circunferencia
int radio, x_centro, y_centro;
float color_r, color_g, color_b;
int grosor;

// Configuración inicial de la ventana
void inicio() {
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(-50, 50, -50, 50); // Define una proyección ortográfica 2D
    glClearColor(1.0, 1.0, 1.0, 1.0); // Color de fondo
}

// Función para pintar un punto con las simetrías de la circunferencia
void pintar(int x, int y) {
    glBegin(GL_POINTS);
    glVertex2f(x_centro + x, y_centro + y);
    glVertex2f(x_centro - x, y_centro + y);
    glVertex2f(x_centro + x, y_centro - y);
    glVertex2f(x_centro - x, y_centro - y);
    glVertex2f(x_centro + y, y_centro + x);
    glVertex2f(x_centro - y, y_centro + x);
    glVertex2f(x_centro + y, y_centro - x);
    glVertex2f(x_centro - y, y_centro - x);
    glEnd();
}

// Función: Algoritmo del Punto Medio para Circunferencia
void circunferencia_punto_medio(int R) {
    int x = 0;
    int y = R;
    int d = 1 - R;
    pintar(x, y);
    while (x < y) {
        if (d < 0) {
            d += 2 * x + 3;
        } else {
            d += 2 * (x - y) + 5;
            y--;
        }
        x++;
        pintar(x, y);
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

    // Dibuja la circunferencia con los parámetros dados
    glColor3f(color_r, color_g, color_b); // Color de la circunferencia
    glPointSize(grosor); // Grosor de los puntos
    circunferencia_punto_medio(radio);

    glFlush(); // Asegura que las órdenes de dibujo se ejecuten
}

int main(int argc, char* argv[]) {
    // Solicitar parámetros al usuario
    std::cout << "Ingrese el radio de la circunferencia: ";
    std::cin >> radio;
    std::cout << "Ingrese la abcisa del centro: ";
    std::cin >> x_centro;
    std::cout << "Ingrese la ordenada del centro: ";
    std::cin >> y_centro;
    std::cout << "Ingrese el primer parametro de la terna de color (r): ";
    std::cin >> color_r;
    std::cout << "Ingrese el segundo parametro de la terna de color (g): ";
    std::cin >> color_g;
    std::cout << "Ingrese el tercer parametro de la terna de color (b): ";
    std::cin >> color_b;
    std::cout << "Ingrese el grosor de la circunferencia: ";
    std::cin >> grosor;

    glutInit(&argc, argv);
    glutInitWindowSize(680, 480);
    glutInitWindowPosition(10, 10);
    glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
    glutCreateWindow("Algoritmo del Punto Medio para Circunferencia"); // Crea una ventana con el título especificado
    inicio();
    glutDisplayFunc(pantalla);
    glutMainLoop();
    return EXIT_SUCCESS;
}
