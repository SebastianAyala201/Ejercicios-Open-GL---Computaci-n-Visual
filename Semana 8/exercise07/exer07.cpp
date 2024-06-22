#include <GL/glut.h>

// Inicialización de OpenGL
void init() {
    glClearColor(0.0, 0.0, 0.0, 1.0); // Color de fondo: negro
    glEnable(GL_DEPTH_TEST); // Habilitar el test de profundidad
}

// Función de dibujado
void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // Limpiar el buffer de color y profundidad
    glLoadIdentity(); // Resetear las transformaciones

    // Configurar la vista de la cámara
    gluLookAt(1, 0, 0.5,  // Posición de la cámara
              1, 0, 0,  // Punto de referencia al que mira la cámara
              5, 1, 0); // Vector de la dirección "arriba" de la cámara

    // Dibujar una esfera en modo alambre con radio 1, 20 meridianos y 10 paralelas
    glutWireSphere(1.0, 20, 10);

    glutSwapBuffers(); // Intercambiar los buffers para mostrar lo dibujado
}

// Función para redimensionar la ventana
void reshape(int w, int h) {
    glViewport(0, 0, (GLsizei)w, (GLsizei)h); // Ajustar el viewport al nuevo tamaño de la ventana
    glMatrixMode(GL_PROJECTION); // Cambiar a la matriz de proyección
    glLoadIdentity(); // Resetear la matriz de proyección
    gluPerspective(45.0, (GLfloat)w / (GLfloat)h, 1.0, 20.0); // Definir la perspectiva
    glMatrixMode(GL_MODELVIEW); // Volver a la matriz de vista/modelo
}

// Función principal
int main(int argc, char** argv) {
    glutInit(&argc, argv); // Inicializar GLUT
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH); // Usar doble buffer, color RGB y test de profundidad
    glutInitWindowSize(800, 600); // Tamaño inicial de la ventana
    glutInitWindowPosition(100, 100); // Posición inicial de la ventana
    glutCreateWindow("Esfera en OpenGL"); // Crear la ventana con un título

    init(); // Llamar a la función de inicialización

    glutDisplayFunc(display); // Definir la función de dibujado
    glutReshapeFunc(reshape); // Definir la función de redimensionado

    glutMainLoop(); // Iniciar el loop principal de GLUT

    return 0;
}
