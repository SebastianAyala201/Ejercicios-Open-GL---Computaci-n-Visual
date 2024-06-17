// Algoritmo del Punto Medio para Elipse

#include <GL/glut.h>
#include <cmath>
#include <iostream>

// Variables globales para almacenar los parametros de la elipse
int a, b;
float color_r, color_g, color_b;
int grosor;

// Configuración inicial de la ventana
void inicio() {
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(-50, 50, -50, 50); // Define una proyección ortográfica 2D
    glClearColor(1.0, 1.0, 1.0, 1.0); // Color de fondo
}

// Función para pintar un punto con las simetrías de la elipse
void pintar(int x, int y) {
    glBegin(GL_POINTS);
    glVertex2f(x, y); // Primer cuadrante
    glEnd();
}

// Función: Algoritmo del Punto Medio para Elipse
void elipse_punto_medio(int a, int b) {
    int x = 0;
    int y = b;
    float a2 = a * a;
    float b2 = b * b;
    float d1 = b2 - a2 * b + 0.25 * a2;

    // Zona 1
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

    // Zona 2
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

    // Dibuja la elipse con los parametros dados
    glColor3f(color_r, color_g, color_b); // Color de la elipse
    glPointSize(grosor); // Grosor de los puntos
    elipse_punto_medio(a, b);

    glFlush(); // Asegura que las órdenes de dibujo se ejecuten
}

int main(int argc, char* argv[]) {
    // Solicitar parametros al usuario
    std::cout << "Ingrese el valor de a: ";
    std::cin >> a;
    std::cout << "Ingrese el valor de b: ";
    std::cin >> b;
    std::cout << "Ingrese el primer parametro de la terna de color (r): ";
    std::cin >> color_r;
    std::cout << "Ingrese el segundo parametro de la terna de color (g): ";
    std::cin >> color_g;
    std::cout << "Ingrese el tercer parametro de la terna de color (b): ";
    std::cin >> color_b;
    std::cout << "Ingrese el grosor de la elipse: ";
    std::cin >> grosor;

    glutInit(&argc, argv);
    glutInitWindowSize(680, 480);
    glutInitWindowPosition(10, 10);
    glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
    glutCreateWindow("Algoritmo del Punto Medio para Elipse"); // Crea una ventana con el título especificado
    inicio();
    glutDisplayFunc(pantalla);
    glutMainLoop();
    return EXIT_SUCCESS;
}
