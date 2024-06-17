#include <GL/glut.h>
#include <cmath>
#include <iostream>

// Radio de la circunferencia
int R;

// Función para inicializar la ventana de OpenGL
void init() {
    glClearColor(1.0, 1.0, 1.0, 1.0); // Color de fondo blanco
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
    
    glColor3f(0.0, 0.0, 0.0);         // Color de los puntos negro
    glPointSize(2.0);                 // Tamaño de los puntos
    gluOrtho2D(-150.0, 150.0, -150.0, 150.0); // Rango de las coordenadas
}

// Función para pintar un punto en la circunferencia
void pintar(float x, float y) {
    glBegin(GL_POINTS);
    glVertex2f(x, y);
    glEnd();
}

// Técnica 1: Circunferencia Paramétrica
void circunferencia_parametrica(int R) {
    float PI = 3.1415;
    float teta = 0;
    float delta = 0.1;
    while (teta < 2 * PI) {
        float x = R * cos(teta);
        float y = R * sin(teta);
        pintar(x, y);
        teta += delta;
    }
}

// Técnica 2: Circunferencia Explícita
void circunferencia_explicita(int R) {
    for (int x = 0; x <= R; x++) {
        float y = sqrt(R * R - x * x);
        pintar(x, y);
        pintar(-x, y);
        pintar(x, -y);
        pintar(-x, -y);
        pintar(y, x);
        pintar(-y, x);
        pintar(y, -x);
        pintar(-y, -x);
    }
}

// Técnica 3: Circunferencia del Punto Medio
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
        pintar(-x, y);
        pintar(x, -y);
        pintar(-x, -y);
        pintar(y, x);
        pintar(-y, x);
        pintar(y, -x);
        pintar(-y, -x);
    }
}

// Función de dibujado
void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    // Líneas cuadriculares verdes
    glColor3f(0.0, 1.0, 0.0);
    glBegin(GL_LINES);
    int a = -500;
    for (int i = 0; i <= 1000; i++) {
        glVertex2f(-500, a);
        glVertex2f(500, a);

        glVertex2f(a, 500);
        glVertex2f(a, -500);
        a++;
    }
    glEnd();

    // Ejes de las ordenadas
    glColor3f(0.0, 0.0, 1.0); // Color de la figura o línea
    glBegin(GL_LINES);
    glVertex2f(750, 0);
    glVertex2f(-750, 0);
    glVertex2f(0, 1500);
    glVertex2f(0, -1500);
    glEnd();
    

    // Técnica 1
    glViewport(0, 0, 250, 500);
    glPushMatrix();
    glTranslatef(-100, 0, 0);
    circunferencia_parametrica(R);
    glPopMatrix();

    // Técnica 2
    glViewport(250, 0, 250, 500);
    glPushMatrix();
    glTranslatef(0, 0, 0);
    circunferencia_explicita(R);
    glPopMatrix();

    // Técnica 3
    glViewport(500, 0, 250, 500);
    glPushMatrix();
    glTranslatef(100, 0, 0);
    circunferencia_punto_medio(R);
    glPopMatrix();

    glFlush();
}

// Función principal
int main(int argc, char** argv) {
    std::cout << "Ingrese el radio de la circunferencia: ";
    std::cin >> R;

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(750, 500);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Tres tecnicas diferentes");
    init();
    glutDisplayFunc(display);
    glutMainLoop();

    return 0;
}
