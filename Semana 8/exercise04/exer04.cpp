#include <GL/glut.h>

// Ángulos de rotación
float rotX = 0.0f;
float rotY = 0.0f;

void inicio() {
    glClearColor(0.0, 0.0, 0.0, 1.0); 
    glEnable(GL_DEPTH_TEST); // Habilita el test de profundidad
    
    glMatrixMode(GL_PROJECTION);
    gluPerspective(45.0, 680.0 / 480.0, 1.0, 200.0); // Proyección perspectiva
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(0.0, 0.0, 5.0, // Posición de la cámara
              0.0, 0.0, 0.0, // Hacia dónde mira la cámara
              0.0, 1.0, 0.0); // Vector "up"
}

void pantalla() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();

    // Posición de la cámara
    gluLookAt(0.0, 0.0, 5.0,
              0.0, 0.0, 0.0,
              0.0, 1.0, 0.0);

    // Aplicar las rotaciones
    glRotatef(rotX, 1.0, 0.0, 0.0);
    glRotatef(rotY, 0.0, 1.0, 0.0);

    // Dibujamos el cubo
    glBegin(GL_QUADS);
        // Al Frente (Cara)
        glColor3f(1.0, 0.0, 0.0); 
        glVertex3f(-1.0, -1.0,  1.0);
        glVertex3f( 1.0, -1.0,  1.0);
        glVertex3f( 1.0,  1.0,  1.0);
        glVertex3f(-1.0,  1.0,  1.0);
        // Atrás (Abajo)
        glColor3f(0.0, 1.0, 0.0); 
        glVertex3f(-1.0, -1.0, -1.0);
        glVertex3f(-1.0,  1.0, -1.0);
        glVertex3f( 1.0,  1.0, -1.0);
        glVertex3f( 1.0, -1.0, -1.0);
        // Izquierda
        glColor3f(0.0, 0.0, 1.0);
        glVertex3f(-1.0, -1.0, -1.0);
        glVertex3f(-1.0, -1.0,  1.0);
        glVertex3f(-1.0,  1.0,  1.0);
        glVertex3f(-1.0,  1.0, -1.0);
        // Derecha
        glColor3f(1.0, 1.0, 0.0); 
        glVertex3f( 1.0, -1.0, -1.0);
        glVertex3f( 1.0,  1.0, -1.0);
        glVertex3f( 1.0,  1.0,  1.0);
        glVertex3f( 1.0, -1.0,  1.0);
        // Arriba (Parte superior)
        glColor3f(1.0, 0.0, 1.0); 
        glVertex3f(-1.0,  1.0, -1.0);
        glVertex3f(-1.0,  1.0,  1.0);
        glVertex3f( 1.0,  1.0,  1.0);
        glVertex3f( 1.0,  1.0, -1.0);
        // Abajo (Parte posterior)
        glColor3f(0.0, 1.0, 1.0); 
        glVertex3f(-1.0, -1.0, -1.0);
        glVertex3f( 1.0, -1.0, -1.0);
        glVertex3f( 1.0, -1.0,  1.0);
        glVertex3f(-1.0, -1.0,  1.0);
    glEnd();

    glFlush(); // Asegura que las órdenes de dibujo se ejecuten
    glutSwapBuffers(); // Cambia los buffers en modo de doble buffering
}

//Funcion para mover el cubo
void flechasTeclado(int key, int x, int y) {
    switch (key) {
        case GLUT_KEY_RIGHT:
            rotY += 5.0f; // Gira hacia la derecha
            break;
        case GLUT_KEY_LEFT:
            rotY -= 5.0f; // Gira hacia la izquierda
            break;
        case GLUT_KEY_UP:
            rotX += 5.0f; // Gira hacia arriba
            break;
        case GLUT_KEY_DOWN:
            rotX -= 5.0f; // Gira hacia abajo
            break;
    }
    glutPostRedisplay(); // Redibuja la pantalla
}

int main(int argc, char *argv[]) {
    glutInit(&argc, argv);
    glutInitWindowSize(680, 480);
    glutInitWindowPosition(10, 10);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH); // Modo de doble buffering y test de profundidad
    glutCreateWindow("Cubo 3D manipulado con las flechas"); // Crea una ventana con el título especificado
    inicio();
    glutDisplayFunc(pantalla);
    glutSpecialFunc(flechasTeclado); // Asocia la función de manejo de teclas especiales
    glutMainLoop();
    return EXIT_SUCCESS;
}
