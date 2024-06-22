#include <GL/glut.h>

void init() {
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // Color de fondo negro
    glEnable(GL_DEPTH_TEST); // Habilitar prueba de profundidad
}


void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    
    // Configurar la posición y orientación de la cámara (vista perspectiva)
    gluLookAt(10.0, 10.0, 10.0,   // Posición de la cámara (eye)
              0.0, 0.0, 0.0,   // Punto de mira (center)
              0.0, 1.0, 0.0);  // Vector de dirección de la cámara (up)
    
    // Configurar el color de dibujo del cubo
    glColor3f(0.0f, 0.0f, 1.0f); // Azul
    
    // Dibujar un cubo sólido
    glutSolidCube(10.0); // Tamaño del cubo: 1 unidad
    
    glutSwapBuffers();
}



int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(800, 600);
    glutCreateWindow("Cubo solido azul desde vista perspectiva");
    
    glutDisplayFunc(display);
    
    init();
    
    glutMainLoop();
    
    return 0;
}
