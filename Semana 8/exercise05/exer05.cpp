#include <GL/glut.h>

void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    // Configurar el color del alambre (azul)
    glColor3f(0.0, 0.0, 1.0);

    // Dibujar un cubo alámbrico estático
    glutWireCube(1.0);

    glFlush();
}

void init() {
    glClearColor(0.0, 0.0, 0.0, 1.0); // Establecer color de fondo negro
    glEnable(GL_DEPTH_TEST); // Habilitar prueba de profundidad para que los objetos se muestren correctamente
}

int main(int argc, char **argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(500, 500);
    glutCreateWindow("Cubo alámbrico estático azul en OpenGL");
    
    init();
    
    glutDisplayFunc(display);
    
    glutMainLoop();
    
    return 0;
}
