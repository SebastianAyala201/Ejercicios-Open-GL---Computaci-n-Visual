#include <GL/glut.h>
#include <vector>

// Estructura para almacenar la posición y color de un píxel
struct Pixel {
    int x, y;
    float r, g, b;
};

// Vector para almacenar los píxeles pintados
std::vector<Pixel> pixels;

void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    // Dibujar cada píxel almacenado en el vector
    glBegin(GL_POINTS);
    for (const auto& pixel : pixels) {
        glColor3f(pixel.r, pixel.g, pixel.b);
        glVertex2i(pixel.x, pixel.y);
    }
    glEnd();

    glutSwapBuffers();
}

void mouse(int button, int state, int x, int y) {
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
        // Convertir coordenadas de ventana a coordenadas de OpenGL
        int windowHeight = glutGet(GLUT_WINDOW_HEIGHT);
        int posX = x;
        int posY = windowHeight - y;  // Invertir y

        // Crear un nuevo píxel con color rojo
        Pixel pixel = { posX, posY, 1.0f, 0.0f, 0.0f };
        pixels.push_back(pixel);

        glutPostRedisplay();
    }
}

void init() {
    glClearColor(1.0, 1.0, 1.0, 1.0);  // Fondo blanco
    glColor3f(0.0, 0.0, 0.0);  // Color de dibujo negro
    glPointSize(5.0);  // Tamaño de los puntos

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, 800.0, 0.0, 600.0);  // Coordenadas del mundo
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(800, 600);
    glutCreateWindow("Resaltar Píxeles");

    init();

    glutDisplayFunc(display);
    glutMouseFunc(mouse);

    glutMainLoop();
    return 0;
}